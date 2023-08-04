#include <iostream>
#include <vector>

using namespace std;


void merge(int arr[], int l, int m, int r)
{

    int i = l;
    int k = l;
    int j = m+1;

    int temp[r];

    while(i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++,k++;
        }
        else 
        {
            temp[k] = arr[j];
            j++, k++;
        }
    }

    while(i <= m)
    {
        temp[k] = arr[i];
        i++,k++;
    }

    while(j <= r)
    {
        temp[k] = arr[j];
        j++, k++;
    }

    for(int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }



}

void mergesort(int arr[], int l, int r)
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
    int arr[] =  {85,45,95,5,23,78};

    int size = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,size-1);

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}