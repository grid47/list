
+++
authors = ["Crafted by Me"]
title = "Leetcode 2855: Minimum Right Shifts to Sort the Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2855: Minimum Right Shifts to Sort the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int  n = nums.size(),ind = -1,cnt = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                if(cnt==0){
                ind = i+1;
                cnt++;
                }else return -1;
            }
        }
        if(ind==-1) return 0;
        if(nums[n-1]>nums[0]) return -1;
        return n-ind;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2855.md" >}}
---
{{< youtube k3uIpQ54LVY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2856: Minimum Array Length After Pair Removals](https://grid47.xyz/posts/leetcode_2856) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
