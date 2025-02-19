//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Zachary Huff
// Version     : 1.0
// Copyright   : Copyright � 2017 SNHU COCE
// Description : Binary Search Tree used to sort bids
//============================================================================

//I didn't implement the a few of the methods because it didn't use them in the main
//method and also there was no instruction to do so besides the comments 

#include <algorithm>
#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// Internal structure for tree node
//I didn't understand why I was recieving this error as well
//I would have reached out but I am very late in getting this done

struct Node {
    Bid bid;
    Node* left;
    Node* right;
    Node* parent;

    // create the key for the given bid
    unsigned int key = atoi(node->bid.bidId.c_str());
    Node* node = &(nodes.at(key));

    // if entry found for the key
    if (node != nullptr && node->key != UINT_MAX
        && node->bid.bidId.compare(bidId) == 0) {
        return node->bid;
    }

    // if no entry found for the key
    if (node == nullptr || node->key == UINT_MAX) {
        return bid;
    }

    while (node != nullptr) {
        // if the current node matches, return it
        if (node->key != UINT_MAX && node->bid.bidId.compare(bidId) == 0) {
            return node->bid;
        }
        node = node->next;
    }

};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void PreOrder();
    void PostOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
    Node* SearchNode(Node* node, string bidId);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // FixMe (1): initialize housekeeping variables
    //root is equal to nullptr
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // FixMe (2): In order root
    // call inOrder fuction and pass root 
    this->inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    // FixMe (3): Post order root
    // postOrder root
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    // FixMe (4): Pre order root
    // preOrder root
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    // FIXME (5) Implement inserting a bid into the tree
    // if root equarl to null ptr
      // root is equal to new node bid
    // else
      // add Node root and bid
    if (root == nullptr) {
        root = new Node;
        root->bid = bid;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
    }
    else {
        addNode(root, bid);
    }
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    // FIXME (6) Implement removing a bid from the tree
    // remove node root bidID
    Node* nodePtr = SearchNode(root, bidId);
    if (nodePtr == nullptr) {
        return;
    }
    else {
        nodePtr->parent->left = nodePtr->left;
        nodePtr->parent->right = nodePtr->right;
        nodePtr->left->parent = nodePtr->parent;
        nodePtr->right->parent = nodePtr->parent;
        delete nodePtr;
    }
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    // FIXME (7) Implement searching the tree for a bid
    // set current node equal to root

    // keep looping downwards until bottom reached or matching bidId found
        // if match found, return current bid

        // if bid is smaller than current node then traverse left
        // else larger so traverse right

    Node* current = root;
    while (current != nullptr) {
        if (current->bid.bidId.compare(bidId) == 0) {
            return current->bid;
        }
        if (bidId.compare(current->bid.bidId) < 0) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    Bid bid;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    // FIXME (8) Implement inserting a bid into the tree
    // if node is larger then add to left
        // if no left node
            // this node becomes left
        // else recurse down the left node
    // else
        // if no right node
            // this node becomes right
        //else
            // recurse down the left node
    int key = atoi(node->bid.bidId.c_str());
    int nextKey = atoi(bid.bidId.c_str());

    if (nextKey > key) {
        if (node->right == nullptr) {
            node->right = new Node;
            node->right->bid = bid;
            node->right->right = nullptr;
            node->right->left = nullptr;
            node->right->parent = node;
        }
        else {
            addNode(node->right, bid);
        }
    }
    else {
        if (node->left == nullptr) {
            node->left = new Node;
            node->left->bid = bid;
            node->left->right = nullptr;
            node->left->left = nullptr;
            node->left->parent = node;
        }
        else {
            addNode(node->left, bid);
        }
    }
}
void BinarySearchTree::inOrder(Node* node) {
    // FixMe (9): Pre order root
    //if node is not equal to null ptr
    //InOrder not left
    //output bidID, title, amount, fund
    //InOder right
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->bid.bidId << ": "
            << node->bid.title << " | "
            << node->bid.amount << " | "
            << node->bid.fund << endl;
        inOrder(node->right);
    }
}
void BinarySearchTree::postOrder(Node* node) {
    // FixMe (10): Pre order root
    //if node is not equal to null ptr
    //postOrder left
    //postOrder right
    //output bidID, title, amount, fund
}

void BinarySearchTree::preOrder(Node* node) {
    // FixMe (11): Pre order root
    //if node is not equal to null ptr
    //output bidID, title, amount, fund
    //postOrder left
    //postOrder right      
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
        << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bst->Insert(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {


    //https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/
    //is the issue I am getting with this code still, couldn't solve by time of turn in

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bst = new BinarySearchTree();

            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bst);

            //cout << bst->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            }
            else {
                cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 4:
            bst->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
