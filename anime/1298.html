class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& ib) {

        vector<int> vis(status.size(), 0);
        set<int> box, magic;
        queue<int> open;
        int res = 0;
        for(int i = 0; i < ib.size(); i++) {
            if(status[ib[i]] == 1) {
                open.push(ib[i]);
                vis[ib[i]] = 1;
            } else box.insert(ib[i]);
        }

        while(!open.empty()) {
            int x = open.front();
            res += candies[x];
            open.pop();
            for(int key: keys[x]) {
                if(box.count(key)) {
                    status[key] = 1;
                    box.erase(key);
                    open.push(key);
                    vis[key] = 1;
                } else if(vis[key] != 1) {
                    magic.insert(key);
                }
            }
            
            for(int bx: containedBoxes[x]) {
                if(vis[bx]) continue;
                if(status[bx] == 1) {
                    if(magic.count(bx)) magic.erase(bx);
                    open.push(bx);
                    vis[bx] = 1;
                }else if(magic.count(bx)) {
                    status[bx] = 1;
                    magic.erase(bx);
                    open.push(bx);
                    vis[bx] = 1;
                } else {
                    box.insert(bx);
                }
            }
        }
        return res;
    }
};