#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void SignalReport(int num)
{
	int ten = num / 10;
	int bits = num % 10;
	char *Readability[] = {"Unreadable","Barely readable", "Readable with considerable difficulty",
							"Readable with practically no difficulty", "Perfectly readable"};
	char *Strength[] = {"Faint signals","Very weak signals", "Weak signals", "Fair signals",
						"Fairly good signals", "Good signals", "Moderately strong signals",
						"Strong signals", "Extremely strong signals"};
	printf("%s, %s\n",Strength[bits - 1],Readability[ten - 1]);
}
int main()
{
	SignalReport(59);
	
	system("pause");
	return 0;
}