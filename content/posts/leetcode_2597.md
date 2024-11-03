
+++
authors = ["Crafted by Me"]
title = "Leetcode 2597: The Number of Beautiful Subsets"
date = "2017-09-23"
description = "In-depth solution and explanation for Leetcode 2597: The Number of Beautiful Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

