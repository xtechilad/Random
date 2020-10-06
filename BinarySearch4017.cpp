/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Binary search implementation for distinct sorted elements of an array
*/

#include<iostream>
using namespace std;

template <typename T>
int binarySearch(T x, T *a, int first, int last)
{
    while(first<=last)
    {
        int mid=first+(last-first)/2;
        if(a[mid]==x)
            return mid;
        if(a[mid]<x)
            first = mid+1;
        else
            last =mid-1;
    }
    return -1;
}

template <typename T>
void inputArray(T *ar, int n)
{
    cout<<"Now enter the elements of array: ";
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
}

int main()
{
    int N;
    int index;
    int x,*ar;
    cout<<"Enter the size of array: ";
    cin>>N;
    ar= new int[N];
    inputArray(ar,N);
    cout<<"Enter the element you want to search in the entered array: ";
    cin>>x;
    index=binarySearch(x, ar, 0, N-1);
    if(index==-1)
    { 
        cout<<"Element not found.\n" ;
    }
    else 
    { 
        cout<<"The required element "<<ar[index]<<" is present at index "<<index+1<<endl;
    }
    return 0;
}