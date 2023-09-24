#include <iostream>

using namespace std;


void bubble_sort(int *arr, int n)
{
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j+1] < arr[j])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
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

    bubble_sort(arr,arr_size);

    for(int i = 0; i < arr_size; i++)
    {
        cout <<  arr[i] << " ";
    }
    cout << endl;

    return 0;
    
}