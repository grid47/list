
+++
authors = ["Crafted by Me"]
title = "Leetcode 1671: Minimum Number of Removals to Make Mountain Array"
date = "2020-04-05"
description = "Solution to Leetcode 1671"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int lis(vector<int> arr) {
        vector<int> res;
        for(int i = 0; i < arr.size(); i++) {
            int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            if(idx == res.size()) res.push_back(arr[i]);
            else res[idx] = arr[i];
        }
        return res.size();
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        int mx = 0;
        
        for(int i = 1; i < n - 1; i++) {

            vector<int> left;
            for(int k = 0; k < i; k++) {
                if(nums[k] < nums[i]) left.push_back(nums[k]);
            }
            left.push_back(nums[i]);
            vector<int> right;
            right.push_back(nums[i]);
            for(int k = i + 1; k < n; k++) {
                if(nums[k] < nums[i]) right.push_back(nums[k]);
            }
            reverse(right.begin(), right.end());
            int a = lis(left);
            int b = lis(right);
            if(a >= 2 && b >= 2) {
                mx = max(mx, a + b - 1);
            }
        }
        
        return nums.size() - mx;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

