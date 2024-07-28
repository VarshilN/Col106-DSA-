/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "heapnode.h"

//Write your code below this line

HeapNode::HeapNode()
{
  this->val=-1;
    this->par=nullptr;
    this->left=nullptr;
    this->right=nullptr;
}
HeapNode::HeapNode(int _val)
{
  this->val=_val;
  this->left=nullptr;
  this->right=nullptr;
  this->par=nullptr;
}
HeapNode::~HeapNode()
{
    this->par=nullptr;
    this->left=nullptr;
    this->right=nullptr;
}




