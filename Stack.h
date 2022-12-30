#pragma once

#include <initializer_list>
#include <iostream>
#include<string>
#include <utility>


template <class T>
class NodeStackSmart {
private:
    std::unique_ptr<NodeStackSmart<T>> next = nullptr;
    NodeStackSmart<T>(T _value) : value(_value) {}
    NodeStackSmart<T>(T _value, std::unique_ptr<NodeStackSmart<T>> _next): value(_value), next(_next) {}

public:
    T value;
    template <class T>
    friend class StackOnList;
};

template <class T>
class StackOnList {
public:
    template <class T>
    struct NodeStack {
    private:
        NodeStack<T>* next{ nullptr };
        NodeStack(T _value) : value(_value) {}
        NodeStack(T _value, NodeStack<T>* _next) : value(_value), next(_next) {}

    public:
        T value;
        template <class T>
        friend class StackOnList;
    };

    std::string to_string();
    void print();

    StackOnList() = default;

    StackOnList(const std::initializer_list<T>& list);

    StackOnList(const StackOnList<T>& stack);
    StackOnList<T>& operator=(const StackOnList<T>& stack);

    StackOnList(StackOnList<T>&& stack) noexcept;
    StackOnList<T>& operator=(StackOnList<T>&& stack) noexcept;

    int Size();

    bool IsEmpty();

    void Push(const T& value);
    T Pop();
    NodeStack<T>* Top();
    const NodeStack<T>* TopConst();

    bool operator==(StackOnList<T>& stack1);
    bool operator!=(StackOnList<T>& stack1);

private:
    NodeStack<T>* top_{ nullptr };
};

template<typename T>
T StackOnList<T>::Pop() {
    if (top_ == nullptr) {
        throw "A head is already empty!\n";
    }
    T res = top_->value;
    NodeStack<T>* temp = top_;
    top_ = top_->next;
    delete temp;
    return res;
}
template <class T>
StackOnList<T>::StackOnList(const std::initializer_list<T>& list) {
    for (auto& el : list) {
        Push(el);
    }
}

template <class T>
StackOnList<T>::StackOnList(const StackOnList<T>& stack) {
    StackOnList<T> tmp;

    NodeStack<T>* cur = stack.top_;
    while (cur) {
        tmp.Push(cur->value);
        cur = cur->next;
    }

    cur = tmp.top_;
    while (cur) {
        Push(cur->value);
        cur = cur->next;
    }
}

template <class T>
StackOnList<T>& StackOnList<T>::operator=(const StackOnList<T>& stack) {
    StackOnList<T> tmp(stack);
    return tmp;
}

template <class T>
StackOnList<T>::StackOnList(StackOnList<T>&& stack) noexcept {
    *this = std::move(stack);
}

template <class T>
StackOnList<T>& StackOnList<T>::operator=(StackOnList<T>&& stack) noexcept {
    if (this != &stack) {
        *this = std::move(stack);
    }
    return *this;
}

template <class T>
int StackOnList<T>::Size() {
    NodeStack<T>* top = top_;
    int size = 0;
    while (top != nullptr) {
        size++;
        top = top->next;
    }
    return size;
}

template <class T>
bool StackOnList<T>::IsEmpty() {
    return !top_;
}

template <class T>
void StackOnList<T>::Push(const T& value) {
    NodeStack<T>* new_node = new NodeStack<T>(value);
    new_node->next = top_;
    top_ = new_node;
}

template <class T>
StackOnList<T>::NodeStack<T>* StackOnList<T>::Top() {
    return top_;
}

template <class T>
const StackOnList<T>::NodeStack<T>* StackOnList<T>::TopConst() {
    return top_;
}

template <class T>
std::string StackOnList<T>::to_string() {
    NodeStack<T>* cur = top_;
    std::string str("Stack: ");
    while (cur) {
        str.append(std::to_string(cur->value)).append(", ");
        cur = cur->next;
    }
    return str;
}

template <class T>
void StackOnList<T>::print() {
    NodeStack<T>* cur = top_;
    while (cur) {
        std::cout << cur->value << " ";
        cur = cur->next;
    }
    std::cout << '\n';
}

template <class T>
bool StackOnList<T>::operator==(StackOnList<T>& stack1) {
    if (Size() != stack1.Size()) {
        return false;
    }

    NodeStack<T>* cur = top_;
    NodeStack<T>* cur1 = stack1.top_;

    while (cur) {
        if (cur->value != cur1->value) {
            return false;
        }
        cur = cur->next;
        cur1 = cur1->next;
    }
    return true;
}

template <class T>
bool StackOnList<T>::operator!=(StackOnList<T>& stack1) {
    if (Size() != stack1.Size()) {
        return true;
    }

    NodeStack<T>* cur = top_;
    NodeStack<T>* cur1 = stack1.top_;

    while (cur) {
        if (cur->value != cur1->value) {
            return true;
        }
        cur = cur->next;
        cur1 = cur1->next;
    }
    return false;
}
#pragma once
