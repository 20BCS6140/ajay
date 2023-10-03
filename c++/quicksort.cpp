#include <iostream>
#include <algorithm>

using namespace std;

int partition(int *arr,int s,int e)
{
    int pivot = arr[e];
    int pindex = s;

    for(int i = s; i < e; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i],arr[pindex]);
            pindex++;
        }
    }

    swap(arr[e],arr[pindex]);

    return pindex;
}

void quicksort(int *arr,int s,int e)
{
    if(s < e)
    {
        int p = partition(arr,s,e);
        quicksort(arr,s,(p-1));
        quicksort(arr,(p+1),e);
    }
}

int main()
{
    int *arr;
    int size;
    cout << "Enter the size: ";
    cin >> size;
    arr = new int[size];

    cout << "Enter the elements: ";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr,0,size-1);
    cout << endl;
    
    for(int i = 0; i < size; i++)
    {
        cout <<  arr[i];
    }

    return 0;
}