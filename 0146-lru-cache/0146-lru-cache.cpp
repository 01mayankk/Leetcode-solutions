class LRUCache {
private:
    
    // ==============================
    // NODE CLASS (Doubly Linked List Node)
    // ==============================
    class Node {
    public:
        int key;       // stores key
        int value;     // stores value
        Node* prev;    // pointer to previous node
        Node* next;    // pointer to next node
        
        // Constructor
        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    int capacity;  // maximum number of elements allowed in cache
    
    // HashMap: key -> pointer to node in DLL
    // This gives O(1) access to nodes
    unordered_map<int, Node*> mp;
    
    Node* head;   // dummy head (Most Recent side)
    Node* tail;   // dummy tail (Least Recent side)
    
    
    // ==========================================
    // FUNCTION: addNode
    // Insert node right after head
    // That means marking it as MOST RECENT
    // ==========================================
    void addNode(Node* node) {
        
        // New node will be placed between
        // head and head->next
        
        node->next = head->next;   // Step 1: new node points to first real node
        node->prev = head;         // Step 2: new node previous becomes head
        
        head->next->prev = node;   // Step 3: old first node's prev becomes new node
        head->next = node;         // Step 4: head points to new node
    }
    
    
    // ==========================================
    // FUNCTION: deleteNode
    // Remove node from anywhere in DLL
    // ==========================================
    void deleteNode(Node* node) {
        
        Node* prevNode = node->prev;   // node before the one we delete
        Node* nextNode = node->next;   // node after the one we delete
        
        // Remove the node by connecting its neighbors
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    
public:
    
    // ==============================
    // CONSTRUCTOR
    // ==============================
    LRUCache(int cap) {
        
        capacity = cap;  // set capacity
        
        // Create dummy head and tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        // Connect head and tail
        head->next = tail;
        tail->prev = head;
    }
    
    
    // ==============================
    // GET FUNCTION
    // ==============================
    int get(int key) {
        
        // If key not present in map
        if (mp.find(key) == mp.end())
            return -1;
        
        // Access node in O(1)
        Node* node = mp[key];
        
        // Since it is accessed, it becomes MOST RECENT
        
        // Step 1: Remove from current position
        deleteNode(node);
        
        // Step 2: Add after head
        addNode(node);
        
        // Return value
        return node->value;
    }
    
    
    // ==============================
    // PUT FUNCTION
    // ==============================
    void put(int key, int value) {
        
        // CASE 1: Key already exists
        if (mp.find(key) != mp.end()) {
            
            Node* node = mp[key];
            
            // Update value
            node->value = value;
            
            // Move it to front (most recent)
            deleteNode(node);
            addNode(node);
        }
        
        // CASE 2: New key
        else {
            
            // If capacity full → remove LRU
            if (mp.size() == capacity) {
                
                // LRU node is just before tail
                Node* lru = tail->prev;
                
                // Remove from DLL
                deleteNode(lru);
                
                // Remove from map
                mp.erase(lru->key);
            }
            
            // Create new node
            Node* newNode = new Node(key, value);
            
            // Insert into map
            mp[key] = newNode;
            
            // Insert into DLL at front
            addNode(newNode);
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */