
+++
authors = ["grid47"]
title = "Leetcode 78: Subsets"
date = "2024-11-01"
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
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/78.jpeg" 
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #79: Word Search](https://grid47.xyz/posts/leetcode-79-word-search-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}