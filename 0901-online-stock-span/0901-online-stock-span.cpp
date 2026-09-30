class StockSpanner {
public:
    stack<int>st;
    vector<int>prices;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        while(!st.empty() && prices[st.top()]<=price){
            st.pop();
        }
        int length;
        if(st.empty()){
            length=i+1;
        }
        else{
            length=i-st.top();
        }
        st.push(i);
        i++;
        prices.push_back(price);
        return length;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */