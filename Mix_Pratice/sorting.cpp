#include<iostream>
using namespace std;


void bobsort(int arr[], int size)
{
    int flag=0;
    for(int i=0;i<size;i++)
    {
        flag=0;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(!flag)
            break;
    }
}

void sel_sort(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void in_sort(int arr[], int size)
{
    int temp,j;
    for(int i=1;i<size;i++)
    {
        j=i-1;
        temp=arr[i];
        while(temp<arr[j] && j>-1)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int arr[10]={4,5,3,1,9,5,4,0,6,2};
    int arr1[10]={4,5,3,1,9,5,4,0,6,2};
    int arr2[10]={4,5,3,1,9,5,4,0,6,2};

    bobsort(arr,10);
    sel_sort(arr1,10);
    in_sort(arr2,10);


    for(int i=0;i<10;i++)
        cout<<arr[i]<<"-";

    cout<<endl;
    for(int i=0;i<10;i++)
        cout<<arr1[i]<<"-";
    
    cout<<endl;
    for(int i=0;i<10;i++)
        cout<<arr2[i]<<"-";
}