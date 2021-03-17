#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter=0;
int input;//for switch statement
char schedule[5][20];
char phonenumber[5][20];
int group[5];
char lettercheck;
int oletter;

//declare function before main (void)
void add();
void delete();
void list();
void enterletter();
void entergroupnumber();
int priority();
int count_letter(char lettercheck);

int main(void)
{
	int flag=0;
	int i;
	int quit;
	printf("Type 1 to add lessons, 2 to delete lessons, 3 to list lessons, 4 to show names that start with letter, 5 to show groups with a number of people, 6 to prioritize, 7 to count letters, and 9 to quit program\n");
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
			case 6:
				if(flag==1)
				{
					printf("No more priority today\n");
					break;
				}
				flag=priority();
				break;
			case 7:
				printf("Please enter a letter you'd like to check\n");
				scanf(" %c", &lettercheck);
				oletter = count_letter(lettercheck);
				printf("%d times for %c\n", oletter, lettercheck);
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
void add(){
			char requestNumber[20];
			char requestName[20];
			int requestGroup;
   			int size=5;	
			int i;
			if(counter==5)
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
void delete(){
   				char cancelName[20];	
				int size=5;
				int flag=0;
				int j;
				int i;
				if(counter==0){
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
void list(){
				int size=5;
				int i;
   				if(counter==0){
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
void enterletter(){ 
					char requestLetter[20];
					int size=1;
					int flag=0;
					int i;
					if(counter==0){
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
void entergroupnumber(){ 
						int requestGroup;
						int size=5;
						int i;
						if(counter==0){
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
int priority(){	
	char requestNumber[20];
	char requestName[20];
	int requestGroup;
	int size=5;
	int i;
	requestName[0] = '\0';
	printf("Please enter a name\n");
	scanf("%s", requestName);
	for(i=0; i<size; i++){
		if(strcmp(schedule[i], requestName)==0){
			printf("Sorry, this name is already used. Please restart and enter a different name\n");
			return 0;
		}
	}
	printf("Please enter your phone number\n");
	scanf("%s", requestNumber);
	printf("Please enter group number\n");
	scanf("%d", &requestGroup);
		if(requestGroup>=5 || requestGroup<=0){
			printf("Please restart and enter a group between 1 and 4. Thank you for you patience.\n");
			return 0;
		}

	if(counter==5){
		i=3;
		printf("%s, under the phone number %s and group number %d, your lesson has been canceled due to priority\n", schedule[4], phonenumber[4], group[4]);
	}
	else{ 
		i=counter-1;	
	}	

	for( ; i>=0; i--){
		strcpy(schedule[i+1], schedule[i]);
		strcpy(phonenumber[i+1], phonenumber[i]);
		group[i+1] = group[i];
		printf("%s, your time has changed to %d:00pm under the phone number %s and the group number %d\n", schedule[i+1], i+2, phonenumber[i+1], group[i+1]);
	}

	strcpy(schedule[0], requestName);
	strcpy(phonenumber[0], requestNumber);
	group[0] = requestGroup;
	if(counter!=5)
		counter++;

	printf("You're lesson is at 1:00pm under the name %s and phone number %s. The group number entered is %d.\n", requestName, requestNumber, requestGroup);
	return 1;
}
int count_letter(char lettercheck){
		int size=5;
		int i;
		int j;
		j=0;
		char *c;
		for(i=0; i<size; i++){
			c = schedule[i];
			while(*c != '\0'){
				if(*c == lettercheck){
					j++;
				}
				c++;
			}
		}
		return j;
}








