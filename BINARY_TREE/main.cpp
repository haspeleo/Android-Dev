/* 
 * http://cslibrary.stanford.edu/110/BinaryTrees.html
 * http://math.hws.edu/eck/cs225/s03/binary_trees/
 * http://math.hws.edu/javanotes/index.html //JAVA
 * http://www.cmcrossroads.com/bradapp/ftp/src/libs/C++/AvlTrees.html //AVL Trees
 * http://fringe.davesource.com/Fringe/Computers/Languages/CC/Tutorial/tutorial2.html#intro
 * http://algs4.cs.princeton.edu/home/
 * http://codepad.org/ //online-compiler
 * http://www.botskool.com/user/register?destination=online-compiler //botskool compiler
 */

#include <cstdlib>
#include <iostream>


using namespace std;


/*node structure */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/*Helper functions*/

struct node * allocateNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    //struct node* newNode = new(struct(node); //allocate with new instead of sizeof
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
/*tree manipulating functions */

struct node* insertNode(struct node*& node, int data) {

    struct node* newNode = allocateNode(data);

    if (node == NULL) {
        return newNode;
    } else {

        if (data < node->data)
            node->left = insertNode(node->left, data);
        else
            node->right = insertNode(node->right, data);
    }
    return node;
}

int lookup(struct node* node, int target) { //could be written using while loop
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

void printTree(struct node* node) {
    if(node == NULL) {
        return; //cout <<"Empty tree !!"<<endl;
    }
    else {
        printTree(node->left);
        cout <<node->data<<" ";
        printTree(node->right);
    }
}
void printTreePostOrder(struct node* node) {
    if(node == NULL) {
        return; //cout <<"Empty tree !!"<<endl;
    }
    else {
        printTree(node->left);        
        printTree(node->right);
        cout <<node->data<<" ";
    }    
}
void printTreePreOrder(struct node* node) {
    if(node == NULL) {
        return; //cout <<"Empty tree !!"<<endl;
    }
    else {
        printTree(node->right);
        printTree(node->left);
        cout <<node->data<<" ";
    }
}

int minValue(struct node* node) {
    struct node* current = node;
    while(current->left) {
        current = current->left;
    }
    return current->data;
}

int maxValue(struct node* node) {
    struct node* current = node;
    while(current->right) {
        current = current->right;
    }
    cout <<" - - - "<<endl;
    return current->data;
}

bool hasPathSum(struct node* node, int sum) {
    int subSum = 0;
    if(node == NULL) {
        return (sum == 0);
    }
    else {
        struct node* current = node;
        subSum = sum - current->data;
        return (hasPathSum(current->left, subSum)
                || hasPathSum(current->right, subSum));
    }
}

/*helper functions for printing the tree paths*/
void printArray(int ints[], int len) {
    for(int i = 0; i < len; i++) {
        cout <<ints[i]<<" ";
    }
    cout <<" "<<endl;
}

void printPathsRecursively(struct node* node, int path[], int pathLen) {
    if(node == NULL) return;
    //append this node to the path array
    path[pathLen] = node->data;
    pathLen ++;
    if(node->left == NULL && node->right == NULL) {
        printArray(path, pathLen);
    }
    else {
        printPathsRecursively(node->left, path, pathLen);
        printPathsRecursively(node->right, path, pathLen);
    }
}
void printTreePaths(struct node * node) {
    int path[1000];
    printPathsRecursively(node, path, 0);
}

void mirror(struct node* node) {
    if (node == NULL) return;
    else {
        struct node * temp = NULL;

        mirror(node->left);
        mirror(node->right);

        //swap(node->left, node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

}


/*===========================================================================*/
/*                                 MAIN PROGRAM                              */
/*===========================================================================*/

int main(int argc, char** argv) {
    
    struct node* tree = NULL;   
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 9);
    tree = insertNode(tree, 1);
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 12);
    tree = insertNode(tree, 8);
    tree = insertNode(tree, 17);
    tree = insertNode(tree, 2);
    
    printTree(tree);
    printTreePreOrder(tree);
    printTreePostOrder(tree);

    cout<<">> Max value of the tree: "<<maxValue(tree)<<endl;

    cout<<">> Min value of the tree: "<<minValue(tree)<<endl;
    
    cout <<">> lookup is fast for Binay trees O(log(N)):  "<<endl;
    int data = 3;
    int searchFor = lookup(tree, data);

    if(searchFor !=  -1)
        cout <<"Found: "<<data<<"; Exists and the value is: "<<searchFor<<endl;
    else
        cout <<"Not Found : "<<data<<"; does NOT exists "<<endl;

    cout <<">> Looking for paths having sum nodes equal to given sum" <<endl;
    int sum = 2;
    if(hasPathSum(tree, sum)) {
        cout <<"Path having node's sum = "<<sum<<" Exits"<<endl;
    }
    else {
        cout <<"No Path having node's sum =  "<<sum<<endl;
    }
    
    cout <<">> Printing all paths in a tree"<<endl;

    printTreePaths(tree);
    cout <<"Mirror of a tree"<<endl;
    printTreePaths(tree);
    mirror(tree);
    printTreePaths(tree);
    return 0;
}

