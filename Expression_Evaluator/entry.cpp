/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream>
#include "entry.h"
using namespace std;
    SymEntry::SymEntry()
    {
        this->key="#";
        this->left=nullptr;
        this->right=nullptr;
        this->val=new UnlimitedRational();       //dummy
    }
    SymEntry::SymEntry(string k, UnlimitedRational* v)
    {
        this->key=k;
        this->val=v;
        this->left=nullptr;  
        this->right=nullptr;
    }
    SymEntry::~SymEntry()
    {
        val->~UnlimitedRational();
        left=nullptr;
        right=nullptr;
    } //check1
/*int main()
{
    cout<<"hi"<<endl;
}*/