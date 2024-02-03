#include <iostream>
using namespace std;
#define max 100

class Queue
{
    int front, rear;
    int arr[max];

public:
    Queue(){
        front=rear=-1;
    }
    bool isempty()
    {
        return front == -1 && rear == -1;
    }
    bool isfull(){
        return rear == max-1;
    }
    void enQueue(int item){
        if(isfull()){
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if(isempty()){
            front = rear = 0;
        }else{
            rear++;
        }
        arr[rear] = item;
        cout << "Enqueue : " << item <<endl;
    }

    void deQueue(){
        if(isempty()){
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if(front==rear){
            front = rear = -1;
        }else{
            front++;
        }
    }

    int peek() {
        if (isempty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Assuming -1 represents an error or an empty value
        }

        return arr[front];
    }

    int size() {
        if (isempty()) {
            return 0;
        }

        return rear - front + 1;
    }

};
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    cout << "Queue Size: " << q.size() << endl;

    cout << "Front element: " << q.peek() << endl;

    q.deQueue();
    q.deQueue();

    cout << "Queue Size: " << q.size() << endl;
    return 0;
}