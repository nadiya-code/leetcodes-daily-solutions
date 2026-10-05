#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int cel=-1;
        for(int i=0;i<M.size();i++){
          bool nobody=true;
          for(int j=0;j<M.size();j++){
            if(M[i][j]==1){
              nobody=false;
              break;
            }
          }
          if(!nobody){
            continue;
          }
          bool everyoneKnows=true;
          for(int k=0;k<M.size();k++){
            if(k!=i && M[k][i]==0){
              everyoneKnows=false;
              break;
            }
          }
          if(everyoneKnows){
            return i;
          }
        }
        return cel;
    }
};
int main(){
  Solution c1;
  int n;
  cin>>n;
  vector<vector<int>>M(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<i<<j<<"element";
      cin>>M[i][j];
    }
  }
  cout<<"person:"<<c1.celebrity(M)+1;
}