/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

//Write your code below this line

    ExprTreeNode::ExprTreeNode()
    {
        this->type="";
        this->id="";
        this->num=0;
        this->left=NULL;
        this->right=NULL;
    }
    ExprTreeNode::ExprTreeNode(string t,int v)
    {
        this->type=t;
        this->num=v;
        this->id=t;
        this->left=NULL;
        this->right=NULL;
    }
    ExprTreeNode::~ExprTreeNode()
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
    }

