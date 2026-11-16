class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int len=0;
            string ans="";
            while(len<s.size()){
                string t=s.substr(len,k);
                int sum=0;
                for(int i=0;i<t.size();i++){
                    sum+=t[i]-'0';
                }
                ans+=to_string(sum);
                len+=k;
            }
            s=ans;
        }
        return s;
    }
};