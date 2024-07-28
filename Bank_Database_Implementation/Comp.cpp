#include "Comp.h"
#include<string>
#include<vector>
using namespace std;
Comp::Comp()
{
    this->size=199999;
   this->length=0;
   arr.resize(100000);
   vect.resize(size);
    //vect=vector<Account>(size);
    Account act;
    act.id="";
    act.balance=-1;
    for(int i=0;i<100000;i++)
    {
        arr[i]=act;
    }
    for(int j=0;j<size;j++)
    {
       vect[j]=act;
    }
}
void Comp::sorted(vector<Account>&arr,int length)
{
    for(int i=1;i<length;i++)
    {
        Account key=arr[i];
        int j=i-1;
        while(j>=0&& arr[j].balance<key.balance)
        {
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
    return ;
}
   int Comp:: pov(int n,int p)
   {
        if(p==0)
        {
            return 1;
        }
        if(n%2==0)
        {
            return pov(n*n,p/2);
        }
        else
        {
            return n*pov(n*n,(p-1)/2);
        }
   }
   int Comp::ht(std::string id)
   {
    /*int p=31;
    //long long fval=0;
    unsigned long fval=0;
    for(int i=0;i<id.length();i++)
    {
        fval=id[i]+fval*p;
    }
    return fval%size;*/
    unsigned long fval=0;
    for(int i=0;i<id.length();i++)
    {
        fval+=id[i]*pov(i,7);
    }
       /* int fval=0;
        int idx=0;
        for(int i=0;i<id.length()-1;i+=2)
        {
            fval+=id[i]*id[i+1]*31;
            idx=i;
        }
        if(idx==id.length()-1)
        {
            fval+=id[idx]*31;
        }*/
      //  return h%size;
      return fval%size;
   }
   int Comp:: helper(std::string id)
   {
        unsigned long fval=0;
        int idx=0;
        for(int i=0;i<id.length()-1;i+=2)
        {
            fval+=id[i]*id[i+1]*23;
            idx=i;
        }
        if(idx==id.length()-1)
        {
            fval+=id[idx]*23;
        }

        return fval%size1;
   }
void Comp::createAccount(std::string id, int count)
 {
    length++;
    Account act;
    act.id=id;
    act.balance=count;
    int val=hash(id);
    vect[val]=act;
    arr[length-1]=act;
   // sorted(arr,length);
    return;
}
std::vector<int> Comp::getTopK(int k) {
    sorted(arr,length);
    vector<int>ans;
    int i=0;
    while(i<k && i<length)
    {
        ans.push_back(arr[i].balance);
        i+=1;
    }
    return ans;
}
int Comp::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    if(!doesExist(id))
    {
        return -1;
    }
    int val= hash(id);
    return vect[val].balance; // Placeholder return value
}
void Comp::addTransaction(std::string id, int count) 
{
    if(!doesExist(id))
    {
        createAccount(id,count);
        return;
    }
    int val=hash(id);
    int pr=vect[val].balance;
    pr+=count;
    if(pr<0)
    {
        pr=0;
    }
    else
    {
        vect[val].balance=pr;
    }
    for(int i=0;i<length;i++)
    {
        if(arr[i].id==id)
        {
            arr[i].balance=pr;
        }
    }
    //sorted(arr,length);
    return;
}
bool Comp::doesExist(std::string id)
 {
    // IMPLEMENT YOUR CODE HERE
    int val=hash(id);
    if(vect[val].id==id)
    {
        return true;
    }
    return false; // Placeholder return value
}
bool Comp::deleteAccount(std::string id)
 {
    if(!doesExist(id))
    {
        return false;
    }
    int val=hash(id);
    vect[val].id="";
    vect[val].balance=-1;
    int j=0;
    //int pout=0;
    for(int i=0;i<length;i++)
    
        if(arr[i].id==id)
        {
            swap(arr[i],arr[length-1]);
            break;
        }
    length--;
    //sorted(arr,length);
    return true;
    // Placeholder return value
 }
int Comp::databaseSize() 
{
    // IMPLEMENT YOUR CODE HERE
    return length; // Placeholder return value
}
int Comp::hash(std::string id) 
{
    int val=ht(id);
    /*if(vect[val].id==id)
    {
        return val;
    }*/
    if(vect[val].id=="")
    {
        return val;
    }
    int probe=val;
    while(vect[probe].id!=id  && vect[probe].id!="")
    {
        probe=(val+helper(vect[probe].id))%size;
    }
    val=probe;
    return val;
}
// Feel free to add any other helper functions you need
// Good Luck!