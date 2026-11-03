class LRUCache {
public:

    int capacity; 
    struct ListNode {
        int key;
        int value;
        ListNode* next;
        ListNode* prev;
        ListNode() : key(0), value(0), next(nullptr), prev(nullptr) {}
        ListNode(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    }; 
    std::unordered_map<int, ListNode*> node_map;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (node_map.contains(key)) {
            if (head == node_map[key]) {
            }
            else if (tail == node_map[key]) {
                tail = node_map[key]->prev;
                tail->next = nullptr;
                node_map[key]->next = head;
                head->prev = node_map[key];
                node_map[key]->prev = nullptr;
                head = node_map[key];
            }
            else {
                node_map[key]->prev->next = node_map[key]->next;
                node_map[key]->next->prev = node_map[key]->prev;
                node_map[key]->next = head;
                node_map[key]->prev = nullptr;
                head->prev = node_map[key];
            }
            head = node_map[key];
            return node_map[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (node_map.contains(key)) {
            node_map[key]->value = value;
            if (head == node_map[key]) {
            }
            else if (tail == node_map[key]) {
                tail = node_map[key]->prev;
                tail->next = nullptr;
                node_map[key]->next = head;
                node_map[key]->prev = nullptr;
                head->prev = node_map[key];
                head = node_map[key];
            }
            else {
                node_map[key]->prev->next = node_map[key]->next;
                node_map[key]->next->prev = node_map[key]->prev;
                head->prev = node_map[key];
                node_map[key]->next = head;
                head = node_map[key];
                node_map[key]->prev = nullptr;
            }
        }
        else if (node_map.size() == capacity) {
            if (capacity == 1) {
                node_map.erase(head->key);
                head->key = key;
                head->value = value;
                node_map[key] = head;
            }
            else {
                node_map.erase(tail->key);
                ListNode* new_node = tail;
                tail = tail->prev;
                new_node->key = key;
                new_node->value = value;
                new_node->next = head;
                new_node->prev = nullptr;
                head->prev = new_node;
                head = new_node;
                node_map[key] = new_node;
            }
        }
        else {
            ListNode* new_node = new ListNode(key, value);
            if (head == nullptr) {
                head = new_node;
                tail = head;
            } else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            node_map[key] = new_node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */