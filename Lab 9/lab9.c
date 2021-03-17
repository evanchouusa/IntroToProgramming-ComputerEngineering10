#include<stdio.h>
#include<strings.h>
#include<ctype.h>

//Prototype Functions
void inputStrings(void);
void reverse(void);
void toUpper(void);
void info(void);
void outputArray(void);

//Global variables
char strings[10][20];
int counter=0;
int length[10];

int main(){
	inputStrings();

	reverse();

	toUpper();

	info();

	return 0;
}

void inputStrings(){
	int i;
	for(i=0;i<10;i++){
		int x=scanf("%s", strings[i]);
		if(x<1){
			break;
		}
		counter++;
	}

	char temp[20];
	int j;
	//Alphabetizing Array
	if(counter>1){
		for(i=1;i<counter;i++){
			for(j=1;j<counter;j++){
				if(strcmp(strings[j-1],strings[j])>0){
					strcpy(temp,strings[j-1]);
					strcpy(strings[j-1],strings[j]);
					strcpy(strings[j],temp);
				}
			}
		}
	}
	printf("\ninputed strings alphabetized:\n");
	outputArray();
}

void reverse(){

	int i=0;
	int j=counter-1;
	int sum=0;
	char temp[20];
	while(i<j)
	{
		strcpy(temp,strings[i]);
		strcpy(strings[i],strings[j]);
		strcpy(strings[j],temp);
		i++;
		j--;
	}

	printf("Reversing the array:\n");
	outputArray();
}

void toUpper(){
	int sum=0;
	int i;
	for(i=0;i<counter;i++){
		char *p;
		p=strings[i];
		
		while(*p!='\0'){
			if(islower(*p)){
				*p=toupper(*p);
			}
			p++;
			sum++;
			//printf("Debug: %d", sum);
		}
		length[i]=sum;
		sum=0;
	}
	printf("All toUpper:\n");
	outputArray();
}

void info(){
	int i;
	//char shortest[20], longest[20];
	
	int sum=0;
	int average;

	printf("\n");
	int min=length[0];
	int max=length[0];
	int minPos=0;
	int maxPos=0;
	for(i=0;i<counter;i++){
		//printf("Debug: %d, %d", min, minPos); 
		if(length[i]<min){
			min=length[i];
			minPos=i;
		}
		else if(length[i]>max){
			max=length[i];
			maxPos=i;
		}
		sum=sum+length[i];
	}
	average=sum/counter;

	printf("Shortest: %s\nLongest: %s\nAverage Length: %d\nWords that starts with something other than letter:\n", strings[minPos], strings[maxPos], average);
	int flag=0;
	for(i=0;i<counter;i++){
		if(!isalpha(strings[i][0])){
			printf("%s\n",strings[i]);
			flag=1;
		}
	}
	if(flag==0){
		printf("All strings start with letters\n");
	}
}

void outputArray(){
	int i;
	for(i=0;i<counter;i++){
		printf("%s\n",strings[i]);
	}
	printf("\n");
}
