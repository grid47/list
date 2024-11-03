
+++
authors = ["Crafted by Me"]
title = "Leetcode 2593: Find Score of an Array After Marking All Elements"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2593: Find Score of an Array After Marking All Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            pq.push({nums[i], i});
        
        while(!pq.empty()) {
            while(!pq.empty() && mp.count(pq.top()[1])) pq.pop();
            if(!pq.empty()) {
                score += pq.top()[0];
                mp[pq.top()[1]] = true;
                mp[pq.top()[1] + 1] = true;
                mp[pq.top()[1] - 1] = true;                
                pq.pop();
            }
        }
        return score;
    }
};
{{< /highlight >}}


---
{{< youtube 6KKgxkXPtsQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2594: Minimum Time to Repair Cars](https://grid47.xyz/posts/leetcode_2594) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

