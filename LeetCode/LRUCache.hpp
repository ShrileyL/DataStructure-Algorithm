class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = NULL;
        tail = NULL;
        keyToNode.clear();
    }
    
    int get(int key) {
        if(keyToNode.count(key) == 0) return -1;
        //Updat:move to end
        moveToEnd(key);
        return keyToNode[key]->val;
    }
    
    void put(int key, int value) {
        //if already exist, update value
        if(get(key)!=-1){
            keyToNode[key]->val = value;
            return;
        }
        
        //if not exist, insert
        if(isFull()) removeHead();
        insertToEnd(key,value);
    }
    
private:
    struct Node{
        Node *pre;
        Node *next;
        int key;
        int val;
        Node(int k,int v):key(k),val(v),pre(NULL),next(NULL){}
    };
    
    int capacity_;
    Node *head;
    Node *tail;
    unordered_map<int,Node*> keyToNode;
    
    bool isFull()
    {
        return (keyToNode.size() >= capacity_);
    }
    
    void insertToEnd(int k, int v){
        //if full or already exist, return
        if(isFull()||keyToNode.count(k)!=0) return;
        
        Node *nd = new Node(k,v);
        keyToNode[k] = nd;
        //if head = tail = NULL
        if(!head){
            head = tail = nd;
        }
        else{
            tail->next = nd;
            nd->pre = tail;
            tail = tail->next;
        }
    }
    
    void removeHead(){
        //if head not exist
        if(!head) return;
        keyToNode.erase(head->key);
        Node *tmp = head;
        if(head == tail)//if only one node
        {
            head = tail = NULL;
        }
        else{
            head = head->next;
            head->pre = NULL;
        }
        delete tmp;
    }
    
    void moveToEnd(int key){
        //if key not exist or already in the end
        if(keyToNode.count(key) == 0|| keyToNode[key] == tail) return;
        
        Node *nd = keyToNode[key];
        if(nd == head)//if at the front
        {
            head = head->next;
            head->pre = NULL;
        }
        else{
            nd->pre->next = nd->next;
            nd->next->pre = nd->pre;
        }
        tail->next = nd;
        nd->pre = tail;
        nd->next = NULL;
        tail = tail->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */