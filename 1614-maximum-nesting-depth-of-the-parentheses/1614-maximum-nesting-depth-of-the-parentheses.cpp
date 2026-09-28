class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int depth=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth+=1;
                ans=max(depth,ans);
            }
            else if(s[i]==')'){
                depth-=1;
            }
        }
        return ans;
    }
};