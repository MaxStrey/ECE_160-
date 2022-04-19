#include <stdio.h>

enum daysOfTheWeek {
    SUN = 0,
    MON = 1,
    TUE = 2,
    WED = 3,
    THU = 4,
    FRI = 5,
    SAT = 6
};

int main()
{	
	enum daysOfTheWeek day;
	day = MON;

	

    	switch(day)
    {
		case SUN: 
			printf("%s\n", "Woohoo no work!");
			break;
	    	case MON: 
			printf("%s\n", "Ugh back to work");
			break;
		case TUE: 
			printf("%s\n", "Ugh back to work");
			break;
		case WED: 
			printf("%s\n", "Ugh back to work");
			break;
		case THU: 
			printf("%s\n", "Ugh back to work");
			break;
		case FRI: 
			printf("%s\n", "Ugh back to work");
			break;
	    	case SAT: 
			printf("%s\n", "Woohoo no work!");
			break;
		break;
    }
    return 0;
}
