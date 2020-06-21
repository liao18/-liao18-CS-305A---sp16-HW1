/* CS 305, SPRING 2016
 * HOMEWORK 1
 *
 * main.c
 * author: Tammy VanDeGrift
 *
 * creates receipts and retail_items and tests them
 *
 * compile with receipt.c and retail_item.c
 * gcc receipt.c retail_item.c main.c
 * OR
 * gcc -o produce receipt.c retail_item.c main.c
 *
 * If creating produce object file, then run with command:
 * produce
 * Otherwise, run with command:
 * a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include "receipt.h"
#include "retail_item.h"

/* prototypes */
int run_test(void);

/* main 
 * using void paramater since we are not using command line arguments
 * for this program
 */
int main(void) {
  run_test();
}

/* run_test
 * runs a test, creating receipts and adding/deleting items
 */
int run_test(void) {
  /* create two receipts */
  /* note: using pointers for receipts so the receipt data can be 
     modified */
  struct receipt *shop = create_receipt(-3);
  struct receipt *fred = create_receipt(2);
	
  /* create retail items */
  /* note: not using pointers to retail_items since once they are created
   * they are not later modified -- only used as data */
  struct retail_item candy   = create_retail_item(1001, "Snickers", 75);
  struct retail_item coffee  = create_retail_item(3033, "Starbucks Blend", 699);
  struct retail_item cookie  = create_retail_item(2222, "Chips Ahoy", 329);
  struct retail_item shirt   = create_retail_item(9212, "Large T Shirt", 1599);
  struct retail_item eggs    = create_retail_item(1234, "Dozen Eggs", 369);
  struct retail_item oranges = create_retail_item(5545, "Clementines", 799);
  struct retail_item bread   = create_retail_item(3222, "Orowheat bread", 499);
  struct retail_item grapes  = create_retail_item(5122, "Red grapes", 549);
  struct retail_item yogurt  = create_retail_item(1121, "Vanilla yogurt", 75);
  struct retail_item peanuts = create_retail_item(2121, "Planters Peanuts Salt", 802);
  struct retail_item shampoo = create_retail_item(4424, "Pantene Shampoo", -633);
  struct retail_item gift_card = create_retail_item(8000, "Fred Meyer Gift Card", 5000);


  /* put items into receipt */
  add_item(shop, candy);
  add_item(shop, coffee);
  add_item(shop, cookie);
  add_item(shop, shirt);

  print_receipt(shop);

  /* put more items in */
  add_item(shop, eggs);
  add_item(shop, eggs);
  add_item(shop, oranges);
  add_item(shop, bread);
  add_item(shop, grapes);

  /* print the receipt */
  print_receipt(shop);

  /* put more items in */
  add_item(shop, yogurt);
  add_item(shop, peanuts);

  /* print the receipt */
  print_receipt(shop);

  /* at point to draw picture 1 in report */

  /* delete item */
  //printf("Trying to delete item 1234\n"); 
  delete_item(shop, 1234);

  /* print the receipt */
  print_receipt(shop);

  /* at point to draw picture 2 in report */

  /* delete item */
  //printf("Trying to delete item 0000\n");
  delete_item(shop, 0000);


  /* add items to fred */
  add_item(fred, coffee);
  add_item(fred, peanuts);

  /* print receipt */
  print_receipt(fred);

  /* add another item to fred */
  add_item(fred, bread);
  add_item(fred, shampoo);

  /* delete items */
  //printf("Trying to delete item 3222\n");
  delete_item(fred, 3222);
  //printf("Trying to delete item 3033\n");
  delete_item(fred, 3033);
  print_receipt(fred);
  //printf("Trying to delete item 2121\n");
  delete_item(fred, 2121);
  print_receipt(fred);
  //printf("Trying to delete item 1234\n");
  delete_item(fred, 1234);
  print_receipt(fred);

  /* add items to fred */
  add_item(fred, shampoo);
  add_item(fred, bread);
  print_receipt(fred);

  /* free memory for receipts */
  free_receipt(fred);
  free_receipt(shop);

  return EXIT_SUCCESS;
} /* end main */
