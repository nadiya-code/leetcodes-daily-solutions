#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int left=0;
        int siz=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
            siz=max(siz,i-left+1);
        }
        return siz;
    }
};
int main(){
  Solution s1;
  int k;
  cout<<"enter k size";
  cin>>k;
  cout<<endl;
  string s;
  cout<<"enter string";
  cin>>s;
  cout<<"longest distinct k characters :"<<s1.kDistinctChar(s,k);
}