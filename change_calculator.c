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
 *     0 if paid < total, else 1
 ******************************************************************************/
int check_amount(float total, float paid) {
  if (paid < total) {
    printf("Insufficient payment.\n");
    return 0;
  }
  return 1;
}

/*******************************************************************************
 * void print_formatted(float change)
 * Print quantity of denominations needed to give specified change.
 * Parameters:
 *     change: the change to print out
 * Notes: Uses denominations: $5, $1, quarter, dime, nickel, penny.
 ******************************************************************************/
void print_formatted(float change) {
  const int CENTS_PER_DOLLAR = 100;
  const int cents_5D = 500;
  const int cents_1D = 100;
  const int cents_Q = 25;
  const int cents_D = 10;
  const int cents_N = 5;
  const int cents_P = 1;

  int change_cents = change * CENTS_PER_DOLLAR;

  // For each denomination, get the count and compute the remaining change.
  // Can't use arrays, so hardcode into counts into variables.
  // $5
  int denom_count_5D = change_cents / cents_5D;
  change_cents -= cents_5D * denom_count_5D;

  // $1
  int denom_count_1D = change_cents / cents_1D;
  change_cents -= cents_1D * denom_count_1D;

  // Q
  int denom_count_Q = change_cents / cents_Q;
  change_cents -= cents_Q * denom_count_Q;

  // D
  int denom_count_D = change_cents / cents_D;
  change_cents -= cents_D * denom_count_D;

  // N
  int denom_count_N = change_cents / cents_N;
  change_cents -= cents_N * denom_count_N;

  // P
  int denom_count_P = change_cents / cents_P;
  change_cents -= cents_P * denom_count_P;

  printf("Your change is: %.2f\n", change);
}

int main(void) {
  float total = get_purchase_total_amount();

  int is_total_valid = validate_total_amount(total);
  if (!is_total_valid) {
    return -1; // Exit code
  }
  /* printf("Total: %f\n", total); */

  float paid = get_paid_amount();
  int is_paid_valid = validate_paid_amount(paid);
  if (!is_paid_valid) {
    return -1; // Exit code
  }
  /* printf("Total: %f\n", paid); */

  int is_amount_valid = check_amount(total, paid);

  float change = paid - total;
  print_formatted(change);

  return 0;
}
