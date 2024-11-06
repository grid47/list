class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        
        int turns = -1, net = 0;
        while(turns) {
            turns = 0;
            for(int sz = stamp.size(); sz > 0; sz--) {
                for(int i = 0; i <= stamp.size() - sz; i++) {
                    string key = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
                    auto pos = target.find(key);
                    while(pos != string::npos) {
                        res.push_back(pos);
                        turns += sz;
                        fill(target.begin() + pos, target.begin() + pos + stamp.size(), '*');
                        pos = target.find(key);
                    }
                }
            }
            // cout << turns << " ";
            net += turns;
        }

        reverse(res.begin(), res.end());
        return net == target.size()? res: vector<int>{};
    }
};