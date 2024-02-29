#include <iostream>
#include <vector>

using namespace std;


class Node
{
    public:
        int value;
        Node *next;
        Node *prev;
        Node(int value)
        {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoubleLinkedList
{
    private:
        Node *head;
        Node *tail;
        int length;

    public:
        DoubleLinkedList(int value)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList()
        {
            Node *temp = head;
            if (temp == nullptr)
            {
                cout << "empty";
            }
            else
            {
                while (temp != nullptr)
                {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr)
                    {
                        cout << " <-> ";
                    }
                }
            }
            cout << endl;
        }

        void append(int value)
        {
            Node *newNode = new Node(value);
            if(length == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        void deleteLast()
        {
            Node*  temp = tail;
            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
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
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteFirst()
        {
            Node *temp = head;
            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }

        Node* getNode(int index)
        {

            if(index < 0 || index >= length)
            {
                return nullptr;
            }
            Node *temp;
            if(index < length/2)
            {
                temp = head;
                for(int i = 0; i < index; i++)
                {
                    temp =  temp->next;
                    
                }
            }
            else
            {
                temp = tail;
                for(int i = length - 1; i > index; i--)
                {
                    temp = temp->prev;
                }
            }
            
            return temp;
        }

        bool setNode(int index, int value)
        {
            if(index < 0 || index  >  length)
            {
                return false;
            }
            Node *temp = getNode(index);
            if(temp)
            {
                temp->next = temp;
                return true;
            }
            return false;
        
        }
        bool insert(int index, int value)
        {
            if(index < 0 || index > length)
            {
                return false;
            }
            if(index == 0)
            {
                prepend(value);
                return true;
            }
            if(index == 1)
            {
                append(value);
                return true;
            }

            Node *newNode = new Node(value);
            Node *after = getNode(index);
            Node *before = getNode(index - 1);

            newNode->prev = before;
            newNode->next = after;
            before->next = newNode;
            after->prev = newNode;
            length++;
        }

        bool deleteNode(int index,  int value)
        {
            if(length < 0 || index  > length)
                return false;
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
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
            return true;
        }
};