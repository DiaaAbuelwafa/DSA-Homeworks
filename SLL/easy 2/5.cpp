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

        void delete_nth (int indx)
        {
            Node* prev = get_nth(indx - 1);
            Node* cur = get_nth(indx);
            prev->next = cur->next;

            if (cur == tail)
            {
                tail = prev;
            }

            delete_node(cur);
        }

        void insert_to_be_sorted(int value)
        {
            Node* item = new Node(value);

            if (value <= head->data)
            {
                insert_front(value);
            }
            else if (value >= tail->data)
            {
                insert_end(value);
            }
            else 
            {
                for (Node* cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next)
                {
                    if (cur->data >= value)
                    {
                        prev->next = item;
                        item->next = cur;
                        break;
                    }
                }
            }

            length++;
        }

};
int main ()
{

    LinkedList list;

    list.insert_end(10);

    list.insert_to_be_sorted(2);
    list.insert_to_be_sorted(4);
    list.insert_to_be_sorted(30);
    list.insert_to_be_sorted(25);
    list.insert_to_be_sorted(-1);

    list.print();

    return 0;
}