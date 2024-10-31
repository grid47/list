
+++
authors = ["Crafted by Me"]
title = "Leetcode 2741: Special Permutations"
date = "2017-05-01"
description = "Solution to Leetcode 2741"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/special-permutations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    vector<vector<int>> grid;
    vector<map<int, int>> mp;
    int specialPerm(vector<int>& nums) {
        
        int conn = 0, n = nums.size();
        grid.resize(n);
        mp.resize(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++)
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0){
                    grid[i].push_back(j);
                    grid[j].push_back(i);
                }
        }
        long ans = 0;

        for(int i = 0; i < n; i++) {
            int msk = 0;
            msk |= (1 << i);
            ans = (ans + dfs(i, n - 1, msk)) % mod;            
        }
        return ans;
    }
    
    int dfs(int i, int n, int msk) {
        
        if(n == 0) return 1;
        if(mp[i].count(msk)) return mp[i][msk];
        long ans = 0;
        for(int x: grid[i]) {
            if(!(msk & (1 << x))) {
                msk ^= (1 << x);
                ans = (ans + dfs(x, n - 1, msk)) % mod;
                msk ^= (1 << x);
            }
        }
        return mp[i][msk] = ans;
    }
    
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

