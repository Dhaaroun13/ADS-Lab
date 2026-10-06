#include <stdio.h>
#include <string.h>

#define SIZE 31
#define K 3

int bitArray[SIZE] = {0};

/* three different hash functions; each returns a bit position */
int hash1(const char *s)                    /* djb2 */
{
    unsigned long h = 5381;
    int i;
    for (i = 0; s[i] != '\0'; i++)
        h = h * 33 + (unsigned char)s[i];
    return (int)(h % SIZE);
}

int hash2(const char *s)                    /* sdbm */
{
    unsigned long h = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++)
        h = (unsigned char)s[i] + (h << 6) + (h << 16) - h;
    return (int)(h % SIZE);
}

int hash3(const char *s)                        /* polynomial, base 31 */
{
    unsigned long h = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++)
        h = h * 31 + (unsigned char)s[i];
    return (int)(h % SIZE);
}

void insert(const char *s)
{
    int h1 = hash1(s), h2 = hash2(s), h3 = hash3(s);
    bitArray[h1] = 1;
    bitArray[h2] = 1;
    bitArray[h3] = 1;
    printf(" %s -> bits %d, %d, %d\n", s, h1, h2, h3);
}

int search(const char *s)
{
    return bitArray[hash1(s)] && bitArray[hash2(s)] && bitArray[hash3(s)];
}

void display()
{
    int i;
    printf("\nBloom Filter (%d bits):\n", SIZE);
    for (i = 0; i < SIZE; i++)




        printf("%d", bitArray[i]);
    printf("\n");
}

int main()
{
    int n, i;
    char str[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%49s", str);
        insert(str);
    }
    display();

    printf("\nEnter elements to search (type quit to stop):\n");
    while (scanf("%49s", str) == 1 && strcmp(str, "quit") != 0) {
        if (search(str))
             printf("%s may be present in the set.\n", str);
        else
             printf("%s is definitely not present in the set.\n", str);
    }
    return 0;
}
