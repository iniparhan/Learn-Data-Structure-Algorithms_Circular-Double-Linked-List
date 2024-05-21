#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* originalAddress;  
    struct Node* next;      
    struct Node* prev;      
};

void insertEnd(struct Node** start, int value)
{
    if (*start == NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
        new_node->data = value;  
        new_node->originalAddress = new_node;  
        new_node->next = new_node->prev = new_node;  
        *start = new_node;  
        return;
    }
      
    struct Node* last = (*start)->prev;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;  
    new_node->originalAddress = new_node;  

    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void display(struct Node* start)
{
    struct Node* temp = start;

    printf("Output\n");
    printf("Address: %p, Data: %d\n", temp->originalAddress, temp->data);
    temp = temp->next;
    while (temp != start) {
        printf("Address: %p, Data: %d\n", temp->originalAddress, temp->data); 
        temp = temp->next;
    }
}

void sort(struct Node** start) {
    struct Node *tmp, *s, *min;
    if (*start == NULL) {  
        printf("List is empty\n");
        return;
    }
    for (tmp = *start; tmp->next != *start; tmp = tmp->next) {
        min = tmp;
        for (s = tmp->next; s != *start; s = s->next) {
            if (s->data < min->data) {  
                min = s;  
            }
        }
        if (min != tmp) {  
            struct Node* temp = tmp->originalAddress;  
            tmp->originalAddress = min->originalAddress;  
            min->originalAddress = temp;  

            int tempData = tmp->data;  
            tmp->data = min->data;  
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
