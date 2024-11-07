
+++
authors = ["Crafted by Me"]
title = "Leetcode 1995: Count Special Quadruplets"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1995: Count Special Quadruplets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-special-quadruplets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        const auto n = nums.size();
        unordered_map<int, int> freq;
        
        freq[nums[n - 1]] = 1;
        size_t answ = 0;
        for (int i = n - 2; i > 1; --i)
        {
            for (int j = i - 1; j > 0; --j)
            {
                for (int k = j - 1; k >= 0; --k)
                {
                    if (freq.count(nums[i] + nums[j] + nums[k]))
                    {
                        answ += freq[nums[i] + nums[j] + nums[k]];
                    }
                }
            }
            freq[nums[i]] += 1;
        }
        return answ;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1995.md" >}}
---
{{< youtube H06N-OsxpoE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1996: The Number of Weak Characters in the Game](https://grid47.xyz/posts/leetcode_1996) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
