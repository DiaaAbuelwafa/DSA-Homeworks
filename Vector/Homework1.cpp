#include <iostream>
#include <algorithm>
using namespace std;

class Vector {
    private:
        int* arr = nullptr;
        int size = 0;
    public:
        Vector(int size):size(size) {
            if (size < 0)
                size = 1;
            arr = new int[size]{};
        }
        ~Vector() {
            delete[] arr;
            arr = nullptr;
        }

        void rotate_right() {
            int* arr2 = new int[size]{};
            for (int i = 0; i < size; ++i) {
                arr2[(i + 1) % size] = arr[i]; 
            }
            swap(arr, arr2);
            delete[] arr2;
        }

        void print() {
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
        }

        void set_values(int indx, int value) {
            arr[indx] = value;
        }
};
int main ()
{
    Vector v(5);

    for (int i = 0; i < 5; ++i) {
        v.set_values(i, i + 1);
    }

    v.print();

    cout << "\n";

    v.rotate_right();

    v.print();
    
    return 0;
}