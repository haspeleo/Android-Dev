

#include<cstdlib>

#include "BinaryTree.h"

BinaryTree::BinaryTree(struct node* root) {
   root = NULL;
}

BinaryTree::BinaryTree(const BinaryTree& orig) {
}

BinaryTree::~BinaryTree() {
}

/*Helper functions*/

struct node * BinaryTree::allocateNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    //struct node* newNode = new(struct(node); //allocate with new instead of sizeof
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void BinaryTree::insertNode(Bi node, int data) {

    struct node* newNode = allocateNode(data);

    if (node == NULL) {
        node = allocateNode(data);
    } else {

        if (data < node->data)
            insertNode(node->left, data);
        else
            insertNode(node->right, data);
    }
}


int BinaryTree::lookup(struct node* node, int target) { //could be written using while loop
    if(node == NULL) return -1; //TO FIX
    else {
        struct node* current = node;
        if(current->data == target) {
            return current->data;
        }
        else {
            if(current->data < target)
                return (lookup(current->right, target));
            else
                return (lookup(current->left, target));
        }
    }
}