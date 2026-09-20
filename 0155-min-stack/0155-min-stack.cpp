class MinStack {
public:
    stack<pair<int,int>>st;
    int Minimum=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        Minimum=min(Minimum,value);
        st.push({value,Minimum});
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        st.pop();
        if(!st.empty()){
            Minimum=st.top().second;
        }
        else{
            Minimum=INT_MAX;
        }
    }
    
    int top() {
        if(st.empty()){
            return 0;
        }
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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