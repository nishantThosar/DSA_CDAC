/*Program for circular queue*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

void que(int [],int *, int *, int *);
void dequeue(int [], int *, int *, int *);
void display(int []);

int main()
{
	int no_of_ele = 0;
	int queue[SIZE];
	for(int i=0;i<SIZE;i++)
	{
		queue[i] = -99;
	}//for ends

	int front = -1;
	int rear = -1;
	int choice;
	while(1)
	{
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: que(queue,&no_of_ele,&front,&rear);
					break;

			case 2: dequeue(queue,&no_of_ele,&front,&rear);
					break;

			case 3: display(queue);
					break;

			case 0: exit(0);
		}//switch case ends
	}//while ends


	return 0;
}//main ends

void que(int queue[],int *ele_no, int *fr_ind, int *rr_ind)
{
	if((*rr_ind == SIZE -1) &&(*fr_ind == 0) || (*fr_ind == *rr_ind +1))
	{
		printf("\n\nERROR QUEUE FULL");
		return;
	}//if ends
	else
	{
		int ele;
		printf("\nEnter the value: ");
		scanf("%d", &ele);
		if((*rr_ind == -1) &&(*fr_ind == -1))
		{
			++(*rr_ind);
			queue[*rr_ind] = ele;
			if( *fr_ind == -1)
			{	
				*fr_ind = 0;
			}//if ends
			++(*ele_no);
			//printf("queue 0: %d", queue[0]);
		}//if ends
		else if((*rr_ind == SIZE-1) && (*fr_ind !=SIZE-1)) // circular queue condition.
		{
			*rr_ind = 0;
			queue[*rr_ind] = ele;
			++(ele_no);
		}//else if ends
		else
		{
			++(*rr_ind);
			queue[*rr_ind] = ele;
			//++(*rr_ind);
		}//else ends.

	}//else ends
	display(queue);
}//queue ends

void dequeue(int queue[], int *ele_no, int *fr_ind, int *rr_ind)
{

	//printf("Fr_ind: %d\n",*fr_ind);
	if((*rr_ind == -1 ) && (*fr_ind == -1))
	{
		printf("\n\n QUEUE IS EMPTY");
	}//if ends
	else if((*fr_ind == *rr_ind))
	{
		printf("\n%d\n", queue[*fr_ind]);
		queue[*fr_ind] = -99;

		*fr_ind = -1; *rr_ind = -1;// reinitialize to initial values
	}//else if ends
	else if((*fr_ind == SIZE-1) && (*rr_ind != *fr_ind))
	{
		printf("\n%d\n", queue[*fr_ind]);
		queue[*fr_ind] = -99;
		*fr_ind = 0;
	}
	else
	{
		printf("\nDequeue: %d\n", queue[*fr_ind]);
		queue[*fr_ind] = -99;
		++(*fr_ind);
	}//else ends
	//	printf("Fr_ind_after: %d\n",*fr_ind);
	display(queue);

}//dequeue ends

void display(int queue[])
{
	for(int i=0;i<6;i++)
	{
		if(queue[i] != -99)
		{
			printf("\t%d", queue[i]);
		}
	}
}