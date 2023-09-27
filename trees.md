//Introduction to tree:

//Binary Tree: A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.

//Binary Tree Representation in C:

//A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of root is NULL.

//A Tree node contains following parts.
//1. Data
//2. Pointer to left child
//3. Pointer to right child

//Leaf Node: The node which does not have any child node is called the leaf node.
//Depth of a node: The distance of a node from the root node is called its depth.
//Height of a node: The height of a node is the number of edges on the longest path between that node and a leaf.
//Height of a Tree: The height of a tree is the height of its root node.

//In C++, we can represent a tree node using structures. Below is an example of a tree node with an integer data.

//struct Node
//{
//  int data;
//  Node* left;
//  Node* right;
//};

//Binary Tree and its Properties
//The maximum number of nodes at level ‘l’ of a binary tree is 2l-1.
//Maximum number of nodes in a binary tree of height ‘h’ is 2h – 1.
//In a Binary Tree with N nodes, minimum possible height or minimum number of levels is  Log2(N+1)
//A Binary Tree with L leaves has at least   Log2L + 1   levels
//In Binary tree where every node has 0 or 2 children, number of leaf nodes is always one more than nodes with two children.
//In a Full Binary, number of leaf nodes is number of internal nodes plus 1
//A Binary Tree with N nodes has N-1 branches.

//Application of Trees:
//1. Manipulate hierarchical data.
//2. Make information easy to search (see tree traversal).
//3. Manipulate sorted lists of data.
//4. As a workflow for compositing digital images for visual effects.
//5. Router algorithms
//6. Form of a multi-stage decision-making (see business chess).
//7. Compilers
//8. File system
//9. Storage of objects in Object Oriented Programming Language.
//10. Networking : Routing algorithm, Broadcast algorithm
//11. AI : Game Playing
//12. XML parsers use tree algorithms.
//13. Syntax Tree: Used in Compilers
//14. Document Object Model(DOM): Used in browsers to make interactive web pages.
//15. Expression Evaluation: Binary Expression Tree
//16. Huffman Coding Tree (Min Heap)
//17. Process management