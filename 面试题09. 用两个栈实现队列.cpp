//题目描述
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

class CQueue {
    stack<int> stack1;
    stack<int> stack2;

public:
    CQueue() {
    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack2.empty() && stack1.empty())
            return -1;
        else if (stack2.empty() && !stack1.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }
};
