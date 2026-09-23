class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot=1;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            if(preorder[i]==','){
                continue;
            }
            slot--;
            if(slot<0){
                return false;
            }
            if(preorder[i]!='#'){
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                slot+=2;
            }
        }
        return slot==0;
    }
};