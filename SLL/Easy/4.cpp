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

        bool is_identical1 (const LinkedList &other)
        {
            if (length != other.length)
            {
                return false;
            }

            Node* temp = other.head;

            for (Node* cur = head; cur; cur = cur->next, temp = temp->next)
            {
                if (cur->data != temp->data)
                {
                    return false;
                }
            }

            return true;
        }

        bool is_identical2 (const LinkedList &other)
        {
            int count1 = 0, count2 = 0;

            for (Node* cur = head; cur; cur = cur->next)
            {
                count1++;
            }

            for (Node* curo = other.head; curo; curo = curo->next)
            {
                count2++;
            }

            if (count1 != count2)
            {
                return false;
            }

            Node* curo = other.head;
            for (Node* cur = head; cur; cur = cur->next)
            {
                if (cur->data != curo->data)
                {
                    return false;
                }
                curo = curo->next;
            }

            return true;
        }
};
int main ()
{
    LinkedList list1, list2;

    list1.insert_end(2);
    list1.insert_end(4);
    list1.insert_end(6);
    list1.insert_end(8);

    list2.insert_end(2);
    list2.insert_end(4);
    list2.insert_end(6);
    list2.insert_end(8);

    cout << list1.is_identical2(list2) << "\n";
    return 0;
}