/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream>
using namespace std;
#include "minheap.h"
int height(int size)
{
    if(size==1||size==0)
    {
        return 0;
    }
    return 1+height(size/2);
}
void free(HeapNode*&root)
{
    if(root==nullptr)
    {
        return;
    }
    free(root->left);
    free(root->right);
    root->~HeapNode();
}

MinHeap::MinHeap()
{
    this->root=nullptr;
    this->size=0;
}
void heapUp(HeapNode*node)
{
    if(node->par==nullptr)
    {
        return ;
    }
    if(node->par&& node->par->val > node->val)
    {
        int temp=node->val;
        node->val=node->par->val;
        node->par->val=temp;
        heapUp(node->par);
    }
}

/*HeapNode*last_parent(HeapNode*root)
{
    if(root==nullptrptr)
    {
        return root;
    }
    HeapNode*left_p=last_parent(root->left);
    HeapNode*right_p=last_parent(root->right);
    if(left_p==nullptrptr ||right_p==nullptrptr)
    {
        return root;
    }
    else
    {
        root->left=left_p;
        root->right=right_p;
        return root;
    }
}*/
HeapNode*last_parent(HeapNode*root,int size)
{
      HeapNode*parent=root;
    if(root==nullptr)
    {
        return root;
    }
   int temp=size+1;
   int idx=0;
   int len=height(temp)+1;
    int curr[len];
    while(temp>0)
    {
        if(temp%2==0)
        {
            curr[len-idx-1]=0;
        }
        else
        {
            curr[len-idx-1]=1;
        }
        temp=temp/2;
        idx++;
    }
    
   
     idx=1;
    while(idx<len-1 && parent!=nullptr)
    {
        if(curr[idx]==0)
        {
            parent=parent->left;
        }
        else
        {
            parent=parent->right;
        }
        idx++;
    }
    return parent;
}
void heapDown(HeapNode*node)
{
    if(node==nullptr)
    {
        return;
    }
    HeapNode*temp=node;
    if(temp->left!=nullptr&&temp->val>temp->left->val)
    {
        temp=temp->left;
    }
    if(temp->right!=nullptr&&temp->val>temp->right->val)
    {
        temp=temp->right;
    }
    if(temp==node)
    {
        return;
    }
    else
    {
        int res=temp->val;
        temp->val=node->val;
        node->val=res;
        heapDown(temp);
    }
}
/*HeapNode*insert_last(HeapNode*root,int size)
{
 
 /* // int idx=0;
   // int size=Nodes(root);
    HeapNode*arr[size];
    int idx=1;
    arr[0]=root;
    while(idx<size &&arr[idx-1]!=nullptr)
    {
        int parent=(idx-1)/2;
        int left=(2*parent+1);
        int right=(2*parent+2);
        HeapNode*front= arr[parent];
        if(front&&front->left)
        {
            arr[left]=front->left;
            idx++;
        }
        if(front&&front->right)
        {
            arr[right]=front->right;
            idx++;
        }
        else
        {
            arr[idx]=nullptr;
        }
    }
    /*for(int i=0;i<size;i++)
    {
        if(arr[i]!=nullptr)
        {
          //   cout<<arr[i]->val<<" ";
        }
    }
    cout<<endl;
    int index=0;
    while(index<size)
    {
        if(2*index+1>=size||2*index+2>=size)
        {
           // HeapNode*temp=arr[index];
            return  arr[index];
        }
        else
        {
            index+=1;
        }
    }   
    
}*/
HeapNode*lastNode(HeapNode*root,int size)
{
    HeapNode*parent=last_parent(root,size);

   if(parent->left==nullptr && parent->right==nullptr)
    {
        return parent;
    }
    if(parent->left==nullptr)
    {
        return parent->right;
    }
    if(parent->right==nullptr)
    {
        return parent->right;
    }
     if(root==nullptr)
    {
        return root;
    }
   // int idx=0;
   // int size=Nodes(root);
  /*  HeapNode*arr[size];
    int idx=1;
    arr[0]=root;
    while(idx<size &&arr[idx-1]!=nullptr)
    {
        int parent=(idx-1)/2;
        int left=(2*parent+1);
        int right=(2*parent+2);
        HeapNode*front= arr[parent];
        if(front&&front->left)
        {
            arr[left]=front->left;
            idx++;
        }
        if(front&&front->right)
        {
            arr[right]=front->right;
            idx++;
        }
        else
        {
            arr[idx]=nullptr;
        }
    }*/
   /* for(int i=0;i<size;i++)
    {
        if(arr[i]!=nullptr)
        {
            // cout<<arr[i]->val<<" ";
        }
    }
    cout<<endl;
   return arr[size-1];*/
}
void MinHeap::push_heap(int num)
{
        if (root == nullptr) 
        {
            root = new HeapNode(num);
            size++;
            return;
        }
        HeapNode* pos = last_parent(root,size);
           cout<<pos->val<<endl;
        //cout<<pos->val<<endl;
        HeapNode* temp = new HeapNode(num);
        if (pos->left == nullptr) {
            pos->left = temp;
            temp->par = pos;
            heapUp(temp); // Call heapUp on the inserted node
            size++;
            return;
        }
        if (pos->right == nullptr) {
            pos->right = temp;
            temp->par = pos;
            heapUp(temp); // Call heapUp on the inserted node
            size++;
            return;
        }
}
int MinHeap::get_min()
{       
        return root->val;
} 
void MinHeap::pop()
{
    if (root == nullptr) {
        return; // Nothing to pop from an empty heap
    }
    if (size == 1) {
        root = nullptr;
        size--;
        return;
    }
    HeapNode*last=lastNode(root,size);
   // cout<<last->val<<endl;
    int res=last->val;
    root->val=last->val;   //we're removing the minimum value
    delete last;
    size--;
    heapDown(root);
    return;
}
MinHeap::~MinHeap()
{
   free(root);
}
/*int main()
{
    //int a=8;
    MinHeap a;
    a.push_heap(5);
    a.push_heap(6);
    a.push_heap(7);
    a.push_heap(8);
    a.push_heap(9);
   a.push_heap(11);
   a.push_heap(4);
   a.push_heap(2);
   a.push_heap(15);
   a.push_heap(18);
}*/