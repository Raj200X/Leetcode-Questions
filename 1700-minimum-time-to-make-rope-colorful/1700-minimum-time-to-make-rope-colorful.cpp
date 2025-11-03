class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mini = 0;
        int maxi = 0;
        for (int i = 1;i<colors.size();i++){
            if (colors[i]==colors[i-1]){
                mini += min(neededTime[i],neededTime[i-1]); 
                neededTime[i]=max(neededTime[i],neededTime[i-1]);
                
            }
        }
        return mini;


    }
};