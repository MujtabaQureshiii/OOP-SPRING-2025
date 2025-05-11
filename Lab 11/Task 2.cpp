#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
private:
    int front, rear, size, capacity;
    T* data;

public:
    Queue(int cap) : front(0), rear(0), size(0), capacity(cap) {
        data = new T[capacity];
    }

    void enqueue(T item) {
        if (size == capacity) {
            throw QueueOverflowException();
        }
        data[rear] = item;
        rear = (rear + 1) % capacity;
        size++;
    }

    T dequeue() {
        if (size == 0) {
            throw QueueUnderflowException();
        }
        T item = data[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    ~Queue() {
        delete[] data;
    }
};

int main() {
    Queue<int> q(3);

    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
    }
    catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to dequeue from an empty queue..." << endl;
        Queue<int> emptyQ(2);
        emptyQ.dequeue();
    }
    catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
