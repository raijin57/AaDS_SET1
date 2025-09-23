#include <stdexcept>
#include "list.h"
#include <cassert>
#include <iostream>
#include <unordered_set>

List::List() {
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

List::List(const List& other) : List() {
    copy(other);
}

List::List(std::vector<int> array) : List() {
    for (const int i : array) {
        push_back(i);
    }
}

List::~List() {
    clear();
}

int List::front() {
    return head->value;
}

int List::back() {
    return tail->value;
}

void List::push_back(int value) {
    if (empty()) {
        head = new Node(value);
        tail = head;
        ++_size;
        return;
    }
    tail->next = new Node(tail, nullptr, value);
    tail = tail->next;
    ++_size;
}

void List::push_front(int value) {
    if (empty()) {
        head = new Node(value);
        tail = head;
        ++_size;
        return;
    }
    head->prev = new Node(nullptr, head, value);
    head = head->prev;
    ++_size;
}

void List::insert(Node* pos, int value) {
    if (pos == nullptr) {
        throw std::runtime_error("Incorrect position!");
    }
    if (pos == tail) {
        push_back(value);
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        if (temp == pos) {
            temp->next = new Node(temp, temp->next, value);
            temp = temp->next;
            temp->next->prev = temp;
            ++_size;
            return;
        }
        temp = temp->next;
    }
    throw std::runtime_error("Incorrect position!");
}

void List::pop_front() {
    if (empty()) {
        throw std::runtime_error("Deleting in empty list");
    }
    if (_size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        _size = 0;
        return;
    }
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    --_size;
}

void List::pop_back() {
    if (empty()) {
        throw std::runtime_error("Deleting in empty list");
    }
    if (_size == 1) {
        delete tail;
        tail = nullptr;
        head = nullptr;
        _size = 0;
        return;
    }
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    --_size;
}

void List::erase(Node* pos) {
    Node* start = head;
    while (start != nullptr) {
        if (start == pos) {
            break;
        }
        start = start->next;
    }
    if (start == nullptr) {
        throw std::runtime_error("Incorrect position!");
    }
    if (pos == nullptr) {
        throw std::runtime_error("Incorrect position!");
    }
    Node* prev = pos->prev;
    Node* next = pos->next;
    if (prev) {
        prev->next = next;
    }
    else {
        head = next;
    }
    if (next) {
        next->prev = prev;
    }
    else {
        tail = prev;
    }
    delete pos;
    --_size;
}

void List::clear() {
    while (!empty()) {
        pop_back();
    }
}

void List::reverse() {
    if (empty() || _size == 1) {
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        std::swap(temp->next, temp->prev);
        temp = temp->prev;
    }
    std::swap(head, tail);
}

void List::remove_duplicates() {
    std::unordered_set<int> seen;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        if (seen.count(current->value)) {
            erase(current);
        } else {
            seen.insert(current->value);
        }
        current = next;
    }
}

void List::replace(int old_value, int new_value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->value == old_value) {
            temp->value = new_value;
        }
        temp = temp->next;
    }
}

void List::merge(const List& other) {
    Node* current = other.head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
}

bool List::check_cycle() const {
    if (empty() || head->next == nullptr) {
        return false;
    }
    Node* turtle = head;
    Node* hare = head;
    while (hare != nullptr) {
        turtle = turtle->next;
        hare = hare->next;
        if (hare != nullptr) {
            hare = hare->next;
        }
        if (turtle == hare) {
            return true;
        }
    }
    return false;
}

size_t List::size() const {
    return _size;
}

bool List::empty() const {
    return _size == 0;
}

void List::copy(const List& other) {
    clear();
    Node* current = other.head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
}