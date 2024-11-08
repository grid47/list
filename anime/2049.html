class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++)
        g[parents[i]].push_back(i);

        vector<int> size(n, 0);
        helper(0, g, size);

        long long cnt = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            long long pro = 1;
            pro = max(pro, (long long) n - size[i]);
            for(int node : g[i]) {
                pro = pro * size[node];
            }

            if (pro > maxi) {
                maxi = pro;
                cnt = 1;
            }
            else if(pro == maxi) {
                cnt++;
            }
        }
        return cnt;
    }

    int helper(int src, vector<vector<int>> &gph, vector<int> &size) {
        int ans = 1;
        for(int g: gph[src])
            ans += helper(g, gph, size);
        return size[src] = ans;
    }
};