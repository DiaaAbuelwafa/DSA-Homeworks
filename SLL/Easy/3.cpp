#include <iostream>
using namespace std;

struct Node
{
    int data {};
    Node* next {};

    Node (int data):data(data){};
};

class LinkedList
{
    private:
        Node* head {};
        Node* tail {};
        int length = 0;
    public:
        void print()
        {

            for (Node* cur = head; cur; cur = cur->next)
            {
                cout << cur->data << " ";
            }

            cout << "\n";
        }

        void insert_end (int value)
        {
            Node* item = new Node(value);

            if (!head)
            {
                head = tail = item;
            }
            else
            {
                tail->next = item;
                tail = item;
            }

            length++;
        }

        int get_length()
        {
            return length;
        }

        Node* get_nth_back (int n)
        {
            int counter = length;

            for (Node* cur = head; cur; cur = cur->next, counter--)
            {
                if (counter == n)
                {
                    return cur;
                }
            }

            return nullptr;
        }
};
int main ()
{
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(6);

    list.print();

    cout << list.get_nth_back(5)->data << "\n";
    return 0;
}