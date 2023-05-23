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

        void pop(int indx) {
            for (int i = indx; i <= size - 2; ++i) {
                arr[i] = arr[i + 1];
            }
            size--;
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
        v.set_values(i, i);
    }

    v.print();

    cout << "\n";

    v.pop(2);

    v.print();
    
    return 0;
}