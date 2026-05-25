#include <stdio.h>
void fastTranspose(int original[][3], int transposed[][3]) {
    int rows = original[0][0];
    int cols = original[0][1];
    int terms = original[0][2];
    int count[cols];
    int position[cols];
    for (int i = 0; i < cols; i++) {
        count[i] = 0;
    }
    for (int i = 1; i <= terms; i++) {
        count[original[i][1]]++;
    }
    position[0] = 1;
    for (int i = 1; i < cols; i++) {
        position[i] = position[i - 1] + count[i - 1];
    }
    transposed[0][0] = cols;
    transposed[0][1] = rows;
    transposed[0][2] = terms;
    for (int i = 1; i <= terms; i++) {
        int col = original[i][1];
        int index = position[col];
        transposed[index][0] = original[i][1];
        transposed[index][1] = original[i][0];
        transposed[index][2] = original[i][2];
        position[col]++;
    }
}
void display(int matrix[][3], int terms) {
    for (int i = 0; i <= terms; i++) {
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}
int main() {
    int rows, cols, terms;
    printf("Enter number of rows, columns and non-zero elements:\n");
    scanf("%d %d %d", &rows, &cols, &terms);
    int original[100][3];
    int transposed[100][3];
    original[0][0] = rows;
    original[0][1] = cols;
    original[0][2] = terms;
    printf("Enter row column value for each non-zero element:\n");
    for (int i = 1; i <= terms; i++) {
        scanf("%d %d %d", &original[i][0], &original[i][1], &original[i][2]);
    }
    fastTranspose(original, transposed);
    printf("\nOriginal Sparse Matrix (Tuple Form):\n");
    display(original, terms);
    printf("\nFast Transposed Sparse Matrix:\n");
    display(transposed, terms);
    return 0;
}