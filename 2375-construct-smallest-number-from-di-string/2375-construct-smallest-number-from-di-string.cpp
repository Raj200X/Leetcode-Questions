class Solution {
public:
    string smallestNumber(string s) {
        stack<int>st;
        string ans = "";
        for (int i =0;i<=s.size();i++){
            st.push(i+1);
            if (i == s.size() || s[i] == 'I'){
                while (!st.empty()) {
                    ans += to_string(st.top());
                    st.pop();
                }
            }

        }
        return ans;
    }
};