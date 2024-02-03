#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isempty() {
        return front == -1 && rear == -1;
    }

    bool isfull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int item) {
        if (isfull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isempty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = item;
        cout << "Enqueued: " << item << endl;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
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

        return (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cout << "Queue Size: " << cq.size() << endl;

    cout << "Front element: " << cq.peek() << endl;

    cq.dequeue();
    cq.enqueue(40);
    cq.enqueue(50);

    cout << "Queue Size: " << cq.size() << endl;

    return 0;
}
