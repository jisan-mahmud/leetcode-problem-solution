class LRUCache {
private:

    class Node{
        public: 
            Node* prev;
            Node* next;
            
            int key;
            int val;

            Node(int key, int value){
                prev = nullptr;
                next = nullptr;
                this->key = key;
                val = value;
            }
    };


    int limit;

    Node* head;
    Node* tail;

    void addNode(Node* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void delNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* node = mp[key];

        delNode(node);
        addNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];

            node->val = value;
            delNode(node);
            addNode(node);

            return;
        }

        if (mp.size() == limit) {
            Node* lru = tail->prev;

            mp.erase(lru->key);
            delNode(lru);
            delete lru;
        }

        

        Node* node = new Node(key, value);
        mp[key] = node;
        addNode(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */