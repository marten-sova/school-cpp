#include "queue.h"
using namespace std;


queue::queue():front(-1), rear(-1), capacity(100)
{
    arr = new resultdata[capacity];
    //for (int i=0;i<capacity;i++)
        //arr[i] = new resultdata();
}

queue::queue(const int maxCapacity):front(-1), rear(-1), capacity(maxCapacity)
{
    arr = new resultdata[capacity];
    //for (int i=0;i<capacity;i++)
        //arr[i] = new resultdata();
}

queue::queue(const queue& aQueue)
{
    capacity = aQueue.capacity;
    front = aQueue.front;
    rear = aQueue.rear;
    arr = new resultdata[capacity];
    for(int i=front; i<=aQueue.rear; i++)
        arr[i] = aQueue.arr[i];
}

const queue& queue::operator=(const queue& aQueue)
{
}

queue::~queue()
{
    /*
    for(int i = 0;i<capacity;i++){
        delete &arr[i];
    }
    */
    delete[] arr;
}

bool queue::enqueue(const resultdata& entry)
{
	if ((front == 0 && rear == capacity-1) || (rear == (front-1)%(capacity-1))) 
    { 
        //cout << "exception: queue is full" << endl;
        return false; 
    } 
  
    else if (front == -1) /* Insert First Element */
    { 
        //cout << "exception: this is the first entry" << endl;
        front = 0;
        rear = 0; 
        arr[rear] = resultdata(entry);
    } 
  
    else if (rear == capacity-1 && front != 0) 
    { 
        //cout << "exception: wrapping" << endl;
        rear = 0; 
        arr[rear] = resultdata(entry);
    } 
  
    else
    { 
        //cout << "standard insertion" << endl;
        rear++; 
        arr[rear] = resultdata(entry);
    }
    return true;
}

resultdata queue::dequeue ()
{
    resultdata entry = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == capacity-1) 
        front = 0; 
    else
        front++;
    return entry;
}

bool queue::isEmpty() const
{
    return (front == -1);
}

void queue::debugInfo() const
{
    cout << "Queue debug info..." << endl;
    cout << "front: " << front << endl;
    cout << "rear: " << rear << endl;
    cout << "capacity: " << capacity << endl;
}
