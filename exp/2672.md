class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    int c[100003] = {}, adj = 0;
    vector<int> res;
    for (const auto &q : queries) {
        int i = q[0] + 1, color_i = q[1];
        if (c[i])
            adj -= (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
        c[i] = color_i;
        adj += (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
        res.push_back(adj);
    }
    return res;
}
};