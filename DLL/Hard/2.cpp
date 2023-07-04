
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

        Node* get_nth(int indx)
        {
            int counter = 1;
            for (Node* cur = head; cur; cur = cur->next, counter++)
            {
                if (counter == indx)
                {
                    return cur;
                }
            }

            return nullptr;
        }

        void delete_with_position (int indx)
        {
            int counter = 1;
            if (!length)
            {
                return;
            }

            for (Node* cur = head; cur; cur = cur->next, counter++)
            {
                if (counter == indx)
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
                        Node* prv = cur->prv;
                        Node* next = cur->next;
                        prv->next = next;
                        next->prv = prv;
                        delete_node(cur);
                    }
                    break;
                }
            }
        }

        void delete_and_link (Node* cur)
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
        }


        void swap_forward_with_backward (int key)
        {
            Node* work1;
            Node* work2;
            int counter = 1;
            for (Node* cur = head, * prv = tail; cur; cur = cur->next, prv = prv->prv, counter++)
            {
                if (counter == key)
                {
                    work1 = cur;
                    work2 = prv;
                    break;
                }
            }

            if (counter == 1)
            {
                Node* first = work1->next;
                Node* second = work2->prv;

                first->prv = work2;
                work2->next = first;
                work2->prv = nullptr;
                head = work2;

                second->next = work1;
                work1->next = nullptr;
                work1->prv = second;
                tail = work1;
            }
            else if (work1->next == work2)
            {
                Node* first = work1->prv;
                Node* second = work2->next;

                work2->next = work1;
                work1->prv = work2;

                first->next = work2;
                work2->prv = first;

                second->prv = work1;
                work1->next = second;

            }
            else
            {
                Node* prv1 = work1->prv;
                Node* next1 = work1->next;

                Node* prv2 = work2->prv;
                Node* next2 = work2->next;

                prv1->next = work2;
                next1->prv = work2;
                work2->prv = prv1;
                work2->next = next1;

                prv2->next = work1;
                next2->prv = work1;
                work1->prv = prv2;
                work1->next = next2;
            }
        }
        
};
int main()
{
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(6);



    list.print();

    list.swap_forward_with_backward(2);

    list.print();
    return 0;
}