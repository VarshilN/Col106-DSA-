
#include<iostream>
#include<stdexcept>
#include"node.h"
using namespace std;
    // Use to construct a sentinel node (see list.h)
    Node::Node(bool sentinel)
    {
        this->is_sentinel=sentinel;
        this->value=-1;
        this->next=nullptr;
        this->prev=nullptr;
    }
    // Use to construct a regular node
   Node:: Node(int v, Node* nxt, Node* prv)
    {
        this->is_sentinel=false;
        this->value=v;
        this->next=nxt;
        this->prev=prv;
    }
    // Return whether a node is a sentinel node 
    // Use it to check if we are at the ends of a list
    bool Node:: is_sentinel_node()
    {
        return this->is_sentinel;
    }
    // Return the value of a node
    int Node:: get_value()
    {
        return this->value;
    }
    