class MinStack {
public:
    std::stack<int> st;
    std::stack<int> mini;
    MinStack() {}
    void push(int val) {
        st.push(val);

        if(mini.empty() || val <= mini.top()) mini.push(val);
    }
    
    void pop() {
        int top = st.top();
        st.pop();

        if(top == mini.top()) mini.pop();
    }
    
    int top() {
        int top = st.top();
        return top;
    }
    
    int getMin() {
        int top = mini.top();
        return top;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */