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

        int find_transposition (int value) {
            int indx = 0;
            for (int i = 0; i < size; ++i) {

                if (arr[i] == value) {
                    indx = i;
                }

                if (indx == 0) {
                    return 0;
                }
            }

            int temp = 0;
            temp = arr[indx - 1];
            arr[indx - 1] = arr[indx];
            arr[indx] = temp;

            for (int i = 0; i < size; ++i) {
                if (arr[i] == value) {
                    return i;
                }
            }
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
        v.set_values(i, (i + 1) * 10);
    }

    v.print();

    cout << "\n";

    cout << v.find_transposition(10) << "\n";

    v.print();
    
    return 0;
}