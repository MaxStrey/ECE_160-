#include <stdio.h>

int main()
{
	char input;
	char computer = 'r';
	scanf("%c", &input);

	if (input == computer)
		printf("%s\n", "Tie.");
	else
		if(input == 'p')
			printf("%s\n", "You Win!");
		else
			if(input == 's')
				printf("%s\n", "You lose!");

			else
				printf("%s\n", "Invalid choice.");
	return 0;
}
