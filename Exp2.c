#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 20
#define LEN 50

/* case-insensitive comparison; ties are broken with strcmp */
int compare(const char *a, const char *b)
{
    int i = 0, d;
    while (a[i] != '\0' && b[i] != '\0') {
        d = tolower((unsigned char)a[i]) - tolower((unsigned char)b[i]);
        if (d != 0)
             return d;
        i++;
    }
    d = tolower((unsigned char)a[i]) - tolower((unsigned char)b[i]);
    if (d != 0)
        return d;
    return strcmp(a, b);
}

void merge(char *arr[], int l, int m, int r)
{
    char *L[MAXN], *R[MAXN];
    int n1 = m - l + 1, n2 = r - m;
    int i, j, k;

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j]) >= 0)          /* larger name first */
             arr[k++] = L[i++];
        else
             arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(char *arr[], int l, int r)
{
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{





    int n, i, c;
    char names[MAXN][LEN];
    char *ptr[MAXN];

    printf("Enter number of names: ");
    scanf("%d", &n);
    if (n < 1 || n > MAXN) {
        printf("Number of names must be between 1 and %d\n", MAXN);
        return 1;
    }
    while ((c = getchar()) != '\n' && c != EOF)
        ;                                   /* discard rest of the line */

    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        if (fgets(names[i], LEN, stdin) == NULL)
            names[i][0] = '\0';
        names[i][strcspn(names[i], "\n")] = '\0';
        ptr[i] = names[i];
    }

    mergeSort(ptr, 0, n - 1);

    printf("\nNames in descending order:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", ptr[i]);
    return 0;
}
