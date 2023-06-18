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

        void insert_front(int value)
        {
            Node* item = new Node(value);

            if (!head)
            {
                head = tail = item;
            }
            else
            {
                item->next = head;
                head = item;
            }

            length++;
        }

        Node* get_nth (int n)
        {
            int counter = 1;
            for (Node* cur = head; cur; cur = cur->next, counter++)
            {
                if (counter == n)
                {
                    return cur;
                }
            }

            return nullptr;
        }

        int search(int value)
        {
            int counter = 1;
            for (Node* cur = head; cur; cur = cur->next, counter++)
            {
                if (cur->data == value)
                {
                    return counter;
                }
            }

            return -1;
        }

        void delete_node (Node* node)
        {
            delete node;
            length--;
        }

        void reverse_list ()
        {
            Node* first = head;
            Node* second = head->next;

            Node* temp = head;
            head = tail;
            tail = temp;
            tail->next = nullptr;

            while (second)
            {
                Node* next = second->next;
                second->next = first;

                first = second;
                second = next;
            }
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

    list.reverse_list();

    list.print();
    return 0;
}