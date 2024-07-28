/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
#include<iostream>
using namespace std;
    SymEntry*findSux(SymEntry*node)
    {
        while(node->left!=nullptr)
        {
            node=node->left;
        }
        return node;
    }
    SymEntry*removeNode(SymEntry*node,string k)
    {
        if(node==nullptr||node->key=="#")
        {
            return nullptr;
        }
        if(node->key<k)
        {
            node->right=removeNode(node->right,k);
        }
        else if(node->key>k)
        {
            node->left=removeNode(node->left,k);
        }
        else
        {
            if(node->left==nullptr)
            {
                SymEntry*temp=node;
                node=node->right;
                delete temp;
                return node;
            }
            if(node->right==nullptr)
            {
                SymEntry*temp=node;
                node=node->left;
                delete temp;
                return node;
            }
            else
            {
               string sux=findSux(node->right)->key;
                node->key=sux;
               node->right= removeNode(node->right,sux);
            }
        }
        return node;
    }
    SymEntry*searchNode(SymEntry*node,string k)
    {
      //  cout<<"hi5"<<endl;
        if(node==NULL)
        {
            return nullptr;
        }
        if(node->key==k)
        {
            return node;
        }
        if(node->key<k)
        {
         return searchNode(node->right,k);   //correct
        }
        else
        {
           return searchNode(node->left,k);
        }   
    }
    SymEntry*insertNode(SymEntry*node,string k,UnlimitedRational*v)
    {
        //cout<<"hi6"<<endl;
        if(node==nullptr)
        {
            return new SymEntry(k,v);
        }
        if(node->key<k)
        {
           node->right= insertNode(node->right,k,v);
        }
        if(node->key>k)   //correct
        {
           node->left= insertNode(node->left,k,v);
        }
        return node;
    }
    SymbolTable::SymbolTable()
    {
        this->size=0;               
        this->root=new SymEntry();
    }
    SymbolTable::~SymbolTable()
    {
        root->~SymEntry();
    }
    // Insert a key value pair in the symbol table
    void SymbolTable::insert(string k, UnlimitedRational* v)
    {
       // bool flag=0;
        insertNode(root,k,v);
        size++;
       // cout<<flag<<endl;
    }
    // Remove a key (and value) in the symbol table
    void SymbolTable::remove(string k)
    {
        SymEntry*temp=removeNode(root,k);
        if(temp)
        {
            size--;
        }
    }
    // Find the val corresponding to the key in the symbol table
    UnlimitedRational*SymbolTable::search(string k)
    {
        SymEntry*found=searchNode(root,k);
        if(found!=nullptr)
        {
            return found->val;
        }
        else
        {
            return nullptr;
        }
    }
   /* int main()
    {
        cout<<"hi"<<endl;
    }*/