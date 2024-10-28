class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& spec) {

        sort(spec.begin(), spec.end());
        int prv = bottom - 1, n = spec.size();

        int res = 0;
        for(int cur : spec) {
            res = max(res, cur - prv - 1);
            prv = cur > prv ? cur : prv;
        }
        res = max(res, top - prv);

        return res;
    }
};

// bottom - top
// spec
// 