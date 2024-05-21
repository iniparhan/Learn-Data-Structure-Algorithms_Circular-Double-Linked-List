#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* memori_asli;  
    struct Node* next;      
    struct Node* prev;      
};

void insertEnd(struct Node** start, int value)
{
    if (*start == NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
        new_node->data = value;  
        new_node->memori_asli = new_node;  
        new_node->next = new_node->prev = new_node;  
        *start = new_node;  
        return;
    }
      
    struct Node* last = (*start)->prev;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;  
    new_node->memori_asli = new_node;  

    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void display(struct Node* start)
{
    struct Node* temp = start;

    printf("Output\n");
    printf("Address: %p, Data: %d\n", temp->memori_asli, temp->data);
    temp = temp->next;
    while (temp != start) {
        printf("Address: %p, Data: %d\n", temp->memori_asli, temp->data); 
        temp = temp->next;
    }
}

void sort(struct Node** start) {
    struct Node *temp, *node, *min;
    if (*start == NULL) {  
        printf("List is empty\n");
        return;
    }
    for (temp = *start; temp->next != *start; temp = temp->next) {
        min = temp;
        for (node = temp->next; node != *start; node = node->next) {
            if (node->data < min->data) {  
                min = node;  
            }
        }
        if (min != temp) {  
            struct Node* temp = temp->memori_asli;  
            temp->memori_asli = min->memori_asli;  
            min->memori_asli = temp;  

            int tempData = temp->data;  
            temp->data = min->data;  
            min->data = tempData;  
        }
    }
}

int main()
{
    struct Node* start = NULL;

    int banyak_data, data;
    printf("Input\n");
    scanf("%d", &banyak_data);

    for(int i = 0; i < banyak_data; i++) {
        scanf("%d", &data);
        insertEnd(&start, data);  
    }

    display(start); 

    sort(&start);

    printf("\nAfter sorting:\n");
    display(start);  

    return 0;
}
