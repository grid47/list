
+++
authors = ["Crafted by Me"]
title = "Leetcode 1800: Maximum Ascending Subarray Sum"
date = "2019-11-29"
description = "In-depth solution and explanation for Leetcode 1800: Maximum Ascending Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-ascending-subarray-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxi = sum;
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                sum = 0;
            }
                sum += nums[i];
                maxi = max(sum,maxi);
        }
            return maxi;
        }
    
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1801: Number of Orders in the Backlog](https://grid47.xyz/posts/leetcode_1801) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

