class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    // APPROACH 1:
    // s1 -> s2;
    // x -> s1;
    // s2 -> s1;

    MyQueue()
    {
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if (s1.empty())
            return -1;
        int popval = s1.top();
        s1.pop();
        return popval;
    }

    int peek()
    {
        if (s1.empty())
            return -1;
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */