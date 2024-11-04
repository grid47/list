
+++
authors = ["Crafted by Me"]
title = "Leetcode 2191: Sort the Jumbled Numbers"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2191: Sort the Jumbled Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-jumbled-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
#include <string.h>
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> tmp;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            
            int num = nums[i];
            
            string str = to_string(num);
            string formed = "";
            for(int j = 0; j < str.size(); j++)
                formed += to_string(mapping[str[j]- '0']);
            int val = stoi(formed);
            tmp.push_back({ val, i });
            
        }
        
        sort(tmp.begin(), tmp.end());
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            ans.push_back(nums[tmp[i].second]);
        
        return ans;
        
    }
};
{{< /highlight >}}


---
{{< youtube rmkF2mxPoZM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2192: All Ancestors of a Node in a Directed Acyclic Graph](https://grid47.xyz/posts/leetcode_2192) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

