class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // ith item -> price, beauty
        // max beauty of an item? whoes price <= query[i]
        vector<int> ans(queries.size());

        vector<pair<int, int>> queriesPair;
        for(int i = 0; i < queries.size(); i++) {
            queriesPair.push_back({queries[i], i});
        }

        sort(queriesPair.begin(), queriesPair.end());
        sort(items.begin(), items.end());

        int itemIdx = 0, maxBeauty = 0;
        for(int i = 0; i < queriesPair.size(); i++) {
            int maxPriceAllowed = queriesPair[i].first;
            int queryOriginalIndex = queriesPair[i].second;

            while(itemIdx < items.size() && items[itemIdx][0] <= maxPriceAllowed) {
                maxBeauty = max(maxBeauty, items[itemIdx][1]);
                itemIdx++;
            }
            ans[queryOriginalIndex] = maxBeauty;
        }
        return ans;
    }
};