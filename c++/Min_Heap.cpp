#include <iostream>
#include <array>
#include <algorithm>
#include <math.h>

using namespace std;

/*
class Minheap
{
    int *heap_arr;
    int capacity;
    int heap_size;

    Minheap(int cap);
    int parent(int i);
    int left(int i);
    int right(int i);
    int getMin();
    int ExtractMin();
    void insertkey(int k);
    void decreasekey(int i, int new_val);
    void deletekey(int i);
    void MinHeapify(int i);
    void linearsearch(int val);
    void printArray();
    int height();
}

*/


class Minheap
{
    public:

        int * heap_arr;
        int capacity;
        int heap_size;


        Minheap(int cap)
        {
            capacity =  cap;
            heap_size = 0;
            heap_arr = new int[capacity];
        }

        void linearsearch(int value)
        {
            for(int i = 0; i < heap_size; i++)
            {
                if(heap_arr[i] == value)
                {
                    cout << "Value found" << endl;
                    return;
                }
            }

            cout << "Value not found" << endl;
            return;
        }

        void print()
        {
            for(int i = 0; i < heap_size; i++)
            {
                cout << heap_arr[i] << " ";
            }
            cout << "\n";
        }

        int height()
        {
            return ceil(log2(heap_size+1)) - 1;
        }

        int parent(int i)
        {
            if(heap_size == 0)
            {
                return 0;
            }
            else
            {
                return (i-1)/2;
            }
        }

        int left_node(int i)
        {
            if(heap_size == 0)
            {
                return 0;
            }
            else
            {
                return (2*i)+1;
            }
        }

        int right_node(int i)
        {
            if(heap_size == 0)
            {
                return 0;
            }
            else
            {
                return (2*i)+2;
            }
        }

        void insertkey(int val)
        {
            if(heap_size >= capacity)
            {
                cout << "Heap Overflow!" << endl;
                return;
            }

            heap_size++;
            int i =  heap_size-1;
            heap_arr[i] = val;
            

            while((i != 0) && (heap_arr[parent(i)] > heap_arr[i]))
            {
                swap(heap_arr[i], heap_arr[parent(i)]);
                i = parent(i);
            }

            cout << "Key Inserted!" << endl;
            return;

        }

        void heapify(int i)
        {
            int l = left_node(i);
            int r = right_node(i);

            int smallest = i;

            if(l < heap_size && heap_arr[i] > heap_arr[l])
                smallest = l;
            if(r < heap_size && heap_arr[r] < heap_arr[smallest])
                smallest = r;
            
            if(smallest != i)
            {
                swap(heap_arr[i], heap_arr[smallest]);
                heapify(smallest);
            }

        }


        int ExtractMin()
        {
            if (heap_size <= 0) return INT_MAX;

            if (heap_size == 1)
            {
                heap_size--;
                return heap_arr[0];
            }


            int root = heap_arr[0];
            heap_arr[0] = heap_arr[heap_size-1];
            heap_size--;
            heapify(0);
            return root;
        }

        int getMinofHeap()
        {
            if(heap_size <= 0)
                return INT_MAX;
            else
                return heap_arr[0];
        }

        int getindex(int element)
        {
            for(int i = 0; i < heap_size; i++)
            {
                if(element == heap_arr[i])
                {
                    return i;
                }
            }

            return -1;
        }


        void DeleteKey(int index, int new_val)
        {
            if(index == -1)
            {
                cout << "Element is not there in the heap." << endl;
                return;
            }
            decrease_key(index,new_val);
            ExtractMin();
            cout << "Element deleted successfully!" << endl;
            return;
        }

        void decrease_key(int i, int val)
        {
            heap_arr[i] = val;

            while(i != 0 && heap_arr[i] < heap_arr[parent(i)])
            {
                swap(heap_arr[i], heap_arr[parent(i)]);
                i = parent(i);
            }
        }


};

int main()
{
    int size;
    cout << "Enter the size: ";
    cin >> size;
    Minheap heap(size);
    cout << "Min Heap created!" << endl;


    int option, val;

    do
    {
        cout << "0. Exit." << endl;
        cout << "1. Insert a value." << endl;
        cout << "2. Search for a value." << endl;
        cout << "3. Delete a value." << endl;
        cout << "4. Get Minimum value." << endl;
        cout << "5. Extract Minimum Value." << endl;
        cout << "6. Height of the heap." << endl;
        cout << "7. Print the heap." << endl;
        cout << "8. Clear screen." << endl;

        cout << "\n\n";
        cout << "Enter an option: ";
        cin >> option;



        switch (option)
        {
            case 1:
            {   
                cout << "Enter a value to insert: ";
                cin >> val;
                heap.insertkey(val);

                break;
            }
            case 2:
            {
                cout << "\n";
                cout << "Enter a value to search in the heap: ";
                cin >> val;
                
                heap.linearsearch(val);
                cout << "\n";
                break;
            }
            case 3:
            {
                cout << "Enter an element to delete: ";
                cin >> val;
                heap.DeleteKey(heap.getindex(val),INT_MIN);
                break;
            }
            case 4:
            {
                int minimumvalue = heap.getMinofHeap();
                if(minimumvalue == INT_MAX)
                {
                    cout << "Heap is empty" << endl;
                }
                else
                {
                    cout << "The minimum value of heap: " << minimumvalue << endl;
                }
                break;
            }
            case 5:
            {
                int minimumvalue = heap.ExtractMin();
                if(minimumvalue == INT_MAX)
                {
                    cout << "Heap is empty" << endl;
                }
                else
                {
                    cout << "The minimum value of heap: " << minimumvalue << endl;
                    heap.print();
                }
                break;
            }
            case 6:
            {
                int height = heap.height();
                cout << "Height of the heap: " << height << endl;
                break;
            }
            case 7:
            {
                heap.print();
                break;
            }
            case 8:
            {
                system("cls");
                break;
            }
            case 0:
                exit(0);
            default:
            {
                cout << "Enter a proper option." << endl;
                break;
            }
        
        
        }
    } while (option != 0);
    


}




