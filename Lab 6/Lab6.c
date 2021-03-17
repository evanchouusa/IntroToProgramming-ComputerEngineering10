#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int count=0;
	int option;
	int position;
	int time;
	//declare variables

	int x[5]={0,0,0,0,0};
	//initialize//
	
	//forever loop starts here
	while(1)

	{

	printf("Type 1 to add lessons, 2 to delete lessons, 3 to list lessons, and 9 to quit program");

	scanf("%d",&option);
		if(option==1)
		{	
   			if(count==5)
				printf("No lesson available\n");

			for(i=0;i<5;i++)
			{	
				if(x[i]==0)
				{	
					x[i]=i+1;
					count++;
					printf("You have added a lesson at %d pm\n",i+1);
					break;
					//schedule
				}
			}	
		}	
		
		else if(option==2)
		{	

			if(count==0)
				printf("no lessons to cancel\n");

			else{
				scanf("%d",&time);
				if(x[time-1]==0)
					printf("no lesson\n");		
	
				else{
					x[time-1]=0;
					count--;
					printf("You have deleted a lesson at: %d pm \n",time);
					//cancel
	
				}
			}
		}

		else if(option==3)
		{
			 if(count==0)
				 printf("no lessons scheduled\n");

			else{ 
			 for(i=0;i<5;i++)
			{	
				if(x[i]==0)
					printf("%d pm is free\n",i+1);
		
				else{
					printf("%d pm is not free\n",i+1);	
					//list lesson
				}
			}
		}

		}
		else if(option==9)
		break;

		else
		printf("Not an option\n");
	}
}
