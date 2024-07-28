#include<iostream>
#include"stack_a.h"
#include<stdexcept>
using namespace std;

/* PART A */
/* Stacks using Fixed Size Arrays */
using namespace std;
    // Constructor
   Stack_A::Stack_A()
    {
        this->size=-1;
       // this->ptr=stk;
    }
  void Stack_A::push(int data)
    {
        if(size==1024)
        {
           throw runtime_error("Stack Full");
        }
        else
        {
        size++;
        stk[size]=data;
        }
    }
   int Stack_A:: pop()
    {
        if(size<0)
        {
            throw std::runtime_error("Empty Stack");
        }
        //else if();
        else
        {
           int top=stk[size];
            size--;
            return top;
        }
    }
    int Stack_A:: get_element_from_top(int idx)
    {
        if(size-idx<0 || idx<0)
        {
            throw std::runtime_error("Index out of range");
        }
        else
        {
            return stk[size-idx];
        }
    }
  int  Stack_A:: get_element_from_bottom(int idx)
    {
        if(idx>size || idx<0)
        {
            throw std::runtime_error("Index out of range");
        }
        else
        {
            return stk[idx];
        }
    }

   void Stack_A:: print_stack(bool size_or_bottom)
    {
        if(size<0)
        {
            throw std::runtime_error("Empty Stack");
        }
        int idx=-1;
        if(size_or_bottom==1)
        {
            idx=size;
            while(idx>=0)
            {
               cout<<stk[idx]<<endl;
               idx--;
            }
        }
        else
        {
            idx=0;
            while(idx<=size)
            {
                cout<<stk[idx]<<endl;
                idx++;
            }
        }
    }
   int Stack_A:: add()
    {
        if(size<1)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        //else if()
        else
        {
           int p=pop();
           int q=pop();
            push(p+q);
            return (p+q);
        }
    }

   int  Stack_A::subtract()
    {
        if(size<1)
        {
            throw runtime_error("Not Enough Arguments");
        }  
        //else if()
        else
        {
           int p=pop();
           int q=pop();
            push(q-p);
            return (q-p);
        }
    }

   int  Stack_A:: multiply()
    {
        if(size<1)
        {
            throw runtime_error("Not Enough Arguments");
        }
       // else if()
       else
       {
      int  p=pop();
      int  q= pop();
        push(q*p);
        return (p*q);
       }
    }
   int  Stack_A:: divide()
    {
        if(size<1)
        {
            throw runtime_error("Not Enough Arguments");
        }
        if(stk[size]==0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        //else if
        else
        {
            int p=pop();
            int q=pop();
            int res=q/p;
            if(p*q<0 && q%p!=0)
            {
                res=res-1;
            }
            push(res);
            return res;
        }
    }
   int* Stack_A:: get_stack()
    {
       return &stk[0];
    } 

   int Stack_A::get_size()
    {
        return size+1;
    }
/*int main()
{
    Stack_A*s1=new Stack_A();
    //s1->pop();
}*/