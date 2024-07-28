#include<iostream>
#include<stdexcept>
#include"stack_b.h"
using namespace std;
/* PART B */
/* Dynamic Stacks */

Stack_B::Stack_B()
{
    this->capacity=1024;
    this->stk=new(std::nothrow)int[capacity];
    if(this->stk==nullptr)
    {
        throw std::runtime_error("Out of Memory");
    }
    this->size=-1;
}
    // Constructor
    // Destructor
   Stack_B:: ~Stack_B()
    {
        delete[]stk;
    }
    /*void grow()
    {
        int growthf=2;
        int newCapacity=capacity*growthf;
        int*newstk=new int[newCapacity];
        if(newstk==nullptr)
        {
            throw std::runtime_error("Out of Memory");
        }
        for(int i=0;i<size;i++)
        {
            newstk[i]=stk[i];
        }
        delete[]stk;
        stk=newstk;
        capacity=newCapacity;
        thsize=capacity/4;
    }*/
   /* void shrink()
    {                   //capacity cannot be less than 1024
         int newCapacity=capacity/2;
         if(newCapacity<1024)
         {
            newCapacity=1024;
         }
         int*newstk=new int[newCapacity];
         for(int i=0;i<size;i++)
         {
            newstk[i]=stk[i];
         }
         delete[]stk;
        stk=newstk;
        capacity=newCapacity;
        thsize=capacity/4;
    }*/
    void Stack_B:: push(int data)
    {
        if(size==capacity)
        {
        int thsize=capacity/4;
        int growthf=2;
        int newCapacity=capacity*growthf; 
        int *newstk = new (std::nothrow) int[newCapacity];
        if(newstk==nullptr)
        {
            throw std::runtime_error("Out of Memory");
        }
        for(int i=0;i<=size;i++)
        {
            newstk[i]=stk[i];
        }
        delete[] stk;
        stk=newstk;
        capacity=newCapacity;
        thsize=capacity/4;
            size++;
            //cout<<size<<endl;
            stk[size]=data;
        }
        else
        {
            size++;
            stk[size]=data;
        }
    }
    int Stack_B:: pop()
    {
        int thsize=capacity/4;
        if(size<0)
        {
            throw std::runtime_error("Empty Stack");
        }
        if(size<thsize)
        {
         int newCapacity=capacity/2;
         if(newCapacity<1024)
         {
            newCapacity=1024;
         }
         int*newstk=new int[newCapacity];
         for(int i=0;i<=size;i++)
         {
            newstk[i]=stk[i];
         }
        delete[] stk;
        stk=newstk;
        capacity=newCapacity;
        thsize=capacity/4;
        int top=stk[size];
            size--;
            return top;  
        }
        else
        {
            int top=stk[size];
            size--;
            return top;
        }
    }
    int Stack_B::get_element_from_top(int idx)
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
    int Stack_B:: get_element_from_bottom(int idx)
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
    void Stack_B::print_stack(bool top_or_bottom)
    {
        if(size<0)
        {
            throw std::runtime_error("Empty Stack");
        }
        int idx=-1;
        if(top_or_bottom==1)
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
   int Stack_B:: add()
    {
        if(size<1)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        //else if()
        else
        {
          int  p=pop();
          int  q=pop();
            push(p+q);
            return (p+q);
        }
    }

   int  Stack_B::subtract()
    {
        if(size<1)
        {
            throw runtime_error("Not Enough Arguments");
        }  
        //else if()
        else
        {
           int p=pop();
          int  q=pop();
            push(q-p);
            return q-p;
        }
    }

   int  Stack_B:: multiply()
    {
        if(size<1)
        {
            throw runtime_error("Not Enough Arguments");
        }
       // else if()
       else
       {
       int p=pop();
      int q= pop();
        push(q*p);
        return p*q;
       }
    }
   int  Stack_B:: divide()
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
    int*Stack_B:: get_stack()
    {
       return stk;
    } 
    int Stack_B::get_size()
    {
        return size+1;
    }
