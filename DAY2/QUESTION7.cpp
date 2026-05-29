#include <stdio.h>

int main() {
    int num, product = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0) {
        int digit = num % 10;  // Get last digit
        product = product * digit;
        num = num / 10;        // Remove last digit
    }

    printf("Product of digits = %d\n", product);

    return 0;
}