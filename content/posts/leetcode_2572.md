
+++
authors = ["Yasir"]
title = "Leetcode 2572: Count the Number of Square-Free Subsets"
date = "2017-10-14"
description = "Solution to Leetcode 2572"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int mod = (int) 1e9 + 7, n;
    vector<int> nums, prime;
    int memo[1001][1 << 11];
    
    int getMask(int num) {
        int mask = 0;
        for(int i= 0; i < prime.size(); i++) {
            int cnt = 0;
            while(num % prime[i] == 0) {
                cnt++;
                num /= prime[i];
            }
            if(cnt > 1) return -1;
            if(cnt == 1) {
                mask |= (1 << (i + 1));                
            }
        }
        return mask;
    }    

    int dp(int idx, int mask) {
        if(idx == n) return 1;

        if(memo[idx][mask] != -1) return memo[idx][mask];        
        int ans = dp(idx + 1, mask);

        int nmask = getMask(nums[idx]);
        if((nmask != -1) && ((nmask & mask) == 0)) {
            ans = (ans + dp(idx + 1, nmask | mask)) % mod;
        }
        return memo[idx][mask] = ans;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        memset(memo, -1, sizeof memo);
        return (dp(0, 0) - 1 + mod) % mod;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

