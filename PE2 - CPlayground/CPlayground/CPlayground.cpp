// Nathan Terrell
// Section 01

#include "stdafx.h"
#include "stdio.h"

#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	printf("Hello World!\n");
	int secDec = 60 * 60 * 24 * 31;
	double circle = M_PI * 6.2 * 6.2;
	double divide = 5 / 3;

	printf("%u seconds.\n",secDec);
	printf("%f units^2. \n",circle);
	printf("%f\n", divide);
	if (divide == 1.0) printf("Integer division truncates.");
	else if (divide == 2.0) printf("Integer division rounds.");
	else if (divide == 1.6666666666666) printf("Integer division produces a double.");
	else printf("If we make it back alive, you're never upgrading anything again.");

    return 0;
}

