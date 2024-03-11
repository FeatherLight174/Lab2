#include "vector.h"
#include <stdio.h>

int main(void) {
  Vector *vector = vector_create();
  if(vector==NULL){
    vector_free(vector);
    return 0;
  }
  else{
    for (int i = 0; i < 100; ++i) {
      vector_push(vector, i * 10 / 7.0);
      if(ptr==NULL){
        break;
      }
    }
    for (int i = 0; i < 100; ++i) {
      if(i>=vector->size){
        break;
      }
      else{
        printf("%f\n", vector_get(vector, i));
      }
    }
  }
  vector_free(vector);
  return 0;
}
