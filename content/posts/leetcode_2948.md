
+++
authors = ["Crafted by Me"]
title = "Leetcode 2948: Make Lexicographically Smallest Array by Swapping Elements"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2948: Make Lexicographically Smallest Array by Swapping Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---
{{< youtube r0981xS7CjY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2949: Count Beautiful Substrings II](https://grid47.xyz/posts/leetcode_2949) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

