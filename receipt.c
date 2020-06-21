#include <stdio.h>
#include <stdlib.h>
#include "retail_item.h"
#include "receipt.h"

//method to create a receipt and returns a struct receipt. Needs number of items passed in.
struct receipt * create_receipt(int max_it) {
  struct receipt *rec = malloc(sizeof(struct receipt));
  rec->num_items = 0;
  rec->total = 0;
  
  //If negative or nonsensical value is passed in for receipt size, default to 10 retail_items
  if(max_it > 0) {
     rec->max_items = max_it;
  }
  else {
    rec->max_items = 10;
  }
  //allocate empty array of items
    rec->items = malloc(sizeof(struct retail_item)*rec->max_items);

  return rec;
}

//add retail_item to receipt's item[] array. Add's item's cost to receipt $total
int add_item(struct receipt* rec, struct retail_item item) {
	if (rec->num_items >= rec->max_items) {
    printf("Cannot add another item to receipt. Maximum size has been reached.\n");
    return -1;
  }
  else{
    rec->items[rec->num_items] = item;
    rec->num_items++;
    rec->total += (float)item.price_cents;
    return 0;
  }
}


//remove retail_item at position of receipt. Also subtracts $total from receipt
int delete_item(struct receipt* rec, int itemNum) {
  int i;
  //if you try to delete something that does not exist, you'll get an error statement
  if (rec->num_items <= itemNum-1) {
    printf("Item number %d not found. Did not delete.\n", itemNum);
    return -1;
  }
  else{
  //Overwrite the deleted element and collapse the array
    for(i = itemNum; i < rec->num_items - 1; i++) {
 	rec->items[i] = rec->items[(i+1)];
    } 
    rec->total -= (rec->items[itemNum]).price_cents;
    rec->num_items--;
    return 0;
  }

}
//display receipt values
void print_receipt(struct receipt* rec) {
    int i;
    for(i = 0; i < rec->num_items; i++) {
	if (i == 0) {
	   printf("Receipt:\n");
	   print(rec->items[i]);
        }
	else if(i == rec->num_items -1) {
	   print(rec->items[i]);
           printf("Total $%.2f\n\n",(float)rec->total/100);
	}
	else {
	   print(rec->items[i]);
	}		
    }	
}
//delete and free data.
void free_receipt(struct receipt* rec) {
   free(rec->items);
   free(rec);
}

