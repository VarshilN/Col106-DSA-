
#include "parser.h"

bool isOp(string s)
{
    if(s=="+"||s=="-"||s=="*"||s=="/"||s=="%")
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool check(string s)
{
    if(isOp(s) || s=="(" || s==")")
    {
        return false;
    }
    for(int i=0;i<s.length();i++)
    {
        if(i==0 && (s[i]=='-'||s[i]=='+'))
        {
            continue;
        }
        if(std::isdigit(s[i])==false)
        {
            return false;
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
            
             if(isOp(code[idx]))
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
                    element->id=top;
                    //element->evaluated_value=element->val=new UnlimitedRational();              
                    vals.pop_back();
                    vals.push_back(element);
                }
                ops.pop_back();
            }
            else if(code[idx]==" ")
            {
                continue;
            }
            else
            {
                ExprTreeNode*element=new ExprTreeNode();
                if(check(code[idx]))
                {
                    element->num=std::stoi(code[idx]);
                    element->type="VAL";
                    element->id=code[idx];
                }
                else
                {
                    element->type="VAR";
                    element->id=code[idx];
                    element->num=symtable->search(code[idx]);
                }
                vals.push_back(element);
            }
            idx++;
       }
       ExprTreeNode*root=new ExprTreeNode();
       root->right=vals.back();
       root->id=code[1];
       root->type="ASS";
       if(code[0]=="ret")
       {
            root->left=new ExprTreeNode();
            root->left->type="RET";
            root->left->id=code[0];
            root->left->num=0;
       }
       else
       {
            root->left=new ExprTreeNode();
            root->left->type="VAR";
            root->left->id=code[0];
       }
       return root;
    }
Parser::Parser()
{
    this->symtable=new SymbolTable();
}
void Parser::parse(vector<string> expression)
{
    if(expression[0]=="del")
    {
    ExprTreeNode*root=new ExprTreeNode();
       root->id=expression[1];
       root->type="ASS"; 
       root->num=0;
    root->left=new ExprTreeNode();
       root->left->id=expression[0];
       root->left->type="DEL";
       root->left->num=0;
    root->right=new ExprTreeNode();
      //  cout<<expression[2]<<endl;
         root->right->id=expression[2];
         root->right->type="VAR";
        symtable->remove(expression[2]);
       expr_trees.push_back(root);
    return;
    }
    else if(expression[0]=="ret")
    {
        expr_trees.push_back(solve(expression,symtable));
    }
    else 
    {
  
        ExprTreeNode*root=solve(expression,symtable);
        expr_trees.push_back(root);
        symtable->insert(root->left->id);
       // int num=evaluate(root->right,symtable);
      //  root->left->num=num;
       // expr_trees.push_back(root);
       // symtable->assign_address(expression[0],num);
    }
    return;
}
/*void preorder(ExprTreeNode*root)
{
    if(root==nullptr)
    {
        return;
    }
   cout<<root->type<<" "<<root->id<<" "<<root->num<<endl;
   preorder(root->left);
    preorder(root->right);
}*/
Parser::~Parser()
{
    for(auto i:expr_trees)
    {
        i->~ExprTreeNode();
    }
    symtable->~SymbolTable();
}
/*int main()
{
    Parser p;
    p.parse({"x",":=","3"});
    p.parse({"del",":=", "z"});
  //  p.parse({"ret",":=","(","w","+","7",")"});
 //  p.parse({"a", ":=", "(", "2", "x", "(", "v", "-", "4", ")", ")"});     
   ExprTreeNode*root=p.expr_trees.back();
   
    preorder(root);
 //  cout<<root->left->num<<endl;ss
}*/