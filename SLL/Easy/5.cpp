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

    public:
        void print()
        {
            for (Node* cur = head; cur; cur = cur->next)
            {
                cout << cur->data << " ";
            }

            cout << "\n";
        }

        void add_element(int value)
        {
            Node* item = new Node(value);
            if (!head)
            {
                head = item;
            } 
            else
            {
                item->next = head;
                head = item;
            }
        }

        Node* get_tail ()
        {
            Node* cur = head;
            for (cur; cur->next; cur = cur->next)
            {
            }

            return cur;
        }
};
int main ()
{

    LinkedList list;
    list.add_element(2);
    list.add_element(4);
    list.add_element(6);
    list.add_element(8);

    cout << list.get_tail()->data << "\n";
    return 0;
}