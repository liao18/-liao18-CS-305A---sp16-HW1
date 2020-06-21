#ifndef RETAIL_ITEM_H
#define RETAIL_ITEM_H

#define MAX_NAME_LENGTH 16

/* struct of retail_item and its data values */
struct retail_item {

  int number;
  char name[MAX_NAME_LENGTH + 1];
  int price_cents;
};

/* here is an example of defining a point struct with a typedef;
 * delete this in your final code
typedef struct point {
  double x;
  double y;
} point;
 */

/* function prototypes -- should match your .c implementation */
struct retail_item create_retail_item (int num, char *name, int price);
void print(struct retail_item ri);

#endif
