#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;
/*Joshua A. Ecat, Jhercy Narito, Humpry Andrei Camacho | BSCS-2A
Final Project and Exam in Data Structures & Algorithms*/

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define GRAY "\033[37m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BROWN "\033[38;5;94m"
#define BOLD "\033[1m"

class BinaryTree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    void inorderTraversal() {
        inorderRec(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorderRec(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorderRec(root);
        cout << endl;
    }

    bool search(int val) {
        return searchRec(root, val);
    }

    void deleteNode(int val) {
        root = deleteRec(root, val);
    }

    void display() {
        displayRec(root, 0);
    }

protected:
    Node* root;

private:
    Node* insertRec(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insertRec(node->left, val);
        else node->right = insertRec(node->right, val);
        return node;
    }

    void inorderRec(Node* node) {
        if (node) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node* node) {
        if (node) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }

    bool searchRec(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        return val < node->data ? searchRec(node->left, val) : searchRec(node->right, val);
    }

    Node* deleteRec(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = deleteRec(node->left, val);
        else if (val > node->data) node->right = deleteRec(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    void displayRec(Node* node, int space) {
        if (node == nullptr) return;

        space += 10;

        displayRec(node->right, space);

        cout << endl;
        for (int i = 10; i < space; i++) cout << " ";
        cout << node->data << endl;

        displayRec(node->left, space);
    }
};

class BinarySearchTree : public BinaryTree {
public:
    void insert(int val) {
        BinaryTree::insert(val);
    }

    bool search(int val) {
        return BinaryTree::search(val);
    }

    void deleteNode(int val) {
        BinaryTree::deleteNode(val);
    }

    void display() {
        BinaryTree::display();
    }
};

class Heap {
public:
    Heap(bool isMin = true) : isMinHeap(isMin) {}

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void display() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }

    void deleteNode(int val) {
        auto it = find(heap.begin(), heap.end(), val);
        if (it != heap.end()) {
            swap(*it, heap.back());
            heap.pop_back();
            heapify();
        }
    }

    void heapify() {
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if ((isMinHeap && heap[index] < heap[parent]) || (!isMinHeap && heap[index] > heap[parent])) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1, right = 2 * index + 2, target = index;

        if (left < heap.size() && ((isMinHeap && heap[left] < heap[target]) || (!isMinHeap && heap[left] > heap[target]))) {
            target = left;
        }

        if (right < heap.size() && ((isMinHeap && heap[right] < heap[target]) || (!isMinHeap && heap[right] > heap[target]))) {
            target = right;
        }

        if (target != index) {
            swap(heap[index], heap[target]);
            heapifyDown(target);
        }
    }

    void changeHeapType() {
        isMinHeap = !isMinHeap;
        heapify();
    }

    void maxToMin() {
        vector<int> sortedHeap = heap;
        sort(sortedHeap.begin(), sortedHeap.end());
        cout << "Max to Min: ";
        for (int value : sortedHeap) {
            cout << value << " ";
        }
        cout << endl;
    }

    void minToMax() {
        vector<int> sortedHeap = heap;
        sort(sortedHeap.rbegin(), sortedHeap.rend());
        cout << "Min to Max: ";
        for (int value : sortedHeap) {
            cout << value << " ";
        }
        cout << endl;
    }

private:
    vector<int> heap;
    bool isMinHeap;
};

void typeEffect(const string& text, int speed = 50) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

void scarecrowMenu(BinaryTree& tree) {
    int choice, val;
    while (true) {
        system("cls");
        cout << BROWN << "\n------------------- SCARECROW'S BINARY HAY MENU -------------------" << RESET << endl;
        cout << BROWN << "1. Give him a straw" << RESET << endl;
        cout << BROWN << "2. Inorder Traversal" << RESET << endl;
        cout << BROWN << "3. Preorder Traversal" << RESET << endl;
        cout << BROWN << "4. Postorder Traversal" << RESET << endl;
        cout << BROWN << "5. Search for a straw" << RESET << endl;
        cout << BROWN << "6. Remove a straw" << RESET << endl;
        cout << BROWN << "7. Display Hay" << RESET << endl;
        cout << YELLOW << "8. Go back to the Yellow Brick Road" << RESET << endl;
        cout << YELLOW << "-------------------------------------------------" << RESET << endl;

        cout << BOLD << "Choose an option: " << RESET;
        cin >> choice;
        if (choice == 8) break;

        switch (choice) {
            case 1:
                cout << "Enter straw value to insert: ";
                cin >> val;
                cout << "Scarecrow has placed the straws in him. What a hay!" << endl;
                tree.insert(val);
                break;
            case 2:
                cout << "The Scarecrow is keeping a secrets in an orderly fashion..." << endl;
                tree.inorderTraversal();
                break;
            case 3:
                cout << "The Scarecrow's curiosity made him explore his hay, exploring every strand of straw..." << endl;
                tree.preorderTraversal();
                break;
            case 4:
                cout << "The Scarecrow is tracing the hay backwards, finding straws and... a horse's hair?..." << endl;
                tree.postorderTraversal();
                break;
            case 5:
                cout << "Enter straw value to search: ";
                cin >> val;
                cout << (tree.search(val) ? "The straws you placed earlier has been found!" : "Oh no, those straws that you've been looking for does not exist.") << endl;
                break;
            case 6:
                cout << "Enter straw value to burn: ";
                cin >> val;
                cout << "The Scarecrow has been burnt. Scarecrow doesn't look that baggy anymore..." << endl;
                tree.deleteNode(val);
                break;
            case 7:
                cout << "The Scarecrow is displaying the full hay!..." << endl;
                tree.display();
                break;
            default:
                cout << RED << "Oh no! The wicked witch of the west distracted you with her spells!" << RESET << endl;
        }

        cout << YELLOW << "Proceed? (Press any key to continue)" << RESET << endl;
        cin.ignore();
        cin.get();
    }
}

void tinManMenu(BinarySearchTree& bst) {
    int choice, val;
    while (true) {
        system("cls");
        cout << BLUE << "\n------------------- TIN MAN'S BST MENU -------------------" << RESET << endl;
        cout << BLUE << "1. Insert a copper" << RESET << endl;
        cout << BLUE << "2. Inorder Traversal" << RESET << endl;
        cout << BLUE << "3. Preorder Traversal" << RESET << endl;
        cout << BLUE << "4. Postorder Traversal" << RESET << endl;
        cout << BLUE << "5. Search for a copper" << RESET << endl;
        cout << BLUE << "6. Delete a copper" << RESET << endl;
        cout << BLUE << "7. Display the coppers" << RESET << endl;
        cout << YELLOW << "8. Go back to the Yellow Brick Road" << RESET << endl;
        cout << YELLOW << "-------------------------------------------------" << RESET << endl;

        cout << BOLD << "Choose an option: " << RESET;
        cin >> choice;
        if (choice == 8) break;

        switch (choice) {
            case 1:
                cout << "Enter the durability of the copper you're about to insert: ";
                cin >> val;
                cout << "The Tin Man has placed the copper! It is quiet strong!..." << endl;
                bst.insert(val);
                break;
            case 2:
                cout << "The Tin Man had carefully placed the copper like bricks in order of their strength!..." << endl;
                bst.inorderTraversal();
                break;
            case 3:
                cout << "The Tin Man is chiseling through the placed coppers with his axe..." << endl;
                bst.preorderTraversal();
                break;
            case 4:
                cout << "The Tin Man is searching for every copper, tracing his steps in reverse..." << endl;
                bst.postorderTraversal();
                break;
            case 5:
                cout << "Enter durability of copper to search: ";
                cin >> val;
                cout << (bst.search(val) ? "It has been found!..." : "Looks like there's not a copper with that durability...") << endl;
                break;
            case 6:
                cout << "Enter copper durability to delete: ";
                cin >> val;
                cout << "The Tin Man is carefully removing a copper with precision..." << endl;
                bst.deleteNode(val);
                break;
            case 7:
                cout << "The Tin Man is proudly displaying the coppers he placed brick by brick..." << endl;
                bst.display();
                break;
            default:
                cout << RED << "Oh no! The wicked witch of the west distracted you with her spells!" << RESET << endl;
        }

        cout << YELLOW << "Proceed? (Press any key to continue)" << RESET << endl;
        cin.ignore();
        cin.get();
    }
}

void cowardlyLionMenu(Heap& heap) {
    int choice, val;
    while (true) {
        system("cls");
        cout << RED << "\n------------------- COWARDLY LION'S BRAVERY MENU -------------------" << RESET << endl;
        cout << RED << "1. Give the Lion Encouragement" << RESET << endl;
        cout << RED << "2. Display Braveness" << RESET << endl;
        cout << RED << "3. Discourage Him" << RESET << endl;
        cout << RED << "4. Heapify" << RESET << endl;
        cout << RED << "5. Min-Heap to Max-Heap" << RESET << endl;
        cout << RED << "6. Max-Heap to Min-Heap" << RESET << endl;
        cout << YELLOW << "7. Go back to the Yellow Brick Road" << RESET << endl;
        cout << YELLOW << "-------------------------------------------------" << RESET << endl;

        cout << BOLD << "Choose an option: " << RESET;
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
            case 1:
                cout << "Enter amount of encouragement: ";
                cin >> val;
                cout << "The Cowardly Lion is bravely adding a pinch of courage to himself!..." << endl;
                heap.insert(val);
                break;
            case 2:
                cout << "The Cowardly Lion is showing off his courage!...." << endl;
                heap.display();
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                cout << "The Cowardly Lion is hesitantly removing a pinch of courage from the heap. Slightly showing his cowardness..." << endl;
                heap.deleteNode(val);
                break;
            case 4:
                cout << "The Cowardly Lion is facing his fears and switching his courage strategies!..." << endl;
                heap.changeHeapType();
                break;
            case 5:
                cout << "The Cowardly Lion is courageously shrugging his cowardness and being full of Bravery!..." << endl;
                heap.maxToMin();
                break;
            case 6:
                cout << "Oh my! Looks like the Cowardly Lion Bravery is being drained..." << endl;
                heap.minToMax();
                break;
            default:
                cout << RED << "Oh no! The wicked witch of the west distracted you with her spells!" << RESET << endl;
        }

        cout << YELLOW << "Proceed? (Press any key to continue)" << RESET << endl;
        cin.ignore();
        cin.get();
    }
}

int main() {
    BinaryTree tree;
    BinarySearchTree bst;
    Heap heap(true);

    int choice;
    while (true) {
        system("cls");
        typeEffect("Your house has been carried by a tornado and it brought you Over The Rainbow...", 50);
        cout << GREEN << "\n-------------------- Welcome to Ozland ! --------------------" << RESET << endl;
        typeEffect("Choose who to enjoy your journey with:\n", 50);
        cout << BROWN << "1. Scarecrow's Binary Hay" << RESET << endl;
        cout << BLUE << "2. Tin Man's BST" << RESET << endl;
        cout << RED << "3. Cowardly Lion's Bravery" << RESET << endl;
        cout << YELLOW << "4. Go Home" << RESET << endl;
        cout << YELLOW << "-------------------------------------------------" << RESET << endl;

        cout << BOLD << "Choose an option: " << RESET;
        cin >> choice;

        switch (choice) {
            case 1:
                scarecrowMenu(tree);
                break;
            case 2:
                tinManMenu(bst);
                break;
            case 3:
                cowardlyLionMenu(heap);
                break;
            case 4:
                cout << YELLOW << "As you tapped the heels of the " << RESET;
                cout << RED << "Ruby Red Slippers. " << RESET;
                cout << YELLOW << "You began to wake up in bed with your family around you." << RESET << endl;
                cout << YELLOW << "Goodbye! You've returned to Kansas because there is No Place Like Home!" << RESET << endl;
                return 0;
            default:
                cout << RED << "Oh no! The wicked witch of the west distracted you with her spells!" << RESET << endl;
        }
    }
}



    
