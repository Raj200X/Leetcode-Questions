class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxi = INT_MIN;
        bool north = true;
        bool south = false;
        bool east = false;
        bool west = false;
        set<pair<int, int>> st;
        for (auto& p : obstacles) {
            st.insert({p[0], p[1]});
        }
        int x = 0, y = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                if (north) {
                    north = false;
                    east = true;
                } else if (south) {
                    south = false;
                    west = true;
                } else if (east) {
                    east = false;
                    south = true;
                } else if (west) {
                    west = false;
                    north = true;
                }
            } else if (commands[i] == -2) {
                if (north) {
                    north = false;
                    west = true;
                } else if (south) {
                    south = false;
                    east = true;
                } else if (east) {
                    east = false;
                    north = true;
                } else if (west) {
                    west = false;
                    south = true;
                }
            } else {
                int steps = commands[i];

                while (steps--) {
                    int nx = x, ny = y;

                    if (north)
                        ny++;
                    else if (south)
                        ny--;
                    else if (east)
                        nx++;
                    else if (west)
                        nx--;

                    if (st.count({nx, ny}))
                        break; 

                    x = nx;
                    y = ny;
                }
            }
            int temp = x * x + y * y;
            maxi = max(temp, maxi);
        }
        return maxi;
    }
};