# Inventory System Report

## **a. Description of the Inventory Item ADT**

The **InventoryItem ADT** represents an item in the store's inventory with the following attributes:

- **ItemID**: A unique identifier for the item (integer).
- **ItemName**: The name of the item (string).
- **Quantity**: The stock quantity of the item (integer).
- **Price**: The price per unit of the item (float).

Methods for this ADT include:
- **display()**: Prints item details.
- **Constructor**: Initializes item attributes.

---

## **b. Strategy for Implementing Arrays, Sparse Representations, and Operations**

- **Arrays**: We use a **vector** (dynamic array) to store the inventory items. Each item is represented as an instance of `InventoryItem`.
- **Sparse Representation**: Items with low quantities (e.g., `<10`) are stored in a **sparse matrix** (unordered map), which only holds the items that are rarely restocked.
  
**Operations**:
- **Insert**: Add items to the vector.
- **Delete**: Remove items based on `ItemID`.
- **Search**: Search items by `ItemID` or `ItemName`.
- **Row-Major/Column-Major Ordering**: Organizes price and quantity into tables.

---

## **c. Approach to Complexity Analysis for Each Function**

1. **Insertion**:  
   - **Time Complexity**: O(1) (Append operation in a vector).
   
2. **Deletion**:  
   - **Time Complexity**: O(n) (Search and erase operation).
   
3. **Search**:  
   - **Time Complexity**: O(n) (Linear search through items).
   
4. **Row-Major/Column-Major Ordering**:  
   - **Time Complexity**: O(n) (Iterate through the items to form the table).
   
5. **Sparse Storage**:  
   - **Time Complexity**: O(n) (Filter items based on quantity).

---

## **d. Analysis of the System’s Efficiency and Functionality**

### **Efficiency**:
- **Time Complexity**: Most operations (insert, delete, search) are linear (O(n)), which is acceptable for moderately sized inventories.
- **Space Complexity**: O(n) for storing inventory items and sparse data.

### **Functionality**:
The system efficiently handles:
- **Inventory management**: Supports adding, deleting, and searching items.
- **Data organization**: Organizes data in both row-major and column-major orders.
- **Space optimization**: Sparse storage ensures optimal space usage for items with low stock.

---

## **Conclusion**

The Inventory System efficiently handles stock management, ensuring that operations like insertion, deletion, and search are straightforward. The use of sparse storage optimizes memory for items with low stock levels, and both row-major and column-major data ordering allow for flexible data representation. The complexity analysis shows that the system is capable of managing moderately sized inventories with an acceptable level of performance.
