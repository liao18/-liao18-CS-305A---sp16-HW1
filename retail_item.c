#include <stdio.h>
#include "retail_item.h"
#include "receipt.h"
#include <string.h>
#include <stdlib.h>
//create retail_item struct
struct retail_item create_retail_item(int num, char* nam, int price) {
  struct retail_item item;
  //concatenate white spaces to names less than 16 char.
  //or truncate if name 
  int i = 0;  
  while(*(nam+i) && i < MAX_NAME_LENGTH) {
	item.name[i] = *(nam+i);
	i++;
  	}	

	while(i < MAX_NAME_LENGTH) {
	item.name[i] = ' ';
	i++;
  	}

	item.name[i] = '\0';
	
	
      if(price >= 0) {
	item.price_cents = price;
      }
      else {
	item.price_cents = 0;
      }

      if(num >= 0) {
	item.number = num;
      }
      else {
	item.number = 0;
      }

    return item;
}
  //print item data values
  void print(struct retail_item s) {
    printf("Item %d\t", s.number);
    printf("%s\t", s.name);
    printf("$%.2f\n", (float) s.price_cents/100);
  }

  

