#include "Node.h"

template <typename T>
Node<T>::Node(T d) : data(d), next(nullptr) {};

template <typename T>
T Node<T>::getData() const {
    return data;
}

template <typename T>
void Node<T>::setData(T o) {
    data = o;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getNext() const {
    return next;
}

template <typename T>
void Node<T>::setNext(std::shared_ptr<Node<T>> n) {
    next = n;
}

template <typename T>
std::string Node<T>::toString() const {
    if constexpr (std::is_same_v<T, std::string>) {
        return "Node: "+ data;
    } else {
        return "Node: "+ std::to_string(data);
    }
}

template class Node<int>;
template class Node<std::string>;
template class Node<double>;