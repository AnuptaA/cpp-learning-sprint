#include "singly_linked_list.hpp"
#include <iostream>

LinkedList::LinkedList() : nPtr_head(nullptr), iSize(0) {}
LinkedList::~LinkedList() {
    Node* current = nPtr_head;

    // iterate and delete each node
    while (current) {
        Node* next = current->next; // shorthand for (*current).next
        delete current;
        current = next;
    }
}

void LinkedList::insert_front(int val) {
    // create new node and simply make it the head
    Node* newNode = new Node(0, val);
    newNode->next = nPtr_head;
    nPtr_head = newNode;

    iSize++;
}

void LinkedList::insert_back(int val) {
    Node* newNode = new Node(iSize, val), * current = nPtr_head;

    // iterate to the end
    while (current && current->next) {
        current = current->next;
    }

    if (current) {
        // if this is non-empty, make it the last node
        current->next = newNode;
    } else {
        // otherwise make it the head
        nPtr_head = newNode;
    }

    iSize++;
}

void LinkedList::insert_at(int index, int val) {
    if (index < 0 || index > iSize) {
        throw std::out_of_range("Index out of range");
    }
    int currentIndex = 0;
    Node* newNode = new Node(index, val), * current = nPtr_head;

    // iterate to the target index
    while (current && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (index == 0) {
        // if inserting at head, there are two cases
        if (current) {
            // if the list is non-empty, treat it like insert_front
            current->next = nPtr_head;
            nPtr_head = newNode;
        } else {
            // otherwise just make it the head
            nPtr_head = newNode;
        }
    } else {
        // make the previous node point to the new node and make the
        // new node point to the next node
        newNode->next = current->next;
        current->next = newNode;
    }
    iSize++;
}

bool LinkedList::remove(int val) {
    Node* current = nPtr_head, * prev = nPtr_head;

    // linearly search for first occurrence of val
    while (current) {
        if (current->val == val) break;
        prev = current;
        current = current->next;
    }

    // not found
    if (!current) return false;

    // found but at head so just make the head point to the next node
    if (current == nPtr_head) nPtr_head = current->next;
    // otherwise make the previous node skip to the next node
    else prev->next = current->next;

    // free the memory and decrement size
    delete current;
    current = nullptr;
    iSize--;

    return true;
}

bool LinkedList::search(int val) const {
    // linearly scan until found or end is reached
    Node* current = nPtr_head;
    while (current) {
        if (current->val == val) return true;
        current = current->next;
    }
    return false;
}

int LinkedList::size() const {
    return iSize;
}

void LinkedList::print() const {
    Node* current = nPtr_head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}