/* 
Build a maxheap from given input data.
The topmost(maximum) element of the heap is swapped with last element of the array.
Reduce the size of heap by 1, and repeat the above steps.
*/

#include<bits/stdc++.h>
using namespace std;

void maxheap(int arr[], int size, int i)
{
    int max = i;
    int left = 2*i + 1;
    int right = 2*i +2;

    if(left < size && arr[left] > arr[max])
    max = left;

    if(right < size && arr[right] > arr[max])
    max = right;

    if(max!=i)
    {
        swap(arr[i], arr[max]);
        maxheap(arr, size, max);
    }
}


void heapsort(int arr[], int size)
{
    int i;
    
    for(i=size/2 - 1; i>=0 ; i--)
    maxheap(arr, size, i);

    for(i=size-1; i>=0; i--)
    {
        swap(arr[0],arr[i]);
        maxheap(arr, i , 0);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];

    heapsort(a,n);

    for(i=0;i<n;i++)
    cout<<a[i]<<" ";    

    return 0;
}