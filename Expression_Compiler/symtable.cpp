/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream>
using namespace std;
#include "symtable.h"
//#include<vector>
//Write your code below this line
    
    void set_parent(SymNode*root,SymNode*&node)
    {
      // <<1<<endl;
      // <<"1"<<endl;
        if(root==NULL)
        {

            return ;
        }
        if(root->key<node->key)
        {
         //  <<2<<endl;
            if(root->right==nullptr)
            {
               //<<3<<endl;
                node->par=root;
                return;
            }
            set_parent(root->right,node);
        }
       else if(root->key>node->key)
        {
          // <<4<<endl;
            if(root->left==nullptr)
            {
              // <<5<<endl;
                node->par=root;
                return;
            }
            set_parent(root->left,node);
        }  
    }
    void free(SymNode*&root)
    {
     //  <<"2"<<endl;
      //  <<6<<endl;
        if(root==NULL)
        {
            return;
        }
        free(root->left);
        free(root->right);
    //   <<7<<endl;
        delete root;
    }
    SymNode* SymbolTable::get_root()
{
   //<<"3"<<endl;
 // <<8<<endl;
    return root;
}
   int htf(SymNode*node)
    {
     //  <<"4"<<endl;
    //<<9<<endl;
        if(node==NULL)
        {
         //  <<10<<endl;
            return 0;
        }
        return node->height;
    }
    void hbf(SymNode*&node)
    {
      // <<"5"<<endl;
    // <<11<<endl;
        if(node!=NULL)
        {
           //<<12<<endl;                                                                         
            node->height= 1+max(htf(node->left),htf(node->right));
        }
    }

        void updateheight(SymNode*root)
    {
        SymNode*temp=root;
        if(temp==nullptr)
        {
            return;
        }
        while(temp&& temp->key!="#")
        {
      //     <<13<<endl;
            hbf(temp);
            temp=temp->par;
        }
      //  temp->~SymNode();
        return;
    }
    int balancef(SymNode*node)
    {
        return htf(node->left)-htf(node->right);
    }
    SymNode*insertNode(SymNode*node,SymNode*root,string k)
    {
      // <<15<<endl;
        if(root==NULL)
        {
         //  <<16<<endl;
         //  <<"7"<<endl;
            root=new SymNode(k);
           // root->key=k;
           set_parent(node,root);
           updateheight(root);
           if(k<root->par->key)
           {
                    root->par->left=root;
           }
           else
           {
                root->par->right=root;
           }
           //<<17<<endl;
            return root;
        }
        else if(root->key<k)
        {
           //<<"8"<<endl;
         // <<18<<endl;
            root->right=insertNode(node,root->right,k);
      //     <<19<<endl;
          // <<"*"<<endl;
        }
        else if(root->key>k)
        {
            //cout<<"9"<<endl;
    //       <<20<<endl;
            root->left=insertNode(node,root->left,k);
         //  <<21<<endl;
           //<<"**"<<endl;
        }
        set_parent(node,root);
        updateheight(root);
    
        int balance=balancef(root);
         if(balance<-1)
        {
          
            if(k>root->right->key)
            {
           //  cout<<"3"<<endl;
                return root->LeftLeftRotation();
            }
            else
            {
             // cout<<"4"<<endl;
             return root->RightLeftRotation();
            }
        }
        if(balance>1)
        {
            if(k<root->left->key)
            {
              // cout<<"1"<<endl;
              
              return root->RightRightRotation();
            }
            else if(k>root->left->key)
            { 
              //  cout<<"2"<<endl;
             return root->LeftRightRotation();
            }
        }
     
        return root;
    }
    SymNode*searchNode(SymNode*node,string k)
    {
      // <<"hi5"<<endl;
    // <<"10"<<endl;
   //<<29<<endl;
        if(node==NULL)
        {
            return NULL;
        }
        if(node->key==k)
        {
            return node;
        }
        if(node->key<k)
        {
         return  searchNode(node->right,k);   //correct
        }
        else
        {
          return searchNode(node->left,k);
        }  
       // return node; 
      //<<30<<endl;
    }
    SymNode*findmin(SymNode*node)
    {
       //<<"11"<<endl;
       //cout<<31<<endl;
        if(node==NULL)
        {
            return node;
        }
        while(node->left!=NULL)
        {
            node=node->left;
        }
        return node;
       //<<32<<endl;
    }
    SymNode*removeNode(SymNode*root,string k)
    {
       //<<"12"<<endl;
        if(root==NULL)
        {
            return NULL;
        }
      else  if(root->key<k)
        {
           //<<"@"<<endl;
            root->right=removeNode(root->right,k);
        }
        else if(root->key>k)
        {
            root->left=removeNode(root->left,k);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {  
                if(root->par)
                {
                    root->par->height=1;
                }
                root->~SymNode();
              //  delete root;
              //  updateheight1(parent);
                return NULL;
                //logic//breaking the linke so node is deleted and we need to decrement height of each succesive parent node by 1

              // delete root;
               //return  NULL;
            }
           else  if(root->left==NULL)
            {
                
               root=root->right;
              //  delete temp;
              //  updateheight1(root);
                return root;
            }
            else if(root->right==NULL)
            { 
               root=root->left;
                return root;
            //    temp->par=nullptr;
            }
            else
            {
                SymNode*temp=findmin(root->right);
                root->key=temp->key;
                //cout<<temp->key;
                root->height=temp->height;
                root->address=temp->address;
                root->right=removeNode(root->right,temp->key);                     
            }
        }
      // <<"hi"<<endl;
        hbf(root);
        
        int balance=balancef(root);
        if(balance<-1)
        {
            if(balancef(root->right)<=0)
            {
                
             return root->LeftLeftRotation();
            }
            else
            {
               return root->RightLeftRotation();
            }
        }
       else if(balance>1)
        {
            if(balancef(root->left)>=0)
            {
              //  cout<<"1"<<endl;
               return  root->RightRightRotation();
            }
            else
            {
                
                return root->LeftRightRotation();
            }
        }
   
        return root;
    }

/*void preorder(SymNode*root)
{
    if(root==NULL||root->key=="#")
    {
        return;
    }
    if(root->par!=nullptr)
    {
      cout <<root->par->key<<" ";
    }
    cout<<root->key<<" ";
   cout<<root->height<<endl;
    preorder(root->left);
    preorder(root->right);
}*/
SymbolTable::SymbolTable()
{
    this->size=0;
    this->root=new SymNode();
}
void SymbolTable::insert(string k)
{
   //<<"13"<<endl;
  //<<33<<endl;
    if(root==NULL||root->key=="#")
    {
        this->root=new SymNode(k);
        root->height=1;
        (this->size)++;
        return ;
    }
   this->root= insertNode(root,root,k);
     size++;                              //while insertion removal check balance factor
}
void SymbolTable::remove(string k)
{
    //cout<<k<<endl;
  // <<"14"<<endl;
     if(root->key=="#"||root==NULL||search(k)==-2)
     {
        return;
     }
   // <<"8"<<endl;
   root= removeNode(root,k);
    size--;
}
int SymbolTable::search(string k)
{
    //cout<<15<<endl;
    if(root==NULL||root->key=="#")
    {
        return -2;
    }
    if(searchNode(root,k))
    {
        return searchNode(root,k)->address;
    }
    else
    {
        return -2;
    }
}
void SymbolTable::assign_address(string k,int idx)
{
    //cout<<16<<endl;
    if(search(k)!=-2)
    {
        searchNode(root,k)->address=idx;
    }
       else
       {
            insert(k);
            searchNode(root,k)->address=idx;
       } 
        return;
 
}
int SymbolTable::get_size()
{
   
    return this->size;
}

SymbolTable::~SymbolTable()
{
    free(root);
}
