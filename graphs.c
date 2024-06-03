#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int vertices;  // the set V
  int **matrix;  // the set E, adjacency matrix
} Graph;

Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  // allocate the outer array.
  g->matrix = (int **)calloc(vertices, sizeof(int*));
  for (int i=0; i < vertices; i++) {
    // allocate each inner array
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}

void graph_add_edge(Graph *g, int i, int j) {
  g->matrix[i][j] = 1;
}

bool graph_has_edge(Graph *g, int i, int j) {
  return g->matrix[i][j];
}

typedef struct ll_int {
  int value;
  struct ll_int *next;
} ll_int;


void print_ll_int(ll_int *list) {
  while (list) {
    printf("element: %d\n", list->value);
    list = list->next;
  }
}

bool ll_int_contains(ll_int *list, int needle) {
  if (!list) {
    return false;
  } else if (list->value == needle) {
    return true;
  } else {
    return ll_int_contains(list->next, needle);
  }
}

ll_int *enqueue(ll_int *queue, int value) {
  if (queue == NULL) {
    ll_int* output = calloc(1, sizeof(ll_int));
    output->value = value;
    return output;
  }

  if (queue->next == NULL) {
    ll_int* last = calloc(1, sizeof(ll_int));
    last->value = value;
    queue->next = last;
    return queue;
  }
  enqueue(queue->next, value);
  return queue;
}

ll_int *dequeue(ll_int* queue, int* result) {
  if (queue == NULL) {
    *result = -1;
    printf("hey you tried to dequeue from an empty queue\n");
  }
  int output = queue->value;
  *result = output;

  ll_int* return_this = queue->next;
  free(queue);
  return return_this;
}


// TODO: don't leak memory, free your graph

int main(void) {

  Graph *g = graph_create(10);
  int *how_i_got_here = NULL;
  how_i_got_here = malloc(sizeof(int) * 10);
  for (int i=0; i < 10; i++) {
    how_i_got_here[i] = -1;
  }

  // Frankfurt.
  graph_add_edge(g, 0, 1);
  graph_add_edge(g, 1, 0);
  graph_add_edge(g, 0, 2);
  graph_add_edge(g, 2, 0);
  graph_add_edge(g, 0, 4);
  graph_add_edge(g, 4, 0);

  // Mannheim
  graph_add_edge(g, 1, 0);
  graph_add_edge(g, 1, 5);
  graph_add_edge(g, 5, 1);

  // Wuerzburg
  graph_add_edge(g, 2, 0);
  graph_add_edge(g, 2, 6);
  graph_add_edge(g, 6, 2);
  graph_add_edge(g, 2, 7);
  graph_add_edge(g, 7, 2);

  int start = 1;
  int goal = 7;

  ll_int *explored = NULL;
  ll_int *q = NULL;
  /*
  - start at the starting node
  - add all of the nodes that we can reach from the starting node to the queue
    of nodes to explore
  - until we run out of places to explore or find the destination...
    - get the next node from the queue
    - enqueue each of that node's unexplored neighbors
   */
  q = enqueue(q, start);
  explored = enqueue(explored, start);

  bool found = false;
  while(q) {
    int being_explored;
    q = dequeue(q, &being_explored);

    if (being_explored == goal) {
      printf("hooray!\n");
      found = true;
      break;
    }
    // THE BUG WAS: we weren't adding to explored.
    // found by Gavin L. Nice work!!
    explored = enqueue(explored, being_explored);
    for (int other=0; other < g->vertices; other++) {
      printf("there is an edge from %d to %d? %d\n",
          being_explored, other, graph_has_edge(g, being_explored, other));

      if (graph_has_edge(g, being_explored, other)) {
        if (!ll_int_contains(explored, other)) {
          q = enqueue(q, other);
          how_i_got_here[other] = being_explored;
        }
      }
    }
  }

  if (!found) {
    printf("we didn't find a path\n");
  } else {
    for(int i = 0; i<10; i++) {
      printf("%d\n", how_i_got_here[i]);
    }
    int here = goal;
    while (here != start) {
      printf("got to %d from %d\n", here, how_i_got_here[here]);
      here = how_i_got_here[here];
      if (here == -1) {
        printf("we flubbed this pretty bad\n");
        break;
      }
    }
  }

  return 0;
}
