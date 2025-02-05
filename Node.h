#pragma once

#include <iostream>
#include <memory>
#include <string>

template <typename T>
class Node {
private:
    T data;
    std::shared_ptr<Node<T>> next;

public:
    // Constructor
    Node(T d);
    // Getter
    T getData() const;
    // Setter
    void setData(T o);
    // Getter for next
    std::shared_ptr<Node<T>> getNext() const;
    // Setter for next
    void setNext(std::shared_ptr<Node<T>> n);
    // toString() method
    std::string toString() const;
};