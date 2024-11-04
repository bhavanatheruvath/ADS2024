#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *Next;
} node;

node *head = NULL, *new, *current, *temp;

void create()
{
    int n;
    printf("Enter Number of Nodes : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        new = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &new->data);
        new->Next = NULL;
        if (head == NULL)
        {
            head = new;
            current = new;
        }
        else
        {
            current->Next = new;
            current = new;
        }
    }
}

void display()
{
    for (temp = head; temp != NULL; temp = temp->Next)
    {
        printf("%d\t", temp->data);
    }
}

void insert()
{
    int c, p;
    printf("Data to be inserted \n1. At the Top\n2. At the Bottom\n3. In Between\nChoose(1/2/3): ");
    scanf("%d", &c);
    if (c == 1)
    {
        // Top Insert
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter The data : ");
        scanf("%d", &new->data);
        new->Next = head;
        head = new;
    }
    else if (c == 2)
    {
        // Bottom Insert
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter The data : ");
        scanf("%d", &new->data);
        new->Next=NULL;
        current->Next = new;
        current = new;
    }
    else
    {
        // Between insert
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter The data : ");
        scanf("%d", &new->data);
        new->Next=NULL;
        printf("enter the position : ");
        scanf("%d", &p);
        for (temp = head; temp->Next != NULL; temp = temp->Next, p--)
        {
            if (p == 2)
            {
                new->Next = temp->Next;
                temp->Next = new;
                current = new;
                break;
            }
        }
        if (p > 2)
            printf("No enough space in the list!");
    }
}
void delete()
{
    
}
void main()
{
    int c;
    while (1)
    {
        printf("\n1. Create a LL\n2. Display the LL\n3. Insert Elements into the LL\n4. End\nChoose : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            break;
        default:
            printf("Instructions Unclear");
            break;
        }
        if (c == 4)
            break;
    }
}