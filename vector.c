#include "vector.h"
#include <stdlib.h>

Vector *vector_create(void) {
  Vector *vector = malloc(sizeof(Vector));
  if(vector==NULL){
    return vector;
  }
  else{
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = malloc(sizeof(double) * vector->capacity);
    return vector;
  }
}

void vector_push(Vector *vector, double element) {
  if(vector!=NULL){
    if (vector->size == vector->capacity) {
      vector->capacity *= 2;
    }
    double* ptr = realloc(vector->data, sizeof(double) * vector->capacity);   
    if(ptr==NULL){
      free(ptr); 
      free(vector->data);
      free(vector);
      vector=NULL;
    }
    else{
      vector->data = ptr;
      vector->data[vector->size++] = element;
    }
    
  }
}

double vector_get(const Vector *vector, int index) {
  if(vector!=NULL){
    if(index>vector->size){
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
    return;
  }
}

/*void another_vector_free(Vector **vector){
  free(*vector);
}*/

