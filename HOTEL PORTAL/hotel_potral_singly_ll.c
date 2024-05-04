/*Program for hotel potral using singly linked llist
1.Name
ID
Date IN
time IN
Input must not be duplicate*/
/*MENU MAKING PENDING IN THIS PROGRAM*/

/*---------------------------------------------------START--------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>//for malloc.
#include<string.h>
#include<ctype.h>
#include <stdio_ext.h>//for fpurge.

/*---------------------------------------------------FUNCTION DECLARAION--------------------------------------------------*/
struct customer* node_maker();//to make node
int duplicate(struct customer *, int );// search if the ID entered by user is duplicate or not.
char* name_insert(void);// to enter the name in calloc
struct customer* node_maker(void);// to make a new node.
void insert_customer(struct customer **);//to insert a new customer.
void display(struct customer *);// to display all the customers
void date_ip_validation(int *,int *, int *);//for input validatoin of date.
void time_ip_validation(int *,int *);//for input validation of time.
int search(struct customer *head, int target);//to search the element in the queue

/*---------------------------------------------------GLOBAL VARIABLE DECLARAION--------------------------------------------------*/


/*----------------------------------------------------------STRUCT DECLARAION----------------------------------------------------------*/
struct customer
{
	struct customer *next;
	char *name;
	int id;
	struct date
	{
		int day;
		int month;
		int year;
	}dt;
	struct time
	{
		int hr;
		int min;
	}time;

};

/*--------------------------------------------------MAIN START---------------------------------------------------------------------*/
int main()
{

	struct customer *portal = NULL;
	insert_customer(&portal);
	printf("\n%s", portal->name);
	display(portal);
	free(portal);//freeing the portal.


}//main ends

/*--------------------------------------------INSERT CUSTOMER FUNCTION----------------------------------------------------------------*/
void insert_customer(struct customer **portal)
{
	int id, date,month,year,hr,min; // temp var of all func.
	struct customer *temp = NULL; // temp pointer to struct of func.
	printf("\nEnter the ID");
	scanf("%d", &id);

	if(!(*portal))
	{
		temp = node_maker();
		temp->id = id;
		temp->name = name_insert();//to insert name.
		printf("\n\nEnter the date");
		
		date_ip_validation(&date,&month,&year);
		temp->dt.day = date;
		temp->dt.month = month;
		temp->dt.year = year;

		time_ip_validation(&hr,&min);
		temp->time.hr = hr;
		temp->time.min = min;

		*portal = temp;// as first node then assign to the head (portal).
	}//if ends
	//else first find if the id entered is duplicate or not if not then enter the id in the linked list.
	else
	{
		//if duplicate ID is present then throw error to user
		if(duplicate(*portal, id))
		{
			printf("\nError duplicate ID");
			return;
		}//if ends
		//else insert the node at the last
		else
		{	struct customer *trav = NULL;
			trav = *portal;
			temp = node_maker();
			temp->id = id;
			temp->name = name_insert();//to insert name.

			date_ip_validation(&date,&month,&year);
			temp->dt.day = date;
			temp->dt.month = month;
			temp->dt.year = year;

			time_ip_validation(&hr,&min);
			temp->time.hr = hr;
			temp->time.min = min;

			while(!trav->next)
			{
				trav = trav->next;//traversing the pointer to the last.
			}//while ends

			trav->next = temp;//inserting the node at the ends.
		}//else ends
	}//else ends


}//insert customer ends

/*---------------------------------------------------TIME INPUT VALADITION FUNCTION--------------------------------------------------*/
void time_ip_validation(int *hr,int *min)
{
	int flag_hr =0;
	int flag_min = 0;
	
	int temp;
	//input validation for hour.
	do{
		printf("Enter hour in 24 format: ");
		scanf("%d", &temp);
		if(temp>0 && temp<24)
		{
			flag_hr = 0;
			*hr = temp;
		}//if ends
		else
		{
			flag_hr = 1;
		}//else ends
	}while(flag_hr == 1);	

	//now for minute
	do{
		printf("Enter minutes");
		scanf("%d", &temp);
		if(temp>=0 && temp<60)
		{
			flag_min = 0;
			*min = temp;
		}//if ends
		else
		{
			flag_min = 1;
		}//else ends
	}while(flag_min == 1);//do while ends
}//time user validation ends

/*---------------------------------------------------DATE INPUT VALADITION FUNCTION--------------------------------------------------*/
void date_ip_validation(int *day,int *month, int *year)
{
	int flag_date =0;
	int flag_month = 0;
	int flag_year = 0;
	int temp;
	do{
		printf("Enter day");
		scanf("%d", &temp);
		if(temp>0 && temp<31)
		{
			flag_date = 0;
			*day = temp;
		}//if ends
		else
		{
			flag_date = 1;
		}//else ends
	}while(flag_date == 1);	

	do{
		printf("Enter month");
		scanf("%d", &temp);
		if(temp>0 && temp<13)
		{
			flag_month = 0;
			*month = temp;
		}//if ends
		else
		{
			flag_month = 1;
		}//else ends
	}while(flag_month == 1);

	do{
		printf("Enter year");
		int scanf_result = scanf("%d", &temp);
		if(scanf_result == 1)
		{
			flag_year = 0;
			*year = temp;
		}//if ends
		else
		{
			flag_year = 1;
		}//else ends
	}while(flag_year == 1);
}//date input validation.

/*---------------------------------------------------NAME INSERT FUNCTION--------------------------------------------------*/
char* name_insert(void)
{
	char buff[100];
	while(1){
		printf("\n\nEnter the name of customer:");
		__fpurge(stdin);
		fgets(buff,100,stdin);
		int len = strlen(buff);
		if((strspn(buff,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == len))
		{
			printf("\n\nENTER PROPER STRING");
		}//if ends
		else 
			break;
	}//while ends
	char *name = NULL;
	name = (char*)calloc(1,strlen(buff));
	if(!name)
	{
		perror("\n\nError in allocating memory for Name");
		exit(0);
	}//if ends
	else 
		strcpy(name,buff);
		return name;
}//name_insert ends

/*---------------------------------------------------SEARCH FUNCTION--------------------------------------------------*/
int duplicate(struct customer *head, int target)
{
	struct customer *trav = NULL;
	trav = head;
	while(!trav->next)
	{
		if(trav->id == target)
		{
			return 1;
		}//if ends
		else return 0;
	}//while ends

}//search ends

/*---------------------------------------------SEARCH FUNCTION-----------------------------------------------------*/
/*TO search the ID in the list*/
int search(struct customer *head, int target)
{
	int count = 0;
	struct customer *trav = NULL;
	trav = head;
	while(trav->next != NULL)
	{
		if(target == trav->id)
		{
			return count;
		}
		else if(trav->next == NULL)
		{
				printf("\n\tERROR ID NOT IN DATABASE\n");
		}
		else
			count ++;
	}//while ends
}//search ends

/*-------------------------------------------------MODIFY--------------------------------------------------------------*/
void modify(struct customer **head, int cnt)
{
	struct customer *trav = NULL;
	trav = *head;
	int temp;
	char *name;

	for(int i=0; i<cnt; i++)
	{
		trav = trav->next;
	}//for ends

	printf("\n\nDetails ");
	printf("\nCurrent ID: %d", trav->id);
	printf("\nCurrent Name: %s", trav->name);
	printf("\nDate: %d/%d/%d ", trav->dt.day,trav->dt.month,trav->dt.year);

	int choice;
	printf("\n\n========================MODIFICATION MENU=================================");
	printf("\n\t1.ID\t2.Name");
	printf("\n\nEnter what you want to modify");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: while(1){
					printf("\nEnter the modified ID");
					scanf("%d", &temp);
					int flag = duplicate(*head,temp);
					if(flag)
					{
						trav->id = temp;
						printf("\n\nDetails ");
						printf("\nCurrent ID: %d", trav->id);
						printf("\nCurrent Name: %s", trav->name);
						printf("\nDate: %d/%d/%d ", trav->dt.day,trav->dt.month,trav->dt.year);
	
						break;
					}
				}//while ends
		
		case 2: name = name_insert();
				printf("\n\nDetails ");
				printf("\nCurrent ID: %d", trav->id);
				printf("\nCurrent Name: %s", trav->name);
				printf("\nDate: %d/%d/%d ", trav->dt.day,trav->dt.month,trav->dt.year);
				break;				
	}//switch end



}//modify ends

/*---------------------------------------------------DELETE FUNCTION---------------------------------------------------*/
void delete_at_pos(struct customer **head, int pos)
{
	struct customer *temp =  NULL;
	temp = *head;

	for(int i=0; i<=pos; i++)
	{
		temp = temp->next;
	}//for ends
	temp->id = 0;
	temp->dt.day = 0;
	temp->dt.month = 0;
	temp->dt.year = 0;
	temp->dt.day = 0;
	temp->time.hr = 0;
	temp->time.min = 0;
}//delete at ends ends

/*---------------------------------------------------DISPLAY FUNCTION--------------------------------------------------*/
void display(struct customer *portal)
{
	struct customer *trav = NULL;
	trav = portal; 

	while(trav)
	{
		printf("\n%d", trav->id);
		printf("\n%s", trav->name);
		trav = trav->next;//traversing
	} 
}//display ends
struct customer* node_maker(void)
{
	struct customer *temp = NULL;
	temp = (struct customer*)calloc(1,sizeof(struct customer));
	if(!temp)
	{
		perror("\n\nError in malloc");
		exit(0);
	}
	else 
		return temp;
}//insert ends.


/*-----------------------------------------------------END---------------------------------------------------------*/
