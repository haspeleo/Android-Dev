/* 
 * http://cslibrary.stanford.edu/110/BinaryTrees.html
 * http://math.hws.edu/eck/cs225/s03/binary_trees/
 * http://math.hws.edu/javanotes/index.html //JAVA
 * http://www.cmcrossroads.com/bradapp/ftp/src/libs/C++/AvlTrees.html //AVL Trees
 * http://fringe.davesource.com/Fringe/Computers/Languages/CC/Tutorial/tutorial2.html#intro
 * http://algs4.cs.princeton.edu/home/
 */

#include <cstdlib>
#include<iostream>
#include"BinaryTree.h"

using namespace std;

int main(int argc, char** argv) {
    struct node* root;
    BinaryTree T = BinaryTree(root);
   
    insertNode(T, 5);

    cout <<"lookup is fast for Binay trees O(log(N)):  "<<endl;
    int data = 6;
    int searchFor = T.lookup(T, data);
    if(searchFor !=  -1)
        cout <<"Found: "<<data<<"; Exists and the value is: "<<searchFor<<endl;
    else
        cout <<"Not Found : "<<data<<"; does NOT exists "<<endl;
    return 0;
}

