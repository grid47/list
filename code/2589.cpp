class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int n = tasks.size(), res = 0;
        vector<bool> line(2001, false);
        for(int i = 0; i < n; i++) {
            int st = tasks[i][0], ed = tasks[i][1], cnt = tasks[i][2];
            cnt -= count(line.begin() + st, line.begin() + ed + 1, true);

            for(int i = ed; cnt > 0; i--) {
                cnt -= !line[i];
                line[i] = true;
            }

        }

        return count(line.begin(), line.end(), true);
    }
    
};