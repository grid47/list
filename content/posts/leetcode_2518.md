
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2518: Number of Great Partitions"
date = "2017-12-08"
description = "Solution to Leetcode 2518"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-great-partitions/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<unordered_map<int, int>> mem;
    vector<int> nums;
    vector<int> twos;    
    int mod = (int) 1e9 + 7;
    int n;
    
    int pos(int n) {
        if(n == 0) return 1;
        if(twos[n] != -1) return twos[n];
        long ans;
        if(n % 2) {
            ans = pos(n / 2);
            ans = (ans * ans * 2) % mod;
        } else {
            ans = pos(n / 2);
            ans = (ans * ans) % mod;            
        }
        return twos[n] = ans;
    }
    
    int dp(int idx, int l1, int l2) {
        
        if(idx == n) return (l1 <= 0 && l2 <= 0);
        
        if(l1 <= 0 && l2 <= 0) {
            return pos(n - idx) % mod;
        }
        int s = l1 * 10000 + l2;
        if(mem[idx].count(s)) return mem[idx][s];
        
        long ans = dp(idx + 1, l1 - nums[idx] <= 0? 0: l1 - nums[idx], l2) % mod;
        
        ans = (ans + dp(idx + 1, l1, l2 - nums[idx] <= 0? 0: l2 - nums[idx])) % mod;        
        
        return mem[idx][s] = ans;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        n = nums.size();
        mem.resize(n);
        twos.resize(n + 1, -1);
        this->nums = nums;
        return dp(0, k, k);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
