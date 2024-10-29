
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2948: Make Lexicographically Smallest Array by Swapping Elements"
date = "2016-10-04"
description = "Solution to Leetcode 2948"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> b;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
            b.push_back(make_pair(nums[i], i));

        sort(b.begin(), b.end(), [](const auto& x, const auto& y) {
            return x.first < y.first;
        });
        vector<vector<pair<int, int>>> c = {{b[0]}};

        for (int i = 1; i < n; ++i) {
            if (b[i].first - b[i - 1].first <= limit)
                c.back().push_back(b[i]);
            else
                c.push_back({b[i]});
        }

        // internal sorting
        for (const auto& t : c) {
            vector<int> ind;
            for (const auto& p : t)
                ind.push_back(p.second);

            sort(ind.begin(), ind.end());

            for (int i = 0; i < ind.size(); ++i)
                nums[ind[i]] = t[i].first;
        }
        return nums;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

