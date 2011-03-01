
#ifndef BINARYTREE_H
#define	BINARYTREE_H

struct node {
        int data;
        struct node* left;
        struct node* right;
    };
 

class BinaryTree {
public:
    BinaryTree(struct node* root);
    BinaryTree(const BinaryTree& orig);
    virtual ~BinaryTree();

    struct node * allocateNode(int data);
    int lookup(BinaryTree &T, int target);
    void insertNode(BinaryTree &T, int data);
    
private:
    struct node* Tree;
    
};

#endif	/* BINARYTREE_H */

