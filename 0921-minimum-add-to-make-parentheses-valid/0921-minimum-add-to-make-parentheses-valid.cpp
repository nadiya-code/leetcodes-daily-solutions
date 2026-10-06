class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        for(char &c:s){
            if(c=='('){
                st.push(c);
                count++;
            }
            else{
                if(st.empty()){
                    count++;
                }
                else{
                    st.pop();
                    count--;
                }
            }
        }
        return count;
    }
};