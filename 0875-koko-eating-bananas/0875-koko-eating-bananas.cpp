class Solution {
public:
    double hours(vector<int>& piles, int mid){
        double hs = 0;
        for (int i=0;i<piles.size();i++){
           hs += ceil((double)piles[i] / mid);
        }
        return hs;
    }
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int l = 1;
        int max_ele = piles[0];
        for (int i = 0;i<piles.size();i++){
            max_ele = max(max_ele,piles[i]);
        }
        int h = max_ele;
        while(l<=h){
            int mid = (h+l)/2;
            double hour = hours(piles,mid);

            if (hour<=hrs){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};