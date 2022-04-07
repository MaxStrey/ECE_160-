#include <stdio.h>
#include <math.h>


int main()
{

	int x_1, y_1, x_2, y_2, x_f, y_f;
	float mag;	
	x_1 = -3;
	x_2 = 6;
	y_1 = 4;
	y_2 = -7;
	x_f = x_2 - x_1;
	y_f = y_2 - y_1;
	mag = sqrt(x_f*x_f + y_f*y_f);
	
	printf("%f\n",mag);
	return 0;

}
