#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class LinkedList {
  private:
    int size;
    T* headPointer;
  public:
    LinkedList();
    ~LinkedList();
    void append(T value);
    void insert(T previousValue, T value);
    void remove(T value);
    int lookupElement(T value);
    T lookupValue(int element_number);
};


#endif /*LINKED_LIST_H*/
