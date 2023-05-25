//circular queue linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
struct node *front=NULL,*rear=NULL;
int max_size,queue_size=0;

void enqueue(int data)
{
	if (queue_size==max_size)
	{
	    printf("Overflow!\n");
	    return;
    }

	struct node* new=malloc(sizeof(struct node));
	new->data=data;
	
	if(front==NULL)
	{
		front=new;
		rear=new;
	}
	else
	{
		rear->next=new;
		rear=rear->next;
	}     
	rear->next=front;	
	queue_size++;
	printf("Data is Inserted.\n");
}
struct node* dequeue()
{
	if(front==NULL)
	{
		printf("Underflow!\n");
		return NULL;
	}
	else
	{
		struct node *temp=front;
		if (front==rear)
	    	front=NULL;
	    else
	    {
		    front=front->next;
		    rear->next=front;
    	}
		queue_size--;
		return temp;
	}
}
void display_queue()
{
	if(front==NULL)
	{
		printf("Queue is Empty!\n");
	}
	else
	{
		printf("Queue is:-\n");
		struct node *ptr;
		for(ptr=front;ptr!=rear;ptr=ptr->next)
			printf("%d ",ptr->data);
		printf("%d ",ptr->data);
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
	if(front!=NULL)
	    printf("Top element of Queue:%d\n",front->data);
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
		int ch,data;
		struct node* del_node;
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
				del_node=dequeue();
				if (del_node!=NULL)
				    printf("Deleted data: %d\n",del_node->data);
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