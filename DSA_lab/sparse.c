#include <stdio.h>
#define MAX 100

typedef struct {
    int r, c, v;          // row, column, value
} Term;

// Read a normal matrix and store only non-zero elements in triplet form
void read(Term a[]) {
    int m, n, i, j, x, k = 1;

    printf("Enter rows & columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the Matrix Elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x != 0) {
                a[k].r = i;
                a[k].c = j;
                a[k].v = x;
                k++;
            }
        }
    }

    // Store matrix dimensions and number of non-zero elements in a[0]
    a[0].r = m;
    a[0].c = n;
    a[0].v = k - 1;
}

// Display sparse matrix in triplet form
void display(Term a[]) {
    int i;
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= a[0].v; i++) {
        printf("%d\t%d\t%d\n", a[i].r, a[i].c, a[i].v);
    }
}

// Add two sparse matrices
int add(Term a[], Term b[], Term s[]) {
    int i = 1, j = 1, k = 1, sum;

    // Check if dimensions match
    if (a[0].r != b[0].r || a[0].c != b[0].c)
        return 0;   // Addition not possible

    while (i <= a[0].v && j <= b[0].v) {
        if (a[i].r < b[j].r || (a[i].r == b[j].r && a[i].c < b[j].c)) {
            s[k++] = a[i++];
        }
        else if (b[j].r < a[i].r || (a[i].r == b[j].r && b[j].c < a[i].c)) {
            s[k++] = b[j++];
        }
        else {
            // Same position → add values
            sum = a[i].v + b[j].v;
            if (sum != 0) {
                s[k].r = a[i].r;
                s[k].c = a[i].c;
                s[k].v = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    // Copy remaining elements
    while (i <= a[0].v)
        s[k++] = a[i++];
    while (j <= b[0].v)
        s[k++] = b[j++];

    // Store result dimensions
    s[0].r = a[0].r;
    s[0].c = a[0].c;
    s[0].v = k - 1;

    return 1;   // Success
}

// Transpose of a sparse matrix
void transpose(Term a[], Term t[]) {
    int col, i, k = 1;

    t[0].r = a[0].c;      // rows become columns
    t[0].c = a[0].r;      // columns become rows
    t[0].v = a[0].v;

    // For each column of original matrix
    for (col = 0; col < a[0].c; col++) {
        for (i = 1; i <= a[0].v; i++) {
            if (a[i].c == col) {
                t[k].r = a[i].c;   // swap row and column
                t[k].c = a[i].r;
                t[k].v = a[i].v;
                k++;
            }
        }
    }
}

int main() {
    Term a[MAX], b[MAX], s[MAX], t[MAX];

    printf("--- Matrix A ---\n");
    read(a);

    printf("--- Matrix B ---\n");
    read(b);

    printf("\nA in Triplet form:\n");
    display(a);

    printf("\nB in Triplet form:\n");
    display(b);

    if (add(a, b, s)) {
        printf("\nA + B in Triplet form:\n");
        display(s);
    } else {
        printf("\nAddition not possible (orders different).\n");
    }

    transpose(a, t);
    printf("\nTranspose of A in Triplet form:\n");
    display(t);

    return 0;
}