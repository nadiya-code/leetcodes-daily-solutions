class Solution {
public:
    bool canAliceWin(int n) {
        int alice=10;
        while(n>=alice){
            n-=alice;
            if(n<alice-1){
                return true;
            }
            else{
                alice--;
                n-=alice;
                alice--;
            }
        }
        return false;
    }
};