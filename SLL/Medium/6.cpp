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

        void delete_front()
        {
            Node* temp = head;
            head = head->next;
            delete_node(temp);

        }

        void delete_end ()
        {
            Node* prev = get_nth(length - 1);
            delete_node(tail);
            tail = prev;
            tail->next = nullptr;
        }

        void delete_nth_node(int n)
        {
            if (n < 1 || n > length)
            {
                cout << "Error" << "\n";
            }
            else if (n == 1)
            {
                delete_front();
            }
            else
            {
                Node* prev = get_nth(n - 1);
                Node* nth = get_nth(n);
                prev->next = nth->next;
                if (nth == tail)
                {
                    tail = prev;
                }
                delete_node(nth);
            }
        }

        void delete_node_2 (Node* node)
        {
            for (Node* cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
            {
                if (cur->next == node->next)
                {
                    if (cur == head)
                    {
                        delete_front();
                    } 
                    else if (cur == tail)
                    {
                        delete_end();
                    }
                    else 
                    {
                        prv->next = cur->next;
                        delete_node(cur);
                    }
                }
            }
        }

        int max (const LinkedList &list)
        {
            int maxi = head->data;

            for (Node* cur = head; cur; cur = cur->next)
            {
                if (cur->data > maxi)
                {
                    maxi = cur->data;
                }
            }

            return maxi;
        }

};
int main ()
{

    LinkedList list;

    list.insert_end(6);
    list.insert_end(10);
    list.insert_end(8);
    list.insert_end(15);


    list.print();


    cout << list.max(list) << "\n";

    return 0;
}