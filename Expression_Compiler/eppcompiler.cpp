//#include<iostream>
#include "eppcompiler.h"
//using namespace std;
/*void print(vector<string>ans)
{
    for(int it=ans.size()-1;it>=0;it--)
    {
        cout<<ans[it]<<endl;
    }
}*/
//Write your code below this line
 /*  void preorder(ExprTreeNode*element)
    {
       if(element==nullptr)
       {
        return;
       }
       cout<<element->type<<endl;
       preorder(element->left);
       preorder(element->right);
    }*/
/*int finder(vector<ExprTreeNode*>res,string key)
{
    for(int i=0;i<res.size();i++)
    {
        if(res[i]->left->id==key)
        {
            return i;
        }
    }
    return -1;
}*/
EPPCompiler::EPPCompiler()
{
    this->memory_size=0;
    this->output_file="a";
}
EPPCompiler::EPPCompiler(string out_file,int mem_limit)
{
    this->output_file=out_file;
    this->memory_size=mem_limit;
}
void EPPCompiler::compile(vector<vector<string>> code)
{
   // ofstream outputFile(output_file);
    //x y z  w no of variables=3
    //mem idx= 0 1 2 3
    //del z //free space at idx=2
    // next element to be inserted at idx=2;
    ofstream outputFile(output_file);
    int index=0;
    index++;
    least_mem_loc.push_heap(0);
  for(int i=0;i<code.size();i++)
  {
       // targ.parse(code[i]);
        //least_mem_loc.push_heap(0);
        if(code[i][0]=="del")
        {
           least_mem_loc.pop();
          // cout<<targ.symtable->search(code[i][2])<<endl;
           
           int mem_index=targ.symtable->search(code[i][2]);
         //  cout<<mem_index<<endl;
        string s="DEL = mem["+std::to_string(mem_index)+"]";
       //     cout<<s<<endl;
            outputFile<<s<<endl;
        //    cout<<mem_index<<endl;     
         //  cout<<code[i][2]<<endl;
           targ.parse(code[i]);
           targ.symtable->remove(code[i][2]);   
          //  cout<<"**"<<endl;
           least_mem_loc.push_heap(mem_index);
           index--;
        // cout<<targ.symtable->search(code[i][0]); okiie;)
        }
        else if(code[i][0]!="del"&&code[i][0]!="ret")
        {
             if(targ.symtable->search(code[i][0])!=-2)
                 {
                    int mem_index=targ.symtable->search(code[i][0]);
                    targ.parse(code[i]);
                   targ.symtable->assign_address(code[i][0],mem_index);
                  }
            else
            {
                targ.parse(code[i]);
             
               int mem_index=least_mem_loc.get_min();
               
                targ.symtable->assign_address(code[i][0],mem_index);
                least_mem_loc.pop();
                index++;
                least_mem_loc.push_heap(index-1);
               
            }
              vector<string>ans=generate_targ_commands();
              for(int it=ans.size()-1;it>=0;it--)
            {
                 outputFile<<ans[it]<<endl;
            }
           // print(ans);
        }
           else
           {
               
             targ.parse(code[i]);
                vector<string>ans=generate_targ_commands();
               for(int it=ans.size()-1;it>=0;it--)
                {
                outputFile<<ans[it]<<endl;
                }
            //    print(ans);
                //memory_size++;
           } 
       /* if(!outputFile.is_open())
        {
            cout<<"error"<<endl;
        }
         for(int i=ans.size()-1;i>=0;i--)
         {
            outputFile<<ans[i]<<endl;
         }*/
    }
    outputFile.close();
}
vector<string>EPPCompiler::generate_targ_commands()
{ 
   
    vector<string>ans;
    vector<ExprTreeNode*>stk;
    ExprTreeNode*back=targ.expr_trees.back();
  
    if(back->left->type=="VAR")
    {
        int num=targ.symtable->search(back->left->id);
      //  cout<<num<<endl;
        string s="mem["+std::to_string(num)+"] = POP";
        ans.push_back(s);
    }
    if(back->left->type=="RET")
    {
        string s="RET = POP";
        ans.push_back(s);   
    }
    back=back->right;
   stk.push_back(back);
   while(!stk.empty() )
   {
           ExprTreeNode*root=stk.back();
           stk.pop_back();
            if(root->type=="VAR")
            {
 
               int d=targ.symtable->search(root->id);
     
                string s="PUSH mem["+std::to_string(d)+"]";
                ans.push_back(s);
            }
            if(root->type=="VAL")
            {
     
                string s= "PUSH "+ root->id;
                ans.push_back(s);        
            }
            if(root->type=="ADD" || root->type=="SUB"||root->type=="MUL"||root->type=="DIV"||root->type=="MOD")
            {
                string s=root->type;
                ans.push_back(s);
            }
        if(root->right)
        {

            stk.push_back(root->right);
        }
        if(root->left)
        {
            stk.push_back(root->left);
        }
   }
    return ans;
}
void EPPCompiler::write_to_file(vector<string> commands)
{
   // cout<<"hi"<<endl;
    return;
}
EPPCompiler::~EPPCompiler()
{
  targ.~Parser();
  least_mem_loc.~MinHeap();
}
/*int main()
{
    EPPCompiler epp;
    epp.compile({{"a",":=","(","(","2","*","4",")","+","10",")"},
        {"b",":=","(","3","*","4",")"},
         {"ret",":=","(","a","+","b",")"}});   
} */
/*x := 3
y := 5
z := 7
del := x
del := y
w := (5+(z/2))
ret := w */