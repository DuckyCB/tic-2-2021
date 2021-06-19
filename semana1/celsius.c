#include <stdio.h>

#define LOW -10.0
#define HIGH 40.0
#define STEP 1.0
#define CELSIUS(F) (((F) - 32) * 5 / 9)

int main(void) {
	double fahrenheit;
	for (fahrenheit = LOW; fahrenheit < HIGH; fahrenheit += STEP) {
		printf("%5.1f grados Fahrenheit son %5.1f grados Celsius\n",
			 fahrenheit, CELSIUS(fahrenheit));
	}
	return 0;
}
