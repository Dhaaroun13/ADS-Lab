#include <stdio.h>
#include <stdlib.h>

#define MAXK 3                    /* max keys per node (order 4) */
#define MAXINS 50

typedef struct BPlusNode {
    int keys[MAXK + 1];         /* one spare slot for overflow */
    struct BPlusNode *child[MAXK + 2];
    struct BPlusNode *next;     /* next leaf */
    int count;
    int isLeaf;
} BPlusNode;

BPlusNode *root = NULL;

BPlusNode *createNode(int isLeaf)
{
    BPlusNode *n = (BPlusNode *)malloc(sizeof(BPlusNode));
    int i;
    n->count = 0;
    n->isLeaf = isLeaf;
    n->next = NULL;
    for (i = 0; i < MAXK + 2; i++)
        n->child[i] = NULL;
    return n;
}

/* Inserts key below node. If node splits, returns the new right sibling
   and stores the separator key in *upKey; otherwise returns NULL. */
BPlusNode *insertRec(BPlusNode *node, int key, int *upKey)
{
    int i, j, mid, childUp;
    BPlusNode *sib, *newChild;

    if (node->isLeaf) {
        for (i = 0; i < node->count; i++)
            if (node->keys[i] == key)
                 return NULL;               /* duplicate ignored */
        i = node->count - 1;
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->count++;

        if (node->count > MAXK) {           /* leaf overflow: split */
            mid = node->count / 2;
            sib = createNode(1);
            for (j = mid; j < node->count; j++)
                sib->keys[j - mid] = node->keys[j];
            sib->count = node->count - mid;
            node->count = mid;




            sib->next = node->next;
            node->next = sib;
            *upKey = sib->keys[0];             /* copied up */
            return sib;
        }
        return NULL;
    }

    i = 0;
    while (i < node->count && key >= node->keys[i])
        i++;
    newChild = insertRec(node->child[i], key, &childUp);

    if (newChild != NULL) {
        for (j = node->count; j > i; j--) {
            node->keys[j] = node->keys[j - 1];
            node->child[j + 1] = node->child[j];
        }
        node->keys[i] = childUp;
        node->child[i + 1] = newChild;
        node->count++;

        if (node->count > MAXK) {           /* internal overflow: split */
            mid = node->count / 2;
            sib = createNode(0);
            for (j = mid + 1; j < node->count; j++)
                sib->keys[j - mid - 1] = node->keys[j];
            for (j = mid + 1; j <= node->count; j++)
                sib->child[j - mid - 1] = node->child[j];
            sib->count = node->count - mid - 1;
            *upKey = node->keys[mid];       /* moved up */
            node->count = mid;
            return sib;
        }
    }
    return NULL;
}

void insert(int key)
{
    BPlusNode *sib, *newRoot;
    int up;

    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = key;
        root->count = 1;
        return;
    }
    sib = insertRec(root, key, &up);
    if (sib != NULL) {                         /* root split: tree grows */
        newRoot = createNode(0);
        newRoot->keys[0] = up;
        newRoot->child[0] = root;
        newRoot->child[1] = sib;
        newRoot->count = 1;
        root = newRoot;
    }
}

void displayTree()
{
    BPlusNode *queue[100], *n;
    int front = 0, rear = 0, levelCount = 1, nextCount, level = 0, i, j;

    if (root == NULL) {
        printf("B+ Tree is empty.\n");
        return;
    }
    queue[rear++] = root;
    while (front < rear) {
        nextCount = 0;
        printf("Level %d: ", level);
        for (i = 0; i < levelCount; i++) {
            n = queue[front++];
            printf("[");
            for (j = 0; j < n->count; j++) {
                if (j) printf(" ");
                printf("%d", n->keys[j]);




            }
            printf("] ");
            if (!n->isLeaf)
                for (j = 0; j <= n->count; j++) {
                    queue[rear++] = n->child[j];
                    nextCount++;
                }
        }
        printf("\n");
        levelCount = nextCount;
        level++;
    }
}

void displayLeaves()
{
    BPlusNode *t = root;
    int i;

    if (t == NULL)
        return;
    while (!t->isLeaf)
        t = t->child[0];
    printf("Leaf chain: ");
    while (t != NULL) {
        printf("[");
        for (i = 0; i < t->count; i++) {
            if (i) printf(" ");
            printf("%d", t->keys[i]);
        }
        printf("] ");
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int n, key, i;

    printf("Enter number of keys: ");
    scanf("%d", &n);
    if (n < 1 || n > MAXINS) {
        printf("Number of keys must be between 1 and %d\n", MAXINS);
        return 1;
    }
    printf("Enter the keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    printf("B+ Tree (level by level):\n");
    displayTree();
    displayLeaves();
    return 0;
}
