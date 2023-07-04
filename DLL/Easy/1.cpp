
#include <iostream>
using namespace std;

struct Node
{
    int data {};
    Node* next {};
    Node* prv {};
    Node (int data):data(data) {};
};

class LinkedList
{
    private:
        Node* head {};
        Node* tail {};
        int length = 0;

    public:
        void print ()
        {
            for (Node* cur = head; cur; cur = cur->next)
            {
                cout << cur->data << " ";
            }

            cout << "\n";
        }

        void insert_end (int value)
        {
            Node* temp = new Node(value);
            if (!head)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                temp->prv = tail;
                tail = temp;
            }

            length++;
        }

        void insert_front (int value)
        {
            Node* temp = new Node(value);

            if (!head)
            {
                head = tail = temp;
            }
            else
            {
                head->prv = temp;
                temp->next = head;
                head = temp;
            }

            length++;
        }

        void delete_node (Node* node)
        {
            delete node;
            length--;
        }

        void delete_front ()
        {
            if (!head)
            {
                return;
            }
            else
            {
                Node* temp = head->next;
                delete_node(head);
                head = temp;
                head->prv = nullptr;
            }
        }


        void delete_end ()
        {
            if (!head)
            {
                return;
            }
            else
            {
                Node* temp = tail->prv;
                delete_node(tail);
                tail = temp;
                tail->next = nullptr;
            }
        }

        void delete_with_key (int key)
        {
            for (Node* cur = head; cur; cur = cur->next)
            {
                if (cur->data == key)
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
                        Node* prev = cur->prv;
                        Node* next = cur->next;
                        prev->next = next;
                        next->prv = prev;
                        delete_node(cur);
                    }
                    break;
                }
            }
        }

        int get_length()
        {
            return length;
        }

        void delet_all_nodes_with_key (int value)
        {
            int counter = 0;
            for (Node* cur = head; cur; cur = cur->next)
            {
                if (cur->data == value)
                {
                    counter++;
                }
            }
            for (int i = 1; i <= counter; i++)
            {
                delete_with_key(value);
            }
        }
};
int main()
{
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(5);
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(4);
    list.insert_end(4);


    list.print();

    list.delet_all_nodes_with_key(4);

    list.print();

    return 0;
}