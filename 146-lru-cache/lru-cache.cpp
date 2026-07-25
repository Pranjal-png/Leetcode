class Node{
    public:
        int key;
        int value;
        Node*prev;
        Node*next;

    Node(int k, int v){
        key =k;
        value=v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:

    int cap;
    unordered_map<int,Node*>mpp;
    Node*head;
    Node*tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        
    }

    void RemoveNode(Node*node){
        Node*prevnode = node->prev;
        Node*nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;

    }

    void InsertNode(Node*node){
        Node*prevnode = tail->prev;
        prevnode->next = node;
        node->prev = prevnode;
        node->next = tail;
        tail->prev = node;

    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node*node = mpp[key];
        RemoveNode(node);
        InsertNode(node);
        return node->value;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*node = mpp[key];
            node->value = value;
            RemoveNode(node);
            InsertNode(node);
            return;
        }
        if(mpp.size()==cap){
            Node*lru = head->next;
            RemoveNode(lru);
            mpp.erase(lru->key);
            delete lru;
            
        }
        Node*newNode = new Node(key,value);
        InsertNode(newNode);
        mpp[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */