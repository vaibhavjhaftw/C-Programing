//INNOVATIVE BILL PROJECT IN C WITH ADDED OFFERS DEPENDING ON THE FINAL PRICE
#include <stdio.h>

int product_codes[] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011};
char* product_names[] = {"Soap", "Shampoo", "Toothpaste", "Oil", "Dal", "Rice", "Chips", "Biscuits", "Pen", "Pencil", "Eraser"};
int product_prices[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};

// Define the offers
int offer_1_amount = 500;
float offer_1_discount = 0.10;
int offer_2_amount = 1000;
float offer_2_discount = 0.20;
int free_gift_amount = 2000;

// GST to lagega re babaaaa
float gst_rate = 0.05;

// Function to print menu 
void print_menu() {
  printf("\nMenu:\n");
  for (int i = 0; i < 11; i++) {
    printf("%d. %s\n", i + 1, product_names[i]);
  }
}

// Function to get the item code and quantity from the user
void get_item_details(int* item_code, int* quantity) {
  printf("Enter the item code (1-11) and quantity (positive integer): ");
  scanf("%d %d", item_code, quantity);
}

// Function to calculate the subtotal
float calculate_subtotal(int item_code, int quantity) {
  return quantity * product_prices[item_code - 1];
}

// EXCITING OFFERS
float get_discount(float subtotal) {
  if (subtotal >= offer_1_amount) {
    return subtotal * offer_1_discount;
  } else if (subtotal >= offer_2_amount) {
    return subtotal * offer_2_discount;
  } else {
    return 0.0f;
  }
}

// Function to calculate the GST
float calculate_gst(float subtotal) {
  return subtotal * gst_rate;
}

// Function to calculate the grand total
float calculate_grand_total(float subtotal, float discount, float gst) {
  return subtotal - discount + gst;
}

// Function to print the bill
void print_bill(float subtotal, float discount, float gst, float grand_total, int item_codes[], int quantities[], int num_items) {
  printf("\n\n");
  printf("------------------------------------------------------------\n");
  printf("| Badheer SuperMarket Pvt Ltd                              |\n");
  printf("|----------------------------------------------------------|\n");

  // Print purchased items and quantities
  printf("| Items Purchased:                                      |\n");
  for (int i = 0; i < num_items; i++) {
    printf("| %s: %d\n", product_names[item_codes[i] - 1], quantities[i]);
  }

  printf("|----------------------------------------------------------|\n");
  printf("| Subtotal                                        | %.2f   |\n", subtotal);
  printf("| Discount                                        | %.2f   |\n", discount);
  printf("| GST                                             | %.2f   |\n", gst);
  printf("|----------------------------------------------------------|\n");
  printf("| Grand Total                                     | %.2f   |\n", grand_total);
  printf("|----------------------------------------------------------|\n");
}

int main() {

  // Declare variables
  int item_code, quantity;
  float subtotal = 0.0f;
  float discount = 0.0f;
  float gst = 0.0f;
  float grand_total = 0.0f;
  int item_codes[100];  // To store purchased item codes
  int quantities[100];  // To store purchased quantities
  int num_items = 0;     // Ye records rakhega items ka backend me

  // Welcome the user
  printf("Welcome to Badheer SuperMarket Pvt Ltd!\n");

  int continue_shopping = 1; //continue karne ke liye ek dabaye

  while (continue_shopping) {
    // sHOPPING LIST PRINT
    print_menu();

    // User Enters item code and quantity
    get_item_details(&item_code, &quantity);

    // Calculate the subtotal
    subtotal += calculate_subtotal(item_code, quantity);

    // item aur quantity store karega
    item_codes[num_items] = item_code;
    quantities[num_items] = quantity;
    num_items++;

    // Options
    printf("Do you want to continue shopping? (1 for Yes, 0 for No): ");
    scanf("%d", &continue_shopping);
  }

  // Creative approach
  discount = get_discount(subtotal);

  // Calculate the GST professional lagne ke liye
  gst = calculate_gst(subtotal);

  // Grand Total
  grand_total = calculate_grand_total(subtotal, discount, gst);

  // Print the bill
  print_bill(subtotal, discount, gst, grand_total, item_codes, quantities, num_items);

  return 0;
}
