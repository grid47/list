class Solution {
public:
    
    void dfs(int node, vector<int> &edge, vector<int> &vis, int x) {
        vis[node] = x;
        if(edge[node] != -1 && vis[edge[node]] == -1)
            dfs(edge[node], edge, vis, x + 1);
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        dfs(node1, edges, dist1, 0);
        vector<int> dist2(n, -1);
        dfs(node2, edges, dist2, 0);
        
        int dist, ans = -1, sol = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(dist1[i] == -1 || dist2[i] == -1)
                continue;
            else
                dist = max(dist1[i], dist2[i]);
            
            if(dist < sol) {
                sol = dist;
                ans = i;
            }
        }
        
        return ans;
    }
};