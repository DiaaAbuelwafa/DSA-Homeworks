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

        void swap_head_tail ()
        {
            if (head->next == tail)
            {
                swap(head, tail);
                head->next = tail;
                tail->next = nullptr;
            }
            else 
            {
                Node* next = head->next;
                Node* prv = nullptr;
                Node* temp = head;
                for (Node* cur = head; cur->next;prv = cur, cur = cur->next)
                {

                }
                head = tail;
                head->next = next;
                prv->next = temp;
                tail = temp;
                tail->next = nullptr;
            }
        }
};
int main ()
{

    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);



    list.print();

    list.swap_head_tail();

    list.print();
    return 0;
}