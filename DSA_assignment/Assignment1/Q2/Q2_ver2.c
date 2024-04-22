/*
 Q2. Create an employee structure with the following members
empid, employee name, salary, year of joining etc.
Accept the data for certain no. o of employees and find their total,
average, max, min salary.
Also find out the employees with maximum, minimum service,use a
function to find service for each employee element in the array.*/


#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include <stdlib.h>


int i=0;

typedef struct employee{
	unsigned int empid : 16;
	char *name;
	long int salary;
	struct{
		short int date;
		short int mon;
		short int year;
	}y;
	char gen[6];
	unsigned int age:8;

}employee;

void input(employee *);
void display(employee *,int);
int search(employee *);
void modify(employee *);
void total_salary(employee *);
void average_salary(employee *);
void min_salary(employee *);
void max_salary(employee *);
int t_duration(employee *,int);
void min_service(employee *);
void max_service(employee *);

int main(){
	employee a;
	employee *emp;
/*
	printf("Enter number of employees:");
	scanf("%d",&n);*/
/*Here the number of employees to be added in this program is lmited to 10, currently
one can enter as much as employees he wants just by modifying the hardcoded value 10 to a variable of user input.
*/
	emp=(employee *)malloc(sizeof(a)*10);
	//NULL check
	if(emp == NULL){
		perror("\n\tMemory allocation failed\n");
		exit(0)
	}// if ends
	int n,temp;//Local var n to take(user input) no of employees, temp to catch the status of search,etc.

	while(1)
	{
		printf("Enter \n1: Input Data\n2:Displaying all Employee details\n");
	printf("3: Update details of an employee based on name\n4: Search and display employee details based on name\n5: Total Salary of all Employees\n6: Average Salary of all employees\n7: Minimum Salary among all employees\n8: Maximum salary among all employees\n 9: Minimum serive employee\n10: Maximum serivice employee\n0: Exit\n");
	printf("Enter a choice: ");
	scanf("%d",&n);
		switch(n){
				case 1:
				//To take input of employee details
					input(emp);
					break;
				case 2:
				//For displaying the employees
					for(int j=0;j<i;j++)
					{
					display(emp,j);
					}
					break;
				case 3:
				//For modofying the details
					modify(emp);
					break;
				case 4:
				//For searching the details
					temp=search(emp);
					break;
				case 5:
				//To find the total salary
					total_salary(emp);
					break;
				case 6:
				//To find the avg salary
					average_salary(emp);
					break;
				case 7:
				//To find the min salary
					min_salary(emp);
					break;
				case 8:
				//To find the max salary
					max_salary(emp);
					break;
				case 9:
				//To find the min service years.
					min_service(emp);
					break;
				case 10:
				//To print the max service years
					printf("1yoj: ");
					max_service(emp);
					break;
				case 0:
					
					printf("=======================================EXITING=============================================");
					//Before exiting the program we need to free the memory so as to avoid memory leaks.
					for(int j=0;j<i;j++)
					{
					free((emp+j)->name);
					free(emp+j);
					}
					emp->name=NULL;
					emp=NULL;
					return -1;

				default:
				//if user enters something else than 0 to 10 
					printf("Invalid input\n");
					break;
		}
		printf("\n\n");
	}
	return 0;

}

//Function to input the details of employees
void input(employee *e)
{

	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int temp,flag=0;
	char buff[20];//Temp buffer to catch the eployee name.

	
	printf("Your Employee ID: %d\n",i+1);
	
	e[i].empid=i+1;

	printf("Enter employee name: ");
	scanf("%s",buff);
	printf("\n");

	e[i].name=(char *)malloc(sizeof(buff));//Malloc the name, as we don't know the length of string.

	strcpy(e[i].name, buff);//Copy the name to heap.

	printf("Enter salary Rs: ");
	scanf("%ld",&e[i].salary);
	__fpurge(stdin);
	printf("\n");


	printf("Enter emplyee year of joining in (dd/mm/yy)=");
	scanf("%hu/%hu/%hu", &e[i].y.date, &e[i].y.mon, &e[i].y.year);
	__fpurge(stdin);
	printf("\n");

	printf("Enter Gender: ");
	scanf("%s",e[i].gen);
	__fpurge(stdin);
	printf("\n");

//Input valadation for age (age must be between 18 to 60).
	do{
	printf("Enter age: ");
	scanf("%d",&temp);
	__fpurge(stdin);
	printf("\n");

	if(18>temp&temp>60)
	{
		printf("Age is not in the range.(0-1000)\n Enter age again\n");
		flag=1;//Flag is set so as to run this loop infinetly until we get the correct input from user
	}
	else{
	e[i].age=temp;
	flag=0;//Resetting the flag if input is within the range
	}
	}while(flag==1
	i++;
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
}//Input ends

//Function to display the details
void display(employee *e,int j)
{
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");

		printf("==========Employee ID: %u=============\n",e[j].empid);
		printf("Employee name: %s\n",e[j].name);
		printf("Salary: %ld\n",e[j].salary);
		printf("Year of joining: %d/%d/%d\n",e[j].y.date, e[j].y.mon, e[j].y.year);

		printf("Gender: %s\n",e[j].gen);
		printf("Age: %u\n",e[j].age);
		
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
}//Display ends

//Func to search the employee details through name.
int search(employee *p)
{
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\ns");
	char ch[20];
	printf("\nEnter name:");
	scanf(" %[^\n]s",ch);//User input name

//Loop to iterate through the name
	for(int j=0;j<i;j++)
	{
		if(!strcmp(p[j].name,ch))//Comparing the string
		{
			display(p,j);
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
			return j;//Returns the index if match found
		}
	}
	printf("no match");//If no match found.
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	return -1;//returns -1 of no match is found.
}//Search ends

//Func to modify the detais of employee
void modify(employee *p)
{
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int choice,k;
	char buff[20];
	int j=search(p);
	if(j<0)
	{
		return;
	}

	printf("\n\t:Modification:\n Choose Option no: \n 1. Name \n 2. Salary \n");
	scanf("%d",&choice);
	
	printf("\n =============================== Employee %d =============================== \n",p[j].empid);

	switch(choice)
	{
		case 1:
			printf("Enter employee name: ");
			__fpurge(stdin);
			scanf("%[^\n]s",buff);
			printf("\n");
			strcpy(p[j].name, buff);
			__fpurge(stdin);
			break;
		case 2:
			printf("Enter salary Rs: ");
			__fpurge(stdin);
			scanf("%ld",&p[j].salary);
			__fpurge(stdin);
			break;
		
		default:
			printf("choose correct option\n");
			break;
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
}

void total_salary(employee *e)
{
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	long int total=0;
	for(int j=0;j<i;j++)
	{
		total=total+e[j].salary;
	}
	printf("\n\n\t Total Salary is %ld\n\n",total);
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void average_salary(employee *e)
{
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	long int total=0;
	float avg;
	for(int j=0;j<i;j++)
	{
		total=total+e[j].salary;
	}
	avg=(float)total/i;
	printf("\n\n\t Average of all employees Salary is %f\n\n\t",avg);
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void min_salary(employee *e)
{
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int j=0,n;
	int temp=e[j].salary;
	for(j=0;j<i;j++)
	{
		if(e[j].salary<temp)
		{
			temp=e[j].salary;
			n=j;
		}
	}
	printf("\n\nEmployee name: %s\nMinimum salary is %d\n\t",e[n].name,temp);
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void max_salary(employee *e)
{
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int j=0,n;
	int temp=e[j].salary;
	for(j=0;j<i;j++)
	{
		if(e[j].salary>temp)
		{
			temp=e[j].salary;
			n=j;
		}
	}
	printf("\n\n Employee Name: %s\nMaximum salary is %d\n\n\t",e[n].name,temp);
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
int t_duration(employee *e,int j)
{
	int duration=0;
	duration=duration+(365*(2023-(e[j].y.year)));
	duration=duration+(30*(12-(e[j].y.mon)));
	duration=duration+(30-e[j].y.date);
	return duration;
}




void max_service(employee *e)
{
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int ms=t_duration(e,0);
		printf("ms=%d\n",ms);
		int n=0;
		for(int j=1;j<i;j++)
		{
			int temp=t_duration(e,j);
			if(ms<temp)
				{
					ms=temp;
					n=j;
				}
		}
		printf("Employe with maximum service is %s\n",e[n].name);
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

void min_service(employee *e)
{	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int ms=t_duration(e,0);
		int n=0;
		for(int j=1;j<i;j++)
		{
			int temp=t_duration(e,j);
			if(ms>temp)                               
				{
					ms=temp;   
					n=j;
				}
		}
	
	printf("Employee with Minimum service is %s\n",e[n].name);
		printf("----------------------------------------------------------------------------------------------------------------------------------------------------------");
}
