#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int *arr,int l, int r, int key)
{
    if(l <= r)
    {
        int mid = l + (r - l) / 2;;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            return binary_search(arr,mid+1,r,key);
        else if(arr[mid] > key)
            return binary_search(arr,l,mid-1,key);
    }
    
    
    return -1;
}

int binary_search_iterative(int *arr,int l, int r, int key)
{
    while (l <= r)
    {
        int mid = l+(r-l)/2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            l = mid+1;
        else if(arr[mid] > key)
            r  = mid-1;

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

    sort(arr,arr+arr_size);


    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    int result = binary_search_iterative(arr, 0, arr_size,key);

    if(result < 0)
        cout << "Not found." << endl;
    else
        cout << "Element found at " << result+1 << endl;
}