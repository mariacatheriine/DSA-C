#include <stdio.h>
typedef struct {
    int coeff;
    int exp;
} Polynomial;
void addPolynomials(Polynomial p1[], int n1,
                    Polynomial p2[], int n2,
                    Polynomial result[], int *nResult) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp > p2[j].exp) {
            result[k] = p1[i];
            i++;
            k++;
        }
        else if (p1[i].exp < p2[j].exp) {
            result[k] = p2[j];
            j++;
            k++;
        }
        else {
            int sumCoeff = p1[i].coeff + p2[j].coeff;
            if (sumCoeff != 0) {
                result[k].coeff = sumCoeff;
                result[k].exp = p1[i].exp;
                k++;
            }
            i++;
            j++;
        }
    }
    while (i < n1) {
        result[k] = p1[i];
        i++;
        k++;
    }
    while (j < n2) {
        result[k] = p2[j];
        j++;
        k++;
    }
    *nResult = k;
}
void displayPolynomial(Polynomial poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i].exp == 0)
            printf("%d", poly[i].coeff);
        else if (poly[i].exp == 1)
            printf("%dx", poly[i].coeff);
        else
            printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i != n - 1)
            printf(" + ");
    }
    printf("\n");
}
int main() {
    Polynomial p1[20], p2[20], result[40];
    int n1, n2, nResult;
    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter coefficient and exponent for Polynomial 1:\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &p1[i].coeff);
        printf("Exponent: ");
        scanf("%d", &p1[i].exp);
    }
    printf("\nEnter number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter coefficient and exponent for Polynomial 2:\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &p2[i].coeff);
        printf("Exponent: ");
        scanf("%d", &p2[i].exp);
    }
    addPolynomials(p1, n1, p2, n2, result, &nResult);
    printf("\nPolynomial 1: ");
    displayPolynomial(p1, n1);
    printf("Polynomial 2: ");
    displayPolynomial(p2, n2);
    printf("Sum: ");
    displayPolynomial(result, nResult);
    return 0;
}