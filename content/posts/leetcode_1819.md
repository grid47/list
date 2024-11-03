
+++
authors = ["Crafted by Me"]
title = "Leetcode 1819: Number of Different Subsequences GCDs"
date = "2019-11-10"
description = "In-depth solution and explanation for Leetcode 1819: Number of Different Subsequences GCDs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-different-subsequences-gcds/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> fact(200001, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j * j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    int f1 = j;
                    int f2 = nums[i] / j;
                    fact[f1] = __gcd(fact[f1], nums[i]);
                    fact[f2] = __gcd(fact[f2], nums[i]);                    
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i <= 200000; i++)
            if(fact[i] == i) res++;
        
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1820: Maximum Number of Accepted Invitations](https://grid47.xyz/posts/leetcode_1820) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

