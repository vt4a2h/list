#ifndef LIST_F_H
#define LIST_F_H

#include <cstdio>
#include <vector>
#include <iostream>

namespace list_f {

    struct Node
    {
        Node(int data) : data_(data) {}

        int data_;
        Node* next;
    };

    Node* prepend(Node* list, Node* node)
    {
        if (node != nullptr) node->next = list;

        return node ? node : list;
    }

    Node* toList(const std::vector<int>& array)
    {
        Node* list = nullptr;

        for (size_t i = 0; i != array.size(); ++i)
            list = prepend(list, new Node(array[i]));

        return list;
    }

    size_t count(Node* list, int value)
    {
        size_t count = 0;

        while(list) {
            if (list->data_ == value) ++count;
            list = list->next;
        }

        return count;
    }

    void deleteList(Node* list)
    {
        while (list) {
            Node* next = list->next;
            delete list;
            list = next;
        }
    }

    void printList(Node* list)
    {
        while (list) {
            std::cout << list->data_ << " ";
            list = list->next;
        }
        std::cout << std::endl;
    }

    size_t listLength(Node* list)
    {
        size_t length = 0;

        while (list) {
            ++length;
            list = list->next;
        }

        return length;
    }

    // NOTE: homework

    /*!
     * \brief Функция поворота списка.
     * \param list список для поворота
     * \return указатель на "голову" нового списка.
     */
    Node* reverseList(Node* list) {
        if (list == nullptr || list->next == nullptr) return list;

        Node *current = list;
        Node *previos = nullptr;
        Node *next    = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previos;
            previos = current;
            current = next;
        }

        return previos;
    }

    /*!
     * \brief Функция проверяет есть ли в списке цикл.
     * \param list списко для проверки.
     * \return true если есть цикл и false в противном случае.
     */
    bool hasCycle(Node *list) {
        if (list == nullptr || list->next == nullptr) return false;

        Node *slow = list;
        Node *fast = list->next->next;

        while (fast != nullptr && fast != slow) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return fast == nullptr ? false : true;
    }


    /*!
     * \brief Функция нахождения места сочленения Y-образного списка.
     * \param firstHead указатель на первую "голову".
     * \param secondHead "указатель на вторую "голову".
     * \return указатель на место сочленения.
     */
    Node *connectionPoint(Node *firstHead, Node *secondHead)
    {
        auto firstLen = listLength(firstHead);
        auto secondLen = listLength(secondHead);

        if (firstLen > secondLen) {
            for (size_t i = 0; i < firstLen - secondLen; ++i) {
                firstHead = firstHead->next;
            }
        } else if(secondLen > firstLen) {
            for (size_t i = 0; i < secondLen - firstLen; ++i) {
                secondHead = secondHead->next;
            }
        }

        while (firstHead != secondHead) {
            firstHead = firstHead->next;
            secondHead = secondHead->next;
        }

        return firstHead;
    }
}

#endif // LIST_F_H
