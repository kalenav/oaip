#include <iostream>

struct DeckEl
{
    int val;
    DeckEl* next;
    DeckEl* prev;
};

DeckEl* begin;
DeckEl* end;

void push_front(DeckEl** endp, int value)
{
    if (end == NULL)
    {
        (*endp)->val = value;
        begin = end = *endp;
        return;
    }
}

int main()
{
    int choice;
    while (true)
    {
        printf("Choose action:\n");
        printf("1. Fill deck at random\n");
        printf("2. Add element at the beginning\n");
        printf("3. Add element at the end\n");
        printf("4. View deck\n");
        printf("5. End program\n");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            int newel;
            printf("Input element: ");
            scanf_s("%d", &newel);
            push_front(&end, newel);
            printf("\n");
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    }
}