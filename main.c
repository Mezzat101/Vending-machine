#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* This is a structure to store the product information */
struct node
{
    char name[20];
    int quantity;
    float cost;
    struct node *next, *prev;
};

/* This is a global variable to store the start and end of the list */
struct node *start, *end;

/************************* Declearation ****************************/
void init_list();
struct node *creat_node(char *ptr, int val1, float val2);
void insert_node(struct node *element);
void print_list();
struct node *search_node(char *ptr);
void delete_node(char *ptr);
void destroy_list();
/****************************** MAIN *********************************/
int main()
{
    int x, quant;
    char i, z, name[10];
    float cost;
    init_list();
    do
    {
        printf("Press 1 to insert a product\nPress 2 to print the list\nPress 3 to delete a product\nPress 4 to search for a product\nPress 5 to destroy the list\n");
        printf("===================================\n");
        scanf("%d", &x);
        if (x == 1)
        {
            printf("Insert product:\nname:\n");
            scanf("%s", name);
            printf("quantity:\n");
            scanf("%d", &quant);
            printf("cost:\n");
            scanf("%f", &cost);
            struct node *ptr;
            ptr = creat_node(name, quant, cost);
            insert_node(ptr);
            printf("The product is added\n");
        }
        else if (x == 3)
        {
            printf("Enter the product you want to delete:\n");
            scanf("%s", name);
            delete_node(name);
        }
        else if (x == 4)
        {
            printf("Enter the product you want to search for:\n");
            scanf("%s", name);
            struct node *result;
            result = search_node(name);
            if (result == '\0')
            {
                printf("The product is not exist\n");
            }
            else
            {
                printf("The product:\n%s\n%d\n%f\n", result->name, result->quantity, result->cost);
            }
        }
        else if (x == 5)
        {
            destroy_list();
        }
        else
        {
            print_list();
        }
        printf("please enter (y) to return or (x) to exit:\n");
        scanf(" %c", &z);
    } while (z != 'x');
    return 0;
}

/*********************************** Definition *******************************/
/* This function initializes the list */
void init_list()
{
    start = end = '\0';
}
/* This function creates a new node and returns a pointer to it */
struct node *creat_node(char *ptr, int val1, float val2)
{
    struct node *element;
    element = (struct node *)malloc(sizeof(struct node));
    strcpy(element->name, ptr);
    element->quantity = val1;
    element->cost = val2;
    element->next = '\0';
    element->prev = '\0';
    return element;
}

/* This function inserts a node into the list */
void insert_node(struct node *element)
{
    struct node *temp = start;
    if (start == end && start == '\0')
    {
        start = element;
        end = element;
    }
    else
    {
        while (temp != '\0' && temp->quantity < element->quantity)
        {
            temp = temp->next;
        }
        if (temp == '\0')
        {
            element->prev = end;
            end->next = element;
            end = element;
        }
        else if (temp == start)
        {
            element->next = start;
            start->prev = element;
            start = element;
        }
        else
        {
            element->next = temp;
            element->prev = temp->prev;
            temp->prev->next = element;
            temp->prev = element;
        }
    }
}

/* This function prints the list */
void print_list()
{
    struct node *temp = start;
    if (temp == '\0')
    {
        printf("There is no list\n");
    }
    while (temp != '\0')
    {
        printf("%s\n%d\n%f\n", temp->name, temp->quantity, temp->cost);
        temp = temp->next;
    }
}

/* This function searches for a node in the list */
struct node *search_node(char *ptr)
{
    struct node *temp = start;
    while (temp->name != ptr && temp != '\0')
    {
        temp = temp->next;
    }
    return temp;
}

/* This function deletes a node from the list */
void delete_node(char *ptr)
{
    struct node *temp = search_node(ptr);
    if (temp == '\0')
    {
        printf("The object is not exist\n");
    }
    else if (temp == start && start == end)
    {
        start = '\0';
        end = '\0';
        free(temp);
    }
    else if (temp == start)
    {
        start = temp->next;
        start->prev = '\0';
        free(temp);
    }
    else if (temp == end)
    {
        end = temp->prev;
        end->next = '\0';
        free(temp);
    }
    else
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
}

/* This function destroys the list */
void destroy_list()
{
    struct node *temp;
    while (start != '\0')
    {
        temp = start;
        start = start->next;
        free(temp);
    }

    end = '\0';
}
