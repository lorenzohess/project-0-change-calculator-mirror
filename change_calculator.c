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
 * int validate_total_amount(float total)
 * Validate that the total is a positive number.
 * Parameters:
 *     total: the purchase total
 * Returns:
 *     1 if positive, else 0
 ******************************************************************************/
int validate_total_amount(float total) { return total > 0; }

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
 * int validate_paid_amount(float paid)
 * Validate that the paid is a positive number.
 * Parameters:
 *     paid: the purchase paid
 * Returns:
 *     1 if positive, else 0
 ******************************************************************************/
int validate_paid_amount(float paid) { return paid > 0; }

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

  int is_total_valid = validate_total_amount(total);
  if (!is_total_valid) {
    return -1; // Exit code
  }
  printf("Total: %f\n", total);

  float paid = get_paid_amount();
  int is_paid_valid = validate_paid_amount(paid);
  if (!is_paid_valid) {
    return -1; // Exit code
  }
  printf("Total: %f\n", paid);

  return 0;
}
