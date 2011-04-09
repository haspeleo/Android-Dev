/* 
 * File:   Heap.cpp
 * Author: doghmen
 * 
 * Created on 8 avril 2011, 17:47
 */
#include <cstdlib>

#include "Heap.h"
template<typename ItemType>
Heap<ItemType>::Heap() {
    nbElements = 0;
}
template<typename ItemType>
int Heap<ItemType>::left(int root) const {
    return (2 * root + 1);
}
template<typename ItemType>
int Heap<ItemType>::right(int root) const {
    //assert(root < (nbElements - 1) / 2);
    return (2 * root + 2);
}

template<typename ItemType>
int Heap<ItemType>::parent(int root) const {
    return (root - 1) / 2;
}

template<typename ItemType>
void Heap<ItemType>::insert(const ItemType& item) {
    //assert(!isFull());
    array[nbElements] = item;
    int new_pos = nbElements;
    nbElements ++;
    while((new_pos != 0) && (array[new_pos] > array[parent(new_pos)])) {
	swap(array[new_pos], array[parent(new_pos)]);
	new_pos = parent(new_pos);
    }
}
