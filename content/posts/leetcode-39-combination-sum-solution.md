
+++
authors = ["grid47"]
title = "Leetcode 39: Combination Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 39: Combination Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combination-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/39.jpeg" 
    alt="A sequence of glowing paths merging together, forming a combination with a gentle light."
    caption="Solution to LeetCode 39: Combination Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        bt(ans, tmp, 0, target, cand);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &tmp, int idx, int sum, vector<int> &cand) {
        if(idx == cand.size() || sum == 0) {
            if(sum == 0) ans.push_back(tmp);
            return;
        }
        if(sum < 0) return;
        tmp.push_back(cand[idx]);
        bt(ans, tmp, idx, sum - cand[idx], cand);
        tmp.pop_back();
        
        bt(ans, tmp, idx + 1, sum, cand);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/39.md" >}}
---
{{< youtube utBw5FbYswk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #40: Combination Sum II](https://grid47.xyz/posts/leetcode-40-combination-sum-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
