/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream>
#include "ulimitedrational.h"
using namespace std;
    static void get_gcd(UnlimitedInt*&m,UnlimitedInt*&n)

    {
      //  cout<<"hi7"<<endl;
        UnlimitedInt*pm=nullptr;
        UnlimitedInt*qm=nullptr;
        int size1=m->get_size();
        int size2=n->get_size();
        int*p=m->get_array();
        int*q=n->get_array();
            if(size1>size2)
            {
                pm=m;      
                qm=n;
            }
            else if(size1<size2)
            {
                pm=n;
                qm=m;
            }
            else
            {
                int idx=0;
                while(idx<size1)
                {
                    if(p[idx]>q[idx])
                    {
                        pm=m;
                        qm=n;
                        break;
                    }
                    else if(p[idx]<q[idx])
                    {
                        pm=n;
                        qm=m;
                        break;
                    }
                    else
                    {
                        idx++;
                    }
                }
                if(idx==size1)
                {
                    pm=m;
                    qm=n;
                }
            }
            UnlimitedInt*temp=nullptr;
            while(qm->to_string()!="0")
            {
                //cout<<"hi#"<<endl;
               /* cout<<pm->to_string()<<endl;
                cout<<qm->to_string()<<endl;*/
                temp=pm->mod(pm,qm);
                pm=qm;
                qm=temp;   
               /* cout<<qm->to_string()<<endl;
                cout<<pm->to_string()<<endl;*/
            }
          //  cout<<"hi8"<<endl;
           m=m->div(m,pm);       
           n=n->div(n,pm);
         //  cout<<"hi9"<<endl;
           return;
    }
    UnlimitedRational::UnlimitedRational()
    {
        this->p=new UnlimitedInt();
        this->q=new UnlimitedInt();
    }
    UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den)
    {
       
        // find gcd
        if(num->to_string()=="0")
        {
            this->p=new UnlimitedInt("0");
            this->q=den;
        }                  //case of zero for gcd:)
        else
        {
        get_gcd(num,den);
        this->p=num;
        this->q=den;
        }
    }
    UnlimitedRational::~UnlimitedRational()
    {
        p->~UnlimitedInt();
        q->~UnlimitedInt();
    }
    UnlimitedInt*UnlimitedRational:: get_p()
    {
        return p;
    }

   UnlimitedInt* UnlimitedRational:: get_q()
    {
        return q;
    }
  string  UnlimitedRational:: get_p_str()
    {
        return p->to_string();
    } // Return the numerator as a string

   string  UnlimitedRational::get_q_str()
    {
        return q->to_string();
    } // Return the denominator as a string
    
    string UnlimitedRational::get_frac_str()
    {
        string res= p->to_string()+'/'+q->to_string();
        return res;
    } // Return the rational as "p/q"
    // Rational arithmetic operations
    UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2)
    {
        
        UnlimitedInt*p1=i1->get_p();
        UnlimitedInt*p2=i2->get_p();
        UnlimitedInt*q1=i1->get_q();
        UnlimitedInt*q2=i2->get_q();
        UnlimitedRational*result=new UnlimitedRational((p1->add(p1->mul(p1,q2),p2->mul(p2,q1))),(q1->mul(q1,q2)));
        return result;
    }
    UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2)
    {
       UnlimitedInt*p1=i1->get_p();
        UnlimitedInt*p2=i2->get_p();
        UnlimitedInt*q1=i1->get_q();
        UnlimitedInt*q2=i2->get_q();
        UnlimitedRational*result=new UnlimitedRational((p1->sub(p1->mul(p1,q2),p2->mul(p2,q1))),(q1->mul(q1,q2))); 
        return result;
    }
    UnlimitedRational*UnlimitedRational:: mul(UnlimitedRational* i1, UnlimitedRational* i2)
    {
       UnlimitedInt*p1=i1->get_p();
        UnlimitedInt*p2=i2->get_p();
        UnlimitedInt*q1=i1->get_q();
        UnlimitedInt*q2=i2->get_q();
        UnlimitedInt*p=new UnlimitedInt(p1->mul(p1,p2)->to_string());
        UnlimitedInt*q=new UnlimitedInt(q1->mul(q1,q2)->to_string());
        UnlimitedRational*result=new UnlimitedRational(p,q);   
        return result;
    }
     UnlimitedRational*UnlimitedRational:: div(UnlimitedRational* i1, UnlimitedRational* i2)
    {
       UnlimitedInt*p1=i1->get_p();
        UnlimitedInt*p2=i2->get_p();
        UnlimitedInt*q1=i1->get_q();
        UnlimitedInt*q2=i2->get_q();
        UnlimitedRational*result=new UnlimitedRational(p1->mul(p1,q2),q1->mul(p2,q1));     
        return result;
    }
 /*int main()
    {
        UnlimitedRational*n1=new UnlimitedRational(new UnlimitedInt("665"),new UnlimitedInt("1"));
      //  cout<<n1->get_p_str()<<endl;
      //  cout<<n1->get_q_str()<<endl;
        UnlimitedRational*n2=new UnlimitedRational(new UnlimitedInt("2"),new UnlimitedInt("51"));
      //  UnlimitedRational*n3=new UnlimitedRational()
      cout<<n1->mul(n1,n2)->get_frac_str()<<endl;
        cout<<n2->get_p_str()<<endl;
       cout<<n2->get_q_str()<<endl;
    }*/