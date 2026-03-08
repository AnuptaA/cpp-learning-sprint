#pragma once

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void insert_front(int val);
    void insert_back(int val);
    void insert_at(int index, int val);  // 0-indexed; throw std::out_of_range if invalid

    bool remove(int val);         // remove first occurrence; return false if not found
    bool search(int val) const;   // return true if val exists

    int size() const;
    void print() const;           // e.g.  3 -> 7 -> 2 -> null

private:
    struct Node {
        int index;
        int val;
        Node* next;
        Node(int index, int val) : index(index), val(val), next(nullptr) {}
    };
    Node* nPtr_head;
    int iSize;
};