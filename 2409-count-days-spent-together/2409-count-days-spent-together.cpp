class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>monthdays={
            31,28,31,30,31,30,31,31,30,31,30,30
        };
        auto convert=[&](string date){
            int month=stoi(date.substr(0,2));
            int day=stoi(date.substr(3,2));
            int total =day;
            for(int i=0;i<month-1;i++){
                total+=monthdays[i];
            }
            return total;
        };
        int startAlice=convert(arriveAlice);
        int startBob=convert(arriveBob);
        int endAlice=convert(leaveAlice);
        int endBob=convert(leaveBob);
        int start=max(startAlice,startBob);
        int end=min(endAlice,endBob);
        return max(0,end-start+1);
    }
};