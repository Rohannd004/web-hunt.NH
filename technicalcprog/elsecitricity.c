#include <stdio.h>

int main() {
    int units;
    float bill_amount = 0.0, surcharge = 0.0, total_bill = 0.0;
   const int fixed_charge = 100;
   printf("Enter the total units consumed: ");
   scanf("%d", &units);
    if (units <= 100) {
        bill_amount = units * 5;
    } else if (units <= 300) {
        bill_amount = (100 * 5) + ((units - 100) * 7);
    } else {
        bill_amount = (100 * 5) + (200 * 7) + ((units - 300) * 10);
    }
    bill_amount += fixed_charge;

    if (bill_amount > 1000) {
        surcharge = bill_amount * 0.05;
    }
    total_bill = bill_amount + surcharge;

    printf("Total units consumed: %d\n", units);
    printf("Bill amount: Rs %.2f\n", bill_amount);
    printf("Surcharge: Rs %.2f\n", surcharge);
    printf("Total bill amount: Rs %.2f\n", total_bill);

    return 0;
}