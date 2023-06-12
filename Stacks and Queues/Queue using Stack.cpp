// link https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        while (s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s1.top();
        s1.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int peek()
    {
        while (s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s1.top();
        s1.pop();
        s2.push(ans);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool empty()
    {
        if (s1.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
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