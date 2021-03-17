#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//declare variables
	int i;
	int n1;
	int n2;
	int score=0;
	//intitalize
	int count=0;
	int answer;
	srand((int)time(NULL));
	for (i=0;i<10;i++)
	{
		n1 = rand()%13;
		n2 = rand()%13;
		printf("%d * %d =\n",n1,n2);
		scanf("%d",&answer);
	
		if(answer == n1*n2)
		{
			count++;
			printf("Correct\n");
		}
		else
			printf("Wrong... The correct answer is %d\n",n1*n2);
	}			
	printf ("Your score is %d%%\n",count*10);
}
