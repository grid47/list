
+++
authors = ["Crafted by Me"]
title = "Leetcode 2741: Special Permutations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2741: Special Permutations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation","Bitmask"]
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
{{< youtube AxXNOXj1upY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2742: Painting the Walls](https://grid47.xyz/posts/leetcode_2742) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
