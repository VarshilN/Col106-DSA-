
#include"node.h"
#include"list.h"
#include"stack_c.h"
#include<stdexcept>
#include<iostream>
using namespace std;
   Stack_C:: Stack_C()
    {
        //this->stk=nullptr;
        try{
        this->stk=new List();
        }
        catch(bad_alloc&c)
        {
            throw("Out of Memory");
        }
    }
    // Destructor
   Stack_C:: ~Stack_C()
    {
        delete stk;
    }

    void Stack_C:: push(int data)
    {
        
        //out of memory condintion
        stk->insert(data);
    }
    int Stack_C:: pop()
    {
        if(get_size()==0)
        {
            throw std::runtime_error("Empty Stack");
        }
        return stk->delete_tail();
    }
    int Stack_C:: get_element_from_top(int idx)
    {
        int len=get_size();
        if(idx>=len || idx < 0)
        {
            throw std::runtime_error("Index out of range");
        }
        // Node*temp=stk->get_head();
        // temp=temp->next; // first element
        // int cnt=0;
        // while(cnt<len)
        // {
        //     if(cnt==len-idx-1)
        //     {
        //         return temp->get_value();
        //     }
        //     temp=temp->next;
        //     cnt++;
        // }
        Node* temp = stk -> get_head();
        temp=temp->next;//first element
        int cnt = 0;
        while(cnt < len - idx - 1){
            temp = temp -> next;
            cnt++;
        }
        return temp-> get_value();
    }
    int Stack_C:: get_element_from_bottom(int idx)
    {
        int len=get_size();
        if(idx>=len || idx<0)
        {
            throw std::runtime_error("Index out of range");
        }
        Node*temp=stk->get_head();
        temp=temp->next;
        int cnt=0;
        while(cnt<idx)
        {
            temp=temp->next;
            cnt++;
        }
        return temp -> get_value();

    }
    void Stack_C:: print_stack(bool top_or_bottom)
    {
        int len=stk -> get_size();
        Node*temp=stk->get_head();
        temp=temp->next ;
        if(top_or_bottom==1)
        {
            while(temp -> next != nullptr)
            {
                temp=temp->next;
            }
            temp=temp->prev;
            while(temp != stk -> get_head())
            {
                cout<<temp->get_value()<<endl;
                temp=temp->prev;
            }
            return;
        }
        else
        {
            while(temp -> next != nullptr)
            {
                cout<<temp->get_value()<<endl;
                temp=temp->next;
            }
            return;
        }
    }

    int Stack_C:: add()
    {
        if(stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
            int a,b;
            a=pop();
            b=pop();
            push(a+b);
            return (a+b);
        }
    }
    int Stack_C::subtract()
    {
        if(stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
            int p=pop();
            int q=pop();
            int res=q-p;
            push(q-p);
            return q-p;
        }
    }

    int Stack_C::multiply()
    {
         if(stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
            int p=pop();
            int q=pop();
            int res=p*q;
            push(p*q);
            return res;
        } 
    }
    int Stack_C:: divide()
    {
         if(stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        int p=pop();
        if(p==0)
        {
            throw std::runtime_error("Divide by Zero Error");
        }
        int q=pop();
        int res=q/p;
        if(p*q<0 && q%p!=0)
        {
            res=res-1;
        }
        push(res);
        return res;
    }

    List*Stack_C:: get_stack()
    {
        return stk;
    }
    // Get a pointer to the linked list representing the stack

    int Stack_C:: get_size()
    {
        return stk->get_size();
    } // Get the size of the stack

// int main(){
//        Stack_C s;
//     s.push(2);
//     s.push(10);
//     s.push(-6);
//     s.push(4);
//     s.push(-15);
//     s.push(4);
//     s.push(5);
//     s.push(11);
//     s.push(-9);
//     s.push(-7);
//     cout<<s.add()<<endl;
//     cout<<s.add()<<endl;
//     cout<<s.add()<<endl;
//     cout<<s.subtract()<<endl;
//     cout<<s.subtract()<<endl;
//     cout<<s.divide()<<endl;
//     cout<<s.divide()<<endl;
//     cout<<s.multiply()<<endl;
//     cout<<s.multiply()<<endl;
// }
