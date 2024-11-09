
+++
authors = ["grid47"]
title = "Leetcode 33: Search in Rotated Sorted Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 33: Search in Rotated Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/33.jpeg" 
    alt="A rotating spiral of light, revealing new paths and points of connection."
    caption="Solution to LeetCode 33: Search in Rotated Sorted Array Problem"
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
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while(s <= e) {
            int mid = s + (e - s + 1) / 2;
            if(nums[mid] == target) return mid;
            if(nums[s] <= nums[mid]) {// window contain jerk
                if(nums[s] <= target && target < nums[mid])
                    e = mid - 1;
                else s = mid + 1;
            } else {// window is linear
                if(nums[mid] < target && target <= nums[e])
                    s = mid + 1;
                else e = mid - 1;
            }
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/33.md" >}}
---
{{< youtube U8XENwh8Oy8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #34: Find First and Last Position of Element in Sorted Array](https://grid47.xyz/posts/leetcode_34) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
