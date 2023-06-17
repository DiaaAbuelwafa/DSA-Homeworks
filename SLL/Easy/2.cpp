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

        void delete_front()
        {
            Node* first = head;
            head = head->next;
            delete first;
        }
};
int main ()
{
    LinkedList list;

    list.insert_end(2);
    list.insert_end(4);
    list.insert_end(6);
    list.insert_end(8);

    list.print();

    list.delete_front();

    list.print();
    
    return 0;
}