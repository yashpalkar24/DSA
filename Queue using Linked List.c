//queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct slinklist
{
    int data;
    struct slinklist *next;
};
typedef struct slinklist node;
node *rear = NULL;
node *front = NULL;

node *getnode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

void enqueue()
{
    node *newnode, *temp;
    newnode = getnode();
    if (front == NULL)
        front = newnode;
    else
    {
        temp = front;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        rear = newnode;
        printf("%d, %d", front->data, rear->data);
    }
}

void dequeue()
{
    node *temp;
    if (front == NULL)
        printf("queue empty");
    else
    {
        temp = front;
        front = temp->next;
        printf("new front = %d", front->data);
        free(temp);
    }
}

void display()
{
    node *temp;
    if (front == NULL)
        printf("queue empty");
    else
    {
        temp = front;
        while (temp->next != NULL)
        {
            printf("%d..", temp->data);
            temp = temp->next;
        }
        printf("%d..X", temp->data);
    }
}

int main()
{
    int c, a;
    printf("\n\n1. enqueue");
    printf("\n2. dequeue");
    printf("\n3. display");
    printf("\n9. exit\n");
    while (c != 9)
    {
        printf("\nEnter a number: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 9:
            return 0;
        }
    }
    return 0;
}