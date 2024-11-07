
+++
authors = ["Crafted by Me"]
title = "Leetcode 153: Find Minimum in Rotated Sorted Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 153: Find Minimum in Rotated Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int ans = -1;

        if(n == 1) return nums[0];

        while(s < e) {
            int mid = s + (e - s) / 2;

            // if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]) return nums[mid];

            if(nums[e] < nums[mid]) {
                s = mid + 1;
            } else{
                e = mid;
            }
        }
        cout << "Hi" << e;
        return nums[e];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/153.md" >}}
---
{{< youtube H2U24n4bcQQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #155: Min Stack](https://grid47.xyz/posts/leetcode_155) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
