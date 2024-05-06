/*
Program for student record manager in doubly linked list.


RULES: 
1. Marks cannot be less than 0 or more than 100.
2. Student in the class cannot be more than 100.(It can be altered by changing the value of macro defined on line number 20)

*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include<stdio_ext.h>

#define RED "\x1b[31m" // changes the text colour on terminal to red in terminal.
#define RESET "\x1b[0m"// changes the text colour back to normal in terminal
#define MAX_OPTION 6 // for switch case options	
#define MAX_STUDENT 100 //Max student in class


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++STRUCTURE+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
typedef struct nd
{
 	struct nd *prev;
	struct nd *next;
	int roll;
	char *name;
	int contact;
	struct mk // nested structure for marks
	{
		int eng;
		int math;
		int sci;
	}marks;
}node;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++FUNCTION PROTOTYPES++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void print_menu(void);// to print the menu.
node* node_maker(int *); // to make the node
void display(node *);// to display the function
void input_sorted(node **, int *);// to input in sorted manner
char* name_input(void);// to input the name in the heap.
char* roll_input(void);// to enter the roll number.
int duplicate(node *head, int);// to find if the roll number already present or not
void delete_all(node **head);// to delete all nodes.
void modify(node *);
void search(node *);
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ MAIN ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main()
{
	int count = 0;// to keep the count of node
	int user_ip;// temp var to insert user choice in switch case
	node *head = NULL;// head pointer
	enum option{Exit,Insert,Delete,Modify,Search, Delete_all};
	enum option choice;// enum var
	while (1)
	{
		int flag = 0;
		do{
			printf("\n\n========================= STUDENT RECORD LOGGER ========================================");
			printf("\n===================================MENU=======================================");
			print_menu();
			scanf("%d", &user_ip);
			
			if((user_ip > -1) && (user_ip > MAX_OPTION))// user input validation for options
			{
				flag = 1;
				printf(RED"\n\n\tERROR! Incorrect option\n"RESET);

			}//if ends
			else
			{
				choice = user_ip;
				break;
			}//else ends
		}while(flag == 1);

		switch(choice)
		{
			case Exit : 	printf("\nExited         ");
							system("clear");
							exit(0);

			case Insert: 	input_sorted(&head, &count);
							break;

			case Delete:	delete_all(&head);
							break;

			case Modify:	modify(head);
							break;

			case Search:	search(head);
							break;

			case Delete_all: while(count)
							 {
							 	delete_all(&head);
							 	--count;
							 }//while ends
		}//switch case ends.
	}//while ends
}//main ends
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++SEARCH FUNCTION++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void search(node *head)
{
	if(!head)
	{
		printf(RED"\n\n\tERROR! No Student\n"RESET);
		return;
	}
	else{
		int target;
		node *trav = head;
	printf("\nEnter the roll number to search");
	scanf("%d", &target);
			//traversing
			while((trav->next != NULL) && (trav->roll == target))
			{
				trav = trav->next;
			}//while ends
			printf("\n");
			printf("\nRoll no: %d", trav->roll);
			printf("\nName: %s", trav->name);
			printf("\n\tContact: %d", trav->contact);
			printf("\n\n\tMarks for each subject");
			printf("\n\tEnglish: %d", trav->marks.eng);
			printf("\n\tScience: %d", trav->marks.sci);
			printf("\n\tMaths:   %d", trav->marks.math);	
	}//else ends
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++MODIFY FUNCTION++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void modify(node *head)
{
	if(!head)
	{
		printf(RED"\n\n\tERROR! No Student\n"RESET);
		return;
	}
	else
	{
		int target, choice, choice2;
		int marks,contact, temp_flag =0;
		node *trav = head;
		while(1)
		{
			printf("\n\n----------------------------------MODIFY---------------------------------------------");
			printf("\nDiscription: Here you can only modify the Marks of a subject and contact of a student");
			printf("\nEnter the Roll Number: ");
			scanf("%d", &target);
			//traversing
			while((trav->next != NULL) && (trav->roll == target))
			{
				trav = trav->next;
			}//while ends
			printf("\n");
			printf("\nRoll no: %d", trav->roll);
			printf("\nName: %s", trav->name);
			printf("\n\tContact: %d", trav->contact);
			printf("\n\n\tMarks for each subject");
			printf("\n\tEnglish: %d", trav->marks.eng);
			printf("\n\tScience: %d", trav->marks.sci);
			printf("\n\tMaths:   %d", trav->marks.math);	

			printf("\nWhat you want to modify?");
			printf("\n1.Marks\n2.contact");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1: printf("Which marks you want to modify?");
						printf("\n1.English\n2.Maths\n3.Science\n0.Exit");
						switch(choice2)
						{
							case 0: printf("\nExiting Modify\n");
									break;
							case 1: 	do{
											temp_flag = 0;
											printf("\nEnter makrs for English");
											scanf("%d", &marks);
											if((marks >-1) && (marks<101))
											{
											temp_flag = 0;
											trav->marks.eng = marks;
										}
										else
										{
											printf(RED"\n\n\tERROR! Marks cannot be less than -1 or more than 100\n"RESET);
											temp_flag = 1;
										}
									}while(temp_flag == 1);
									printf("\nRoll no: %d", trav->roll);
									printf("\nName: %s", trav->name);
									printf("\n\tContact: %d", trav->contact);
									printf("\n\n\tMarks for each subject");
									printf("\n\tEnglish: %d", trav->marks.eng);
									printf("\n\tScience: %d", trav->marks.sci);
									printf("\n\tMaths:   %d", trav->marks.math);
									break;

							case 2:
									do{
										temp_flag = 0;
										printf("\nEnter makrs for Maths");
										scanf("%d", &marks);
										if((marks >-1) && (marks<101))
										{
											temp_flag = 0;
											trav->marks.math = marks;
										}//if ends
										else
										{
											printf(RED"\n\n\tERROR! Marks cannot be less than -1 or more than 100\n"RESET);
											temp_flag = 1;
										}//else ends
									}while(temp_flag == 1);
									printf("\nRoll no: %d", trav->roll);
									printf("\nName: %s", trav->name);
									printf("\n\tContact: %d", trav->contact);
									printf("\n\n\tMarks for each subject");
									printf("\n\tEnglish: %d", trav->marks.eng);
									printf("\n\tScience: %d", trav->marks.sci);
									printf("\n\tMaths:   %d", trav->marks.math);

							case 3: do{
										printf("\nEnter makrs for Science");
										scanf("%d",&marks);
										if((marks >-1) && (marks<101))
										{
											temp_flag = 0;
											trav->marks.sci = marks;
										}// if ends
										else
										{
											printf(RED"\n\n\tERROR! Marks cannot be less than -1 or more than 100\n"RESET);
											temp_flag = 1;
										}//else ends
									}while(temp_flag == 1);
									printf("\nRoll no: %d", trav->roll);
									printf("\nName: %s", trav->name);
									printf("\n\tContact: %d", trav->contact);
									printf("\n\n\tMarks for each subject");
									printf("\n\tEnglish: %d", trav->marks.eng);
									printf("\n\tScience: %d", trav->marks.sci);
									printf("\n\tMaths:   %d", trav->marks.math);
						}//nested case ends
						break;
				case 2: printf("\nEnter the updated contact number: ");
						scanf("%d", &contact);
						do{
							temp_flag = 0;
							printf("\nEnter the contact");
							scanf("%d", &contact);
							if((contact%1000000000) == 0)
							{
								temp_flag = 0;
								trav->contact = contact;

							}//if ends
							else
							{
								printf(RED"\n\n\tERROR! in contact number %d \n"RESET, MAX_STUDENT);
								temp_flag = 1;
							}
						}while(temp_flag ==1);

			}//switch ends
		}//while ends
	}//else ends.
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++DELELETE FUNCTON+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void delete_all(node **head)
{
	if(!(*head))
	{
		printf(RED"\n\n\tERROR! No Student\n"RESET);
		return;
	}
	else{
		node *temp = NULL;
		temp->name = NULL;
		free(temp->name);//freeing the name mallocked array
		temp->roll = 0;
		temp->marks.eng = 0;
		temp->marks.math = 0;
		temp->marks.sci = 0;
		(*head) = temp->next;
		temp->next = NULL;
		free(temp);
	}//else ends
}//delete all end

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++INPUT SORTED+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void input_sorted(node **head, int *count)
{
	int temp_flag = 0;
	int marks, roll, contact;
	node *temp= NULL;// temp pointer
	temp = (node*)calloc(1,sizeof(node));// making new node
	if(!temp)
	{
		perror("\n\nError in Allocating memory");
		exit(1);
	}
	++(*count);//incrimenting the node count.

	printf("\n\nEnter the marks");
	//validation for english marks
	do{
		temp_flag = 0;
		printf("\nEnter marks for English: ");
		scanf("%d", &marks);
		if((marks >-1) && (marks<101))
		{
			temp_flag = 0;
			temp->marks.eng = marks;
		}
		else
		{
			printf(RED"\n\n\tERROR! Marks cannot be less than -1 or more than 100\n"RESET);
			temp_flag = 1;
		}
	}while(temp_flag == 1);
	//validation for maths marks
	do{
		temp_flag = 0;
		printf("\nEnter marks for Maths: ");
		scanf("%d", &marks);
		if((marks >-1) && (marks<101))
		{
			temp_flag = 0;
			temp->marks.math = marks;
		}//if ends
		else
		{
			printf(RED"\n\n\tERROR! Marks cannot be less than -1 or more than 100\n"RESET);
			temp_flag = 1;
		}//else ends
	}while(temp_flag == 1);
	//validation for science marks
	do{
		printf("\nEnter marks for Science: ");
		scanf("%d", &marks);
		if((marks >-1) && (marks<101))
		{
			temp_flag = 0;
			temp->marks.sci = marks;
		}// if ends
		else
		{
			printf(RED"\n\n\tERROR! Marks cannot be less than -1 or more than 100\n"RESET);
			temp_flag = 1;
		}//else ends
	}while(temp_flag == 1);
	
	//roll number insertion
	do{
		temp_flag = 0;
		printf("\nEnter Roll Number: ");
		scanf("%d", &roll);
		// int dup = duplicate(*head, roll);
		// printf("Duplicate: %d", dup);

		if(duplicate(*head, roll)&&(roll >0) && (marks<MAX_STUDENT))
		{
			temp_flag = 0;
			temp->roll = roll;
		}//if ends
		else
		{
			printf(RED"\n\n\tERROR! Roll Number cannot be less than 1 or more than %d \n"RESET, MAX_STUDENT);
			temp_flag = 1;
		}//else ends
	}while(temp_flag == 1);
	

	temp->name = name_input();

	do{
		temp_flag = 0;
		printf("\nEnter the contact");
		scanf("%d", &contact);
		if((contact%100000000) != 0)
		{
			temp_flag = 0;
			temp->contact = contact;

		}//if ends
		else
		{
			printf(RED"\n\n\tERROR! in contact number %d \n"RESET, MAX_STUDENT);
			temp_flag = 1;
		}
	}while(temp_flag ==1);
	
	temp->prev = NULL;
	temp->next = NULL;
	node *trav = *head;
	
	//insertion of node.
	if(*head == NULL)// inserting first node
	{
		//printf("\n*****Here0");//debugger
		*head = temp;
	}//if ends
	else
	{
		if(trav->roll > temp->roll)//insert at beginging
		{
			//printf("\n*****HereBegning");// debugger
			temp->next = *head;
			(*head)->prev = temp;
			(*head) = temp;
		}//if ends
		else
		{
			trav = *head;
			while((trav->next!=NULL) && (trav->next->roll < temp->roll))
			{
				//printf("\n*****Here");//debugger
				trav = trav->next;
			}//while ends
			if(trav->next == NULL)//insert at end.
			{
				printf("\n*****Her2");//debugger
				trav->next = temp;
				temp->prev = trav;

			}//if end
			else				//insert at pos
			{
				//printf("\n*****Her3");// debugger
				temp->prev = trav;
				temp->next = trav->next;
				trav->next->prev = temp;
				trav->next = temp;

			}//double nested else ends
		}//nested else ends
	}//else ends
	display(*head);
}//input sorted ends

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++DUPLICATE FUNCTION++++++++++++++++++++++++++++++++++++++++++++++*/
int duplicate(node *head, int target)
{
	if(!head)
	{
		printf(RED"\n\n\t\n"RESET);
		return 1;
	}
	else
	{
		node *trav = NULL; // temp pointer to traverse in the list
		trav = head;
		while(!trav->next)
		{
			if(trav->roll == target)
			{
				return 0;
			}//if ends
			else 
				return 1;
		}//while ends
	}
}//search ends

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++NAME INPUT FUNCTION+++++++++++++++++++++++++++++++++++++++++++++++*/
char* name_input(void)
{
	int flag = 1;
	char buff[100];
	do{	
		printf("\nEnter the Name:");
		__fpurge(stdin);
		fgets(buff,100,stdin);
		int len = strlen(buff);
	char *name = (char*)calloc(1,sizeof(buff));

		if((strcspn(buff,"0123456789!@#$%^&*()_+:{}[]:;',.<>/?") == len)) // for user input validation in the name
		{
			flag = 1;
			strcpy(name,buff);// to cpoy in the heap memory.
			return name;// to return to the node.
		}//if ends
		else
		{
			printf(RED"\n\n\tERROR! Name cannot contain numericals\n"RESET);
			flag = 0;
		}
	}while(flag == 0);


}// name input function ends
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++DISPLAY++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void display(node *head)
{
	if(!head)
	{
		printf(RED"\n\n\tERROR! List is empty \n"RESET);
		return;
	}
	else{
		node *temp = head;
		while(temp)
		{
			printf("\n");
			printf("\nRoll no: %d", temp->roll);
			printf("\nName: %s", temp->name);
			printf("\n\tContact: %d", temp->contact);
			printf("\n\n\tMarks for each subject");
			printf("\n\tEnglish: %d", temp->marks.eng);
			printf("\n\tScience: %d", temp->marks.sci);
			printf("\n\tMaths:   %d", temp->marks.math);
			temp = temp->next;
		}//while ends
	}//else ends
}//display ends

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++PRINT MENU FUNCTION++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void print_menu(void)
{
	
	printf("\n\n\t0.Exit\t1.Insert\t2.Delete\t3.Modify\t4.Search\t5Delete_all");
	printf("\n\nEnter choice: ");


}//menu functon ends.

/*____________________________________________________________________________END___________________________________________________________________________*/
