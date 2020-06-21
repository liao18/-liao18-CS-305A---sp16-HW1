#ifndef RECEIPT_H
#define RECEIPT_H

#include "retail_item.h"

/* define receipt struct here */
struct receipt {
  
  struct retail_item* items;
  int  num_items;
  int max_items;
  int total;
};

/* function prototypes - should match your .c implementations */
struct receipt * create_receipt(int max_it);
int add_item(struct receipt * rec, struct retail_item item);
int delete_item(struct receipt * rec, int item_num);
void print_receipt(struct receipt * rec);
void free_receipt(struct receipt * rec);

#endif
