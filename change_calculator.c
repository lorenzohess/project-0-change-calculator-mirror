/*******************************************************************************
 * int check_amount(float total, float paid)
 * Brief description of the function
 * Parameters:
 *     total: the purchase amount
 *     paid: the amount the customer paid
 * Returns:
 *     1 if paid >= total, else 0
 * Notes:
 * Sources:
 ******************************************************************************/
int check_amount(float total, float paid);

/*******************************************************************************
 * void print_formatted(float change)
 * Print quantity of denominations needed to give specified change.
 * Parameters:
 *     change: the change to print out
 * Notes: Uses denominations: $5, $1, quarter, dime, nickel, penny.
 * Sources:
 ******************************************************************************/
void print_formatted(float change);

int main(void) { return 0; }
