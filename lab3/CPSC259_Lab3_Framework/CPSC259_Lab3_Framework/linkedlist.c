/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       Your names
 Student #s:   12345678 and 12345678
 CWLs:         cwl1 and cwl2
 Date:         Add the date here
 */
 
/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

/*
 Returns a pointer to a new, empty linked list of struct node.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a new, empty linked list of struct node (NULL)
 */
node* create_linked_list()
{
	// Insert your code here
    return NULL;

}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane.  The node's next pointer doesn't point to anything
 e.g., it is equal to NULL.
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
node* create_node(airplane plane)
{
	// Insert your code here
    node* new_node = (node*) malloc(sizeof(node));
    new_node->plane.flight_number = plane.flight_number;
    new_node->plane.city_origin = plane.city_origin;
    new_node->plane.city_destination = plane.city_destination;
    new_node->plane.priority = plane.priority;
    new_node->plane.maximum_speed_kph = plane.maximum_speed_kph;
    new_node->plane.cruising_altitude = plane.cruising_altitude;
    new_node->plane.capacity = plane.capacity;
    new_node->next = NULL;

  // replace this line with something appropriate
  return new_node;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_node is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
node* prepend_node(node* list, node* new_node)
{
	// Insert your code here
    new_node->next = list;
  // replace this line with something appropriate
  return new_node;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
node* delete_node(node* list)
{
	// Insert your code here
    if (list == NULL) return list; // check if there is even a node

    // if there is a node, free this node and return the next one
    node* next_node = list->next;
    free(list);

  // replace this line with something appropriate
  return next_node;
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(node* list)
{
    int length = 0;
	// Insert your code here
    while (list != NULL) {
        length++;
        list = list->next;
    }

  // replace this line with something appropriate
  return length;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.  
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
node* delete_list(node* list)
{
    node* curr_node = list;
	// Insert your code here
    while (list != NULL) {
        curr_node = list;
        list = list->next;
        free(curr_node);
    }

  // replace this line with something appropriate
  return list;
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(node* node_to_print)
{
	// Insert your code here
    if (node_to_print == NULL) {
        printf("The node is empty\n\n");
        return;
    }

    printf("The node contains an airplane structure with the following information:\n");
    printf("    Flight Number = %d\n", node_to_print->plane.flight_number);
    printf("    City Origin = %s\n", node_to_print->plane.city_origin);
    printf("    City Destination = %s\n", node_to_print->plane.city_destination);
    printf("    Priority = %d\n", node_to_print->plane.priority);
    printf("    Maximum Speed (kph) = %d\n", node_to_print->plane.maximum_speed_kph);
    printf("    Cruising Altitude = %d\n", node_to_print->plane.cruising_altitude);
    printf("    Capacity = %d\n", node_to_print->plane.capacity);
    if (node_to_print->next == NULL) printf("Link = NULL\n");
    else printf("Link points to address %p\n", node_to_print->next);

    printf("\n");

    return;
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(node* list_to_print)
{
	// Insert your code here
    if (list_to_print == NULL) {
        printf("The list is empty\n");
        return;
    }

    int number = 0;

    while (list_to_print != NULL) {
        number++;
        printf("Found node number %d\n", number);
        print_node(list_to_print);
        list_to_print = list_to_print->next;
    }

    return;

}

/*
 Reverses a list. 
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
node* reverse(node* list)
{
	// Insert your code here
    node* prev_node = NULL;
    node* next_node = NULL;

    while (list != NULL) {
        // temporarily store next
        next_node = list->next;

        // if the first of the list
        if (prev_node == NULL) {
            list->next = NULL;
        }
        // if not the first of the list
        else {
            list->next = prev_node;
        }

        // store and point to the next
        prev_node = list;
        list = next_node;
    }

  // replace this line with something appropriate
    if (prev_node == NULL) return list;
    return prev_node;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
node* remove_from_list(node* list, char* destination_city)
{
    node* prev_node = NULL;
    node* curr_node = NULL;
    node* first_node = list;

	// Insert your code here
    while (list != NULL) {
        // need to delete
        if (strcmp(list->plane.city_destination, destination_city) == 0) {
            // if the first in the list
            if (prev_node == NULL) {
                first_node = list->next;
            }
            else {
                prev_node->next = list->next;
            }
            
            // delete the node
            curr_node = list;
            list = list->next;
            free(curr_node);
        }
        // no delete
        else {
            prev_node = list;
            list = list->next;
        }
    }

  // replace this line with something appropriate
  return first_node;
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordi+nality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
node* retrieve_nth(node* list, int ordinality)
{
	// Insert your code here
    int iter = 1;
    while (iter < ordinality) {
        if (list == NULL) return NULL;

        list = list->next;
        iter++;
    }

  // replace this line with something appropriate
    return list;
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
			correct location
            ELSE a pointer to the unchanged list
 */
node* insert_nth(node* list, node* node_to_insert, int ordinality)
{
	// Insert your code here
    node* prev_node = NULL;
    node* first_node = list;
    int iter = 1;

    // insert node at the start (prepend)
    if (ordinality == 1) {
        node_to_insert->next = list;
        first_node = node_to_insert;
        return first_node;
    }

    while (iter < ordinality - 1) {
        // if overflow
        if (list == NULL) return first_node;

        list = list->next;
        iter++;
    }

    // if overflow on empty node
    if (list == NULL) {
        return first_node;
    }

    // insert node at given ordinality position
    node_to_insert->next = list->next;
    list->next = node_to_insert;

  // replace this line with something appropriate
  return first_node;
}