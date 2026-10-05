class StockSpanner {
public:
    int i;
    stack<int>st;
    vector<int>arr;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        int x;
        while(!st.empty() && arr[st.top()]<=price){
            st.pop();
        }
        if(st.empty()){
            x= i+1;
        }
        else{
            x= i-st.top();
        }
        arr.push_back(price);
        st.push(i);
        i++;
        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */