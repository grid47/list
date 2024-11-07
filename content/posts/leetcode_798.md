
+++
authors = ["Crafted by Me"]
title = "Leetcode 798: Smallest Rotation with Highest Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 798: Smallest Rotation with Highest Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-rotation-with-highest-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n, 0);
        for(int i = 0; i < n; i++) {
            change[(i - nums[i] + 1 + n) % n]--;
        }
        for(int i = 1; i < n; i++) {
            change[i] += change[i - 1] + 1;
        }
        return distance(change.begin(), max_element(change.begin(), change.end()));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/798.md" >}}
---
{{< youtube UsAmnJUWz18 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #799: Champagne Tower](https://grid47.xyz/posts/leetcode_799) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
