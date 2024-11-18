
+++
authors = ["grid47"]
title = "Leetcode 39: Combination Sum"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 39: Combination Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "utBw5FbYswk"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/39.webp"
+++



[`Problem Link`](https://leetcode.com/problems/combination-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/39.webp" 
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #40: Combination Sum II](https://grid47.xyz/leetcode/solution-40-combination-sum-ii/) |
| --- |
