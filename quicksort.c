#include<stdio.h>


int partition(int *arr,int low,int high){
int i=low-1;
    int j=low;
    for(j=low;j<high;j++)
    {
        if(arr[j]<arr[high])
        {

            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;

        }

    }
             i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
    return i;}
void Quicksort(int* arr,int low,int high)
{
    if(low>=high)return ;
    int pivot=partition(arr,low,high);
    Quicksort(arr,low,pivot-1);
    Quicksort(arr,pivot+1,high);
}

int main()
{
   int n=0;
   printf("Enter the size:");
   scanf("%d",&n);
   int arr[n];
   for(int i=0;i<n;i++)
   {

       scanf("%d",&arr[i]);
   }


   Quicksort(arr,0,n-1);
   printf("\n \n");
   for(int i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }

}
