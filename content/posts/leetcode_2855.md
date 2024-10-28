
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2855: Minimum Right Shifts to Sort the Array"
date = "2017-01-04"
description = "Solution to Leetcode 2855"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

