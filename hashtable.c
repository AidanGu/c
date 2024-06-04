#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

// Inventory system for an online retailer.
// key: name of the thing
// values: how many we have, price

typedef struct ll_item {
  char *name;
  size_t count;
  double price;
  struct ll_item *next;
} ll_item;

typedef struct hashtable {
  // buckets
  size_t num_buckets;
  // array of the linked lists that we have;
  ll_item **buckets;
} hashtable;

hashtable *new_hashtable(size_t num_buckets) {
  hashtable *output = calloc(1, sizeof(hashtable));
  output->num_buckets = num_buckets;

  output->buckets = calloc(num_buckets, sizeof(ll_item *));
  return output;
}

void add_item(hashtable *table, char *name, size_t count, double price) {
  // decide which bucket.
  unsigned long hashed = hash(name);
  unsigned long bucket_num = hashed % table->num_buckets;

  printf("hash for '%s': %lu, goes to bucket %lu\n", name, hashed, bucket_num);

  // this is a specific bucket that's in the array of buckets.
  ll_item* bucket = table->buckets[bucket_num];

  // allocate the linked list node.
  ll_item* new_item = calloc(1, sizeof(ll_item));
  new_item->name = strdup(name);
  new_item->count = count;
  new_item->price = price;

  // cons it in there.
  new_item->next = table->buckets[bucket_num];
  // pop a new pointer into that array of pointers.
  table->buckets[bucket_num] = new_item;
  return;
}

ll_item *lookup(hashtable *table, char *name) {
  unsigned long hashed = hash(name);
  unsigned long bucket_num = hashed % table->num_buckets;
  // this is a specific bucket that's in the array of buckets.
  ll_item* here = table->buckets[bucket_num];

  while(here) {
    if (!strcmp(here->name, name)) {
      return here;
    }
    here = here->next;
  }
  return NULL;
}

void print_item(hashtable *table, char *name) {
  ll_item *found = lookup(table, name);
  if (found) {
    printf("found it!\n");
    printf("name: %s, count %lu, price %f\n", found->name, found->count,
        found->price);
  } else {
    printf("not found: %s\n", name);
  }
}

//  This is a big ol' array of linked lists with load-balancing over the linked
//  lists.

// other operations we want:
// CRUD: create, read, update, delete
// update: what would updating look like?
// -- selling things
// -- get new inventory in, increase the number
// delete: 
// -- de-listing things
// delete the entire data structure when we're exiting the program

int main(void) {
  hashtable *inventory = new_hashtable(100);
  add_item(inventory, "Jordan 1", 23, 103.50);
  add_item(inventory, "Subaru BRZ", 5, 20000.50);

  print_item(inventory, "Jordan 1");
  print_item(inventory, "Smash Bros Melee");
  print_item(inventory, "Subaru BRZ");

  return 0;
}
