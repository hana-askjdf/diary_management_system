#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


struct userInfo
{
	char name[10];
	char password[15];
	int number;
}; typedef userInfo Info;

struct record
{
	int year;
	int month;
	int day;
	char contents[20];
};

//나중에 메뉴프린트 하는 코드들은 다른 파일로 옮긴 뒤에, 이 파일로 참조해서 사용하기. 
void print_loginmenu();
void print_diarymenu();
void print_recordmenu();
void print_personalmenu();

int login(Info *user);
/*
int match(); -- check whether entered user info exists in the database or no
int add_user(); -- add user into the databse

*/

void menu(Info* user);
/*
int addRecord();
int editRecord();
int viewRecord();
int deleteRecord();

*/
int updateName(Info *user);
int updatePassword(Info *user);

int main()
{
	Info user[5];
	login(user);
	
	return 0;
}

void print_loginmenu()
{
	printf("=================================\n");
	printf("=             LOGIN             =\n");
	printf("=================================\n");
	printf("Do you have account? (Yes-1/No-2)\nAnswer:");
}
void print_diarymenu()
{
	printf("            MEMU \n");
	printf("-----------------------------\n");
	printf(" Record management        [1]\n");
	printf(" Personal info management [2] \n");
	printf("-----------------------------\n");
	printf("\nEnter your choice: ");
}
void print_recordmenu()
{
	printf("\n         Menu       ");
	printf("\n----------------------\n");
	printf("  Add record    [1] \n");
	printf("  Edit record   [2] \n");
	printf("  View record   [3] \n");
	printf("  Delete record [4] \n");
	printf("  Exit          [5] \n");
	printf("----------------------\n");
	printf("\nEnter your choice: ");
}

void print_personalmenu()
{
	printf("\n          Menu         ");
	printf("\n---------------------------\n");
	printf("  Change User name    [1] \n");
	printf("  Change Password     [2] \n");
	printf("  Exit                [3] \n");
	printf("---------------------------\n");
	printf("\n Enter your choice: ");
}

int login(Info *user)
{
	Info temp;
	int choice, i = 1;
	print_loginmenu();
	scanf("%d",&choice);

	while (i <4)
	{
		switch (choice)
		{

		case 1:
		{
			printf("\nUser name: ");
			scanf("%s", temp.name);
			printf("Password:");
			scanf("%s", temp.password);
			//match();  -- if not match .. print error. 
			i = 4;
			menu(&temp);
			break;
		}
		case 2:
		{
			//add_user();
			printf("add user -- this message has wrote for marking purpose ");
			//menu(&temp);
			i = 4;
			break;
		}
		default:
		{
			printf("\nWARNING! Chance remain (%d/3)times\n\n", 3 - i);
			i++;

			if (i < 4)
			{
				printf("Do you have account? (Yes-1/No-2)\nAnswer:");
				scanf("%d", &choice);
			}
			break;
		}
		}
	}

	return 0;
}
/*
int match() //-- check wheter id & password matches in the database or no.
{
	return 0;
}

int add_user() //collect user's last 4 phonenuber too. 
{
	return 0;
}  

 

*/
void menu(Info *user)
{
	int choice,choice2;
	system("cls");
	printf("*********************************\n");
	printf("******** %5s's Diary  *********\n", user->name);
	printf("*********************************\n\n");

	print_diarymenu();
	scanf("%d",&choice);

	if (choice == 1)
	{
		system("cls");
		print_recordmenu();
		scanf("%d",&choice2);

		switch (choice2)
		{

		case 1:
			printf("num 1");
			//addRecord();
			break;
		case 2:
			printf("#2");
			//editRecord();
			break;
		case 3:
			printf("#3"); 
			//viewRecord();
			break;
		case 4:
			printf("#4"); 
			//deleteRecord();
			break;
		case 5:
			exit(0);
		default:
			printf("Warning: You have put wrong number!\n");
		}
	}
	else if (choice == 2)
	{
		system("cls");
		print_personalmenu();
		scanf("%d", &choice2);
		switch (choice2){
		case 1:
				updateName(user);
				break; 
		case 2:
				updatePassword(user);
				break;
		case 3:
				exit(0);
		default:
			printf("Warning: You have put wrong number!\n");
		}
	}
	
}

/*
int addRecord()
{
	return 0;
}

int editRecord()
{
	return 0;
}

int viewRecord()
{
	return 0;
}

int deleteRecord()
{
	return 0;
}


*/
int updateName(Info *user)
{
	Info temp[300];
	int ans;

	printf("Enter the new name:");
	scanf("%s",temp->name);
	printf("Do you really want to change name %s -> %s? (y-1/n-2)",user->name,temp->name);
	scanf("%d",&ans);
	if (ans == 1)
		strcpy(user->name, temp->name);
	else
		exit(0);

	printf("new name: %s\n",user->name);
	return 0;
}

int updatePassword(Info *user)	
{
	Info temp[30];
	Info temp2[20];

		printf("Enter the current password: ");
		scanf("%s", temp->password);
		
			
		if (strcmp(temp->password, user->password) == 0)
		{
		label:
				printf("Enter the new password: ");
				scanf("%s", temp->password);
				printf("Enter the new password one more: ");
				scanf("%s", temp2->password);

				if (strcmp(temp->password, temp2->password) == 0)
				{
					printf("Password has been updated! \n");
					strcpy(user->password, temp->password);
				
				}
				else
				{
					printf("Warning!; different password has been entered! \n");
					goto label;
				}
			}

			else
			{
				printf("WARNING!; WRONG PASSWORD!\n\n");
				updatePassword(user);
			}	
		
	return 0;
}

