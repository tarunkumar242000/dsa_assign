#include<bits/stdc++.h>
using namespace std;



 class LFUCache {
public:
    
    map<int,int>m1;
    map<int,int>m3;
    map<int,int>m5;
    map<int,int>m4;
    int cap=0,size=0,index=0;
    map<int, set<int> > mS;
    

    
    
 
    LFUCache(int capacity) {
        
        cap=capacity;
    }
    
    int get(int key) {
        if(m1.find(key)!=m1.end())
        {
            set<int>s;
            m4.erase(m5[key]);
            m4[index]=key;
           
            s=mS[m3[key]];
            s.erase(m5[key]);
            mS.erase(m3[key]);
             if(!s.empty())
             {
                 mS[m3[key]]=s;
             }
            m3[key]=m3[key]+1;
            mS[m3[key]].insert(index);
             m5.erase(key);
            m5[key]=index;
            index++;
            return m1[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m1.find(key)!=m1.end())
        {
            m4.erase(m5[key]);
            m4[index]=key;
            set<int>s;
            s=mS[m3[key]];
            s.erase(m5[key]);
             mS.erase(m3[key]);
             if(!s.empty())
             {
                 mS[m3[key]]=s;
             }
            m3[key]=m3[key]+1;
            mS[m3[key]].insert(index);
            m5.erase(key);
            m5[key]=index;
            m1.erase(key);
            m1[key]=value;
            index++;
        }
        else
        {
            if(cap>0)
            {if(size==cap)
            {
                set<int>s;
                int ss;
                auto it=m4.begin();
                auto ii=mS.begin();
                ss=ii->first;
                
                //cout<<ss<<endl;
                s=ii->second;
                
                if(s.size()==1)
                {
                   // cout<<1<<endl;
                    auto ii=mS.begin();
                    auto p=s.begin();
                    int a;
                    a=*p;
                    m3.erase(m4[a]);
                    m1.erase(m4[a]);
                    mS.erase(ii);
                }
                else
                {
                    int m,a,b;
                  //  cout<<3<<endl;
                    auto k=s.begin();
                  //  cout<<4<<endl;
                    auto ii=mS.begin();
                  //  cout<<5<<endl;
                    
                   // cout<<*k<<endl;
                  //  cout<<6<<endl;
                    
                    m3.erase(m4[*k]);
                  //  cout<<7<<endl;
                    m1.erase(m4[*k]);
                   // cout<<8<<endl;
                    s.erase(*k);
                    mS.erase(ii);
                   // cout<<9<<endl;
                    mS[ss]=s;
                    //cout<<10<<endl;
                }
                m4.erase(it);
                m1[key]=value;
                m4[index]=key;
                m5[key]=index;
                m3[key]=1;
                mS[1].insert(index);
                index++;
            }
            else
            {
                m1[key]=value;
                size++;
                m4[index]=key;
                m5[key]=index;
               
                m3[key]=1;
                mS[1].insert(index);
                 index++;
            }
        }
    }}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int capa,q;
    cin>>capa>>q;
    LFUCache* obj = new LFUCache(capa);
    vector<vector<int>>v;
    vector<int>v1;
    int temp;
    temp=q;
    while(temp--)
    {
        int a,b,c;
        cin>>a;
        v1.push_back(a);
        if(a==2)
        {
            cin>>b>>c;
            v1.push_back(b);
            v1.push_back(c);
            v.push_back(v1);
            v1.clear();
        }
        else
        {
            cin>>b;
            v1.push_back(b);
            v.push_back(v1);
            v1.clear();
        }
    }

    for(int i=0;i<q;i++)
    {
        if(v[i][0]==2)
       {
            int a,b;
            a=v[i][1];
            b=v[i][2];
            obj->put(a,b);
            cout<<22<<endl;
        }
        else
        {
            int a,b;
            a=v[i][1];
            b=obj->get(a);
            cout<<1121<<endl;
            cout<<b<<endl;
        }
    }
    return 0;
}

