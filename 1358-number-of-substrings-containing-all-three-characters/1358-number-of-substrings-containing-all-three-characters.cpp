class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1;
        int b=-1;
        int c=-1;
        int minimum=-1;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a=i;
            }
            else if(s[i]=='b'){
                b=i;
            }
            else{
                c=i;
            }
            minimum=min({a,b,c});
            if(minimum!=-1){
                count+=minimum+1;
            }
        }
        return count;
    }
};