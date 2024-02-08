# Vending Machine C-Program 😊 

Documentation
 This documentation provides a detailed explanation of the vending machine program implemented in C programming language.
 ## Structure 🚧
 The program consists of the following components:

* Struct Definition: Defines a structure named node to store product information. Each node contains the name of the product (name), the quantity of the product (quantity), the cost of the product (cost), and pointers to the next and previous nodes (next and prev).

* Global Variables: Declares global variables start and end to store the start and end of the linked list representing the vending machine.

* Function Declarations: Declares function prototypes for all functions used in the program.

* Main Function: The main() function serves as the entry point of the program. It provides a menu-driven interface for users to interact with the vending machine.

* Function Definitions: Contains the implementations of all functions declared earlier in the program.

## Functionality 🌝
* Initialization
     * *init_list()*: Initializes the linked list representing the vending machine. Sets both start and end pointers to NULL.

* Node Creation
    * *creat_node()*: Creates a new node with the provided product information (name, quantity, cost) and returns a pointer to the newly created node.

* Node Insertion
    * *insert_node()*: Inserts a new node into the linked list in ascending order based on the quantity of the product. Handles cases when the list is empty, the new node should be inserted at the beginning, or in the middle of the list.

* Printing
    * *print_list()*: Prints the contents of the linked list, i.e., the products available in the vending machine.

* Searching
    * *search_node()*: Searches for a product in the vending machine by its name. Returns a pointer to the node if the product is found, otherwise returns NULL.

* Deletion
   * *delete_node()*: Deletes a product from the vending machine based on its name. Handles cases when the product to be deleted is at the beginning, at the end, or in the middle of the list.

* Destruction
    * *destroy_list()*: Destroys the entire linked list representing the vending machine. Frees the memory allocated for each node in the list.

## User Interaction 🙆
The main() function provides a user-friendly menu-driven interface for interacting with the vending machine. Users can perform the following actions:

* Insert a product into the vending machine by providing its name, quantity, and cost.
Print the list of products available in the vending machine.

* Delete a product from the vending machine by specifying its name.

* Search for a product in the vending machine by specifying its name.

* Destroy the entire vending machine, removing all products from the list.

## Flow Control 🎛️
The program utilizes a do-while loop to repeatedly display the menu and prompt the user for input until the user chooses to exit by pressing 'x'.

## Error Handling ⁉
* The program handles cases where the user inputs an invalid option by defaulting to printing the list of products.

* Error messages are displayed if a product is not found during deletion or search operations.

* Memory allocation errors are not explicitly handled in this program.

# Project Demo 🧐
<video controls src="vanding machine-1.mp4" title="Title"></video>