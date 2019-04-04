#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

typedef struct queue {
    int start, end, size;
    point **elements;
} queue;

/****************************
* implement functions below *
****************************/

queue *new_queue(int size) {
  queue * tmp =(queue*)malloc(sizeof(queue));
  tmp->elements=(point**)malloc(sizeof(point*)*size);
  tmp->start=tmp->size=0;
  tmp->end =0;
  return tmp;
  
    
}

void delete_queue(queue *q) {
  free(q->elements);
  free(q);
}

void put(queue *q, point *value) {
  q->elements[q->end]=value;
  q->end++;
  q->size++;
    
}

point *get(queue *q) {
  point *tmp = q->elements[q->start];
  q->start++;
  q->size--;
  return tmp;
}

bool is_empty(queue *q) {
  return(q->size==0);
    
}

void fill(int **image, int n, int x, int y, int color) {
    queue *points = new_queue(n * n);
    point* strt = (point*)malloc(sizeof(point));
    strt->x =x;
    strt->y=y;
    put(points,strt);
    while (!is_empty(points)) {
      point* tmp= get(points);
      if(image[tmp->x][tmp->y]==0){
	image[tmp->x][tmp->y]=color;
	if(tmp->x<n-1){
	  strt=(point*)malloc(sizeof(point));
	  strt->x=tmp->x+1;
	  strt->y=tmp->y;
	  put(points,strt);
	}
	if(tmp->x>0){
	  strt=(point*)malloc(sizeof(point));
	  strt->x=tmp->x-1;
	  strt->y=tmp->y;
	  put(points,strt);
	}
	if(tmp->y<n-1){
	  strt=(point*)malloc(sizeof(point));
	  strt->y=tmp->y+1;
	  strt->x=tmp->x;
	  put(points,strt);
	}
	if(tmp->y>0){
	  strt=(point*)malloc(sizeof(point));
	  strt->y=tmp->y-1;
	  strt->x=tmp->x;
	  put(points,strt);
	}
      }
      free(tmp);
    }
    delete_queue(points);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int **image = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        image[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int x, y, color;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &color);
        fill(image, n, x, y, color);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
        free(image[i]);
    }
    free(image);
}
