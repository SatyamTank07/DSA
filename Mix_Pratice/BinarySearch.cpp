#include<iostream>

using namespace std;


int bi_s(int arr[], int beg,int end, int target)
{
    int mid=(beg+end)/2;

    if(beg>end)
    {
        cout<<"Not Found"<<endl;
        return -1;
    }
    else
    {
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            return bi_s(arr,mid+1,end,target);
        else if(arr[mid]>target)
            return bi_s(arr,beg,mid-1,target);
    }
    return mid;
}

int main()
{ 
    int arr[5]={1,2,3,4,5};
    cout<<"target at index :"<<bi_s(arr,0,5,5)<<endl;
     
}