# BinarySearchTree

# Binary Search Tree for Managing Municipal Auction Bids

This program explores binary search tree algorithms for managing auction bids data extracted from a municipal government dataset. The application is built in C++ and offers a console interface to load, search, display, and manage bid data.

## **Project Overview**
The dataset includes bid records stored in two comma-separated files (CSV):
- `eBid_Monthly_Sales.csv` — containing 17,937 bids.
- `eBid_Monthly_Sales_Dec_2016.csv` — containing 179 bids.

The focus of this project is to implement a **binary search tree** (BST) for efficient insertion, deletion, and search operations on the bid records. A starter console application is provided, with the logic for BST operations partially implemented. The primary task is to complete the necessary methods for the BST.

---

## **Functionality**
The application provides the following interactive menu options when run:


### **Available Operations**
1. **Load Bids:** Load bids from a CSV file into the binary search tree.
2. **Display All Bids:** Display all loaded bids in sorted order.
3. **Find Bid:** Search for a specific bid using its unique bid ID.
4. **Remove Bid:** Remove a bid from the tree using its bid ID.
5. **Exit:** Close the program.

---

## **Binary Search Tree Implementation**
The program's core logic is contained in the **`BinarySearchTree.cpp`** file. You'll implement the following methods to complete the BST functionality:


Project Setup
Create the Project:
Start by creating a new C++ project:

Project type: Hello World C++ Project
Project name: BinarySearchTree
Click Finish to generate the basic project structure.
Copy Starter Files:
Download the starter program files and copy them into the src directory of the project, replacing the auto-generated file.
Note: Refresh the project to ensure all files are correctly added.

Build and Run:
After implementing the necessary methods, build the project and run the program to test the different menu options.

Menu:

Load Bids
Display All Bids
Find Bid
Remove Bid
Exit Enter choice:


### **Public API**
```cpp
class BinarySearchTree {
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};


### Example output

Menu:
   1. Load Bids
   2. Display All Bids
   3. Find Bid
   4. Remove Bid
   9. Exit
Enter choice: 1

Loading CSV file 'eBid_Monthly_Sales.csv'...
[...loading messages...]

Successfully loaded 17937 bids.

Enter choice: 2

Displaying all bids:
------------------------------------
Bid ID: 98123 | Title: Property Auction 1 | Amount: $450,000
Bid ID: 76541 | Title: Property Auction 2 | Amount: $350,000
[...sorted bids...]

Enter choice: 3
Enter Bid ID to search: 98123

Bid found: Property Auction 1 - $450,000

Enter choice: 4
Enter Bid ID to remove: 76541

Bid successfully removed.

Enter choice: 9
Exiting program...


### Technologies Used
Language: C++
Development Environment: Any C++ IDE or compiler (e.g., Eclipse, Visual Studio, or GCC).
Data Format: CSV files


### Further Improvements
Implement error handling for file loading and input validation.
Optimize tree balancing (consider AVL trees or red-black trees for balanced search times).
Extend the application to include additional bid metrics or visualization options.


Author
Zach Huff

Feel free to contribute to this project or suggest improvements!

