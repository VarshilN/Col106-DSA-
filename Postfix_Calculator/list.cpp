#include<stdexcept>
#include"node.h"
#include"list.h"
#include<iostream>
using namespace std; 
    List::List()
    {
        this->size=0;
        try{
            this->sentinel_head=new Node(true);
            this->sentinel_tail=new Node(true);
        }catch(bad_alloc &e){
            throw("Out of Memory");
        }
        sentinel_head->next=sentinel_tail;
        sentinel_tail->prev=sentinel_head;
        sentinel_head -> prev = nullptr;
        sentinel_tail -> next = nullptr;
    }
   List:: ~List()
    {
        Node*temp=sentinel_head;
        while(temp != sentinel_tail)
        {
            Node*nxt=temp;
            temp=temp->next;
            delete nxt;
        }
        delete sentinel_tail;
        //delete sentinel_head;
    }
    // Insert an element at the tail of the linked list 
    void List:: insert(int v)
    {
        Node*target=nullptr;
        
        try{
            target=new Node(v,nullptr,nullptr);
        }
        catch(bad_alloc & e)
        {
            throw("Out of Memory");
        }
         target->prev=sentinel_tail->prev;
         target->next=sentinel_tail;
         sentinel_tail->prev->next=target;
         sentinel_tail->prev=target;
        size++;
        /*Node* back = sentinel_tail -> prev;
        back -> next = target;
        target -> prev = back;
        target -> next = sentinel_tail;
        sentinel_tail -> prev = target;*/
        return;
    }
    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
    int List::delete_tail()
    {
        (this->size)--;
        int top=sentinel_tail->prev->get_value();
        Node*temp1=sentinel_tail->prev;
        Node*temp=temp1->prev;
        temp->next=sentinel_tail;
        delete temp1;
        sentinel_tail->prev=temp;
        return top;
    }
    // Return the size of the linked list 
    // Do not count the sentinel elements
    int List:: get_size()
    {
        return this->size;
    }
    // Return a pointer to the sentinel head of the linked list 
    Node*List:: get_head()
    {
        return this->sentinel_head;
    }
    //Node*get_tail();
