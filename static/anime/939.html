class Solution {
public:
    int minAreaRect(vector<vector<int>>& pts) {
        
        unordered_map<int, set<int>> mp;
        for(auto &it: pts)
        mp[it[0]].insert(it[1]);
        
        int n = pts.size();
        int area = INT_MAX;
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            
            int x1 = pts[i][0], y1 = pts[i][1];
            int x2 = pts[j][0], y2 = pts[j][1];
            
            if(x1 != x2 && y1 != y2) {
                
                if(mp[x1].find(y2) != mp[x1].end() &&
                  mp[x2].find(y1) != mp[x2].end())
                {
                    area = min(area, abs(x1 - x2) * abs(y1 - y2));
                }
            }
            
        }
        
        return area == INT_MAX? 0: area;
    }
};