//circular Queue array
#include<stdio.h>

int queue[100];
int max_size,queue_size=0;
int front=-1,rear=-1;

void enqueue(int data)
{
	if((rear+1)%max_size==front)
	{
		printf("Overflow!\n");
		return;
	}

	if(front==-1)
		front=0;
	rear=(rear+1)%max_size;
	queue[rear]=data;
	queue_size++;
    printf("Data is Inserted.\n");
}
int dequeue()
{
	if(front==-1)
	{
		printf("Underflow!\n");
		return -1;
	}

	int del=front;
	if (front==rear)
	{
		front=-1; rear=-1;	
	}
	else
	    front=(front+1)%max_size;
	queue_size--;
	return del;
}
void display_queue()
{
	if(front==-1)
		printf("Queue is Empty!\n");
	else
	{
		printf("Queue is:-\n");
		for(int i=front;i<=rear;i=(i+1)%max_size)
			printf("%d ",queue[i]);
		printf("\n");
	}
}
void get_size()
{
	if(queue_size)
	    printf("Size of Queue:%d\n",queue_size);
	else
	    printf("Empty Queue!\n");
}
void get_top()
{
	if(front!=-1)
	    printf("Top element of Queue:%d\n",queue[front]);
	else
	    printf("No Top Element!\n");
}
void main()
{
	printf("Enter the max size of Queue:");
    scanf("%d",&max_size);
	printf("Enter 1 to Enqueue\n");
	printf("Enter 2 to Dequeue\n");
	printf("Enter 3 to Display Queue\n");
	printf("Enter 4 to Get size of Queue\n");
	printf("Enter 5 to Get value on Top\n");
	printf("Enter 6 to Exit\n");
	
	while(1)
	{
		int ch,del_data,data;
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
	            printf("Enter data to insert:");
	            scanf("%d",&data);
				enqueue(data);
				break;
			case 2:
				del_data=dequeue();
				if (del_data!=-1)
				    printf("Deleted data: %d\n",queue[del_data]);
				break;
			case 3:
				display_queue();
				break;
			case 4:
				get_size();
				break;
			case 5:
				get_top();
				break;
			case 6:
				printf("Thanks!");

        		return;
			default:
				printf("Invalid choice!\n");
		}
	}
}