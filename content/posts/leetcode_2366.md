
+++
authors = ["Crafted by Me"]
title = "Leetcode 2366: Minimum Replacements to Sort the Array"
date = "2018-05-12"
description = "In-depth solution and explanation for Leetcode 2366: Minimum Replacements to Sort the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0, prv = nums[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            int cnt = nums[i] / prv;
            if(nums[i] % prv != 0) {
                cnt++;
                prv = nums[i] / cnt;
            }
            ans += cnt - 1;
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

