/* 
 * File:   Heap.h
 * Author: doghmen
 *
 * Created on 8 avril 2011, 17:47
 */

#ifndef HEAP_H
#define	HEAP_H

const int MAX_SIZE = 100;



template<typename ItemType>
class Heap {
public:
    Heap();
    virtual ~Heap();
    int left() const;
    int right() const;
    int parent() const;
    void insert(const ItemType&);
    ItemType removeMax();
    bool isEmpty() const;
    bool isFull() const;
    int count() const;
private:
    ItemType array[MAX_SIZE];
    int nbElments;
    void reHeap(int);
};

#endif	/* HEAP_H */

