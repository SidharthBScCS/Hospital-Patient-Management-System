# **Hospital Patient Management System**

## **Problem Statement**
The Hospital Patient Record Management System is a software solution designed to efficiently manage patient records, emergency queues, billing calculations, and inventory operations in a hospital setting. This system leverages linear data structures such as linked lists, stacks, and queues to dynamically handle patient admissions, prioritize emergency cases, track changes, and perform calculations for billing and inventory management. The assignment focuses on implementing these data structures to address real-world hospital management scenarios.

## **Attributes**
- **patientID** -> Integer, unique indentifier for the patient
- **patientName** -> String, name of the patient
- **admissiondate** -> String, date of the admission
- **treatmentDetails** -> String, description of the patient
- **head** -> Pointer to the linked list of patients
- **undoStack** -> Stack to store recent admissions
- **emergencyQueue** -> Priority queue to manage emergency patients


## **Class: PatientRecordManagementSystem**
- **insertPatient()** -> Inserts a new patient into the linked list
- **deletePatient()** -> Deletes a patient by ID
- **retrievePatient()** -> Retrieves patient details by ID
- **addPatientRecord()** -> Adds a patient and updates the undo stack
- **undoAdmission()** -> Deletes the most recent admission
- **manageEmergencyQueue()** -> Manages emergency patients using priority queue
- **calculateBilling()** -> Calculates billing
- **evaluateInventory()** -> Evaluates postfix expressions


## **main()**
Implements a menu-driven interface using switch-case to allow users to: 
- Add,delete and view patient details
- Undo the last admission
- Manage emergency queue
- Calculate billing
- Evaluate inventory expressions


## **Explanation of the code**
- **Linked List** -> To store patient records dynamically, allowing insertion and deletion without shifting elements. Each patient is represented as a node in a singly linked list. The **Patient** struct contains patient details and a pointer to the next patient. The **head** pointer in the class always points to the first patient in the list. **insertPatient()** adds a new node at the begining. **deletePatient()** searches and removes a node by ID. **retrievePatient()** traverses the list to find and display a patient.

- **Stack** -> To track the most recent patient admissions and allow undoing the last action. A **stack<Patient>** named **undoStack** stores patient records as they are added. When **undoAdmission()** is caleed the top patient is popped and deleted from the linked list. **addPatientRecord()** pushes the patient onto the stack. **undoAdmission()** pops the top patient and deletes it from the list.

- **Priority Queue** -> To manage emergency patients based on their priority level. A **priority_queue<EmergencyPatient>** stores patients with a priority value. The patient with the highest priority is treated first. **manageEmergencyQueue()** adds emergency patients and displays them in priority order.

- **Stack Postfix expressions** -> To evaluate mathematical expressions used for inventory calculations. A **stack<int>** is used in **evaluateInventory()** to process postfix expressions. Operands are pushed and operators pop two values to compute and push the result.


## **Time Complexity**
- **insertPatient()** -> O(1)
- **deletePatient()** -> O(n)
- **retrievePatient()** -> O(n)
- **addPatientRecord()** -> O(1)
- **undoAdmission()** -> O(n)
- **manageEmergencyQueue()** -> O(n log n)
- **calculateBilling()** -> O(1)
- **evaluateInventory()** -> O(n)


## **Space Complexity**
- **Space Complexity** -> O(n)
 

## **Learning Outcome** 
- Implementation of Linked List, Stacks, Queues
- Use of priority queues for emergency management
- Postfix expression evaluation
- Menu-Driven Programming
- Time and Space Complexity
- Real-World application


## **Sample Outcome**
<img width="513" height="527" alt="Screenshot (55)" src="https://github.com/user-attachments/assets/9ab5a528-f0b3-4960-b7c4-074b6cbde6c2" />
<img width="423" height="571" alt="Screenshot (56)" src="https://github.com/user-attachments/assets/0580b559-0473-4e08-b93b-d7e91a8a8fcd" />
<img width="589" height="507" alt="Screenshot (57)" src="https://github.com/user-attachments/assets/cb6f7722-ad77-4768-b949-a8b681a378d2" />


## **Student Details** 
- **Nam**        ->      Sidharth Krishna S
- **Roll No**   ->      2401720003
- **Course**     ->      BSc Computer Science
- **Semester**   ->      3rd
- **Assignment** ->     Theory Assignment 2
