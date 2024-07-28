/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream>
#include "ulimitedint.h"
    UnlimitedInt::UnlimitedInt()
    {
        this->size=1;
        this->capacity=1;
        this->unlimited_int=new int[capacity];
        unlimited_int[0]=0;
        this->sign=1;
    }
    UnlimitedInt::UnlimitedInt(string s)
    {
        //flag=1;
        if(s[0]=='-')
        {
            this->sign=-1;
            this->size=s.length()-1;
            this->capacity=size;
            this->unlimited_int=new int[capacity];
            for(int i=1;i<s.length();i++)
            {
                unlimited_int[i-1]=s[i]-'0';
            }
            if(s[1]==0)
            {
                this->size=1;
                this->capacity=size;
                this->unlimited_int=new int[capacity];
                unlimited_int[0]=0;
               return;
            }
        }
        else
        {
            this->sign=1;
            this->size=s.length();
            this->capacity=size;
            this->unlimited_int=new int[capacity];
            for(int i=0;i<s.length();i++)
            {
                unlimited_int[i]=s[i]-'0';
            }
        }
    } 
    UnlimitedInt::UnlimitedInt(int i)
    { 
        size=0;
        int temp=0;
        if(i==0)
        {
            this->sign=1;
            this->unlimited_int=new int[1];
            unlimited_int[0]=0;
        }
       else if(i<0)
        {
            this->sign=-1;
            temp=-i;
            while(temp>0)
            {
                temp=temp/10;
                size++;
            }
            this->capacity=size;
            this->unlimited_int=new int[capacity];
            temp=-i;
            int k=0;
            while(temp>0)
            {
                unlimited_int[size-k-1]=temp%10;
                k+=1;
                temp=temp/10;
            }
        }
        else
        {
                this->sign=1;
            temp=i;
            while(temp>0)
            {
                temp=temp/10;
                size++;
            }
            this->capacity=size;
            this->unlimited_int=new int[capacity];
            temp=i;
            int k=0;
            while(temp>0)
            {
                unlimited_int[size-k-1]=temp%10;
                k+=1;
                temp=temp/10;
            }
        }
    } // Create from int
    UnlimitedInt::UnlimitedInt(int*unlimited_int,int  cap,int sgn,int sz)
    {
        this->unlimited_int=unlimited_int;
        this->capacity=sz;
        this->size=sz;
        this->sign=sgn;
    }
    UnlimitedInt::~UnlimitedInt()
    {
        delete[]unlimited_int;
    }
    // Return the size of the unlimited int
    int UnlimitedInt::get_size()
    {
        return size;
    }
    // Return the unlimited_int array
    int*UnlimitedInt:: get_array()
    {
        return unlimited_int;
    }
    int UnlimitedInt::get_capacity()
    {
        return size;
    }
    // Get sign
    int UnlimitedInt:: get_sign()
    {
        return sign;
    }
    // Implement these integer operations as they are defined for integers in mathematics
    // (Since there are no size restrictions)
   /*UnlimitedInt*UnlimitedInt::solve(UnlimitedInt*i1,UnlimitedInt*i2)
    {
        int sign=1;
      //  string num="";
        int s1=i1->get_sign();
        int s2=i2->get_sign();
        int size1=i1->get_size();
        int size2=i2->get_size();
        int*p1=i1->get_array();
        int*p2=i2->get_array();
        int tsize=max(size1,size2)+1;
        int*result=new int[tsize];
        result[0]=0;
    if(s1*s2>0)
    {
 
       // int*result=new int[tsize]
        if(s1>0 || s2>0)
        {
            sign=1;
        }
        else
        {
            sign=-1;
        }
         int carry=0;
        int idx=0;
        for(int i=0;i<tsize;i++)
        {
            int d1=0;
            int d2=0;
            if(i<size1)
            {
                d1=p1[size1-i-1];
            }
            if(i<size2)
            {
                d2=p2[size2-1-i];
            }
            int sum=d1+d2+carry;
            int temp=sum%10;
            result[tsize-1-i]=temp;
            carry=sum/10;
        }
       while(result[idx]==0 && idx<tsize)
       {
            idx++;
       }
       if(idx!=tsize)
       {
            int*n=new int[tsize-idx];
            for(int i=idx;i<tsize;i++)
            {
                n[i-idx]=result[i];
            }
            result=n;
          //  delete[]result;
            return new UnlimitedInt(result,tsize-idx,sign,tsize-idx);
       }
      return new UnlimitedInt(result,tsize,sign,tsize);
        /*else
        {
            int*temp=new int[tsize-1];
            for(int i=1;i<tsize;i++)
            {
                temp[i-1]=result[i];
            }
            result=temp;
            delete temp;
            tsize--;
        }
      if(sign==-1)
      {
        num+='-';
      }
      for(int i=0;i<tsize;i++)
      {
        num+=result[i];
      }
    }
    else
    {
        int idx=0;
       // int csize1,csize2;
        int*num1=nullptr;
        int*num2=nullptr;
      tsize=max(size1,size2);
      if(tsize==size1 && tsize!=size2)
      {
        if(s1==-1)
        {
            sign=-1;
        }
        num1=p1;
        num2=p2;
      }
      else if(tsize==size2 && tsize!=size1)
      {
        if(s2==-1)
        {
            sign=-1;
        }
        num1=p2;
        num2=p1;
      }
      else
      {
          bool flag=0;
        int idx=0;
        while(idx<tsize)
        {
            if(p1[idx]>p2[idx])
            {
                if(s1==-1)
                {
                    sign=1;
                }
                num1=p1;
                num2=p2;
                flag=1;
                break;
            }
            else if(p1[idx]<p2[idx])
            {
                if(s2==-1)
                {
                    sign=-1;
                }
                num2=p1;
                num1=p2;
                flag=1;
                break;
            }
            else
            {
                idx++;
            }
      }
            if(flag==0)
            {
                return new UnlimitedInt("0");
            }
      }
    int msize=min(size1,size2);
      int borrow=0; 
      for(int i=0;i<tsize;i++)
      {
        int d1=num1[tsize-i-1];
        int d2=0;
        if(i<msize)
        {
            d2=num2[msize-1-i];
        }
        int dif=d1-d2-borrow;
        if(dif<0)
        {
            dif+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        result[tsize-i-1]=dif;
      }
        idx=0;
        while(result[idx]==0&& idx<tsize)
        {
            idx++;
        }
        if(idx!=tsize)
        {
            int*n=new int[tsize-idx];
            for(int i=idx;i<tsize;i++)
            {
                n[i-idx]=result[i];
            }
          //  delete[]result;
            result=n;
            return new UnlimitedInt(result,tsize-idx,sign,tsize-idx);         
        }
        return new UnlimitedInt(result,tsize,sign,tsize);
    }
    }*/
     UnlimitedInt*UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2)
    {
        int sign=1;
        string num="";
        int s1=i1->get_sign();
        int s2=i2->get_sign();
        int size1=i1->get_size();
        int size2=i2->get_size();
        int*p1=i1->get_array();
        int*p2=i2->get_array();
        int tsize=0;
    if(s1*s2>0)
    {
        tsize=max(size1,size2);
       // int*result=new int[tsize];
        int carry=0;
        if(s1>0 || s2>0)
        {
            sign=1;
        }
        else
        {
            sign=-1;
        }
        for(int i=0;i<tsize;i++)
        {
            int d1=0;
            int d2=0;
            if(i<size1)
            {
                d1=p1[size1-i-1];
            }
            if(i<size2)
            {
                d2=p2[size2-i-1];
            }
            int sum=d1+d2+carry;
            int temp=sum%10;
            char ch=temp+'0';
            num=ch+num;
            carry=sum/10;
        }
        if(carry!=0)
        {
            char ch=carry+'0';
            num=ch+num;
        }
        if(sign==-1)
        {
            num='-'+num;
        }
        /*else
        {
            int*temp=new int[tsize-1];
            for(int i=1;i<tsize;i++)
            {
                temp[i-1]=result[i];
            }
            result=temp;
            delete temp;
            tsize--;
        }
      if(sign==-1)
      {
        num+='-';
      }
      for(int i=0;i<tsize;i++)
      {
        num+=result[i];
      }*/
    }
    else
    {
       // int csize1,csize2;
        int*num1;
        int*num2;
      tsize=max(size1,size2);
      if(tsize==size1 && tsize!=size2)
      {
        if(s1==-1)
        {
            sign=-1;
        }
        num1=p1;
        num2=p2;
      }
      else if(tsize==size2 && tsize!=size1)
      {
        if(s2==-1)
        {
            sign=-1;
        }
        num1=p2;
        num2=p1;
      }
      else
      {
          bool flag=0;
        int idx=0;
        while(idx<tsize)
        {
            if(p1[idx]>p2[idx])
            {
                if(s1==-1)
                {
                    sign=-1;
                }
                num1=p1;
                num2=p2;
                flag=1;
                break;
            }
            else if(p1[idx]<p2[idx])
            {
                if(s2==-1)
                {
                    sign=-1;
                }
                num2=p1;
                num1=p2;
                flag=1;
                break;
            }
            else
            {
                idx++;
            }
      }
            if(flag==0)
            {
                return new UnlimitedInt("0");
            }
      }
      
    int msize=min(size1,size2);
      int*result=new int[tsize];
      int borrow=0; 
      for(int i=0;i<tsize;i++)
      {
        int d1=num1[tsize-i-1];
        int d2=0;
        if(i<msize)
        {
            d2=num2[msize-1-i];
        }
        int dif=d1-d2-borrow;
        if(dif<0)
        {
            dif+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        char ch=dif+'0';
        num=ch+num;
      }
      /*if(result[0]==0)
      {
        int k=0;
        while(result[k]==0 && k<tsize-1)
        {
            k+=1;
        }
        int len=tsize-k;
        int*temp=new int[len];
        for(int r=k;r<tsize;r++)
        {
            temp[r-k]=result[r];
        }
        tsize=len;
        result=temp;
        delete result;
      }*/
      //int idx=0;
      //num.substr(idx,num.length()-idx);
     /* for(int i=0;i<tsize;i++)
      {
        num+=(result[i]+'0');
      }*/
    }
    //cout<<num<<endl;
    int idx=0;
    while(num[idx]=='0' && idx<num.length())
    {
        idx++;
    }
    num=num.substr(idx);
      if(sign==-1 && num[0]!='-')
      {
          num='-'+num;
      }
    UnlimitedInt*curr=new UnlimitedInt(num);
    return curr;
    }
     UnlimitedInt*UnlimitedInt:: sub(UnlimitedInt* i1, UnlimitedInt* i2)
{
    int s2=i2->get_sign();
    string s=i2->to_string();
    if(s2==-1)
    {
        s=s.substr(1,s.length()-1);
    }
    else
    {
        s='-'+s;
    }
    UnlimitedInt*pi2=new UnlimitedInt(s);
    return add(i1,pi2);
}
    UnlimitedInt*UnlimitedInt:: mul(UnlimitedInt* i1, UnlimitedInt* i2)
    {
       // cout<<"hi1"<<endl;
        string res="";
        UnlimitedInt*result=new UnlimitedInt();
        int s1=i1->get_sign();
        int carry=0;
        int s2=i2->get_sign();
        int*p1=i1->get_array();
        int*p2=i2->get_array();
        int size1=i1->get_size();
        int size2=i2->get_size();
        //int tsize=size1+size2;
        if(i1->to_string() =="0" || i2->to_string()=="0")
        {
            return new UnlimitedInt("0");
        }
       for(int i=0;i<size2;i++)
       {
           string pre="";
           carry=0;
           for(int j=0;j<size1;j++)
           {
               int temp=p2[size2-1-i]*p1[size1-1-j]+carry;
               char ch=temp%10+'0';
              pre=ch+pre;
              carry=temp/10;
           }
           if(carry!=0)
           {
            char ch=carry+'0';
            pre=ch+pre;
           }
         for(int k=0;k<i;k++)
         {
             char ch='0';
             pre+=ch;
         }
        UnlimitedInt*p=new UnlimitedInt(pre);
        UnlimitedInt*temp=new UnlimitedInt(res);
        res=p->add(p,temp)->to_string();
        p->~UnlimitedInt();
        temp->~UnlimitedInt();
       }
 
       if(s1*s2<0)
       {
           res='-'+res;
       }
       result=new UnlimitedInt(res);
       return result;
    }
/* UnlimitedInt*div1(UnlimitedInt* i1, UnlimitedInt* i2)
    {
        cout<<"hi2"<<endl;
        bool flag=0;
        string r1=i1->to_string();
        string r2=i2->to_string();
        int s1=i1->get_sign();
        int s2=i2->get_sign();
        if(r1[0]=='-')
        {
            r1=r1.substr(1,r1.length()-1);
        }
        if(r2[0]=='-')
        {
            r2=r2.substr(1,r2.length()-1);
        }
        UnlimitedInt*t1=new UnlimitedInt(r1);
        UnlimitedInt*t2=new UnlimitedInt(r2);
        UnlimitedInt*count=new UnlimitedInt("0");
        UnlimitedInt*t=new UnlimitedInt("1");
        UnlimitedInt*t0=new UnlimitedInt("-1");
        while(1)
        {
            t1=t1->sub(t1,t2);
            if(t1->to_string()[0]=='0')
            {
                flag=1;
                count=count->add(count,t);
                break;
            }
            if(t1->to_string()[0]=='-')
            {
                break;
            }
            count=count->add(count,t);
        }
       if(s1*s2>0)
       {
            t1->~UnlimitedInt();
            t2->~UnlimitedInt();
            t->~UnlimitedInt();
            t0->~UnlimitedInt();
            return count;
       }
       else
       {
            string s='-'+count->to_string();
            count=new UnlimitedInt(s);
           if(!flag) 
           {

                count=count->add(count,t0);
           }
            t1->~UnlimitedInt();
            t2->~UnlimitedInt();
            t->~UnlimitedInt();
            t0->~UnlimitedInt();
           return count;
       }
    }*/
   /* UnlimitedInt*mod1(UnlimitedInt*i1,UnlimitedInt*i2)
    {

        string res="";
        int s1=i1->get_sign();
        int s2=i2->get_sign();
         int size1=i1->get_size();
         int size2=i2->get_size();
         UnlimitedInt*temp1=new UnlimitedInt(i1->to_string());
         UnlimitedInt*temp2=new UnlimitedInt(i2->to_string());
         if(i1->to_string()=="-0" || i1->to_string()=="0")
         {
            return new UnlimitedInt("0");
         }
         int flag=-1;
        if(size1==size2)
        {
            int idx=0;
            if(s1<0)
            {
                string res1=i1->to_string();
                res1=res1.substr(1,res1.length()-1);
                temp1=new UnlimitedInt(res1);
            }
            if(s2<0)
            {
                string res2=i2->to_string();
                res2=res2.substr(1,res2.length()-1);
                temp2=new UnlimitedInt(res2);  
            }
            int*p1=temp1->get_array();
            int*p2=temp2->get_array();
            while(idx<size1)
            {
                if(p1[idx]>p2[idx])
                {
                    flag=1;
                    break;
                }
                else if(p1[idx]<p2[idx])
                {
                    flag=0;
                    break;
                }
                else
                {
                    idx++;
                }
            }
            if(flag==-1)
            {
                return new UnlimitedInt("0");
            }      
        }
         if(size1<size2 || flag==0)
         {
            if(s1*s2>0)
            {
            UnlimitedInt*temp=new UnlimitedInt(i1->to_string());
            return temp;
            }
            else
            {
            if(s1<0)
            {
                string res1=i1->to_string();
                res1=res1.substr(1,res1.length()-1);
                temp1=new UnlimitedInt(res1);
            }
            if(s2<0)
            {
                string res2=i2->to_string();
                res2=res2.substr(1,res2.length()-1);
                temp2=new UnlimitedInt(res2);  
            }
              UnlimitedInt*result=temp2->sub(temp2,temp1);
              temp2->~UnlimitedInt() ;
                temp1->~UnlimitedInt();
                return result;
            }
         }
       else
        {
            if(s1<0)
            {
                string res1=i1->to_string();
                res1=res1.substr(1,res1.length()-1);
                temp1=new UnlimitedInt(res1);
            }
            if(s2<0)
            {
                string res2=i2->to_string();
                res2=res2.substr(1,res2.length()-1);
                temp2=new UnlimitedInt(res2);  
            }
            UnlimitedInt*curr=temp1;
            string s="";
            while(1)
            {
                s=curr->to_string();
                curr=temp2->sub(curr,temp2);
                if(curr->get_sign()==-1)
                {
                    res=s;
                    break;
                }
            }
        if(s1*s2>0|| res=="0")
        {
            return new UnlimitedInt(res);
        }
        else
        {
            UnlimitedInt*t=new UnlimitedInt(res);
           UnlimitedInt*temp=temp2->sub(temp2,t);
           t->~UnlimitedInt();
           return temp;
        }
        }
    }*/
    int comp(UnlimitedInt*m,UnlimitedInt*n)
    {
        int*p1=m->get_array();
        int*p2=n->get_array();
          int size1=m->get_size();
          int size2=n->get_size();
               // int csize1,csize2;
      int tsize=max(size1,size2);
      if(tsize==size1 && tsize!=size2)
      {
        return 1;
      }
      else if(tsize==size2 && tsize!=size1)
      {
        return -1;
      }
      else
      {
          bool flag=0;
        int idx=0;
        while(idx<tsize)
        {
            if(p1[idx]>p2[idx])
            {
                return 1;
            }
            else if(p1[idx]<p2[idx])
            {
                return -1;
            }
            else
            {
                idx++;
            }
    }
        return 0;
      } 
      //return 0;   
      }
    UnlimitedInt*UnlimitedInt::div(UnlimitedInt*i1,UnlimitedInt*i2)
    {
       // int count=0;
       // cout<<"hi"<<endl;
        int*p1=i1->get_array();
        int s1=i1->get_sign();
        int s2=i2->get_sign();
        string r1=i1->to_string();
        string r2=i2->to_string();
        UnlimitedInt*q=new UnlimitedInt("0");
        UnlimitedInt*r=new UnlimitedInt("0");
        if(s1<0)
        {
            r1=r1.substr(1,r1.length()-1);
        }
        if(s2<0)
        {
            r2=r2.substr(1,r2.length()-1);
        }
        UnlimitedInt*temp=new UnlimitedInt(r2);
        UnlimitedInt*ten=new UnlimitedInt("10");
        UnlimitedInt*nul=new UnlimitedInt("0");
        UnlimitedInt*un=new UnlimitedInt("1");
        int idx=0;
        while(idx<r1.length())
        {
            r=mul(r,ten);
            //cout<<std::to_string(p1[idx])<<endl;
            UnlimitedInt*p=new UnlimitedInt(std::to_string(p1[idx]));
            r=add(r,p);
            UnlimitedInt*d=nul;
            while(comp(r,temp)>=0)
            {
                r=sub(r,temp);
                d=add(d,un);
            }
            q=mul(q,ten);
            q=add(q,d);
            p->~UnlimitedInt();
            idx++;
        }
        ten->~UnlimitedInt();
        temp->~UnlimitedInt();
        nul->~UnlimitedInt();
        un->~UnlimitedInt();
        if(s1*s2==-1)
        {
            return new UnlimitedInt('-'+q->to_string());
        }
        return new UnlimitedInt(q->to_string());
    }
     UnlimitedInt*UnlimitedInt:: mod(UnlimitedInt* i1, UnlimitedInt* i2)
    {
       // cout<<"hi3"<<endl;
       
        UnlimitedInt*d=div(i1,i2);
        UnlimitedInt*b=mul(i2,d);
        UnlimitedInt*a=sub(i1,b);
        b->~UnlimitedInt();
        d->~UnlimitedInt();
        return a;                    // (a - (b*([a/b])))
    }
    // Conversion Functions 
  string UnlimitedInt:: to_string()
    {
        string res="";
        if(this->sign==-1)
        {
            res="-";
        }
        for(int i=0;i<size;i++)
        {
            res+=std::to_string(unlimited_int[i]);
        }
        return res;         
    }
/*int main()
{
    UnlimitedInt*num=new UnlimitedInt("655");
    UnlimitedInt*num2=new UnlimitedInt("2");  
    UnlimitedInt*num3=new UnlimitedInt("5");             
    UnlimitedInt*num4=new UnlimitedInt("5");
    cout<<num->mul(num,num2)->to_string()<<endl;  // div and mod
   // cout<<num2->mul(num2,new UnlimitedInt("2"))->to_string()<<endl;  // div and mod
}*/