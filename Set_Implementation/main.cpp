#include<iostream>
#include<vector>
using namespace std;
class SET
{
    public:
    vector<int>set;
    int set_n;
    SET()
    {
        this->set=set;
        this->set_n=set_n;
    }
    int size()
    {
        return set.size();
    }
    void insert(int data)
    {
        if(set.size()==0)
        {
            set.push_back(data);
            return;
        }
        int index=0;
        set.push_back(data);
       while(set[index]<data && index<set.size()-1)
       {
            index+=1;
       }
       while(set[index]>data && index<set.size()-1)
       {
            swap(set[index],set[set.size()-1]);
            index+=1;
       }
       if(index==set.size()-1)
       {
            return;
       }
    }
    int belongs_to(int data)
    {
        if(set.size()==0)
        {
            return 0;
        }
        for(size_t i =0 ;i<set.size();i++)
        {
            if(set[i]==data)
            {
                return 1;
            }
        }
        return 0;
    }
    void Delete(int data)
    {
        int idx=0;
        vector<int>vect;
        for(size_t i =0;i<set.size();i++)
        {
            if(set[i]!=data)
            {
                vect.push_back(set[i]);
            }
        }
        this->set=vect;
    }
    void Union(vector<int>set1)
    {
        int i=0;
        int j=0;
        vector<int>result;
        while(i<set.size() && j<set1.size())
        {
            if(set[i]<set1[j])
            {
                result.push_back(set[i]);
                i+=1;
            }
            else if(set[i]>set1[j])
            {
                result.push_back(set1[j]);
                j+=1;
            }
            else
            {
                result.push_back(set[i]);
                i+=1;
                j+=1;
            }
        }
        while (i<set.size())
        {
            result.push_back(set[i]);
            i+=1;
        }

        while(j<set1.size())
        {
            result.push_back(set1[j]);
            j+=1;
        }
        this->set=result;
        return;
    }
    void intersection(vector<int>set1)
    {
        if(set.size()==0)
        {
            return;
        }
        int j=0;
        SET*result=new SET();
        while(j<set1.size())
        {
            if(belongs_to(set1[j])==1)
            {
                result->insert(set1[j]);
                j+=1;
            }
            else
            {
                j+=1;
            }
        }
        this->set=result->set;
    }
    void difference(vector<int>set1)
    {
        if(set.size()==0)
        {
            return;
        }
        if(set1.size()==0)
        {
            return;
        }
        int j=0;
        SET*result=new SET();
        while(j<set1.size())
        {
        if(belongs_to(set1[j])==1)
        {
            Delete(set1[j]);
            j+=1;
        }
        else
        {
            j+=1;
        }
        }
        if(j==set1.size())
        {
            return;
        }
    }
    void symmetric_difference(vector<int>set1)
    {
        SET*result1=new SET();
        result1->set=set;
        Union(set1);
        result1->intersection(set1);
        difference(result1->set);
    }
    void print()
    {
        if(set.size()==1)
        {
            cout<<set[0];
            cout<<endl;
            return;
        }
        if(set.size()==0)
        {
            cout<<endl;
            return;
        }
        int j=0;
        for(size_t i=0;i<set.size()-1;i++)
        {
            cout<<set[i]<<",";
            j=i;
        }
        cout<<set[j+1];
        cout<<endl;
        return;
    }
};
    SET*get_set(bool &  flag,int b,vector<SET*>&sets)
    {
        SET*s=new SET();
        for(size_t i=0;i<sets.size();i++)
        {
            if(sets[i]->set_n==b)
            {
                flag=true;
                return sets[i];
            }
        }
        s->set_n=b;
        sets.push_back(s);
            return s;
    }
int main()
{
    int a,b,c;
    vector<SET*>sets;
    while(cin>>a>>b)
    {
        bool flag=false;
        SET*curr=new SET();
        SET*curr1=new SET();
        if(a==1) 
        {
            cin>>c;
            curr=get_set(flag,b,sets);
           curr->insert(c);
           cout<<curr->size()<<endl;
        }
        if(a==2)
        {
            cin>>c;
            curr=get_set(flag,b,sets);
            if(flag==false)
            {
                cout<<-1<<endl;
            }
            else
            {
                curr->Delete(c);
                cout<<curr->size()<<endl;
            }    
        }
        if(a==3)
        {
            cin>>c;
            curr=get_set(flag,b,sets);
            if(flag==false)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<curr->belongs_to(c)<<endl;
            }
        }
        if(a==4)
        {
            cin>>c;
            curr=get_set(flag,b,sets);
            curr1=get_set(flag,c,sets);
            curr->Union(curr1->set);
            cout<<curr->size()<<endl;
        }
        if(a==5)
        {
            cin>>c;
            curr=get_set(flag,b,sets);
            curr1=get_set(flag,c,sets);
            curr->intersection(curr1->set);
            cout<<curr->size()<<endl;
        }
        if(a==6)
        {
            curr=get_set(flag,b,sets);
            cout<<curr->size()<<endl;
        }
        if(a==7)
        {
            cin>>c;
            curr=get_set(flag,b,sets);
            curr1=get_set(flag,c,sets);
            curr->difference(curr1->set);
            cout<<curr->size()<<endl;
        }
        if(a==8)
        {
            cin>>c;
            curr=get_set(flag,b,sets);
            curr1=get_set(flag,c,sets);
            curr->symmetric_difference(curr1->set);
            cout<<curr->size()<<endl;
        }
        if(a==9)
        {
            get_set(flag,b,sets);
            if(!flag)
            {
                cout<<endl;
            }
            else
            {
                curr=get_set(flag,b,sets);
                curr->print();
            }
        }
    }
}
