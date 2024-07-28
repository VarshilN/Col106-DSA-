/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"

//Write your code below this line
   int heightf(SymNode*node)
    {
        if(node==NULL)
        {
            return 0;
        }
        return node->height;
    }
    int hb(SymNode*node)
    {
        if(node!=NULL)
        {
           return 1+max(heightf(node->left),heightf(node->right));
        }
    }
SymNode::SymNode()
{
    this->key="#";
    this->height=0;
    this->par=NULL;
    this->left=NULL;
    this->right=NULL;
    this->address=-1;
}
SymNode::SymNode(string k)
{
    this->key=k;
    this->height=1;
    this->par=NULL;
    this->left=NULL;
    this->right=NULL;
   this->address=-1;
}
SymNode* SymNode::LeftLeftRotation()
{
    SymNode*gp=this->par;
    SymNode*Y=this;
   SymNode*X=Y->right;
   SymNode*T2=X->left;
   X->left=Y;
   Y->right=T2;
    X->left = Y;
    Y->right = T2;
    X->par = gp;
    Y->par = X;
    if (T2)
        T2->par = Y;
   Y->height=hb(Y) ;
   X->height=hb(X);
    return X;
}
SymNode* SymNode::RightRightRotation()
{
    SymNode*gp=this->par;
    SymNode*Y=this->left;
    SymNode*T1=Y->right;
    Y->right=this;
    this->left=T1;
    Y->par=gp;
    this->par=Y;
    if(T1)
    {
        T1->par=this;
    }
    this->height=hb(this);
    Y->height=hb(this);
    return Y;
}
SymNode* SymNode::LeftRightRotation()
{
    SymNode*X=this->left;
   this->left= X->LeftLeftRotation();
   return this-> RightRightRotation();
}
SymNode*SymNode::RightLeftRotation()
{
    SymNode*Y=this->right;
    this->right=Y->RightRightRotation();
   return this->LeftLeftRotation();  
}
SymNode::~SymNode()
{
   if(left)
   {
    delete left;
    left=nullptr;
   }
   if(right)
   {
    delete right;
    right=nullptr;
   }
 
   // delete par;
    //delete this;
}
