#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define MAXD 32

typedef struct Node {
    int key, degree, mark;
    struct Node *parent, *child, *left, *right;
} Node;

Node *minNode = NULL;
int total = 0;

Node *newNode(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->degree = 0;
    n->mark = 0;
    n->parent = NULL;
    n->child = NULL;
    n->left = n;
    n->right = n;
    return n;
}

void insert(int key)
{
    Node *n = newNode(key);
    if (minNode == NULL) {
        minNode = n;
    } else {
        n->left = minNode;
        n->right = minNode->right;
        minNode->right->left = n;
        minNode->right = n;
        if (n->key < minNode->key)
             minNode = n;
    }
    total++;
}

void linkNodes(Node *y, Node *x)
{
    y->left->right = y->right;
    y->right->left = y->left;
    y->parent = x;
    y->mark = 0;
    if (x->child == NULL) {
        x->child = y;
        y->left = y;
        y->right = y;
    } else {
        y->left = x->child;

        y->right = x->child->right;
        x->child->right->left = y;
        x->child->right = y;
    }
    x->degree++;
}

void consolidate()
{
    Node *A[MAXD];
    Node *roots[MAXN];
    Node *w, *x, *y, *tmp;
    int nroots = 0, i, d;

    for (i = 0; i < MAXD; i++)
        A[i] = NULL;

    w = minNode;
    do {
         roots[nroots++] = w;
         w = w->right;
    } while (w != minNode);

    for (i = 0; i < nroots; i++) {
        x = roots[i];
        d = x->degree;
        while (A[d] != NULL) {                 
            y = A[d];
            if (x->key > y->key) {
                 tmp = x; x = y; y = tmp;
            }
            linkNodes(y, x);
            A[d] = NULL;
            d++;
        }
        A[d] = x;
    }

    minNode = NULL;
    for (i = 0; i < MAXD; i++)
        if (A[i] != NULL && (minNode == NULL || A[i]->key < minNode->key))
            minNode = A[i];
}

int extractMin(int *out)
{
    Node *z = minNode, *c, *next;
    int i, cnt;

    if (z == NULL)
        return 0;
    *out = z->key;

    
    c = z->child;
    cnt = z->degree;
    for (i = 0; i < cnt; i++) {
        next = c->right;
        c->parent = NULL;
        c->mark = 0;
        c->left = z;
        c->right = z->right;
        z->right->left = c;
        z->right = c;
        c = next;
    }

    
    z->left->right = z->right;
    z->right->left = z->left;

    if (z == z->right) {
        minNode = NULL;
    } else {
        minNode = z->right;
        consolidate();
    }
    free(z);
    total--;




    return 1;
}

void printNode(Node *n)
{
    Node *c;
    int i;
    printf("%d", n->key);
    if (n->child != NULL) {
        printf("(");
        c = n->child;
        for (i = 0; i < n->degree; i++) {
             if (i) printf(" ");
             printNode(c);
             c = c->right;
        }
        printf(")");
    }
}

void display()
{
    Node *t;
    if (minNode == NULL) {
         printf("Heap empty\n");
         return;
    }
    printf("Root List (from min): ");
    t = minNode;
    do {
         printNode(t);
         printf(" ");
         t = t->right;
    } while (t != minNode);
    printf("\n");
}

int main()
{
    int choice, key, out;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Get Min\n4. Extract Min\n5. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1)
            break;
        if (choice == 1) {
            if (total >= MAXN) {
                 printf("Heap limit (%d nodes) reached\n", MAXN);
                 continue;
            }
            printf("Enter key: ");
            scanf("%d", &key);
            insert(key);
        } else if (choice == 2) {
            display();
        } else if (choice == 3) {
            if (minNode)
                 printf("Minimum = %d\n", minNode->key);
            else
                 printf("Heap empty\n");
        } else if (choice == 4) {
            if (extractMin(&out))
                 printf("Extracted minimum = %d\n", out);
            else
                 printf("Heap empty\n");
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
