#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst {
  char *name;
  char *fav_game;
  struct bst *left;
  struct bst *right;
} bst;


bst *add_friend(char *name, char *fav_game, bst *tree) {
  if (!tree) {
    bst *out = calloc(1, sizeof(bst));
    out->name = strdup(name);
    out->fav_game = strdup(fav_game);
    return out;
  }

  // we know that the tree is not NULL
  if (strcmp(name, tree->name) < 0) {
    // go left
    tree->left = add_friend(name, fav_game, tree->left);
  } else if (strcmp(name, tree->name) > 0) {
    // go right
    tree->right = add_friend(name, fav_game, tree->right);
  } else {
    printf("WARNING! duplicate friend??\n");
    free(tree->fav_game);
    tree->fav_game = strdup(fav_game);
  }
  return tree;
}

bst *lookup(char *name, bst *tree) {
  if (!tree) {
    return NULL;
  }
  int result = strcmp(name, tree->name);
  if (result < 0) {
    return lookup(name, tree->left);
  } else if (result > 0) {
    return lookup(name, tree->right);
  } else {
    return tree;
  }
}

void delete_tree(bst *tree) {
  if (!tree) {
    return;
  }
  // recursive call on children, THEN free root
  delete_tree(tree->left);
  delete_tree(tree->right);
  free(tree->name);
  free(tree->fav_game);
  free(tree);
}

int main(void) {
  bst *friends = NULL;
  friends = add_friend("Justin", "COD", friends);
  friends = add_friend("Sankritya", "Stardew Valley", friends);
  friends = add_friend("bimmy", "roblox", friends);
  friends = add_friend("Juan", "Melee", friends);
  friends = add_friend("alexr", "Tekken", friends);
  friends = add_friend("Jim", "Pong", friends);

  bst *found = lookup("bimmy", friends);
  if (found) {
    printf("this person: %s plays %s\n", found->name, found->fav_game);
  }

  found = lookup("Emily", friends);
  if (found) {
    printf("this person: %s plays %s\n", found->name, found->fav_game);
  } else {
    printf("this person was not found.\n");
  }
  delete_tree(friends);

  return 0;
}
