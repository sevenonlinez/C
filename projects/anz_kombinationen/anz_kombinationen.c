#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Prototypen:
void out_counter(int *counter);
void calc_moelichkeiten(int *counter);
void next_stelle(int *counter, int y);


int zahl1;
int zahl2;
int len_zahl;
int stelle; /* Aktuelle Ebene */
int erste_stelle; // gesammt übersicht

int main(int argc, char* argv[]) {
  
  if(argc==3) {
    zahl1=atoi(argv[1]);
    zahl2=atoi(argv[1]);
    len_zahl=atoi(argv[2]);
  }
  else if(argc==4) {
    if(atoi(argv[1])<atoi(argv[2])) {
      zahl1=atoi(argv[1]);
      zahl2=atoi(argv[2]);
      len_zahl=atoi(argv[3]);
    }
    else if(atoi(argv[1])>atoi(argv[2])) {
      zahl1=atoi(argv[2]);
      zahl2=atoi(argv[1]);
      len_zahl=atoi(argv[3]);
    }
    else /* if(atoi(argv[1])==atoi(argv[2])) */ {
      zahl1=atoi(argv[1]);
      zahl2=atoi(argv[2]);
      len_zahl=atoi(argv[3]);
    }
  }
  
  else {
    printf("Fehler bei der Eingabe!!\n");
    return -1;
  }
  if(len_zahl<=0) {
	  return -1;
  }
  
  int *counter= calloc(len_zahl,sizeof(int));
  

  
  // Init counter with 0 //
  int i;
  for(i=0;i<len_zahl;i++) {
    counter[i]=zahl1;
  }
  
  stelle=len_zahl-1; // "zuhinderst" der Ziffer //
  
  calc_moelichkeiten(counter);
  return 0;
}



void calc_moelichkeiten(int *counter) {
  
  int j;
  for(j=zahl1;j<=zahl2;j++) {
    counter[stelle]=j;
    //printf("\n\nStelle:\t%i\n\n", stelle);
    if(stelle!=len_zahl-1) {
      --stelle;
      calc_moelichkeiten(counter);
    }
    out_counter(counter);
  }
  
  if(counter[len_zahl-1]==zahl2) {
	  next_stelle(counter,len_zahl-1);
  }
  calc_moelichkeiten(counter);
 /* for(k=len_zahl-1;k>=0;k--) {
    printf("\nIn calc_moeglichkeiten, = zahl2 überprüefung\n\n");
    if(counter[k]==zahl2) {
      next_stelle(counter,k);
    }
    calc_moelichkeiten(counter);
  }
  * */
}

void out_counter(int *counter) {
  int j;
  for(j=0;j<len_zahl;j++) {
    printf("%i", counter[j]);
    // usleep(10000);
  }
  printf("\n");
  // durchgang++;
}


void next_stelle(int *counter, int y) {
  int x=y;
  //printf("\nIn next stelle\t%i \n\n", x);
  if(counter[x]==zahl2) {
    counter[x]=zahl1;
    if(x==0) {
      exit(0);
    }
    next_stelle(counter,--x);
  }

  else if(counter[x]<zahl2) {
    counter[x]++;
  }
  else if(counter[x]>zahl2) {
	  printf("\nERROR\n");
  }

}		
