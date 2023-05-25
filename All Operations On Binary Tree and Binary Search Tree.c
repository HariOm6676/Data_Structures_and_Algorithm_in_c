//BST 
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;
struct node* arr[100];
int i=-1,j=-1;
void bt_insert(int data)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	if(i==-1)
	{
		i++;    
		root=new;
    }
	else
	{
		struct node* temp=arr[i];
		if (temp->left==NULL)
			temp->left=new;
		else
		{
			temp->right=new;
			i++;
	    }
	}
	j++;
	arr[j]=new;
	printf("%d is inserted in the Binary Tree.\n",data);
}
struct node *inOrderPredecessor(struct node* root){
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
int bt_delete(struct node *root, int value){
    struct node* iPre;
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL){
        free(root);
        return 0;
    }
    if(value<root->data){
        root->left=bt_delete(root->left,value);
    }
    else if(value>root->data){
        root->right=bt_delete(root->right,value);
    }
    else{
        iPre=inOrderPredecessor(root);
        root->data=iPre->data;
        root->left=bt_delete(root->left,iPre->data);
    }
    return 1;
}
void bst_insert(int data)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	if(root==NULL)
	    root=new;
	else
	{
		struct node* temp=root;
		while(temp)
		{
			if(new->data<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=new;
					break;
			 	}
			    temp=temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=new;
					break;
				}
				temp=temp->right;    
			}
		}
	}
	printf("%d is inserted in the Binary Search Tree.\n",data);
}
struct node* findMinimum(struct node* cur) 
{  
    while(cur->left!=NULL) {  
        cur=cur->left;  
    }  
    return cur;  
} 
void search(struct node* cur,int item,struct node* parent)  
{  
    while(cur!=NULL&&cur->data!=item)  
    {  
        parent=cur;  
        if(item<cur->data)  
            cur=cur->left;  
        else  
            cur=cur->right;
    }  
}   
int bst_delete(int item)
{
    struct node* parent=NULL;  
    struct node* cur=root;
	while(cur!=NULL&&cur->data!=item)  
    {
        parent=cur;  
        if(item<cur->data)  
            cur=cur->left;  
        else  
            cur=cur->right;  
    } 
    if(cur==NULL)  
        return 0;  
    if(cur->left==NULL&&cur->right==NULL)
    {  
        if(cur!=root)
        {  
            if(parent->left==cur)  
                parent->left=NULL;  
            else  
                parent->right=NULL;  
        }  
        else  
            root=NULL; 
		return 1; 
    }  
    else if(cur->left&&cur->right)  
    {  
        struct node* succ=findMinimum(cur->right);  
        int val=succ->data;  
        bst_delete(succ->data);  
        cur->data=val;  
        return 1;
    }  
    else  
    {  
        struct node* child=(cur->left)?cur->left:cur->right;  
        if(cur!=root)  
        {  
            if (cur==parent->left)  
                parent->left=child;  
            else  
                parent->right=child; 
        }  
        else  
            root=child;  
        return 1;
    }
    return 1;
}
void trav_pre(struct node* temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		trav_pre(temp->left);
		trav_pre(temp->right);
	}
}
void trav_in(struct node* temp)
{
	if(temp!=NULL)
	{
		trav_in(temp->left);
		printf("%d ",temp->data);
		trav_in(temp->right);
	}
}	
void trav_pos(struct node* temp)
{
	if(temp!=NULL)
	{
		trav_pos(temp->left);
		trav_pos(temp->right);
		printf("%d ",temp->data);
	}
}
void bt()
{
	printf("Enter 1 to Insert a node\n");
	printf("Enter 2 to Delete a node\n");
	printf("Enter 3 to Traverse In-order\n");
	printf("Enter 4 to Traverse Pre-order\n");
	printf("Enter 5 to Traverse Post-order\n");
	printf("Enter 6 to Exit\n");	
	while(1)
	{
		int ch,data;
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
	            printf("Enter data to insert:");
	            scanf("%d",&data);
				bt_insert(data);
				break;
			case 2:
			    printf("Enter data to delete:");
	            scanf("%d",&data);
				if (bt_delete(root,data))
				    printf("%d is deleted from the Binary Tree.\n",data);
				else
				    printf("Data not found in the Binary Tree!\n");
				break;
			case 3:
				trav_in(root);
				printf("\n");
				break;
			case 4:
				trav_pre(root);
				printf("\n");
				break;
			case 5:
				trav_pos(root);
				printf("\n");
				break;
			case 6:
				printf("Binary Tree is Deleted.\n\n");
        		root=NULL;
        		return;
			default:
				printf("Invalid choice!\n");
		}
	}
}
void bst()
{
	printf("Enter 1 to Insert a node\n");
	printf("Enter 2 to Delete a node\n");
	printf("Enter 3 to Traverse In-order\n");
	printf("Enter 4 to Traverse Pre-order\n");
	printf("Enter 5 to Traverse Post-order\n");
	printf("Enter 6 to Exit\n");
	while(1)
	{
		int ch,data;
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
	            printf("Enter data to insert:");
	            scanf("%d",&data);
				bst_insert(data);
				break;
			case 2:
			    printf("Enter data to delete:");
	            scanf("%d",&data);
				if (bst_delete(data))
				    printf("%d is deleted from the Binary Search Tree.\n",data);
				else
				    printf("Data not found in the Binary Search Tree!\n");
				break;
			case 3:
				trav_in(root);
				printf("\n");
				break;
			case 4:
				trav_pre(root);
				printf("\n");
				break;
			case 5:
				trav_pos(root);
				printf("\n");
				break;
			case 6:
				printf("Binary Search Tree is Deleted.\n\n");
				root=NULL;
        		return;
			default:
				printf("Invalid choice!\n");
		}
	}
}
void main()
{
	while(1)
	{
		printf("Enter 1 for Binary Tree\n");
		printf("Enter 2 for Binary Search Tree\n");
		printf("Enter 3 for Exit\n");	
		int ch;
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				bt();
				break;
			case 2:
				bst();
				break;
			case 3:
				printf("Thanks!");

		    	return;
			default:
				printf("Invalid choice!\n");
		}
	}
}