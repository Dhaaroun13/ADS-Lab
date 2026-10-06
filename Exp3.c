#include <stdio.h>
#include <string.h>

#define SIZE 10
#define A 0.6180339887

typedef struct {
    int key;
    char val[30];
    int used;
} Entry;

Entry table[SIZE];

int h_div(int k) { return k % SIZE; }

int h_mul(int k)
{
    double x = k * A;
    double f = x - (int)x;
    return (int)(SIZE * f);
}

int hash(int k, int mul) { return mul ? h_mul(k) : h_div(k); }

void insert(int k, char *v, int mul)
{
    int i = hash(k, mul), start = i;

    while (table[i].used) {
        if (table[i].key == k) {
            strcpy(table[i].val, v);
            printf("Key %d already present - value updated\n", k);
            return;
        }
        i = (i + 1) % SIZE;                 /* linear probing */
        if (i == start) {
            printf("Table full\n");
            return;
        }
    }
    table[i].key = k;
    strcpy(table[i].val, v);
    table[i].used = 1;
}

char *search(int k, int mul)
{
    int i = hash(k, mul), start = i;

    while (table[i].used) {
        if (table[i].key == k)




            return table[i].val;
        i = (i + 1) % SIZE;
        if (i == start)
            break;
    }
    return NULL;
}

void display()
{
    int i;
    printf("\nIndex Key    Value\n");
    for (i = 0; i < SIZE; i++) {
        if (table[i].used)
             printf("%-5d %-5d %s\n", i, table[i].key, table[i].val);
        else
             printf("%-5d ---   ---\n", i);
    }
}

int main()
{
    int choice, k, method, i;
    char v[30], *res;

    printf("Method? 1=Div 2=Mul: ");
    scanf("%d", &method);
    for (i = 0; i < SIZE; i++)
        table[i].used = 0;

    while (1) {
        printf("\n1.Insert 2.Search 3.Display 4.Exit: ");
        if (scanf("%d", &choice) != 1)
            break;
        if (choice == 1) {
            printf("Key: ");
            scanf("%d", &k);
            if (k < 0) {
                 printf("Key must be non-negative\n");
                 continue;
            }
            printf("Value: ");
            scanf("%29s", v);
            insert(k, v, method == 2);
        } else if (choice == 2) {
            printf("Key: ");
            scanf("%d", &k);
            if (k < 0) {
                 printf("Key must be non-negative\n");
                 continue;
            }
            res = search(k, method == 2);
            if (res)
                 printf("Found %s\n", res);
            else
                 printf("Not found\n");
        } else if (choice == 3) {
            display();
        } else {
            break;
        }
    }
    return 0;
}
