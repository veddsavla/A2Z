
class LinkedListStack
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node *topNode; // renamed from 'top' to avoid name conflict
    int size;

public:
    LinkedListStack()
    {
        topNode = nullptr;
        size = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = topNode;
        topNode = temp;
        size++;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        Node *temp = topNode;
        int poppedVal = temp->val;
        topNode = topNode->next;
        delete temp;
        size--;
        return poppedVal;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        return topNode->val;
    }

    bool isEmpty()
    {
        return (topNode == nullptr);
    }
};