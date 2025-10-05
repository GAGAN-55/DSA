# Inventory System for a Grocery Store - Report

## a. Description of the Inventory Item ADT

The **Inventory Item ADT** represents the basic attributes and methods required for managing products in a grocery store:

### Attributes:
- **ItemID**: Integer, unique identifier for the item.
- **ItemName**: String, name of the item.
- **Quantity**: Integer, current stock quantity.
- **Price**: Float, price per unit of the item.

### Methods:
- **insertItem()**: Inserts a new item into the inventory.
- **deleteItem()**: Deletes an item based on its `ItemID`.
- **searchItem()**: Searches for an item by `ItemID` and retrieves its details.
- **displayAll()**: Displays all items in the inventory.

## b. Strategy for Implementing Arrays, Sparse Representations, and Operations

- **Arrays**: A fixed-size array of size 100 is used to store inventory items. Each item has attributes such as `ItemID`, `ItemName`, `Quantity`, and `Price`.
  
- **Sparse Representation**: In this implementation, sparse representation is not directly needed because the inventory array is relatively small. However, for a large inventory, sparse storage could be useful, where a dynamic array or hash map could be implemented to store items only when they are restocked.

- **Operations**:
  - **Insert**: Adds an item to the inventory at the next available index in the array. 
  - **Delete**: Finds the item by `ItemID` and removes it by shifting the remaining items in the array.
  - **Search**: Iterates over the array to find and display the item with the specified `ItemID`.
  - **Display**: Lists all items in the inventory.

## c. Approach to Complexity Analysis

- **Time Complexity**:
  - **Insert**: O(1), as items are added sequentially at the next available index.
  - **Delete**: O(n), where `n` is the number of items, because it may require shifting all items after the deleted one.
  - **Search**: O(n), as it requires a linear search through the array.
  - **Display**: O(n), as it iterates over all items to display them.

- **Space Complexity**:
  - O(1) for the operations themselves, but the array itself uses O(n) space where `n` is the number of items in the inventory.

## d. Analysis of the System’s Efficiency and Functionality

### Efficiency:
- **Space Efficiency**: The use of a fixed-size array makes it efficient for small inventories but could be inefficient for larger inventories due to wasted space or frequent resizing.
- **Time Efficiency**: The `insertItem()` operation is efficient, but both `deleteItem()` and `searchItem()` are linear in complexity, which could be a bottleneck for large datasets.

### Functionality:
- The system supports basic inventory operations such as inserting, deleting, searching, and displaying items.
- For small-scale use, the system is efficient and functional. For large inventories, performance could degrade due to the linear search and delete operations.

### Improvements:
- For larger inventories, **dynamic arrays** or **hash maps** could be implemented to optimize search and delete operations.
- A **sparse matrix** could be utilized if most items are infrequently restocked, saving space for rarely used items.

