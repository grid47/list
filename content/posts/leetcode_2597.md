
+++
authors = ["Crafted by Me"]
title = "Leetcode 2597: The Number of Beautiful Subsets"
date = "2017-09-22"
description = "Solution to Leetcode 2597"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-beautiful-subsets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> cnt, nums;
    
    int dp(int idx, int k) {
        if(idx == nums.size()) return 1;
        int ans = 0;
        if(nums[idx] - k >= 0 && (cnt[nums[idx] - k] > 0)) {
            ans += dp(idx + 1, k);
        } else {
            ans += dp(idx + 1, k);
            cnt[nums[idx]]++;
            ans += dp(idx + 1, k);
            cnt[nums[idx]]--;            
        }
        return ans;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        cnt.resize(1001, 0);
        this->nums = nums;
        return dp(0, k) - 1; // exluding none selected
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

