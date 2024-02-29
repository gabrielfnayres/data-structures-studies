#include <iostream>

using namespace std;


class Node
{
    public:
        int value;
        Node *next;
        Node(int value)
        {
            this->value = value;
            next = nullptr;
        }
};

class Queue
{
    private:
        Node* first;
        Node* last;
        int length;
    public:
        Queue(int value)
        {
            Node *newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }
        void enqueue(int value)
        {
            Node* newNode = new Node(value);
            if(length == 0)
            {
                first = newNode;
                last = newNode;
            }
            else
            {
                last->next = newNode;
                last = newNode; 
                
            } 
            length++;
        }

        int dequeue()
        {
            if(length == 0)
            {
                return INT8_MIN;
            }

            int valDeq = first->value;
            Node *temp = first;
            if(length == 1)
            {
                first = nullptr;
                last = nullptr;
                return 0;
            }
            else
            {
                first = first->next;
            }
            
            delete temp;
            length--;

            return valDeq;
        }   
};