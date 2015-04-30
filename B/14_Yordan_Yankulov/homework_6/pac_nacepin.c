#include<stdio.h>
void PacManEats ( int barrels, float position1, float position2, float *cordinate1, float *cordinate2)
{
	int mass = 1;
	int index;
	float vector1;
	float vector2;
	for(index = 1; index <= barrels; index ++)
	{
		vector1 = cordinate1[index] - position1;
		vector2 = cordinate2[index] - position2;
		vector1 = vector1 + vector1/mass;
		vector2 = vector2 + vector2/mass;
		position1 = position1 + vector1;
		position2 = position2 + vector2;
		mass = mass*2;
		printf(" %f %f \n", vector1, vector2);
	}
	printf(" %f %f \n", position1, position2);
}
int main()
{
	int index;
	int barrels;
	float position1;
	float position2;
	float cordinate1[999];
	float cordinate2[999];
	scanf(" %f", &position1);
	scanf(" %f", &position2);
	scanf(" %d", &barrels);
	for(index = 1; index <= barrels; index ++)
	{
		scanf(" %f", &cordinate1[index]);
		scanf(" %f", &cordinate2[index]);
	 
	}
	PacManEats( barrels,position1, position2, cordinate1, cordinate2);
	return 0;
}
	
	
