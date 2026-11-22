class Solution {
public:
    bool checkString(string s) {
        bool presentb=false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a' && presentb==true){
                return false;
            }
            else if(s[i]=='b'){
                presentb=true;
            }
        }
        return true;
    }
};