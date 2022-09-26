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

    void put(int key, int value) {
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

