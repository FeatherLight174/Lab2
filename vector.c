#include "vector.h"
#include <stdlib.h>



Vector *vector_create(void) {
  Vector *vector = malloc(sizeof(Vector));
  if(vector==NULL){
    return vector;
  }
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;
  vector->data = malloc(sizeof(double) * vector->capacity);
  return vector;
}

void vector_push(Vector *vector, double element) {
  if(vector!=NULL){
    if (vector->size == vector->capacity) {
      vector->capacity *= 2;
      ptr = realloc(vector->data, sizeof(double) * vector->capacity);
    }
    if(ptr==NULL){
      free(ptr);
    }
    else{
      vector->data = realloc(vector->data, sizeof(double) * vector->capacity);
      vector->data[vector->size++] = element;
    }
  }
  else{
    return 0;
  }
}

double vector_get(const Vector *vector, int index) {
  if(vector!=NULL){
    if(index>=vector->size){
      return 0;
    }
    else{
      return vector->data[index];
    }
  }
  else{
    return 0;
  }
}

void vector_free(Vector *vector) {
  if(vector!=NULL){
    free(vector->data);
    free(vector);
  }
  else{
    return 0;
  }
}
