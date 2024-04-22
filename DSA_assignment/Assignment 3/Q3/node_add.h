/*This header file contains defination of structure and declaration of 
1. node maker.
2. Insert at begining
3. To make first node
4. To insert node at position
4. To insert at end.
*/

#ifndef __Header
#define __Header

struct node{
    int data;
    struct node *next;
};//structure node ends

struct node* node_maker();
void insert_at_beg(struct node **);
void first_node(struct node **);
void add_at_end(struct node **);
void insert_at_pos(struct node **);
#endif