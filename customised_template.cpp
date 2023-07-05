#include <iostream>

using namespace std;

template <class T>

class vector
{
    T* arr;
    int size;

    public:

    vector(int n, float ar[])
    {
        size = n;
        arr = new T[size];
        arr = ar;

    }

    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    int product(vector &v)
    {
        T temp = 0;
        T d = 0;
        for(int i = 0; i < size; i++)
        {
           temp = this->arr[i]*v.arr[i]; 
           d+=temp;
        }
        
        return d;
    }

};

int main()
{
    float* arr = new float[2];
    arr[0] = 5.57;
    arr[1] = 10;
    
    vector <float>v1(2,arr);

    v1.display();
    
    float* arr1 = new float[2];
    arr1[0] = 10;
    arr1[1] = 15;
    vector <float>v2(2,arr1);
    v2.display();
    
    cout << v1.product(v2) << endl;



    

    return 0;
}