
+++
authors = ["grid47"]
title = "Leetcode 2855: Minimum Right Shifts to Sort the Array"
date = "2024-01-26"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2856: Minimum Array Length After Pair Removals](https://grid47.xyz/posts/leetcode-2856-minimum-array-length-after-pair-removals-solution/) |
| --- |
