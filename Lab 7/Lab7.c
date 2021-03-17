#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i;
int counter=0;
int quit;
int input;
char schedule[5][20];
int j;
char requestName[20];
char cancelName[20];
char requestLetter[20];
int flag=0;

int main(void)
{
	printf("Type 1 to add lessons, 2 to delete lessons, 3 to list lessons, 4 to show names that start with letter, and 9 to quit program\n");
	for(i=0;i<5;i++){
		schedule[i][0] = '\0';
	}

	while(quit != 1){
		printf("Enter a command: ");
		scanf("%d", &input);

		//printf("%d\n", counter);
		switch(input) {
			case 1:
				if(counter==5)
					printf("No lesson available\n");
				else{
					requestName[0] = '\0';
					printf("Please enter a name\n");
					scanf("%s", requestName);
					printf("You're lesson is at %d:00pm under the name %s\n", counter+1, requestName);
					strcpy(schedule[counter],requestName);
					counter++;
				}
				break;
			case 2:
				if(counter==0){
					printf("There are no lessons scheduled, so no lessons to cancel\n");
					break;
				}
				printf("Enter a name to cancel that lesson:\n");
				scanf("%s", cancelName);
				flag = 0;
				for(i=0;i<5;i++){
					if(strcmp(schedule[i], cancelName)==0){
						flag=1;
						printf("Lessons under name %s will be canceled\n", schedule[i]);
						for(j=i;j<4;j++){
							strcpy(schedule[j], schedule[j+1]);
						}
						counter--;
						schedule[counter][0]='\0';
						break;
					}
				}
				if(flag==0)
					printf("Entered name not found\n");
				break;
			case 3: 
				if(counter==0){
					printf("No one has scheduled any lessons\n");
					break;
				}
				for(i=0;i<5;i++){
					if(schedule[i][0] == '\0'){
						printf("%d:00pm is free\n", i+1);
					}
					else{
						printf("%d:00pm is booked under name %s\n",i+1,schedule[i]);
					}
				}
				break;
			case 4:
				if(counter==0){
					printf("No one has scheduled any lessons\n");
					break;
				}
				printf("Please enter a letter for the names wanted:\n");
				scanf("%s", requestLetter);
				if(strlen(requestLetter) == 1){
					flag = 0;
					for(i=0;i<5;i++){
						if(schedule[i][0] == requestLetter[0]){
							flag=1;
							printf("%d:00pm is booked under name: %s\n",i+1,schedule[i]);
						}
					}
						if(flag==0){
							printf("There are no names that match your letter\n");
						}
				}
				else if(strlen(requestLetter) != 1){
					printf("Please only enter one letter\n");
				}
				break;
			case 9:
				printf("Quitting...");
				quit = 1;
				break;
			default:
				if(quit == 0){
					printf("Please enter one of the correct commands\n");
				}
				break;
		}
	}
return 0;

}










