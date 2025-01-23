#include <stdio.h>

/*******************************************************************************
 * float get_purchase_total_amount(void)
 *
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
 *
 * Validate that the total is a positive number.
 * Parameters:
 *     total: the purchase total
 * Returns:
 *     1 if positive, else 0
 ******************************************************************************/
int validate_total_amount(float total) { return total > 0; }

/*******************************************************************************
 * float get_paid_amount(void)
 *
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
 *
 * Validate that the paid is a positive number.
 * Parameters:
 *     paid: the purchase paid
 * Returns:
 *     1 if positive, else 0
 ******************************************************************************/
int validate_paid_amount(float paid) { return paid > 0; }

/*******************************************************************************
 * int check_amount(float total, float paid)
 *
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
 * int decrement_change(int change_cents, int denom_value_cents, int
 *denom_count)
 *
 * Decrement the change by a multiple of a denomination value and return it.
 * Parameters:
 *     change_cents: the current change in cents
 *     denom_value_cents: the denomination value in cents
 *     denom_count: how many denominations to decrement change by
 * Returns:
 *     The change value after being decremented.
 ******************************************************************************/
int decrement_change(int change_cents, int denom_value_cents, int denom_count) {
  return change_cents - (denom_value_cents * denom_count);
}

void print_denomination(int denom_count, char *denom_name) {
  if (denom_count != 0) {
    printf("%d - %s\n", denom_count, denom_name);
  }
}

/*******************************************************************************
 * void print_formatted(float change)
 *
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

  // To ensure floats with decimal > 0.5 are rounded up, add 0.5 cents to the
  // float before the cast. See https://cboard.cprogramming.com/c-programming/
  // 107750-converting-float-integer-without-rounding-post793349.html#post793349
  float change_cents_incremented = (change * CENTS_PER_DOLLAR) + 0.5;
  int change_cents_rounded = (int)change_cents_incremented;
  int change_cents = change_cents_rounded;

  // For each denomination, get the count and compute the remaining change.
  // Can't use arrays, so hardcode into counts into variables.
  // $5
  int denom_count_5D = change_cents / cents_5D;
  change_cents = decrement_change(change_cents, cents_5D, denom_count_5D);

  // $1
  int denom_count_1D = change_cents / cents_1D;
  change_cents = decrement_change(change_cents, cents_1D, denom_count_1D);

  // Q
  int denom_count_Q = change_cents / cents_Q;
  change_cents = decrement_change(change_cents, cents_Q, denom_count_Q);

  // D
  int denom_count_D = change_cents / cents_D;
  change_cents = decrement_change(change_cents, cents_D, denom_count_D);

  // N
  int denom_count_N = change_cents / cents_N;
  change_cents = decrement_change(change_cents, cents_N, denom_count_N);

  // P. Remaining change, in cents, is by definition penny count.
  int denom_count_P = change_cents;

  printf("Your change is: %.2f\n", change);
  print_denomination(denom_count_5D, "5D");
  print_denomination(denom_count_1D, "1D");
  print_denomination(denom_count_Q, "Q");
  print_denomination(denom_count_D, "D");
  print_denomination(denom_count_N, "N");
  print_denomination(denom_count_P, "P");
  /* printf("%d - 5D\n", denom_count_5D); */
  /* printf("%d - 1D\n", denom_count_1D); */
  /* printf("%d - Q\n", denom_count_Q); */
  /* printf("%d - D\n", denom_count_D); */
  /* printf("%d - N\n", denom_count_N); */
  /* printf("%d - P\n", denom_count_P); */
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
