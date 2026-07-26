class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    int freq;

    Node(int k , int v){
        key=k;
        value=v;
        freq=1;
        prev=nullptr;
        next=nullptr;
    }

};

class List{
public:
    Node*head;
    Node*tail;
    int size;

    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        size =0;
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node*node){
        Node*prevnode = tail->prev;
        node->prev = prevnode;
        prevnode->next = node;
        node->next = tail;
        tail->prev = node;
        size++;
    }

    void remove(Node*node){
        Node*prevnode = node->prev;
        Node*nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        size--;
    }
};
class LFUCache {
public:
    int cap;
    int minfreq;
    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqList;

    LFUCache(int capacity) {
        cap = capacity;
        minfreq=0;
    }

    void updateFreq(Node*node){
        int freq = node->freq;
        freqList[freq]->remove(node);
        if(freq==minfreq && freqList[freq]->size==0){
            minfreq++;
        }
        node->freq++;
        if(freqList.find(node->freq)==freqList.end()){
            freqList[node->freq]=new List();
        }
        freqList[node->freq]->insert (node);
    }
    
    int get(int key) {
        if(keyNode.find(key)==keyNode.end()){
            return -1;
        }
        Node*node = keyNode[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cap == 0 ){
            return ;
        }
        if(keyNode.find(key)!= keyNode.end()){
            Node *node =keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }
        if(keyNode.size()==cap){
            List*list = freqList[minfreq];
            Node *node = list->head->next;
            list->remove(node);
            keyNode.erase(node->key);
            delete node;
        }
        Node *newNode = new Node(key, value);

        minfreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->insert(newNode);

        keyNode[key] = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */