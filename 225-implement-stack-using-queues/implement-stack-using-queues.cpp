class MyStack {
public:
    int stack[100000];
    int front;
    int rear;
    MyStack() {
        front=0;
        rear=0;
    }
    
    void push(int x) {
        stack[rear++]=x;
        if(rear>1){
            front++;
        }
    }
    
    int pop() {
        rear--;
        if(front==0){
            return stack[front];
        }
        return stack[front--];
    }
    
    int top() {
        return stack[front];
    }
    
    bool empty() {
        return front==rear;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */