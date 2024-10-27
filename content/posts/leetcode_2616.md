
+++
authors = ["Yasir"]
title = "Leetcode 2616: Minimize the Maximum Difference of Pairs"
date = "2017-08-30"
description = "Solution to Leetcode 2616"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/)

---

**Code:**

{{< highlight html >}}

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), l = 0, r = nums[n - 1] - nums[0], ans = nums[n - 1] - nums[0];
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int k = p;
            for(int i = 1; i < n && k > 0; i++) {
                if(nums[i] - nums[i - 1] <= mid) {
                    k--;
                    i++;
                }
            }
            if(k == 0) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        
        return ans;
    }
};
{{< /highlight >}}

