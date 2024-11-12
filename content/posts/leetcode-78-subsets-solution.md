
+++
authors = ["grid47"]
title = "Leetcode 78: Subsets"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 78: Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subsets/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/78.webp" 
    alt="Multiple floating subsets gently coming together, forming a whole."
    caption="Solution to LeetCode 78: Subsets Problem"
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
    vector<int> nums;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<vector<int>> ans;
        vector<int> tmp;
        bt(ans, tmp, 0);
        return ans;
    }
    
    void bt(vector<vector<int>> & ans, vector<int> &tmp, int idx) {
        if(idx == nums.size()) {
            ans.push_back(tmp);
            return;
        }

        
        bt(ans, tmp, idx + 1);
        
        tmp.push_back(nums[idx]);
        bt(ans, tmp, idx + 1);
        tmp.pop_back();
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/78.md" >}}
---
{{< youtube UP3dOYJa05s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #79: Word Search](https://grid47.xyz/posts/leetcode-79-word-search-solution/) |
| --- |
