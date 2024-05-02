/*Hash table program 1 
in this program 
1. Enters elemet inside table 
2. Generate key
3. Avoid duplcate element insertion.
4. display elements
5. Search elemetns*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
void insert(int [], int *);// to insert the elements in # table.
int search(int [], int);// to search the elements in the # table.
int hashing(int const ele);// hashing function
void print_menu(void);// for printing the menu.
void display(int [],int);
#define GOOD_GARBAGE -99

int main()
{
	int count = 0;
	int size, user_choice;
	int *table = NULL;
	printf("\nEnter the size of table: ");
	scanf("%d", &size);
	bool flag = false;

	table = (int*)calloc(size, sizeof(int));
	//Null check
	if(!table){
		perror("\n\nError in memory allocation");
		exit(0);
	}// if ends

	//inserting -99 in the array.
	for(int i=0; i<size;i++)
	{
		table[i] = GOOD_GARBAGE;
	}//for ends

	enum option{Exit=0,Insert,Display,Find};
	enum option choice;//enum variable
	
	while(true)
	{
		/*User input validation*/
		do{
			print_menu();
			scanf("%d", &user_choice);
			if((isdigit(user_choice)) &&(-1<user_choice) && (user_choice<4)){//here if we comment out is digit then the loop works fine.
				flag = false;
				choice = user_choice;
				break;
			}//if ends
			else{
				printf("\n\t WRONG INPUT");
				flag = true;
			}
		}while(flag == true);

		switch(choice)
		{

			case Insert : if(count == size)
							{
								printf("\nTable full");
							}//if ends
						   else{
								insert(table,&count);
								printf("\n\tInserted");
								display(table,size);
						   }//else ends

			case Display:	display(table,size);
							break;

			case Find:		int ind, target;
							printf("\nEnter the element to find");
							scanf("%d", &target);
							ind = search(table,target);
							printf("\n\tElement found at %d index of table", ind);
							break;

			case Exit:		printf("\nExiting");
							free(table);
							return 0;
		}//switch ends

	}//while ends
	

	return 0;
}//main ends

/*This function first checks if the #table is full or not if full then returns, else calls the #function and gets the hashing done then assigns the index to the array*/
void insert(int hash[], int *count)
{
		int ele, index;
		printf("\nEnter the element: ");
		scanf("%d", &ele);
		if(!search(hash,ele)){
		index = hashing(ele);
		hash[index] = ele;
		*count++;
		}
		else
			printf("\n\tSORRY! Element present already.");
}//insert ends

/*Hashing function*/
int hashing(int const ele)
{
	#define PER_HASHING 3
	int temp;
	temp  = ele%10;
	printf("temp = %d", temp);
	return temp;
}//hashing ends


//To search the element inside array
int search(int hash[], int target)
{
	int i = 0;
	while(hash[i]){
		if(target = hash[i]){
			return i;
		}
		else{
			i++;
		}
	}//while ends
	return 0;
}//search ends

void print_menu(void)
{
	printf("\n");
	printf("=====================================================================================================");
	printf("\t\v\n\n\r------------------------------------Hash Table Ver1-----------------------------------");
	printf("         |");printf("\n\t0.Exit\t1.Insert\t2.Display\t3.Search");printf("                       |");
	printf("         |");printf("\nEnter the choice: ");printf("                                            |");
}//print_menu ends

void display(int hash[],int size)
{
	for(int i=0; i<size;i++){
		if(hash[i]!= -99)
		{
			printf("%d", hash[i]);
		}// if ends
	}
}// display ends

