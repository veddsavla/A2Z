void MyQueue::push(int x)
{
    QueueNode *temp = new QueueNode(x);
    if (front == nullptr)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp; // ✅ Update rear after enqueue
    }
}

int MyQueue::pop()
{
    if (front == nullptr)
        return -1; // ✅ Queue is empty

    int val = front->data;
    QueueNode *temp = front;
    front = front->next;

    if (front == nullptr) // ✅ If queue becomes empty, update rear too
        rear = nullptr;

    delete temp;
    return val;
}
