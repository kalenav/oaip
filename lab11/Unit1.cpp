//---------------------------------------------------------------------------

#include <iostream>
#include <time.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

struct Stack
{
        int val;
        Stack* next;
} *head;
int choice;

Stack* push(Stack* head, int el)
{
        Stack* ns = new Stack;
        ns -> val = el;
        ns -> next = head;
        return ns;
}

void viewstack(Stack* head)
{
        if(head == NULL)
        {
                printf("Stack empty!\n\n");
                return;
        }
        Stack* t = head;
        while(t != NULL)
        {
                printf("%d ", t -> val);
                t = t -> next;
        }
        printf("\n\n");
        return;
}

Stack* pop(Stack* head, int* out)
{
        *out = head -> val;
        head = head -> next;
        return head;
}

void delstack(Stack** head)
{
        Stack* temp;
        while(*head != NULL)
        {
                temp = *head;
                *head = (*head) -> next;
                delete temp;
        }
        return;
}

Stack* sort_p(Stack* head)
{
        if(head -> next == NULL) return head;
        int changes;
        head = push(head, -999);
        do
        {
                changes = 0;
                Stack* s = head -> next;
                Stack* prev = head;
                Stack* less;
                Stack* greater;
                Stack* following;
                while(s -> next != NULL)
                {
                        if(s -> val > s -> next -> val) // in increasing order
                        {
                                less = s -> next;
                                greater = s;
                                following = s -> next -> next;
                                prev -> next = less;
                                less -> next = greater;
                                greater -> next = following;
                                changes++;
                        }
                        prev = prev -> next;
                        s = prev -> next;
                }
        }
        while(changes > 0);
        head = pop(head, &changes);
        return head;
}

void sort_v(Stack* head)
{
        int changes;
        int temp;
        Stack* s;
        do
        {
                changes = 0;
                s = head;
                while(s -> next != NULL)
                {
                        if(s -> val > s -> next -> val) // in increasing order
                        {
                                temp = s -> next -> val;
                                s -> next -> val = s -> val;
                                s -> val = temp;
                                changes++;
                        }
                        s = s -> next;
                }
        }
        while(changes > 0);
}

Stack* individual(Stack* head, int* max)
{
        int temp;
        *max = -999;
        Stack* aux = new Stack;
        while(head != NULL)
        {
                head = pop(head, &temp);
                aux = push(aux, temp);
                if(*max < temp) *max = temp;
        }
        while(aux -> next != NULL)
        {
                aux = pop(aux, &temp);
                if(temp != *max) head = push(head, temp); // udalyaet vse max elementi, ne perviy iz
        }
        return head;
}

int main(int argc, char* argv[])
{
        while(true)
        {
                printf("1. Fill stack at random\n");
                printf("2. Add element\n");
                printf("3. Take element\n");
                printf("4. View stack\n");
                printf("5. Delete stack\n");
                printf("6. Sort by exchange of pointers\n");
                printf("7. Sort by exchange of values\n");
                printf("8. Individual task (find and delete max element)\n");
                printf("9. End program\n");
                scanf("%d", &choice);
                printf("\n");
                switch(choice)
                {
                        case 1:
                        {
                                if(head != NULL)
                                {
                                        delstack(&head);
                                        printf("Old stack deleted.\n");
                                }
                                int num;
                                printf("How many elements? ");
                                scanf("%d", &num);
                                randomize();
                                for(int i = 0; i < num; i++) head = push(head, random(19) - 9);
                                printf("Stack filled.\n\n");
                                break;
                        }
                        case 2:
                        {
                                int elem;
                                printf("Input element: ");
                                scanf("%d", &elem);
                                head = push(head, elem);
                                printf("\n");
                                break;
                        }
                        case 3:
                        {
                                int temp;
                                head = pop(head, &temp);
                                printf("Took %d('s) from the stack.\n\n", temp);
                                break;
                        }
                        case 4:
                        {
                                viewstack(head);
                                break;
                        }
                        case 5:
                        {
                                delstack(&head);
                                printf("Stack deleted.\n\n");
                                break;
                        }
                        case 6:
                        {
                                if(head == NULL)
                                {
                                        printf("Create a stack first.\n\n");
                                        break;
                                }
                                head = sort_p(head);
                                printf("Stack sorted.\n\n");
                                break;
                        }
                        case 7:
                        {
                                if(head == NULL)
                                {
                                        printf("Create a stack first.\n\n");
                                        break;
                                }
                                sort_v(head);
                                printf("Stack sorted.\n\n");
                                break;
                        }
                        case 8:
                        {
                                if(head == NULL)
                                {
                                        printf("Create a stack first.\n\n");
                                        break;
                                }
                                int max;
                                head = individual(head, &max);
                                printf("Took %d from the stack.\n\n", max);
                                break;
                        }
                        default: return 0;
                }
        }
}
//---------------------------------------------------------------------------
