#include <stdio.h>
#include <stdbool.h>
void primzahl (int max);
int main (int argc, char *argv[]) {
	if(argc==2) {
		primzahl(atoi(argv[1]));
	}
	else {
		primzahl(100);
	}
	
	return 0;
}



void primzahl (int max) {
	
	const int primmax = max;
	bool istprimzahl;
	int primzahlen[primmax/2+1];
	primzahlen[0]=2;
	int g;

	for (g=3;g<primmax;g++) {    //g mögliche Primzahl
		istprimzahl = true;
		int divisor;
		for (divisor = 2; divisor < g;divisor++) {
			
			//restlos teilbar? 
			if (g%divisor==0) {
				//wenn restlos teilbar ist es keine Primzahl!
				istprimzahl = false;
			}
		}
		if (istprimzahl == true) {	
			printf("%i \n", g);
		}
	}
	
}
		
