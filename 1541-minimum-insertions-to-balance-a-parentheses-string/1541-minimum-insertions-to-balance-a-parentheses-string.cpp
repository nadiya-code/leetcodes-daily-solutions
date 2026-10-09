class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            else{
                if(count<=0){
                    ans++;
                }
                else{
                    count--;
                }
                if(i+1<n && s[i+1]==')'){
                    i++;
                }
                else{
                    ans++;
                }
            }
        }
        return ans+count*2;
    }
};