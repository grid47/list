class Solution {
    typedef vector<vector<int>> mo;
public:
    vector<int> countPoints(mo& pts, mo& qrs) {
        vector<int> res;

        for(auto &q: qrs) {
            int cnt = 0, rr = q[2] * q[2];
            for(auto &p: pts)
                cnt += (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]) <= rr;
            res.push_back(cnt);
        }

        return res;
    }
};