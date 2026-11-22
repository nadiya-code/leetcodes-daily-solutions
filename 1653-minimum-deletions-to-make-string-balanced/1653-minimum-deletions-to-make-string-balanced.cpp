class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int removed=INT_MAX;
        vector<int>leftb(n,0);
        vector<int>righta(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            leftb[i]=count;
            if(s[i]=='b'){
                count++;
            }
        }
        count=0;
        for(int i=n-1;i>=0;i--){
            righta[i]=count;
            if(s[i]=='a'){
                count++;
            }
        }
        for(int i=0;i<n;i++){
            removed=min(removed,leftb[i]+righta[i]);
        }
        return removed;
    }
};