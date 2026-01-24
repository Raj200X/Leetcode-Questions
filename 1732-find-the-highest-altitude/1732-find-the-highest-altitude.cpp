class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector <int>ps(gain.size()+1);
        ps[0] = 0;
        ps[1] = gain[0];
        for (int i = 1;i<gain.size();i++){
            ps[i+1] = gain[i] + ps[i];
        }
        return *max_element(ps.begin(),ps.end());
    }
};