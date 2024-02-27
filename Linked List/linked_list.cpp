#include <iostream>

using namespace std;


class Node 
{
    public:
        int value;
        Node* next; 
        Node(int  value)
        {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList
{
    private:
        Node *head;
        Node *tail;
    
    public:
        int length;
        LinkedList(int value)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
        }
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        void append(int value)
        {
            Node * newNode = new Node(value);

            if(length == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }
        void deleteLast()
        {
            if(length == 0)
            {
                head = nullptr;
                tail = nullptr;
            }

            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node *temp = head;
                Node *prev = head;
                while(temp->next)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = nullptr;
                tail = prev;
                length--;
                if(length == 0)
                {
                    head = nullptr;
                    tail = nullptr;
                }
                delete temp;
            }
            
        }
};

int main()
{
    LinkedList list(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.deleteLast();
    list.printList();
    
    return 0;
}