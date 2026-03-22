class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char>st;
        for (auto &p:s){
            st.insert(p);
        }
        return st.size();
    }
};