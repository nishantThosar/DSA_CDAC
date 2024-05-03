/*Tree program first time*/

#include<stdio.h>
#include<stdlib.h>

/*--------------------------------------------------------------STRUCT DECLARATION-----------------------------------------------------*/
struct tree
{
	struct tree *left;
	struct tree *right;
	int data;
};
/*--------------------------------------------------------------GLOBAL DECLARATION------------------------------------------------------*/

/*---------------------------------------------------------------FUNCTION PROTOTYPES----------------------------------------------------*/
void node_insertion(struct tree **);
struct tree* tree_node_maker(void);
void display_inorder(struct tree*);

/*_____________________________________________________________________START____________________________________________________________*/
int main()
{
	struct tree *root = NULL;
	node_insertion(&root);
	display_inorder(root);
}//main ends

/*-----------------------------------------------------------------NODE INSERTION FUNCTION-----------------------------------------------------*/
void node_insertion(struct tree **root)
{
	int ele;// user input var.
	struct tree *temp = NULL;
	temp = tree_node_maker();
	printf("Enter the data: ");
	scanf("%d", &ele);
	
	if(!*root)
	{
 		*root = temp; // if no node in the tree then make first node and assign the next node to the root.
	}//if ends
	//if nodes are present in the tree then traverse till correct position and insert at the correct location.
	else
	{
		struct tree *trav = NULL;// temp pointer to traverse in the tree.
		trav = *root;
		while((!trav->left) || (!trav->right))//unless null is found in the left or right.
		{	
			//if data is less than the tree data then traverse to the left till the left of data is not null.
			if((!trav->left) && (ele<trav->data) )
			{
				trav = trav->left;
			}//if ends
			//if data is grater than the tree data then traverse tothe right of current node till the next of current node is not null.  
			else if((!trav->right) && (ele>trav->data))
			{
				trav = trav->right;
			}//else if ends
		}//while ends

		/*Now after traversing the traverse pointer is standing on the node on which we have to add the node.*/
		if (ele<trav->data)
		{
			trav->left = temp;//insert the node to the left of leaf node.
		}//if ends.
		else if(ele>trav->data)
		{
			trav->left = temp;//insert the node at the right of leaf
		}//else if ends

	}//else ends
}//root node ends

/*--------------------------------------------------------------TREE NODE MAKING FUNCTION-------------------------------------------------------*/
struct tree* tree_node_maker(void)
{
	struct tree *temp = NULL;
	temp = (struct tree*)calloc(1,sizeof(struct tree));
	if(!temp)
	{
		perror("\n\nError in node making");
		exit(0);
	}//if ends
	else
	{
		return temp;
	}//else ends
}//tree node maker ends

/*----------------------------------------------------------------DISPLAY INORDER-------------------------------------------------------------------*/
void display_inorder(struct tree *root)
{
	// struct tree *trav = NULL;
	// struct tree *trav2 = NULL;

	// //Traverse first to the right side till the leaf node.
	// while((!trav->left) && (!trav->right))
	// {	trav2 = trav;
	// 	trav = trav->left;
	// 	printf("Inorder: %d", trav->data);
	// 	trav = trav2;
	// }//while ends

	while(!root)
	{
		return;
	}//while ends
	display_inorder(root->left);
	printf("Inorder: %d", root->data);
	display_inorder(root->right);
}//display ends

/*______________________________________________________________________END______________________________________________________________________*/