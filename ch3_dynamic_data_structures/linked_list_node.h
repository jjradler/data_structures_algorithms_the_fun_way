#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <typename T>
class LinkedListNode {
  private:
    T value;
    T* nextNode;
  public:
    LinkedListNode(T value);
    ~LinkedListNode();
    T getValue();
    T* getNext();
};

#endif /*LINKED_LIST_NODE_H*/
