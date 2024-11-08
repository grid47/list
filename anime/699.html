class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        vector<vector<int>> past;
        vector<int> ans;
        int h = 0;  
        for(vector<int> i: pos) {
            vector<int> cur = {i[0], i[0] + i[1] - 1, i[1]};
            int res = search(past, cur);
            h = max(h, res);
            ans.push_back(h);
        }
        return ans;
    }
    int search(vector<vector<int>> &past, vector<int> &cur) {
        int mx = 0;
        for(auto i: past) {
            if(cur[1] < i[0] || cur[0] > i[1]) continue;
            mx = max(mx, i[2]);
        }
        cur[2] += mx;
        past.push_back(cur);
        return cur[2];
    }
};