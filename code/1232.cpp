class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        double slopt = (cord[1][0] - cord[0][0]) == 0? INT_MAX: (double)(cord[1][1] - cord[0][1]) / (double)(cord[1][0] - cord[0][0]);
        for(int i = 2; i < cord.size(); i++) {
            double slp = (cord[i][0] - cord[0][0]) == 0?INT_MAX: (double)(cord[i][1] - cord[0][1]) / (double)(cord[i][0] - cord[0][0]);
            if(slp != slopt) return false;
        }
        return true;
    }
};