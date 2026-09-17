class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int f=s2.top();
            s2.pop();
            return f;
        }
        else if(!s1.empty()){
            while(!s1.empty()){
                int f=s1.top();
                s1.pop();
                s2.push(f);
            }
            int f=s2.top();
            s2.pop();
            return f;
        }
        else{
            return 0;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            int f=s2.top();
            return f;
        }
        else if(!s1.empty()){
            while(!s1.empty()){
                int f=s1.top();
                s1.pop();
                s2.push(f);
            }
            int f=s2.top();
            return f;
        }
        else{
            return 0;
        }
    }
    
    bool empty() {
        if(!s1.empty()||!s2.empty()){
            return false;
        }
        return true;
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