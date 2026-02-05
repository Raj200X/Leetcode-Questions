class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack <int> lmax;
        stack <int> rmax;
        lmax.push(0);
        rmax.push(0);
        int ans =0 ;
        for (int i = 0;i<height.size();i++){
            if (lmax.top()<height[i]){
                lmax.push(height[i]);
            }
            else {
                lmax.push(lmax.top());
            }
        }
        for (int i = n-1;i>0;i--){
            int ele = min(lmax.top(),rmax.top())-height[i];
            if (ele>0){
                ans = ans + ele;
            }
            if (rmax.top()<height[i]){
                rmax.push(height[i]);
            }
            else{
                rmax.push(rmax.top());
            }
            lmax.pop();
        }
        return ans;

        
    }
};