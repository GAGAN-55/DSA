# Online Food Ordering and Delivery Management System - Report

## a. Description of the System ADT

The **Online Food Ordering and Delivery Management System ADT** represents the structure and operations required for efficiently managing a digital food ordering platform.  
It simulates how restaurants or cloud kitchens handle menus, order flows, and customer histories using dynamic data structures.

### Core Components and Attributes:
1. **Menu Management (Linked List)**  
   - Manages food items dynamically with attributes like name and price.  
   - Supports insert, delete, and display operations.  

2. **Order Queue (Circular Queue)**  
   - Handles incoming customer orders in a **First In, First Out (FIFO)** manner.  
   - Ensures proper sequence of food preparation and delivery.  

3. **Customer Order History (Stack)**  
   - Maintains a customer’s recent orders using **Last In, First Out (LIFO)** logic.  
   - Allows viewing or undoing the latest order.  

4. **Combo Deals (Polynomial Representation)**  
   - Represents promotional combo offers using polynomial expressions.  
   - Each term in the polynomial denotes an item and its quantity.

---

## b. Strategy for Implementing Data Structures and Operations

### 1. **Linked List for Menu Management**
- Used to store menu items dynamically.
- Items can be added or removed at runtime without needing a fixed array size.
- Supports insertion at the tail, deletion by name, and full menu display.

### 2. **Circular Queue for Order Flow**
- Used to manage the sequence of customer orders.
- Prevents overflow and underflow conditions by wrapping around the array.
- Orders are enqueued when placed and dequeued when processed.

### 3. **Stack for Customer Order History**
- Used to record the most recent orders for each customer.
- Allows easy access to the latest order for correction or review.
- Supports push (add), pop (remove), and peek (view) operations.

### 4. **Linked List for Combo Deals (Polynomial Representation)**
- Each combo deal is represented as a polynomial, e.g., `2x² + x + 3`.
- Coefficients represent item quantities, and exponents represent item types.
- Supports combining and displaying combo offers.

---

## c. Approach to Complexity Analysis

### **Time Complexity:**

| Operation | Data Structure | Time Complexity | Description |
|------------|----------------|----------------|--------------|
| Insert Item | Linked List | O(n) | Traverse to insert at end of list |
| Delete Item | Linked List | O(n) | Search item and remove node |
| Display Menu | Linked List | O(n) | Traverse and print all items |
| Enqueue Order | Circular Queue | O(1) | Insert at rear |
| Dequeue Order | Circular Queue | O(1) | Remove from front |
| Display Queue | Circular Queue | O(n) | Print all queued orders |
| Push Order | Stack | O(1) | Add order to top |
| Pop Order | Stack | O(1) | Remove top order |
| Peek Order | Stack | O(1) | Access top order |
| Add Combo Term | Linked List | O(n) | Traverse to insert term |
| Display Combo | Linked List | O(n) | Print polynomial terms |

### **Space Complexity:**
- **Menu Management**: O(n) — one node per menu item.  
- **Order Queue**: O(m) — circular array of size `m`.  
- **Order History (Stack)**: O(k) — stack grows with recent orders.  
- **Combo Deals**: O(t) — one node per polynomial term.

---

## d. Analysis of the System’s Efficiency and Functionality

### **Efficiency:**
- **Dynamic Management**: The use of linked lists allows the system to adjust to changing menu sizes without wasted memory.  
- **Fast Order Handling**: Circular queues ensure continuous order processing with no need for shifting data.  
- **Recent Order Tracking**: Stacks efficiently manage customer order histories.  
- **Combo Representation**: Polynomials simplify the handling of multi-item combos and promotional offers.

### **Functionality:**
- Provides end-to-end workflow simulation of a real-world food ordering system.  
- Supports all core operations: adding menu items, placing and processing orders, tracking order history, and managing combo offers.  
- Easily extendable for additional features like premium order prioritization or file storage.

### **Improvements:**
- Implement **priority queues** for premium or express orders.  
- Integrate **file I/O** or **database storage** for persistent data.  
- Add **search functionality** in the menu using hashing or BST.  
- Include a **GUI (Tkinter/Web)** for user interaction.  

---

## e. Conclusion

The **Online Food Ordering and Delivery Management System** effectively demonstrates the practical use of **Linked Lists**, **Stacks**, **Queues**, and **Polynomials** in solving real-world problems.  
It models how restaurants manage their workflow — from menu updates and order processing to maintaining customer records and offering discounts.  

The system is efficient for small to medium-scale implementations and serves as a strong foundation for future extensions like GUI integration, data persistence, and real-time order tracking.
