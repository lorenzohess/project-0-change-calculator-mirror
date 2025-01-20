#include <stdio.h>

/*******************************************************************************
 * float get_purchase_total_amount(void)
 * Get the purchase amount from the user.
 * Returns:
 *     the purchase amount
 ******************************************************************************/
float get_purchase_total_amount(void) {
  float total;

  puts("Input purchase total");
  scanf("%f", &total);

  return total;
}

/*******************************************************************************
 * float get_paid_amount(void)
 * Get the amount paid by the user.
 * Returns:
 *     paid: the amount paid
 ******************************************************************************/
float get_paid_amount(void) {
  float paid;

  puts("Input amount paid");
  scanf("%f", &paid);

  return paid;
}

/*******************************************************************************
 * int check_amount(float total, float paid)
 * Ensure paid >= total.
 * Parameters:
 *     total: the purchase amount
 *     paid: the amount the customer paid
 * Returns:
 *     1 if paid >= total, else 0
 ******************************************************************************/
int check_amount(float total, float paid);

/*******************************************************************************
 * void print_formatted(float change)
 * Print quantity of denominations needed to give specified change.
 * Parameters:
 *     change: the change to print out
 * Notes: Uses denominations: $5, $1, quarter, dime, nickel, penny.
 ******************************************************************************/
void print_formatted(float change);

int main(void) {
  float total = get_purchase_total_amount();
  printf("Total: %f\n", total);

  float paid = get_paid_amount();
  printf("Total: %f\n", paid);
  return 0;
}
