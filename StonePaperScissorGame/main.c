#include<stdio.h>        
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void play()
{
	char name[20];
	system("cls");
	int i=0,num=0, k=0;
	char *computer[]={" ","stone", "paper", "scissor"};
	char user[50], *result[]={"DRAW", "DEFEATED", "YOU WIN"};
	char fin[3][30];
	
	printf("\t\tEnter your name : ");
	gets(name);
	
	system("cls");
	
	printf("\t\t%s", name);
	printf(" It's a Series of #3\n");
	 
	for(i=1; i<3; i++)
	{
		printf("\n--------------------------GAME%d-------------------------\n\n\t\tSTONE!!PAPER!!SCISSOR  : ", i);
		scanf("%s", &user);
	
		srand(time(0));
		num=rand() % 3 + 1;
	 
 		printf("\n\t\tUser:%s  \n\t\tComputer:%s\n\n\t\tSTATUS[%d]:", user, computer[num], i);

		if(strcmp(user,computer[num])==0)                                   
		{
			printf("DRAW\n\n");
			strcpy(fin[i],result[0]);
		}
	
		else if(strcmp(user,computer[1])==0 && strcmp(computer[num],computer[2])==0)  
		{
			printf("DEFEATED\n\n");
			strcpy(fin[i],result[1]);
		}

	 
		else if(strcmp(user,computer[1])==0 && strcmp(computer[num],computer[3])==0)
		{
			printf("YOU WIN\n\n");
			strcpy(fin[i],result[2]);
		}
	
		else if(strcmp(user,computer[2])==0 && strcmp(computer[num],computer[1])==0)
		{
			printf("YOU WIN\n\n");
			strcpy(fin[i],result[2]);
		}
	
		else if(strcmp(user,computer[2])==0 && strcmp(computer[num],computer[3])==0)
		{
			printf("DEFEATED\n\n");
			strcpy(fin[i],result[1]);
		}
	
		else if(strcmp(user,computer[3])==0 &&strcmp(computer[num],computer[2])==0)
		{
			printf("YOU WIN\n\n");
			strcpy(fin[i],result[2]);
		} 
	
		else if(strcmp(user,computer[3])==0 && strcmp(computer[num],computer[1])==0 )
		{
			printf("DEFEATED\n\n");
			strcpy(fin[i],result[1]);
		}
	
		else 
		{
			printf("invalid string\n\n");
		}
	}
	
	if(strcmp(fin[1],result[0])==0  && strcmp(fin[2],result[0])==0)
	{
 	 
 	printf("RESULT::DRAW");
	}
	
	else if(strcmp(fin[1],result[1])==0 && strcmp(fin[2],result[1])==0)
	{
	printf("RESULT::YOU LOSE");
	}
	else if(strcmp(fin[1],result[2])==0 && strcmp(fin[2],result[2])==0)
	{
	printf("RESULT::YOU WIN");
	}
	
	else if(strcmp(fin[1],result[2])==0 && strcmp(fin[2],result[1])==0)
	{
	printf("RESULT::DRAW");
	}
	
	else if(strcmp(fin[1],result[1])==0 && strcmp(fin[2],result[2])==0)
	{
	printf("RESULT::DRAW");
	}
	
	else if(strcmp(fin[1],result[0])==0 && strcmp(fin[2],result[1])==0)
	{
	printf("RESULT:YOU LOSE");
	}
	
	else if(strcmp(fin[1],result[0])==0 && strcmp(fin[2],result[2])==0)
	{
	printf("RESULT::YOU WIN");
	}
	
	else if(strcmp(fin[1],result[1])==0 && strcmp(fin[2],result[0])==0)
	{
	printf("RESULT::YOU LOSE");
	}
	
	else if(strcmp(fin[1],result[2])==0 && strcmp(fin[2],result[0])==0)
	{
	printf("RESULT::YOU WIN");
	}
	
	else 
	{
	printf("try again");
	}	 
}
int main()
{
	char repeat;
	
	printf("\t\t\t\tMR COMPUTER CHALLENGE\n");
	
	do
	{
    play();
		
	printf("\n\n Do you want to continue YES[Y]/NO[N]");
	fflush(stdin);
	
	repeat=getchar();
	
	system("cls");
	}
	while(repeat=='y' || repeat=='Y');
	
	return 0;	
} 

 
