
+++
authors = ["grid47"]
title = "Leetcode 2741: Special Permutations"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2741: Special Permutations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AxXNOXj1upY"
youtube_upload_date="2023-06-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AxXNOXj1upY/maxresdefault.webp"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2741.md" >}}
---
{{< youtube AxXNOXj1upY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2744: Find Maximum Number of String Pairs](https://grid47.xyz/leetcode/solution-2744-find-maximum-number-of-string-pairs/) |
| --- |