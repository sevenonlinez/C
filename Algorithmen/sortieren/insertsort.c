#include <stdio.h>
#include <stdlib.h>

void insertsort(int &array, int elemente) {
  int i,j,k,t;
  for(i=2;i<=elemente;i++) {
    j=i;
    t=array[i];
    k=t;
    
