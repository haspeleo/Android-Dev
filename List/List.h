/* 
 * File:   List.h
 * Author: doghmen
 *
 * Created on 7 avril 2011, 07:38
 */

#ifndef LIST_H
#define	LIST_H

template<typename ItemType>
struct ListNode {
    ItemType data;
    ListNode *next;
};

template<typename ItemType>
class List {
public:
    List();
    ~List();
    void insert(const ItemType);
    void deleteElement();
    void next();
    void prev();
    void reset();
    void clear();
    int length();
    bool isEmpty();
    bool isFull();
    ItemType value();
private:
    ListNode<ItemType> *list;
    ListNode<ItemType> *prevcurrent;
    int len;
};


#endif	/* LIST_H */

