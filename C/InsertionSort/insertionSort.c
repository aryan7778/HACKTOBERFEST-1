#include <stdio.h>

int main()
{
    int n,key,j,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        j=i-1;
        key=a[i];
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    
}
