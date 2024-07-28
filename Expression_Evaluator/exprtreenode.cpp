/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream>
#include "exprtreenode.h"
    ExprTreeNode::ExprTreeNode()
    {
        this->type="#"; 
        this->val=new UnlimitedRational();
        this->left=nullptr;
        this->id="#";
        this->right=nullptr;  // this one is dummy node;
        this->evaluated_value=new UnlimitedRational();
    } 
    ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v)
    {
        this->type=t;
        this->id=t;
        this->val=new UnlimitedRational(v,new UnlimitedInt(1));
        this->evaluated_value=val;
        this->left=nullptr;               
        this->right=nullptr;              // evaluated values of v and := garbage
    }
    ExprTreeNode::ExprTreeNode(string t,UnlimitedRational*v)
    {
        this->type=t;
        this->val=v;
        this->id=type;
        this->left=nullptr;           
        this->right=nullptr;
        this->evaluated_value=v;
    }
    ExprTreeNode::~ExprTreeNode()
    {
        val->~UnlimitedRational();
        evaluated_value->~UnlimitedRational();
        left=nullptr;
        right=nullptr;
    }              // check1
/*int main()
{
    cout<<"hi"<<endl;
}*/