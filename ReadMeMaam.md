# Wizard-of-Oz-Project-and-Final-Examination-in-DSA
Joshua A. Ecat, Jhercy Narito, Humpry Andrei Camacho from BCSC-2A
# Project Overview
A Wizard of Oz themed C++ code that includes Binary Tree, Binary Search Tree &amp; Heaps. Featuring four characters from The Wizard of Oz, Scarecrow, Tin-man, Cowardly Lion and The Wicked Witch of the West. Relive Dorothy's journey throughout Oz with this code.
# How to Run the Code
You can run this code in any IDE or Code Editor Software, we decided to use Codeblocks for this code. After creating a C++ File, type or paste this code in it and click the Build and Run button. A terminal will pop-up and the output would be displayed, from then on you can immerse yourself with the fun Wizard of Oz themed Binary Tree, Binary Search Tree and Heaps calculator. 
# Description of Each Functionality
Main Classes 
The program is organized into three main classes, each representing a different data structure: BinaryTree, BinarySearchTree, and Heap. Each class has specific functions to perform operations on these data structures:

1. BinaryTree
This class represents a basic binary tree, where each node has at most two child nodes (left and right).
~ Key Functions
• insert(int val)
Adds a new node with the value val to the tree.
• inorderTraversal() - Visits nodes in the order: left subtree → current node → right subtree. Outputs values in ascending order.
• preorderTraversal() - Visits nodes in the order: current node → left subtree → right subtree.
• postorderTraversal() - Visits nodes in the order: left subtree → right subtree → current node.
• search(int val) • Searches for a node with the value val and returns true if it exists, false otherwise.
• deleteNode(int val) - Removes a node with the value val from the tree.
• display() - Visually represents the tree structure.

2. BinarySearchTree (BST)
This class is a specialized version of the BinaryTree. In a BST:
~ All values in the left subtree are smaller than the current node.
~ All values in the right subtree are larger.
~ It inherits all the functions from BinaryTree, so it has the same operations. The key difference is how the tree ensures the ordering of values.

3. Heap
This class implements a heap, which is a tree-like structure where:
• A min-heap has the smallest value at the root.
• A max-heap has the largest value at the root.
~ Key Functions
• insert(int val) - Adds a new value val to the heap.
• display() - Displays all the elements of the heap in an array-like format.
• deleteNode(int val) - Removes a specific value from the heap.
• heapify() - Rearranges the heap to maintain its properties after any change.
• changeHeapType() - Switches between a min-heap and max-heap.
• maxToMin() - Converts the heap into a sorted ascending list.
• minToMax() - Converts the heap into a sorted descending list.

Additional Features
~ Menus (scarecrowMenu, tinManMenu, cowardlyLionMenu) - These provide a user-friendly way to interact with the three data structures:
• The Scarecrow menu operates on the BinaryTree.
• The Tin Man menu operates on the BinarySearchTree.
• The Cowardly Lion menu operates on the Heap.
~ Typewriter Effect (typeEffect) - Simulates text being typed out for better user engagement.
~ Main Menu - Lets the user choose which data structure to work with or exit the program.
