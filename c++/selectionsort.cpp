#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int *arr, int n)
{
    int min = 0;
    int temp = 0;
    for(int i = 0; i < n-1; i++)
    {
        min = i;

        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

    }
    return;
}


int main()
{
    int arr_size;
    int *arr;
    cout << "Enter array size: ";
    cin >> arr_size;

    arr = new int[arr_size];

    cout << "Enter " << arr_size << " elements by giving space: ";

    for(int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    selection_sort(arr,arr_size);

    for(int i = 0; i < arr_size; i++)
    {
        cout <<  arr[i] << " ";
    }
    cout << endl;

    return 0;
    
}