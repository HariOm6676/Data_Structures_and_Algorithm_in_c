//Sorting Algorithms - Recursive.(Merge,Quick)
#include<stdio.h>


void MergeSort(int arr[], int l, int r);
void Merge(int arr[], int l, int m, int r);

void QuickSort(int arr[],int low,int high);
int Partition(int arr[],int low,int high);

void print_arr(int arr[],int n)
{
	int i;
	printf("Sorted Array:-\n");
	for(i=0;i<n;i++)
	    printf("%d ",arr[i]);
	printf("\n\n");
	return;
}
int get_arr(int * arr)
{
	int n,i;
	printf("Enter size of array:");
	scanf("%d",&n);

	printf("Enter array:- ");
	for(i=0;i<n;i++)
	    scanf("%d",(arr+i));
	
	return n;
}

int main()
{
	int ch;
	printf("Enter 1 to sort the array by Merge Sort\n");
	printf("Enter 2 to sort the array by Quick Sort\n");
	printf("Enter 3 to Exit\n\n");
	while(1)
	{
		printf("Enter your Choice:");
	    scanf("%d",&ch);
	    int * arr,n;
	    switch(ch)
	    {
	    	case 1:
	    		n=get_arr(arr);
	    		MergeSort(arr,0,n-1);
	    		print_arr(arr,n);
	    		break;
	    	case 2:
	    		n=get_arr(arr);
	    		QuickSort(arr,0,n-1);
	    		print_arr(arr,n);
                break;
	    	case 3:
	    		printf("Thanks!");

	    		return 0;
	    	default:
	    		printf("Invalid Choice!\n\n");
		}
	}
}

void QuickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int Pi=Partition(arr,low,high);
		QuickSort(arr,low,Pi-1);
		QuickSort(arr,Pi+1,high);
	}
}
int Partition(int arr[],int low,int high)
{
	int Pivot=arr[high],temp;
	int i=low-1,j;
	for(j=low;j<=(high-1);j++)
	{
		if(arr[j]<Pivot)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return i+1;
}

void MergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}
void Merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	
}
