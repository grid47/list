
+++
authors = ["Crafted by Me"]
title = "Leetcode 1994: The Number of Good Subsets"
date = "2019-05-19"
description = "In-depth solution and explanation for Leetcode 1994: The Number of Good Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-good-subsets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    set<int> bad = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28 };
    vector<int> msk;    
    vector<int> cnt;    
    int two(int x) {
        if(x == 0) return 1;
        return ((long long)2 * two(x - 1)) % mod;
    }
    
    int dp(int mask, int num) {
        if(num == 1) return 1;
        
        long long ans = dp(mask, num - 1);
        
        if(!bad.count(num) && ((mask | msk[num]) == mask))
            ans = (ans + (long long) dp(mask ^ msk[num], num - 1) * cnt[num]) % mod;
        
        return ans % mod;
    }
    
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        for(int i = 0; i < 31; i++) {
            int m = 0;
            for(int j = 0; j < p.size(); j++) {
                if((i % p[j]) == 0)
                m |= (1 << j);
            }
            msk.push_back(m);
        }
        cnt.resize(31, 0);
        for(int x: nums) cnt[x]++;
        
        return ((long long) (dp(1023, 30) - 1 + mod)%mod * two(cnt[1])) % mod;
        
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1995: Count Special Quadruplets](https://grid47.xyz/posts/leetcode_1995) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

