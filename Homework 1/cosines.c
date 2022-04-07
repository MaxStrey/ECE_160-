#include <stdio.h>
#include <math.h>

int main()

{

	float a, b, c;
	float gamma;
	
	a = 9.0;
	b = 11.0;
	c = 18.0;
	gamma = acos((a*a - b*b + c*c)/(2*a*c));

	printf("%f\n", gamma);
	return 0;

}
