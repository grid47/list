
+++
authors = ["Crafted by Me"]
title = "Leetcode 2343: Query Kth Smallest Trimmed Number"
date = "2018-06-04"
description = "In-depth solution and explanation for Leetcode 2343: Query Kth Smallest Trimmed Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> res;
        for(auto &v : q) {
            
            vector<pair<string, int>> fk;
            for(int i = 0; i < nums.size(); i++) {
                fk.push_back({nums[i].substr(nums[i].size() - v[1]), i});
            }
            sort(fk.begin(), fk.end());
            res.push_back(fk[v[0] - 1].second);
            
        }
        
        return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2344: Minimum Deletions to Make Array Divisible](https://grid47.xyz/posts/leetcode_2344) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

