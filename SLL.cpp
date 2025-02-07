#include "SLL.h"
#include "Token.h"
#include <memory>

template<typename T>
SLL<T>::SLL() : head(nullptr) {};

/**
 * Add the input data in order to the linked list
 *
 * @param data The data to add to the linked list
 * @return void
 */
template<typename T>
void SLL<T>::addInOrder(T data) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);
    
    if constexpr (std::is_same_v<T, Token>) {
        if (head == nullptr || data.compareTo(head->getData()) <= 0) {
            newNode->setNext(head);
            head = newNode;
            return;
        }
    } else {
        if (head == nullptr || data <= head->getData()) {
            newNode->setNext(head);
            head = newNode;
            return;
        }
    }

    std::shared_ptr<Node<T>> current = head;
    while (current->getNext() != nullptr && data.compareTo(current->getNext()->getData()) > 0) {
        current = current->getNext();
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
}

// Sorts the elements in the linked list in ascending order
template<typename T>
void SLL<T>::sort() {
    std::shared_ptr<Node<T>> current = head;
    while (current != nullptr) {
        std::shared_ptr<Node<T>> next = current->getNext();
        while (next != nullptr) {
            // Check after implementation (dot vs arrow operator)
            if (current->getData().compareTo(next->getData()) > 0) {
                T temp = current->getData();
                current->setData(next->getData());
                next->setData(temp);
            }
            next = next->getNext();
        }
        current = current->getNext();
    }
}

/**
 * Returns the size of the linked list
 *
 * @return int The size of the linked list
 */
template<typename T>
int SLL<T>::size() {
    int count = 0;
    std::shared_ptr<Node<T>> current = head;
    while (current != nullptr) {
        count++;
        current = current->getNext();
    }
    return count;
}

/**
 * Returns the head of the linked list
 *
 * @return std::shared_ptr<Node<T>> The head of the linked list
 */
template<typename T>
std::shared_ptr<Node<T>> SLL<T>::getHead() {
    return head;
}

/**
 * Sets the head of the linked list
 *
 * @param newHead The new head of the linked list
 * @return std::shared_ptr<Node<T>> The new head of the linked list
 */
template<typename T>
std::shared_ptr<Node<T>> SLL<T>::setHead(std::shared_ptr<Node<T>> newHead) {
    std::shared_ptr<Node<T>> oldHead = head;
    head = newHead;
    return oldHead;
}

/**
 * Returns the node at the specified index
 *
 * @param index The index of the node to return
 * @return std::shared_ptr<Node<T>> The node at the specified index
 */
template<typename T>
std::shared_ptr<Node<T>> SLL<T>::get(int index) {
    if (index < 0 || index >= size()) {
        return nullptr;
    }

    std::shared_ptr<Node<T>> current = head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }

    return current;
}

/**
 * Returns the index of the specified data in the linked list
 *
 * @param data The data to search for
 * @return int The index of the specified data, or -1 if the data is not found
 */
template<typename T>
int SLL<T>::indexOf(T data) {
    std::shared_ptr<Node<T>> current = head;
    int index = 0;

    while (current != nullptr) {
        // Check after implementation (dot vs arrow operator)
        if (current->getData().Token::equals(data)) {
            return index;
        }
        current = current->getNext();
        index++;
    }
    
    return -1;
}

template class SLL<int>;
template class SLL<std::string>;
template class SLL<double>;