#include<iostream>
#include "Chaining.h"
#include <vector>
#include<string>
using namespace std;
Chaining::Chaining()
{
    this->size=0;
    this->tsize=199999;
    Account act;
    act.id="#";
    act.balance=-1;
    bankStorage2d.resize(tsize);
    arr.resize(100000);
    for(int i=0;i<100000;i++)
    {
        arr[i]=act;
    }
    for(int j=0;j<tsize;j++)
    {
        bankStorage2d[j].push_back(act);
    }
}
void Chaining::sorted(vector<Account>&arr,int size)
{
    for(int i=1;i<size;i++)
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
void Chaining::createAccount(std::string id, int count) 
{
    size++;
    Account act;
    act.id=id;
    act.balance=count;
    int val=hash(id);
    if(bankStorage2d[val][0].id=="#"||bankStorage2d[val][0].balance==-1)
    {
        bankStorage2d[val][0]=act;
    }
    else
    {
        bankStorage2d[val].push_back(act);
    }
    arr[size-1]=act;
   // sorted(arr,size);
    return;
}
/*int Chaining::pov(int n, int p)
{
    if(p==0)
    {
        return 1;
    }
    if(p%2==0)
    {
        return pov(n*n,p/2);
    }
   return n*pov(n*n,(p-1)/2);
}*/
int Chaining::ht(std::string id)
{
       unsigned long fval=0;
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
        return fval%tsize; 
}
std::vector<int> Chaining::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
    sorted(arr,size);
    vector<int>ans;
    if(k==0)
    {
        return ans;
    }
    int i=0;
    while(i<k && i<size)
    {
        ans.push_back(arr[i].balance);
        i+=1;
    }
     // Placeholder return value
     return ans;
}
int Chaining::getBalance(std::string id) {
   if(!doesExist(id) || id=="#")
   {
        return -1;
   }
   int val=hash(id);
   for(int i=0;i<bankStorage2d[val].size();i++)
   {
        if(bankStorage2d[val][i].id==id)
        {
            return bankStorage2d[val][i].balance;
        }
   }
   return -1;
}
void Chaining::addTransaction(std::string id, int count)
 {
    if(!doesExist(id))
    {
        createAccount(id,count);
        return;
    }
    else
    {
        int temp=0;
        int val=hash(id);
        for(int i=0;i<bankStorage2d[val].size();i++)
        {
            if(bankStorage2d[val][i].id==id)
            {
                temp=bankStorage2d[val][i].balance+count;
                if(temp<0)
                {
                    temp=0;
                }
                bankStorage2d[val][i].balance=temp;
                break;
            }
        }
        int idx=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i].id==id)
            {
                arr[i].balance=temp;
                idx=i;
                break;
            }
        }
     //   sorted(arr,size);
        return;
    }
}
bool Chaining::doesExist(std::string id)
 {
    // IMPLEMENT YOUR CODE HERE
    for(int i=0;i<size;i++)
    {
        if(arr[i].id==id)
        {
            return true;
        }
    }
    return false;
}
bool Chaining::deleteAccount(std::string id) {
    if(!doesExist(id))
    {
        return false;
    }
    else
    {
        int val=hash(id);
        int len=bankStorage2d[val].size();
        int idx=0;
        for(int i=0;i<len;i++)
        {
            if(bankStorage2d[val][i].id==id)
            {
                idx=i;
                break;
            }
        }
       swap(bankStorage2d[val][idx],bankStorage2d[val][len-1]);
       bankStorage2d[val].pop_back();
       for(int i=0;i<size;i++)
       {
        if(arr[i].id==id)
        {
            swap(arr[i],arr[size-1]);
            break;
        }
       }
       size--;
     //  sorted(arr,size);
       return true;
    }
}
int Chaining::databaseSize() {
    return size;
}

int Chaining::hash(std::string id) 
{
    int val=ht(id);
    return val;
}

