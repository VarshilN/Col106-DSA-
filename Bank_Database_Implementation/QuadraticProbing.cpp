#include "QuadraticProbing.h"
#include<string>
#include<vector>
using namespace std;
QuadraticProbing::QuadraticProbing()
{
    this->size=199999;
   this->length=0;
   arr.resize(100000);
   bankStorage1d.resize(size);
   Account act;
   act.id="";
   act.balance=-1;
    //bankStorage1d=vector<Account>(size);
    for(int i=0;i<100000;i++)
    {
        arr[i]=act;
    }
    for(int j=0;j<size;j++)
    {
       bankStorage1d[j]=act;
    }
}
  void QuadraticProbing::sorted(vector<Account>&arr,int length)
{
    for(int i=1;i<length;i++)
    {
        Account key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j].balance<key.balance)
        {
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
    return ;
}
   int QuadraticProbing:: pov(int n, int p)
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
   int QuadraticProbing::ht(string id)
   {
    /*int p=31;
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
       /*     int fval=0;
        int idx=0;
        for(int i=0;i<id.length()-1;i+=2)
        {
            fval+=id[i]*id[i+1]*31;
            idx=i;
        }
        if(idx==id.length()-1)
        {
            fval+=id[idx]*31;
        }
    */
   return  fval%size;
   }
void QuadraticProbing::createAccount(std::string id, int count)
 {
    length++;
    Account act;
    act.id=id;
    act.balance=count;
    int val=hash(id);
    bankStorage1d[val]=act;
    arr[length-1]=act;
   // sorted(arr,length);
    return;
}
std::vector<int> QuadraticProbing::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
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
int QuadraticProbing::getBalance(std::string id) {
    if(!doesExist(id))
    {
        return -1;
    }
    int val=hash(id);
    return bankStorage1d[val].balance;
}
void QuadraticProbing::addTransaction(std::string id, int count) 
{
    if(!doesExist(id))
    {
        createAccount(id,count);
        return;
    }
    int val=hash(id);
    int pr=bankStorage1d[val].balance;
    pr+=count;
    if(pr<0)
    {
        pr=0;
    }
    else
    {
        bankStorage1d[val].balance=pr;
    }
    for(int i=0;i<length;i++)
    {
        if(arr[i].id==id)
        {
            arr[i].balance=pr;
        }
    }
   // sorted(arr,length);
    return;
}
bool QuadraticProbing::doesExist(std::string id)
 {
    int val=hash(id);
    if(bankStorage1d[val].id==id)
    {
        return true;
    }
    return false;
}
bool QuadraticProbing::deleteAccount(std::string id)
 {
      // IMPLEMENT YOUR CODE HERE
    if(!doesExist(id))
    {
        return false;
    }
    int val=hash(id);
    bankStorage1d[val].id="";
    bankStorage1d[val].balance=-1;
    int j=0;
    int pout=0;
    for(int i=0;i<length;i++)
    {
        if(arr[i].id==id)
        {
            swap(arr[i],arr[length-1]);
            break;
        }
    }
    length--;
    //sorted(arr,length);
    return true;
    // Placeholder return value
}
int QuadraticProbing::databaseSize() 
{
    // IMPLEMENT YOUR CODE HERE
    return length; // Placeholder return value
}
int QuadraticProbing::hash(std::string id) 
{
    int val=ht(id);
    /*if(bankStorage1d[val].id==id)
    {
        return val;
    }*/
    int idx=1;
    if(bankStorage1d[val].id=="")
    {
        return val;
    }
    int probe=val;
    while(bankStorage1d[probe].id!=id && bankStorage1d[probe].id!="")
    {
        probe=(val+idx*idx)%size;
        idx++;
    }
    val=probe;
    return val;
}

