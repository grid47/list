
+++
authors = ["Crafted by Me"]
title = "Leetcode 2070: Most Beautiful Item for Each Query"
date = "2019-03-04"
description = "In-depth solution and explanation for Leetcode 2070: Most Beautiful Item for Each Query in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2071: Maximum Number of Tasks You Can Assign](https://grid47.xyz/posts/leetcode_2071) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

