class Solution {
public:
    long long hours(vector<int>& piles, int k){
        long long hs = 0;
        for(int i = 0; i < piles.size(); i++){
            hs += (piles[i] + k - 1) / k; 
        }
        return hs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l <= r){
            int mid = l + (r - l) / 2;
            long long need = hours(piles, mid);

            if(need <= h){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
