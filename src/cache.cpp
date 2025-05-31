#include "cache.hpp"
#include <iostream>

// ----------- Node Constructor -----------
LRUCache::Node::Node(const std::string& k, const std::string& v)
    : key(k), value(v), prev(nullptr), next(nullptr) {}

// ----------- Constructor & Destructor -----------
LRUCache::LRUCache(size_t cap)
    : capacity(cap), size(0), head(nullptr), tail(nullptr) {}

LRUCache::~LRUCache() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

// ----------- Get Method -----------
std::string LRUCache::get(const std::string& key) {
    auto it = map.find(key);
    if (it == map.end()) {
        return ""; // Or throw/return sentinel if not found
    }
    moveToFront(it->second);
    return it->second->value;
}

// ----------- Put Method -----------
void LRUCache::put(const std::string& key, const std::string& value) {
    auto it = map.find(key);

    if (it != map.end()) {
        it->second->value = value;
        moveToFront(it->second);
    } else {
        Node* newNode = new Node(key, value);

        if (size == capacity) {
            // Evict least recently used (tail)
            map.erase(tail->key);
            removeNode(tail);
            --size;
        }

        insertAtFront(newNode);
        map[key] = newNode;
        ++size;
    }
}

// ----------- Internal Helpers -----------

void LRUCache::removeNode(Node* node) {
    if (!node) return;

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

void LRUCache::insertAtFront(Node* node) {
    node->prev = nullptr;
    node->next = head;

    if (head) {
        head->prev = node;
    }

    head = node;

    if (!tail) {
        tail = node;
    }
}

void LRUCache::moveToFront(Node* node) {
    if (node == head) return;

    // Detach node
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    if (node == tail) {
        tail = node->prev;
    }

    // Move to front
    node->prev = nullptr;
    node->next = head;
    if (head) head->prev = node;
    head = node;

    if (!tail) {
        tail = node;
    }
}
