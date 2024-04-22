/*
Q2. Create an employee structure with the following members
empid, employee name, salary, year of joining etc.
Accept the data for certain no. o of employees and find their total,
average, max, min salary.
Also find out the employees with maximum, minimum service,use a
function to find service for each employee element in the array
*/
struct employee
{
    int salary;
    int empid;
    char name[50];
    int year;

}emp1, *emp2;

#include<stdio.h>
#include<stdlib.h>

void mem_alloc(int *);
void enter_data(int);

int main()
{
    int no_of_emp = 0;// local var to keep count of employee.
    mem_alloc(no_of_emp);// calling memory allocation function.
    enter_data(no_of_emp);//calling enter data function.

}// main ends

//Function to allocate the menory in heap
void mem_alloc(int *no_of_emp)
{
    int no_of_emp;
    printf("Enter how many employees you want to add: ");
    scanf("%d", &no_of_emp);

    emp2 = (struct employee*)calloc(no_of_emp, sizeof(struct employee));
    //Null calloc check
    if(emp2 == NULL){
        perror("\nCalloc failed");
        exit(0);
    }//if ends
    else{
        return emp2;
    }
}

//To enter the data in the structure allocated in heap.
void enter_data(int no_of_emp)
{
    for(int i= 0; i,no_of_emp; i++){
        printf("\nEnter the name of employee");
        scanf(" %[^\n]s", emp2[i].name);      
    }//for ends

}//enter data ends

//display function
void display(int no_of_emp)
{
    for(int i=0; i<no_of_emp;i++){
        printf("The name of empoyee: %s", emp2[i].name);
    }//for ends.
}//display ends