#include <stdio.h>

float get_purchase_total_amount_dollars(void);
float get_paid_amount_dollars(void);
int check_amount(float total, float paid);
int decrement_change_cents(int change_cents, int denom_value_cents,
                           int denom_count);
void print_denomination(int denom_count, char *denom_name);
void print_formatted(float change);

int main(void) {
  // Get user input
  float total = get_purchase_total_amount_dollars();
  float paid = get_paid_amount_dollars();

  // Validate user input
  int is_amount_valid = check_amount(total, paid);
  if (!is_amount_valid) {
    return -1;
  }

  // Compute change and print
  float change = paid - total;
  print_formatted(change);

  return 0;
}

/*******************************************************************************
 * float get_purchase_total_amount_dollars(void)
 *
 * Get the purchase amount from the user.
 * Returns:
 *     the purchase amount
 * Notes: assume amount in dollars.
 ******************************************************************************/
float get_purchase_total_amount_dollars(void) {
  float total;

  puts("Input purchase total:");
  scanf("%f", &total);

  return total;
}

/*******************************************************************************
 * float get_paid_amount_dollars(void)
 *
 * Get the amount paid from the user.
 * Returns:
 *     the amount paid
 * Notes: assume amount in dollars.
 ******************************************************************************/
float get_paid_amount_dollars(void) {
  float paid;

  puts("Input amount paid:");
  scanf("%f", &paid);

  return paid;
}

/*******************************************************************************
 * int check_amount(float total, float paid)
 *
 * Validate that paid >= total, print warning if not.
 * Parameters:
 *     total: the purchase amount
 *     paid: the amount paid
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
 * int decrement_change_cents(int change_cents, int denom_value_cents, int
 * denom_count)
 *
 * Decrement the change by a multiple of a denomination value and return it.
 * Parameters:
 *     change_cents: the current change in cents
 *     denom_value_cents: the denomination value in cents
 *     denom_count: how many denominations to decrement change by
 * Returns:
 *     the change value after being decremented
 ******************************************************************************/
int decrement_change_cents(int change_cents, int denom_value_cents,
                           int denom_count) {
  return change_cents - (denom_value_cents * denom_count);
}

/*******************************************************************************
 * void print_denomination(int denom_count, char *denom_name)
 *
 * Print the count of a denomination.
 * Parameters:
 *     denom_count: the count of the denomination
 *     denom_name: the string representation of the denomination
 ******************************************************************************/
void print_denomination(int denom_count, char *denom_name) {
  // We shouldn't print anything if the count is 0.
  if (0 != denom_count) {
    printf("%3d - %s\n", denom_count, denom_name);
  }
}

/*******************************************************************************
 * void print_formatted(float change)
 *
 * Print quantity of denominations needed to give specified change.
 * Parameters:
 *     change: the change
 * Notes: Uses denominations $5, $1, quarter, dime, nickel, penny.
 ******************************************************************************/
void print_formatted(float change) {
  // Converting dollars to cents allows us to do integer arithmetic and thus
  // avoid floating-point errors.
  const int CENTS_PER_DOLLAR = 100;
  const int CENTS_5D = 5 * CENTS_PER_DOLLAR;
  const int CENTS_1D = 1 * CENTS_PER_DOLLAR;
  const int CENTS_Q = 25;
  const int CENTS_D = 10;
  const int CENTS_N = 5;

  // Convert change to cents, but keep as float
  float change_cents_float = change * CENTS_PER_DOLLAR;

  // To ensure floats with decimal > 0.5 are rounded up, add 0.5 cents to the
  // float before the cast. If decimal < 0.5, will still properly round down.
  float change_cents_incremented = change_cents_float + 0.5;
  int change_cents = (int)change_cents_incremented;

  // For each denomination, get the count and compute the remaining change.
  // Can't use arrays, so we store each counts in its own variable.
  int denom_count_5D = change_cents / CENTS_5D;
  change_cents = decrement_change_cents(change_cents, CENTS_5D, denom_count_5D);

  int denom_count_1D = change_cents / CENTS_1D;
  change_cents = decrement_change_cents(change_cents, CENTS_1D, denom_count_1D);

  int denom_count_Q = change_cents / CENTS_Q;
  change_cents = decrement_change_cents(change_cents, CENTS_Q, denom_count_Q);

  int denom_count_D = change_cents / CENTS_D;
  change_cents = decrement_change_cents(change_cents, CENTS_D, denom_count_D);

  int denom_count_N = change_cents / CENTS_N;
  change_cents = decrement_change_cents(change_cents, CENTS_N, denom_count_N);

  // Remaining change, in cents, is by definition penny count.
  int denom_count_P = change_cents;

  printf("Your change is $%.2f\n", change);
  print_denomination(denom_count_5D, "5D");
  print_denomination(denom_count_1D, "1D");
  print_denomination(denom_count_Q, "Q");
  print_denomination(denom_count_D, "D");
  print_denomination(denom_count_N, "N");
  print_denomination(denom_count_P, "P");
}
