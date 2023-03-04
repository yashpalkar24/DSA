//quadratic probing
#include <stdio.h>
int size = 10, c1 = 1, c2 = 3;
int hash[10];

int insert()
{
    int val, k;
    printf("Enter a value: ");
    scanf("%d", &val);
    for (int i = 0; i < size; i++)
    {
        k = (val%size + (c1*i)+(c2*i*i));
        if (hash[k] == -1)
        {
            hash[k] = val;
            break;
        }
    }
}

int search()
{
    int val, count;
    printf("Enter element to be searched: ");
    scanf("%d", &val);
    for (int i = 0; i < size; i++)
    {
        if (val == hash[i])
        {
            printf(" Element found at %d pos", i);
            return 0;
        }
    }
    printf("element not found");
}

int display()
{
    for(int i = 0; i<size; i++)
        printf("%d ", hash[i]);
}

int main()
{
    int c, a;
    for (int i = 0; i < size; i++)
    {
        hash[i] = -1;
    }
    printf("\n\n1. insert");
    printf("\n2. search");
    printf("\n3. display");
    printf("\n9. exit\n");
    while (c != 9)
    {
        for(int i = 0; i<size; i++)
        printf("%d ", hash[i]);
        printf("\nEnter a number: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
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