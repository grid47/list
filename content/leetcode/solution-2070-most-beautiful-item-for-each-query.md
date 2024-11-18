
+++
authors = ["grid47"]
title = "Leetcode 2070: Most Beautiful Item for Each Query"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2070: Most Beautiful Item for Each Query in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-beautiful-item-for-each-query/description/)

---
**Code:**

{{< highlight cpp >}}
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
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2070.md" >}}
---
{{< youtube r1WymhQxLZA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2073: Time Needed to Buy Tickets](https://grid47.xyz/leetcode/solution-2073-time-needed-to-buy-tickets/) |
| --- |
