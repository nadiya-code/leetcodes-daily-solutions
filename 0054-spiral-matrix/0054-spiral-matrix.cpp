class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow=0;
        int scol=0;
        int erow=matrix.size()-1;
        int ecol=matrix[0].size()-1;
        vector<int>array;
        while(srow<=erow && scol<=ecol){
            for(int i=scol;i<=ecol;i++){
                array.push_back(matrix[srow][i]);
            }
            srow++;
            for(int i=srow;i<=erow;i++){
                array.push_back(matrix[i][ecol]);
            }
            ecol--;
            if(srow<=erow){
                for(int i= ecol;i>=scol;i--){
                    array.push_back(matrix[erow][i]);
                }
            }
            erow--;
            if(scol<=ecol){
                for(int i=erow;i>=srow;i--){
                    array.push_back(matrix[i][scol]);
                }
            }
            scol++;
        }
        return array;
    }
};