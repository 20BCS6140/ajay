#include <iostream>

using namespace std;

void merge(int *arr, int l, int m, int r)
{
    int i = l, j = m+1, k=l;

    int *temp;
    temp = new int[r-l];

    while(i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;    
        }
    }

    while(i <= m)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while(j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++; 
    }

    for(int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }

}


void mergesort(int *arr, int l, int r)
{
    int m = (l+r)/2;
    if(l < r)
    {
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
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

    mergesort(arr,0,size-1);
    cout << endl;
    
    for(int i = 0; i < size; i++)
    {
        cout <<  arr[i];
    }
}