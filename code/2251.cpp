class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flo, vector<int>& peo) {
        
        sort(flo.begin(), flo.end());

        vector<pair<int, int>> pp;
        
        for(int i = 0; i < peo.size(); i++) {
            pp.push_back(make_pair(peo[i], i));
        }

        sort(pp.begin(), pp.end());        
        
        vector<int> ans(peo.size(), 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int j = 0;
        for(int i = 0; i < peo.size(); i++) {

            while(!pq.empty() && pp[i].first > pq.top()) {
                // cout << pq.top() << ',';
                pq.pop();
            }
            // cout << '-';            
            
            while(j < flo.size() && pp[i].first >= flo[j][0]) {
                // cout << flo[j][1] << ',';
                if (pp[i].first <= flo[j][1])
                pq.push(flo[j][1]);
                j++;
            }
            // cout << '_';
            // cout << pp[i].first;
            // cout << '\n';
            
            ans[pp[i].second] = pq.size();
        }
        return ans;
    }
};