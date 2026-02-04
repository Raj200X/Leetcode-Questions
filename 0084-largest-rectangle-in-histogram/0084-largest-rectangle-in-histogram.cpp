class Solution {
public:
    vector <int> nextSmallest(vector<int>& heights){
        stack <int> st;
        st.push(-1);
        int n = heights.size();
        vector <int> ans(n);
        for (int i = n-1;i>=0;i--){
            int curr = heights[i];
            while (st.top()!=-1 && curr <= heights[st.top()]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;

    }
    vector <int> prevSmallest(vector<int>& heights){
        stack <int> st;
        st.push(-1);
        int n = heights.size();
        vector <int> ans(n);
        for (int i = 0;i<n;i++){
            int curr = heights[i];
            while (st.top()!=-1 && curr <= heights[st.top()]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> next(n);
        vector <int> prev (n);
        next = nextSmallest(heights);
        prev = prevSmallest(heights);
        int maxArea = 0;
        for (int i = 0;i<n;i++){
            int l = heights[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int area = l*b;
            maxArea = max(area,maxArea);
        }
        return maxArea;

    }
};