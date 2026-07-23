class MinStack {
private:
    stack<long long> stk;
    long long mini=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(stk.empty()){
            stk.push(value);
            mini=value;
        }
        else{
            if(mini<=value) stk.push(value);
            else{
                long long a=2*(long long)value - mini;
                stk.push(a);
                mini=(long long)value;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        else if(mini<=stk.top()) stk.pop();
        else{
            long long value=stk.top();
            mini=2*mini - value;
            stk.pop();
        } 
    }
    
    int top() {
        if(stk.top() > mini) return stk.top();
        else return mini;
    }
    
    int getMin() {
        return mini;
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