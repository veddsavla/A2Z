class ArrayQueue
{
private:
    int *q;
    int size;
    int curSize;
    int start;
    int end;
    int capacity;

public:
    ArrayQueue()
    {
        size = capacity;
        curSize = 0;
        start = 0;
        end = -1;
        q = new int[size];
    }

    void push(int x)
    {
        if (curSize == size)
            return; // or handle full queue appropriately
        if (curSize == 0)
        {
            start = end = 0;
        }
        else
        {
            end = (end + 1) % size;
        }
        q[end] = x;
        curSize += 1;
    }
    int pop()
    {
        if (curSize == 0)
            return -1; // or throw exception
        int value = q[start];
        start = (start + 1) % size;
        curSize -= 1;
        return value;
    }

    int peek()
    {
        if (curSize == 0)
            return -1; // or throw exception
        return q[start];
    }

    bool isEmpty()
    {
        return curSize == 0;
    }
};