class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (k >= n) {
            return *max_element(arr.begin(), arr.end());
        }
        int winner = arr[0];
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (winner > arr[i]) {
                count++;
            } else {
                winner = arr[i];
                count = 1;
            }
            if (count == k) {
                return winner;
            }
        }
        return winner;
    }
};