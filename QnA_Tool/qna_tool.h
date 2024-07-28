
#include <iostream>
#include <fstream>
#include "Node.h"
#include"dict.h"
#include"search.h"
//#include"minheap.h"
using namespace std;

class telement
{
public:
    int book_code = 0;
    int page = 0;
    int paragraph = 0;
    int sentence_no = 0;
    std::vector<string> sentence;
    telement(int b, int p, int pa, int se, vector<string> s)
    {
        book_code = b;
        page = p;
        paragraph = pa;
        sentence_no = se;
        sentence = s;
    }
};


class QNA_tool {
private:

    // You are free to change the implementation of this function
    void query_llm(string filename, Node* root, int k, string API_KEY,string question);
    

    // You can add attributes/helper functions here

public:
    vector<telement*> corpus;
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Hash*wordpair;
    Dict*dic = new Dict();
    SearchEngine*src;
    dumyHash*dumy;
    QNA_tool(); // Constructor
    ~QNA_tool(); // Destructor

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);
    // This function is similar to the functions in dict and search 
    // The corpus will be provided to you via this function
    // It will be called for each sentence in the corpus

    Node* get_top_k_para(string question, int k);
    // This function takes in a question, preprocess it
    // And returns a list of paragraphs which contain the question
    // In each Node, you must set: book_code, page, paragraph (other parameters won't be checked)
    std::string get_paragraph(int book_code, int page, int paragraph);
    void query(string question, string filename);
    // This function takes in a question and a filename.
    // It should write the final answer to the specified filename.

    /* -----------------------------------------*/
    /* Please do not touch the code above this line */

    // You can add attributes/helper functions here
};


//MINHEAP IMPLEMENTATION:


class heapNode
{
  public:
  float val;
  //std::string par;
  Node*n=nullptr;
  heapNode()
  {
   // this->par="";
    this->val=-1;
  }
};
class MinHeap{
  public:
   int size;
vector<heapNode*>heap;
  MinHeap(){
    this->heap=vector<heapNode*>();
  }
  ~MinHeap(){
    for(heapNode*node:heap)
        {
            if(node != nullptr){
                delete node;
            }    
        }
        //heap.clear();
  }
  void push_heap(float value,Node*n){
    
    heapNode*temp=new heapNode();
        temp->n=n;
        temp->val=value;
        heap.push_back(temp);
        heap_up(heap.size() - 1,heap);

  } // Insert num into the heap
  heapNode*get_min(){

    return heap[0];    

  } // Returns min of the heap (which must be at root)
  void pop(){

    if (heap.empty())
         {
            return;
        }
        heapNode*res=heap[0];
        heap[0]=heap[heap.size()-1];
        heap[heap.size()-1]=res;
        delete res;
        heap.pop_back();
        heap_down(0,heap);

  } // Deletes the min element from the heap
  bool empty(){

    return heap.empty();    

  }

  //helpers:

    void  heap_up(int index,vector<heapNode*>&heap) {
        while (index > 0) {
            int parent= (index - 1) / 2;
            if (heap[index]->val < heap[parent]->val) {
                    heapNode*res=heap[index];
        heap[index]=heap[parent];
        heap[parent]=res;
                index = parent;
            } else {
                break;
            }
        }
    }
    void heap_down(int index,vector<heapNode*>&heap) {
        int left = 2 * index + 1;
        int right= 2 * index + 2;
        int idx = index;
        if (left< heap.size() && heap[left]->val < heap[idx]->val) {
            idx = left;
        }

        if (right< heap.size() && heap[right]->val < heap[idx]->val) {
            idx = right;
        }

        if (idx != index) {
            heapNode*res=heap[index];
        heap[index]=heap[idx];
        heap[idx]=res;
            heap_down(idx,heap);
        }
    }
};
// //.cpp part:

// // Helper function to madoubleain the heap property after push_heapion or deletion
//     MinHeap::MinHeap()
//     {
//         this->heap=vector<heapNode*>();
//     }
//     void  heap_up(int index,vector<heapNode*>&heap) {
//         while (index > 0) {
//             int parent= (index - 1) / 2;
//             if (heap[index]->val < heap[parent]->val) {
//                     heapNode*res=heap[index];
//         heap[index]=heap[parent];
//         heap[parent]=res;
//                 index = parent;
//             } else {
//                 break;
//             }
//         }
//     }
//     void heap_down(int index,vector<heapNode*>&heap) {
//         int left = 2 * index + 1;
//         int right= 2 * index + 2;
//         int idx = index;
//         if (left< heap.size() && heap[left]->val < heap[idx]->val) {
//             idx = left;
//         }

//         if (right< heap.size() && heap[right]->val < heap[idx]->val) {
//             idx = right;
//         }

//         if (idx != index) {
//             heapNode*res=heap[index];
//         heap[index]=heap[idx];
//         heap[idx]=res;
//             heap_down(idx,heap);
//         }
//     }
//     // push_heap an element doubleo the heap
//     void MinHeap::push_heap(double value,Node*n) {
//         heapNode*temp=new heapNode();
//         temp->n=n;
//         temp->val=value;
//         heap.push_back(temp);
//         heap_up(heap.size() - 1,heap);
//     }
//     // Delete the minimum element (root) from the heap
//     void MinHeap::pop() {
//         if (heap.empty())
//          {
//             return;
//         }
//         heapNode*res=heap[0];
//         heap[0]=heap[heap.size()-1];
//         heap[heap.size()-1]=res;
//         delete res;
//         heap.pop_back();
//         heap_down(0,heap);
//     }
//     // Get the minimum element (root) of the heap
//     heapNode*MinHeap:: get_min() {
//         return heap[0];
//     }
//     bool MinHeap::empty()
//     {
//         return heap.empty();
//     }
//     MinHeap::~MinHeap()
//     {
//         for(heapNode*node:heap)
//         {
//             delete node;
//         }
//         heap.clear();
//     }

//     //.h part