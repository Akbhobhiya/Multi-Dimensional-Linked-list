// The main aim of this program is to make a dynamic matrix so that we can save static memory 
//Mostly uses in Databases index, image proccessing!!
//Two dimensional linked list operations
//linked list as a multidimensional array using dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>
int xd,countx=0,county=0;
struct node
{
	char data;
	struct node* px,*py;
}*hor=NULL,*ver=NULL,*root=NULL,*move;
int NumofNode=0;
void insert(int);
void show();
void delete(int);
struct node* search(int);

//MAIN FUNCTION TO OPERATE ALL THE FUNCTIONS

int main()
{
	printf("Enter number of element in x direction\n");
	scanf("%d",&xd);
	while(1)
	{
		int x;
		printf("\nTwo dimensional linked list Menu!!\nEnter your choice for given option\n");
		printf("1 for insert\n2 for traverse\n3 find Number of node\n4 for search a data\n5 for delete a node\n6 for exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			      {
			      	int num;
			      	printf("Enter ele to be inserted\n");
			      	scanf("%d",&num);
			      	insert(num);
			      	break;
			      }
			case 2:show();
			       break;
			case 3:printf("Total number of node in this Linked list is:: %d\n",NumofNode);
			       break;
			case 4:
			      {
			      	struct node*find;
			      	int num;
			      	printf("Enter a number to search\n");
			      	scanf("%d",&num);
			      	find=search(num);
			      	if(find)
			      	{
			      		printf("Data is present in the Structure\n");
			      	}
			      	else
			      	{
			      		printf("Data isn't present in the Two dimensional linked list\n");
			      	}
			      	break;
			      }
			case 5:
			     {
			     	int num;
			     	printf("Enter a number that you want to delete\n");
			     	scanf("%d",&num);
			     	delete(num);
			     	break;
			     }
			case 6:exit(0);
			default: printf("WRONG CHOICE!! CHOOSE A ANOTHER OPTION(1-6)\n");
		}
	}
}
// for inserting element one by one
// time complexity of insert is O(1), means constant time for insert a element
void insert(int num)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->px=temp->py=NULL; 
	NumofNode++;             //for counting total node

    // for row change
	if(countx==xd)
	{
		county++;
		countx=0;
	}
	// inserting root node
	if(root==NULL)
	{
		root=temp;
		ver=temp;
		move=temp;
		hor=temp;
		countx++;
	}
	//insert a node in first row 

	else if((countx<xd)&&(county==0))
	{
		hor->px=temp;
		hor=temp;
		countx++;
	}
	//insert a node after first row

	else if(county>0)
	{
		// insert  a element at first column of the row(execpt first row first element)
		if(countx==0)
		{
			move=ver;
			ver=temp;
			hor=temp;
			move->py=temp;
			move=move->px;
			countx++;
		}
        // insert a element after first column

		else
		{
			hor->px=temp;
			hor=temp;
			move->py=temp;
			move=move->px;
			countx++;
		}
	}

	// to put NULL char in last element in  all row 
	if(countx==xd)
	{
		hor->px=NULL;
		hor=NULL;
	}
}
// A function to display all the element of two dimensional linked list
// traversing all the node one by one
// time complexity is O(n)

void show()
{
	printf("Data of two dimensional linked list::\n");
	int x=0;
	struct node*movex,*movey;
	movey=root->py;
	movex=root;
	while(movex||movey)
	{
		// here "int x" is for changing the line ie. first line to second line
		x++;
		printf("%d   ",movex->data);
		movex=movex->px;
		if(x==xd)
		{
			x=0;
			movex=movey;
			if(movex)
			{
				movey=movey->py;
			}
			printf("\n");
		}
	}
}
// A function to search a given element by user
// here time complexity is also O(n) for searching a element

struct node* search(int num)
{
	int x=0;
	struct node*find=NULL,*movex,*movey;
	movey=root->py;
	movex=root;
	while(movex||movey)
	{
		x++;
		if(num==movex->data)
		{
			find=movex;
			return find;
		}
		movex=movex->px;
		if(x==xd)
		{
			x=0;
			movex=movey;
			if(movex)
			{
				movey=movey->py;
			}
		}
	}
	return find;
}
// function to delete a give data from the two dimensional linked list
// time compelexity is O(n),due to searching the the given element for delete

void delete(int num)
{
	struct node* del;
	del=search(num);
	if(del)
	{
		del->data=-1;
		printf("The given Data(%d) is deleted from the list\n",num);
	}
	else
	{
		printf("The give data is not present in the list\nChoose another data for delete and try again\n");
	}
} 
