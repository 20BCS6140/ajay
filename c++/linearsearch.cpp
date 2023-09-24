#include <iostream>
using namespace std;

int linear_search(int* arr, int arr_size, int key)
{
    for(int i = 0; i < arr_size; i++)
    {
        if(key == arr[i])
        {
            return i;
        }
    }

    return -1;
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

    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    int result = linear_search(arr,arr_size,key);

    if(result < 0)
        cout << "Not found." << endl;
    else
        cout << "Element found at " << result+1 << endl;
    
    return 0;

}