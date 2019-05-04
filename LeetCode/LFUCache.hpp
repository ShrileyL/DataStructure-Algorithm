class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        //if not exist
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        
        Node* node = cacheMap[key];
        //update freq
        freqMap[node->freq].erase(node->it);
        node->freq += 1;
        freqMap[node->freq].push_front(key);
        node->it = freqMap[node->freq].begin();
        if(freqMap[minFreq].size()==0)
            minFreq = node->freq;
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity <= 0) return;
        
        if(get(key) == -1)
        {
            if(cacheMap.size()==capacity)
            {
                //remove
                int popkey = freqMap[minFreq].back();
                cacheMap.erase(popkey);
                freqMap[minFreq].pop_back();
            }
            
            //insert new node
            Node*  node = new Node(value);
            minFreq = 1;
            freqMap[1].push_front(key);
            node->it = freqMap[1].begin();
            cacheMap[key] = node;
        }
        else
        {
            cacheMap[key]->val = value;
        }
    }

private:
    struct Node{
        int val;
        int freq;
        list<int>::iterator it;
        Node():freq(1){}
        Node(int value):val(value),freq(1){}
    };
    
    int capacity;
    int minFreq;
    unordered_map<int,Node*> cacheMap;
    unordered_map<int,list<int>> freqMap;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */