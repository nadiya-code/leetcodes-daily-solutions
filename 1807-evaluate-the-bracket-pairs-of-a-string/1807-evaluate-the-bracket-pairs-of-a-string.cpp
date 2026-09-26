class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string t="";
        int n=s.size();
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<n;i++){
            if(s[i]!='('){
                t+=s[i];
            }
            else {
                string f="";
                i++;
                while(i<n && s[i]!=')'){
                    f+=s[i];
                    i++;
                }
                auto it=mp.find(f);
                t+=(it!=mp.end()? it->second :"?");       
            }
        }
        return t;
    }
};