//Implementation of Stack using Linked list.
#include<stdio.h>
#include<stdlib.h>


struct stack
{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
int sizestack=0;

void push()
{
	struct stack *new=malloc(sizeof(struct stack));
	int data;
	printf("Enter a data to push into stack:");
	scanf("%d",&data);
	new->data=data;
	new->next=top;
	top=new;
	printf("Data is Pushed.\n");
	sizestack++;
	return;
}
int pop()
{
	int poped_d=top->data;
	top=top->next;
	sizestack--;
	return poped_d;
}
void display()
{
	struct stack *ptr=top;
	while (ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
    return;
}
int size_of_stack()
{
	return sizestack;
}
int top_of_stack()
{
	return top->data;
}
int main()
{
	printf("Enter 1 to Push an element into the stack\n");
	printf("Enter 2 to Pop an element from the stack\n");
	printf("Enter 3 to Display the stack\n");
	printf("Enter 4 to Get size of stack\n");
	printf("Enter 5 to Get value on top\n");
	printf("Enter 6 to Exit\n");
	while(1)
	{
		int ch;
		printf("\nEnter your choice:");
		scanf("%d",&ch);
        switch(ch)
        {
        	case 1:
        		push();
        		break;
        	case 2:
        		if(top==NULL)
        		    printf("Underflow!\n");
        		else
        		    printf("Poped data: %d\n",pop());
        		break;
        	case 3:
        		if(top==NULL)
        		    printf("Empty Stack!\n");
        		else
        		    display();
        		break;
        	case 4:
        		printf("Stack is containing %d value(s)\n",size_of_stack());
        		break;
        	case 5:
        		if(top==NULL)
        		    printf("No Top element!\n");
        		else
        		    printf("Value at Top of Stack: %d\n",top_of_stack());
        		break;
        	case 6:
        		printf("Thanks!");

        		return 0;
        	default:
			    printf("Invalid choice!\n");
		}
	}
}