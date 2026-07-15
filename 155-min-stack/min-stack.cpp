class MinStack {
public:
    stack<int>Main;
    stack<int>Min;
    MinStack() {
        
    }
    
    void push(int value) {

        if(Main.empty()){
            Main.push(value);
            Min.push(value);
        }
        else{
            Main.push(value);
            if(Min.top()>=value){
                Min.push(value);
            }
            else{
                Min.push(Min.top());
            }

        }
    }

    
    void pop() {
        Main.pop();
        Min.pop();

    }
    
    int top() {
        return Main.top();
    }
    
    int getMin() {
        return Min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */