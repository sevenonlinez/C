#include <stdio.h>
#include <stdlib.h>


void sort(int array[],int anz_elemente) {
  int i,j,min,t;
  for(i=0;i<anz_elemente-1;i++) {
    min=i;
    for(j=i+1;j<anz_elemente;j++) {
      if(array[j]< array[min]) {
	min=j;
      }
    }
      t=array[min];
      array[min]=array[i];
      array[i]=t;
    
   
  }
}

int main() {
  int array[]={9,8,7,6,5,4,2,3,1,12,7};
  sort(array,sizeof(array)/sizeof(int)-1);
  
  int k;
  for(k=0;k<10;k++) {
    printf("%i\n", array[k]);
  }
  return 0;
}
  
