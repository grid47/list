
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2517: Maximum Tastiness of Candy Basket"
date = "2017-12-08"
description = "Solution to Leetcode 2517"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool can(vector<int> nums, int mid, int k) {
        int cnt = 1, n = nums.size();
        int i = 1;
        int prv = nums[0];
        while(i < n) {
            if(nums[i] - prv >= mid) {
                cnt++;
                prv = nums[i];
            }
            if(cnt >= k) return true;
            i++;
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int l = 0, r = nums[n - 1] - nums[0];
        int ans = r;
        
        while(l <= r) {
            
            int mid = l + (r - l + 1) / 2;
            // cout << mid << " " << can(nums, mid, k) << "\n";
            if(can(nums, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
            
        }
        
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

