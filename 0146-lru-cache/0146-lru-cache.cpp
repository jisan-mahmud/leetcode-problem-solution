class LRUCache {
private:
    class Node {
        public:
            Node* next;
            Node* prev;
            int key;
            int val;

            Node (int key, int val){
                this->key = key;
                this->val = val;

                next = prev = nullptr;
            }
    };

    int limit;
    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    void addNode(Node* node){
        head->next->prev = node;
        node->next = head->next;

        head->next = node;
        node->prev = head;
    }

    void delNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;

        Node* node = cache[key];
        delNode(node);
        addNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* node = cache[key];
            node->val = value;

            delNode(node);
            addNode(node);
            return;
        }

        if(cache.size() == limit){
            Node* node = tail->prev;
            cache.erase(node->key);
            delNode(node);

            delete node;
        }

        Node* node = new Node(key, value);
        addNode(node);
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */