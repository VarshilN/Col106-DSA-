/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream>
#include "evaluator.h"
#include<vector>
using namespace std;
    bool isOp(string s)
    {
        if(s=="+"||s=="*"||s=="-"||s=="/"||s=="%")
        {
            return true;
        }
        return false;
    }
    bool check(string s)
    {
        vector<string>res={"(",")","%","+","-","*","/"};
        for(int i=0;i<res.size();i++)
        {
            if(s==res[i])
            {
                return  false;
            }
        }
        return true;
    }

    ExprTreeNode*solve(vector<string>code,SymbolTable*symtable)
    {
           int idx=2;
           vector<ExprTreeNode*>vals;
           vector<string>ops;
           int count=0;
       while(idx<code.size())
       {
            if(check(code[idx]))
            {
               // count+=2;
                ExprTreeNode*temp=nullptr;
                string type="";
                if(symtable->search(code[idx]))
                {
                    
                    // type=code[idx];
                   // cout<<code[idx]<<endl;
                     UnlimitedRational*val=symtable->search(code[idx]);
                     temp=new ExprTreeNode();
                     temp->type="VAR";
                     temp->val=val;
                     temp->evaluated_value=val;
                     temp->id=code[idx];
                   //  cout<<"**"<<endl;
                }
                else
                {
                    //it's a constant
                   // cout<<"**"<<endl;
                    temp=new ExprTreeNode();
                    temp->type="VAL";
                    temp->val=new UnlimitedRational(new UnlimitedInt(code[idx]),new UnlimitedInt("1"));
                    temp->evaluated_value=temp->val;
                    temp->id=temp->type;
                }
                vals.push_back(temp);
            }
            else if(isOp(code[idx]))
            {
                ops.push_back(code[idx]);
            }
           else  if(code[idx]=="(")
            {
                ops.push_back(code[idx]);
            }
           else  if(code[idx]==")")
            {
                while(!ops.empty()&&ops.back()!="(")
                {
                    string top=ops.back();
                    ops.pop_back();
                    string type="" ;//trash part of assgnment
                    if(top=="+")
                    {
                        type="ADD";
                    }
                     if(top=="-")
                    {
                        type="SUB";
                    }
                     if(top=="*")
                    {
                        type="MUL";
                    }
                     if(top=="/")
                    {
                        type="DIV";
                    } 
                    if(top=="%") 
                    {
                        type="MOD";
                    }
                    ExprTreeNode*element=new ExprTreeNode();
                    element->type=type;
                    element->right=vals.back();
                    vals.pop_back();
                    element->left=vals.back();
                    element->id=type;
                    element->evaluated_value=element->val=new UnlimitedRational();
                    vals.pop_back();
                    vals.push_back(element);
                }
                ops.pop_back();
            }
            idx++;
       }
      /*while(!ops.empty())
       {
                    string top=ops.back();
                    string type="" ;//trash part of assgnment
                    if(top=="+")
                    {
                        type="ADD";
                    }
                    else if(top=="-")
                    {
                        type="SUB";
                    }
                    else if(top=="*")
                    {
                        type="MUL";
                    }
                    else if(top=="/")
                    {
                        type="DIV";
                    } 
                    else if(top=="%") 
                    {
                        type="MOD";
                    }       
                    ops.pop_back();
                    ExprTreeNode*element=new ExprTreeNode();
                    element->type=type;
                    element->id=type;
                    element->right=vals.back();
                    vals.pop_back();
                    element->left=vals.back();
                    vals.pop_back();
                    vals.push_back(element);
       }*/
      // cout<<count<<endl;
       ExprTreeNode*element=new ExprTreeNode();
       element->type="ASS";
       element->id=code[1];
       element->left=new ExprTreeNode();
       element->left->type="VAR";
       element->left->id=code[0];
       element->right=vals.back();
       vals.pop_back();
       
      // cout<<count<<endl;
       return element;
    }
   /*UnlimitedRational*evaluate(ExprTreeNode*root,SymbolTable*symtable)
    {
        vector<ExprTreeNode*>ops;
        vector<UnlimitedRational*>vals;
        ops.push_back(root);
        while(!ops.empty())
        {
            ExprTreeNode*top=ops.back();
            ops.pop_back();
            if(top->left==nullptr && top->right==nullptr)
            {
            if(check(top->type))
            {
                if(top->type=="VAR")
                {
                    vals.push_back(symtable->search(top->id));
                }
                else
                {
                    vals.push_back(top->val);
                }
            }
            }
        else
        {

            if(check(top->type))
            {
                if(top->type=="VAR")
                {
                    vals.push_back(symtable->search(top->id));
                }
                else
                {
                    vals.push_back(top->val);
                }
            }
            else
            {
                UnlimitedRational*left=vals.back();
                vals.pop_back();
                UnlimitedRational*right=vals.back();
                vals.pop_back();
                string key=ops.back()->type;
            if(key=="ADD")
            {
                vals.push_back(left->add(left,right));
            }
            if(key=="SUB")
            {
              
                vals.push_back(right->sub(left,right));
            }
            if(key=="MUL")
            {
                vals.push_back(left->mul(left,right));
            }
            if(key=="DIV")
            {
              vals.push_back(left->div(left,right));
            }  
            }
        }
        }
        if(!vals.empty())
        {
            return vals.back();
        }
       if(root==NULL)
        {
            return new UnlimitedRational(new UnlimitedInt("0"),new UnlimitedInt("1"));
        }
        else if(root->left==nullptr && root->right==nullptr)
        {
            if(root->type=="VAR")
            {
               // cout<<"**"<<endl;
               cout<<root->id<<endl;
              cout<<root->val->get_frac_str()<<endl;
              // root->val=root->evaluated_value=symtable->search(root->id)
                return root->evaluated_value;
            }
            else
            {
                //cout<<"**"<<endl;
                cout<<root->val->get_frac_str()<<endl;
                return root->val;
            }
        }
        UnlimitedRational*left=evaluate(root->left,symtable);
        UnlimitedRational*right=evaluate(root->right,symtable);
        if(root->type=="VAR" ||root->type=="VAL")
        {
            //cout<<root->type<<endl;
            if(root->type=="VAR")
            {
              //  cout<<"**"<<endl;
              // root->val=root->evaluated_value = symtable->search(root->id);
               return root->evaluated_value;
            }
            else
            {
               // cout<<root->val->get_frac_str()<<endl;
                return root->val;
            }
        }
      else
        {
            string key=root->type;
           // cout<<key<<endl;
            UnlimitedRational*temp=new UnlimitedRational(new UnlimitedInt("0"),new UnlimitedInt("1"));
            if(key=="ADD")
            {
               root->val= root->evaluated_value=temp->add(left,right);      
                //cout<<root->val->get_frac_str()<<endl;
            }
            if(key=="SUB")
            {
               root->val= root->evaluated_value=temp->sub(left,right);
        
            }
            if(key=="MUL")
            {
               root->val= root->evaluated_value=temp->mul(left,right);

              //  cout<<root->val->get_frac_str()<<endl;
            }
            if(key=="DIV")
            {
              root->val= root->evaluated_value=temp->div(left,right);
               // cout<<root->val->get_frac_str()<<endl;
            }
             return root->val;
        }
    }*/
UnlimitedRational*evaluate(ExprTreeNode* root, SymbolTable* symtable)
{
    if (root == nullptr)
    {
        return new UnlimitedRational(new UnlimitedInt("0"), new UnlimitedInt("1"));
    }
     if (root->left == nullptr && root->right == nullptr)
    {
        if (root->type == "VAR")
        {

          root->evaluated_value = symtable->search(root->id);
            //cout<<root->val->get_frac_str()<<endl;
            return root->evaluated_value;
        }
        else
        {
            return root->val;
        }
    }
    UnlimitedRational* left = evaluate(root->left, symtable);
    UnlimitedRational* right = evaluate(root->right, symtable);
    if (root->type == "VAR" || root->type == "VAL")
    {
        if (root->type == "VAR")
        {
           // cout<<root->id<<endl;
            root->evaluated_value=symtable->search(root->id);
            return root->evaluated_value;
        }
        else
        {
            return root->val;
        }
    }
    else
    {
        string key = root->type;
        UnlimitedRational* temp = new UnlimitedRational(new UnlimitedInt("0"), new UnlimitedInt("1"));
        if (key == "ADD")
        {
           root->evaluated_value = left->add(left, right);
            return root->evaluated_value;
        }
        if (key == "SUB")
        {
           root->evaluated_value = left->sub(left, right);
            return root->evaluated_value;
        }
        if (key == "MUL")
        {
            //cout<<"**"<<endl;
          // cout<<left->get_frac_str()<<endl;
           // cout<<right->get_frac_str()<<endl;
          root->evaluated_value = right->mul(left, right);
          // cout<<root->val->get_frac_str()<<endl;
         // cout<<root->evaluated_value->get_frac_str()<<endl;
            return root->evaluated_value;
        }
        if (key == "DIV")
        {
           root->evaluated_value =left->div(left, right);
            return root->evaluated_value;
        }
       return temp;
    }
}
    Evaluator::Evaluator()
    {
        this->symtable=new SymbolTable();
        
    }

   Evaluator:: ~Evaluator()
    {
        symtable->~SymbolTable();
        for(auto i:expr_trees)
        {
            i->~ExprTreeNode();
        }
    }
    // Read an input vector of tokens (strings)
    // Parse it and convert it to a parse tree
    // Push the root of the tree in the expr_trees
    void Evaluator:: parse(vector<string> code)
    {
          //  cout<<evaluate(solve(code,symtable)->right,symtable)->get_frac_str()<<endl;
            expr_trees.push_back(solve(code,symtable));
    }
    // Evaluate the last element of the expr_trees
    // This function is guaranteed to be called immediately 
    // after a call to parse, and will be only called ONCE
    // for a tree
    // Also populate the symbol tables
    void Evaluator::eval()
    {
        ExprTreeNode*root=expr_trees.back();
        //cout<<root->right->left->val->get_frac_str()<<endl;
        root->left->evaluated_value=evaluate(root->right,symtable);
        root->left->val=root->left->evaluated_value;
        symtable->insert(root->left->id,root->left->val);
         return;
    }