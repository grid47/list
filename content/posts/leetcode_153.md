
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 153: Find Minimum in Rotated Sorted Array"
date = "2024-05-30"
description = "Solution to Leetcode 153"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
