#ifndef __HEAD
#define __HEAD
struct student
{
    struct student *prev;
    char *name;
    int prn;
    struct student *next;
};// student structure ends.

struct student* node_maker(void);
char* name_memory();
void first_node(struct student **);
void insert_at_begining(struct student **);
void insert_at_end(struct student **);

#endif