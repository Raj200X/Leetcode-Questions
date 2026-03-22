class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ones;
        int n = boxes.size();
        
        // store indices of '1'
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                ones.push_back(i);
            }
        }
        
        vector<int> ans(n, 0);
        
        // for each box
        for (int i = 0; i < n; i++) {
            int moves = 0;
            for (int idx : ones) {
                moves += abs(i - idx);
            }
            ans[i] = moves;
        }
        
        return ans;
    }
};