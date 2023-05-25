#include<stdio.h>
//Implementation of Stack using Araay.

int stack[100],top=-1,maxsize=100;

void push()
{
	int data;
	printf("Enter a data to push into stack:");
	scanf("%d",&data);
	top+=1;
	stack[top]=data;
	printf("Data is Pushed.\n");
	return;
}

int pop()
{
	int poped_d=stack[top];
	top-=1;
	return poped_d;
}

void display()
{
	int i=top;
	printf("Stack:-\n");
	while(i!=-1)
	{
		printf("%d\n",stack[i]);
		i-=1;
	}
	return;
}
int size_of_stack()
{
	return maxsize;
}
int top_of_stack()
{
	return stack[top];
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
        		if(top>=(maxsize-1))
        		    printf("Overflow!\n");
        		else
        		    push();
        		break;
        	case 2:
        		if(top<0)
        		    printf("Underflow!\n");
        		else
        		    printf("Poped data: %d\n",pop());
        		break;
        	case 3:
        		if(top<0)
        		    printf("Empty Stack!\n");
        		else
        		    display();
        		break;
        	case 4:
        		printf("Stack can contain %d value(s)\n",size_of_stack());
        		break;
        	case 5:
        		if(top<0)
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
