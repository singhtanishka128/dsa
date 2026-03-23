/* Program for Least Recently Used (LRU) Page Replacement Algorithm:

Problem Statement: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
int get(int key): Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity. */



/* code: 

// Class representing the LRU Cache
class LRUCache {
public:
    // Doubly linked list node class
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;                   
        Node(int _key, int _val) {    // Constructor to initialize node
            key = _key;
            val = _val;
        }
    };

    // Head and tail dummy nodes
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    // Constructor to initialize LRU cache
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to add a node right after head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Function to remove a given node from list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // Function to get value from cache
    int get(int key_) {

        // If key exists in cache
        if (m.find(key_) != m.end()) {

            Node* resNode = m[key_];
            int res = resNode->val;

            // Remove old mapping
            m.erase(key_);

            // Move accessed node to front
            deleteNode(resNode);
            addNode(resNode);

            // Update map
            m[key_] = head->next;
            return res;
        }

        // If not found
        return -1;
    }

    // Function to put key-value into cache
    void put(int key_, int value) {

        // If key already exists
        if (m.find(key_) != m.end()) {
            Node* existingNode = m[key_];
            m.erase(key_);
            deleteNode(existingNode);
        }

        // If capacity reached
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // Insert new node at front
        addNode(new Node(key_, value));
        m[key_] = head->next;
    }
};

tc: O(1)
sc: O(capacity)
see notes
*/