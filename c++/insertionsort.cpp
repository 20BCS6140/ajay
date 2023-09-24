#include <iostream>
using namespace std;

void insertion_sort(int *arr, int n)
{
    int key = 0;
    int j;

    for(int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
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

    insertion_sort(arr,arr_size);

    for(int i = 0; i < arr_size; i++)
    {
        cout <<  arr[i] << " ";
    }
    cout << endl;

    return 0;
}