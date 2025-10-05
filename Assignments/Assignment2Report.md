# Hospital Patient Record Management System Report

## 1. Patient Record ADT

The **Patient Record ADT** manages patient information in a hospital, storing:
- **PatientID**: Unique identifier.
- **PatientName**: Name of the patient.
- **AdmissionDate**: Date of admission.
- **TreatmentCost**: Cost of the treatment.

The ADT is implemented using a **linked list**, enabling dynamic addition, deletion, and retrieval of patient records.

---

## 2. Strategy for Implementing Linked Lists, Stacks, and Queues

- **Linked List**: 
  - Used to manage patient records.
  - Supports dynamic insertion and deletion of records with O(n) time complexity for searches.
  
- **Stack**:
  - Used for **undo functionality**.
  - Operations (push, pop, peek) are O(1).
  
- **Queue**:
  - **Circular Queue**: Manages emergency patients in a fixed-size queue, with O(1) enqueue and dequeue operations.
  - **Priority Queue**: Stores emergency patients based on priority, with O(log n) complexity for insertions.

---

## 3. Approach to Polynomial Operations and Postfix Expression Evaluation

- **Polynomial Operations**: Billing is calculated using a polynomial formula:  
  `Billing = (treatmentDuration)^2 + (serviceCost * treatmentDuration)`.

- **Postfix Expression Evaluation**: Used for inventory calculations, where each token (operand or operator) is processed in sequence. This method is efficient with O(n) time complexity.

---

## 4. Analysis of the System’s Efficiency and Functionality

- **Efficiency**: 
  - Linked lists provide flexibility, though searches and deletions are O(n). 
  - Stacks and queues operate efficiently with O(1) for most operations, while priority queue insertions are O(log n).

- **Functionality**: 
  - The system manages patient records effectively, with undo functionality, emergency queues, and billing calculations.
  - Postfix evaluation allows for easy inventory updates.

- **Limitations**:
  - **Scalability**: For large datasets, linked lists may not be optimal for searches.
  - **User Interface**: A GUI could improve usability.

---

## Conclusion

The system effectively handles patient records, emergency queues, and billing. While efficient for small to medium data sizes, it can be further optimized for scalability and usability in a real-world environment.
