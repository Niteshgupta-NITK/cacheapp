#pragma once
#include <string>
#include <unordered_map>

class LRUCache {
public:
    explicit LRUCache(size_t capacity);
    ~LRUCache();
    std::string get(const std::string& key);
    void put(const std::string& key, const std::string& value);

private:
    struct Node {
        std::string key;
        std::string value;
        Node* prev;
        Node* next;
        Node(const std::string& k, const std::string& v);
    };

    size_t capacity;
    size_t size;
    std::unordered_map<std::string, Node*> map;
    Node* head;
    Node* tail;

    void removeNode(Node* node);
    void insertAtFront(Node* node);
    void moveToFront(Node* node);
};
