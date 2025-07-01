class MinStack
{
public:
    stack<long long> st;
    long long mini;
    MinStack()
    {
    }

    void push(int val)
    {
        long long value = val;

        // edge case: if the stack is empty
        if (st.empty())
        {
            mini = value;
            st.push(value);
        }

        else
        {
            if (value < mini)
            {
                st.push(2LL * value - mini);
                mini = val;
            }
            else
                st.push(value);
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long ele = st.top();
        st.pop();

        if (ele < mini)
        {
            mini = 2LL * mini - ele;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return (int)mini; // return real mini
        return (int)el;
    }

    int getMin()
    {
        return (int)mini;
    }
};
