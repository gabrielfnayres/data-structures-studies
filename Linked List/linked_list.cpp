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
        void prepend(int value)
        {
            Node *newNode = new Node(value);
            if(length == 0)
            {
                head = newNode;
                tail = newNode;
            }

            else
            {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteFirst()
        {
            Node* temp = head;
            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
                length--;
            }
            else
            {
                head = head->next;
                temp = nullptr;
                length--;
            }
        }

        Node* getNode(int index)
        {
            if(index < 0 || index >= length)
            {
                return nullptr;
            }
            Node* temp = head;
            for(int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp;
            
        }
        bool setNode(int index,  int value)
        {
            Node *temp = getNode(index);
            if(temp)
            {
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index , int value)
        {
            if(index < 0 || index > length)
            {
                return false;
            }
            if(index = 0)
            {
                prepend(value);
                return true;
            }
            if(index == length)
            {
                append(value);
                return true;
            }
            Node *newNode = new Node(value);
            Node *temp = getNode(index-1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        bool deleteNode(int index, int value)
        {
            if(length < 0 || length > index)
            {
                return false;
            }
            if(length == 0)
            {
                head = nullptr;
                tail = nullptr;
                return true;
            }
            if(length == 1)
            {
                deleteFirst();
                return true;
            }
            Node *temp = getNode(index);
            Node *prev = getNode(index - 1);
            prev->next = temp->next;
            delete temp;
            length--;
            return true;
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
    list.deleteFirst();
    list.printList();
    cout << list.getNode(0)->value << endl;
    
    return 0;
}