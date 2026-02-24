//622
#include<iostream>
using namespace std;

class MyCircularQueue {
private:
    int front;
    int rear;
    int size;
    int *arr;

public:
    MyCircularQueue(int k) {
        size = k + 1;
        arr = new int[size];
        front = rear = 0;
    }

    bool enQueue(int value) {
        if(isFull()) return false;

        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;

        front = (front + 1) % size;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;
        return arr[(front + 1) % size];
    }

    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    ~MyCircularQueue(){
        delete[] arr;
    }
};

int main(){
    MyCircularQueue q(3);

    cout<<q.enQueue(1)<<endl;
    cout<<q.enQueue(2)<<endl;
    cout<<q.enQueue(3)<<endl;
    cout<<q.enQueue(4)<<endl;

    cout<<q.Rear()<<endl;
    cout<<q.isFull()<<endl;

    cout<<q.deQueue()<<endl;
    cout<<q.enQueue(4)<<endl;

    cout<<q.Rear()<<endl;

    return 0;
}
