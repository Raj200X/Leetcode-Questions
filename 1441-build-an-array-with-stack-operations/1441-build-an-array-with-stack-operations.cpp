class Solution {
public:
    bool isEqual(vector<int>& v, stack<int> s) {
        if (v.size() != s.size()) return false;

        for (int i = v.size() - 1; i >= 0; i--) {
            if (s.empty() || v[i] != s.top())
                return false;
            s.pop();
        }
        return true;
    }

    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> s;
        vector<string> ans;
        unordered_set<int> st;

        for (int x : target) st.insert(x);

        for (int i = 1; i <= n; i++) {
            if (st.count(i)) {
                s.push(i);
                ans.push_back("Push");
            } else {
                s.push(i);
                ans.push_back("Push");
                s.pop();
                ans.push_back("Pop");
            }

            if (isEqual(target, s))
                return ans;
        }
        return ans;
    }
};
