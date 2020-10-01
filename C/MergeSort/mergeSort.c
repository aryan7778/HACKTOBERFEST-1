#include<stdio.h>
#include<stdlib.h>

#define Max_size_arr 10

//function prototype
int merge(int* ,int ,int,int,int);
int mergesort(int* ,int ,int,int);


int main()
{
	int arr[Max_size_arr];
	int i;
	int size_arr;
	printf("Enter size of array\n");
	scanf("%d",&size_arr);

	//getting input for arr from user
	for(i=0;i<size_arr;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,size_arr-1,size_arr);

	//printing elements of arr after sorting
	for(i=0;i<size_arr;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int mergesort(int* arr,int left,int right,int size_arr)
{
	if(left<right)
	{
		int mid=(left+right)/2;

		mergesort(arr,left,mid,size_arr);
		mergesort(arr,mid+1,right,size_arr);

		//to merge array
		merge(arr,left,mid,right,size_arr);
	}
}

//function for merging array elements
int merge(int* arr,int left,int mid,int right,int size_arr)
{
	int arr2[size_arr];
	int i;
	int j;
	int k;

	//copying elements from arr to arr2
	for(i=left;i<=right;i++)
	{
		arr2[i]=arr[i];
	}
	i=left;
	j=mid+1;
	k=left;

	//checking each element
	while(i<=mid && j<=right)
	{
		if(arr2[i]>=arr2[j])
		{
			arr[k]=arr2[j];
			j++;
			k++;
		}
		else
		{
			arr[k]=arr2[i];
			i++;
			k++;
		}
	}

	while(i<=mid)
	{
		arr[k]=arr2[i];
		i++;
		k++;
	}
	while(j<=right)
	{
		arr[k]=arr2[j];
		k++;
		j++;
	}
}