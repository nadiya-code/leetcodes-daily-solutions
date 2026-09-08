class Solution {
public:
    int countCommas(int n) {
        int count=0;
        if(n>=1000){
            n-=1000;
            count=n+1;
        }
        return count;
    }
};