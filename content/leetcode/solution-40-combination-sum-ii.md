
+++
authors = ["grid47"]
title = "Leetcode 40: Combination Sum II"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 40: Combination Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combination-sum-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/40.webp" 
    alt="A more intricate set of glowing paths, representing different combinations, gently overlapping."
    caption="Solution to LeetCode 40: Combination Sum II Problem"
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
    map<vector<int>, bool> mp;
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
               
        vector<vector<int>> ans;
        vector<int> tmp;
        mp.clear();
        sort(cand.begin(), cand.end());
         bt(ans, cand, 0, target, tmp);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &nums, int idx,
            int sum, vector<int> &tmp) {
        if(sum == 0) {
            ans.push_back(tmp);
            return;
        }
        if(sum < 0 || idx == nums.size()) return;
        
        for(int i = idx; i < nums.size(); i++) {
            if(i && i > idx && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            bt(ans, nums, i + 1, sum - nums[i], tmp);
            tmp.pop_back();
        }
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/40.md" >}}
---
{{< youtube FAjCxGNlxgk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #43: Multiply Strings](https://grid47.xyz/leetcode/solution-43-multiply-strings/) |
| --- |
