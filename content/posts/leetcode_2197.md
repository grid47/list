
+++
authors = ["Crafted by Me"]
title = "Leetcode 2197: Replace Non-Coprime Numbers in Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2197: Replace Non-Coprime Numbers in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            
            ans.push_back(nums[i]);
            
            while(ans.size() > 1 && __gcd(ans.back(), ans[ans.size() - 2]) > 1) {
                long long a = ans.back(),
                    b = ans[ans.size() - 2];
                ans.pop_back();
                ans.pop_back();
                ans.push_back(a * b/ __gcd(a, b));
            }
            
        }
        return ans;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2198: Number of Single Divisor Triplets](https://grid47.xyz/posts/leetcode_2198) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

