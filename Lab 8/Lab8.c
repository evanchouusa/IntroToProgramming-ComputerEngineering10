#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
int counter=0;
int quit;
int input;
char schedule[5][20];
char phonenumber[5][20];
int group[5];
int j;
char requestName[20];
char cancelName[20];
char requestLetter[20];
char requestNumber[20];
int  requestGroup;
int size=5;
int flag=0;

//declare function before main (void)
void add();
void delete();
void list();
void enterletter();
void entergroupnumber();

int main(void)
{
	printf("Type 1 to add lessons, 2 to delete lessons, 3 to list lessons, 4 to show names that start with letter, 5 to show groups with a number of people, and 9 to quit program\n");
		for(i=0;i<5;i++){
			schedule[i][0] = '\0';
		}

	while(quit != 1){
		printf("Enter a command: ");
		scanf("%d", &input);

		//printf("%d\n", counter);
		switch(input) {
			case 1:
				add();
				break;
			case 2:
				delete();
				break;
			case 3: 
				list();
				break;
			case 4:
				enterletter();
				break;
			case 5:
				entergroupnumber();
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
//code for void
void add(){ if(counter==5)
				printf("No lesson available\n");
			else{
				requestName[0] = '\0';
				printf("Please enter a name\n");
				scanf("%s", requestName);
					for(i=0; i<size; i++){
						if(strcmp(schedule[i], requestName)==0){
							printf("Sorry, this name is already used. Please restart and enter a different name\n");
								return;
						}
					}
				printf("Please enter your phone number\n");
				scanf("%s", requestNumber);
				printf("Please enter group number\n");
				scanf("%d", &requestGroup);
					if(requestGroup>=5 || requestGroup<=0){
						printf("Please restart and enter a group between 1 and 4. Thank you for your patience.\n");
							return;
						}
				printf("You're lesson is at %d:00pm under the name %s and phone number %s. The group phone number entered is %d\n", counter+1, requestName, requestNumber, requestGroup);
				strcpy(schedule[counter],requestName);
				strcpy(phonenumber[counter],requestNumber);
				group[counter]=requestGroup;
				counter++;
				}
}			
void delete(){ if(counter==0){
					printf("There are no lessons scheduled\n");
					return;
				}
				printf("Enter a name to cancel that lesson:\n");
				scanf("%s", cancelName);
				flag=0;
				for(i=0;i<5;i++){
					if(strcmp(schedule[i], cancelName)==0){
						flag=1;
						printf("Lessons under name %s will be canceled\n", schedule[i]);
						for(j=i;j<counter-1;j++){
							strcpy(schedule[j], schedule[j+1]);
							strcpy(phonenumber[j], phonenumber[j+1]);
							group[j] = group[j+1];
							printf("%s, your time has changed to %d:00pm under the phone number %s and the group number %d\n", schedule[j], j+1, phonenumber[j], group[j]);
						}
						counter--;
						schedule[counter][0]='\0';
						break;
					}
				}
				if(flag==0)
					printf("Entered name not found\n");
				
}
void list(){ if(counter==0){
					printf("No one has scheduled any lessons\n");
					return;
				}
				for(i=0;i<5;i++){
					if(schedule[i][0] == '\0'){
						printf("%d:00pm is free\n", i+1);
					}
					else{
						printf("%d:00pm is booked under name %s under the phone number %s and the group number %d\n",i+1,schedule[i], phonenumber[i], group[i]);
					}
				}
}
void enterletter(){ if(counter==0){
						printf("No one has scheduled any lessons\n");
						return;
					}
					printf("Please enter a letter for the names wanted:\n");
					scanf("%s", requestLetter);
					if(strlen(requestLetter) == 1){
						flag=0;
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
}
void entergroupnumber(){ if(counter==0){
							printf("No groups have scheduled a lesson\n");
							return;
						}
						printf("Please enter a group number:\n");
						scanf("%d", &requestGroup);
							for(i=0;i<counter;i++){
								if(requestGroup == group[i])
									printf("%d:00pm under name %s\n", i+1, schedule[i]);
							}
}









