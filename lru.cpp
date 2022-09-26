#include<bits/stdc++.h>
using namespace std;


class LRUCache {
public:

    unordered_map<int,int>m1;
    unordered_map<int,int>m3;
    map<int,int>m2;
    int cap=0,index=0,size=0;

    LRUCache(int capacity) {
        cap=capacity;
    }

    int get(int key) {
        if(m1.find(key)!=m1.end())
        {
            m2.erase(m3[key]);
            m2[index]=key;
            m3.erase(key);
            m3[key]=index;
            index++;
            return m1[key];
        }
        return -1;
    }

    void set1(int key, int value) {
        if(m1.find(key)!=m1.end())
        {
            m1.erase(key);
            m1[key]=value;
            m2.erase(m3[key]);
            m2[index]=key;
            m3.erase(key);
            m3[key]=index;
            index++;
        }
        else
        {
            if(size==cap)
            {
                auto it=m2.begin();
                m1.erase(m2[it->first]);
                m2.erase(it);
                m1[key]=value;
                m2[index]=key;
                m3[key]=index;
                index++;
            }
            else
            {
                m1[key]=value;
                m2[index]=key;
                m3[key]=index;
                index++;
                size++;
            }
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int capa,q;
    cin>>capa>>q;
    LRUCache* obj = new LRUCache(capa);
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
    cout<<endl<<endl;
    for(int i=0;i<q;i++)
    {
        if(v[i][0]==2)
       {
            int a,b;
            a=v[i][1];
            b=v[i][2];
            obj->set1(a,b);
            //cout<<22<<endl;
        }
        else
        {
            int a,b;
            a=v[i][1];
            b=obj->get(a);
            //cout<<1121<<endl;
            cout<<b<<endl;
        }
    }
    return 0;
}
