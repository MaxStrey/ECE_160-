#include <stdio.h>

int main()
{

	int temperature;
	scanf("%d", &temperature);
	if (temperature > 32)
		printf("%s\n", "Above freezing");
	else
		printf("%s\n", "Below Freezing");
	return 0;
}
