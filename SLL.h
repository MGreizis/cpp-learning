#pragma once

#include "Node.h"
#include <iostream>
#include <memory>
#include <string>

template <typename T>
class SLL {
public:
    std::shared_ptr<Node<T>> head;
    SLL();
    void addInOrder(T data);
    void sort();
    int size();
    std::shared_ptr<Node<T>> getHead();
    std::shared_ptr<Node<T>> setHead(std::shared_ptr<Node<T>> newHead);
    std::shared_ptr<Node<T>> get(int index);
    int indexOf(T data);
};
