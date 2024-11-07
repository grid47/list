
+++
authors = ["Crafted by Me"]
title = "Leetcode 2261: K Divisible Elements Subarrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2261: K Divisible Elements Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Trie","Rolling Hash","Hash Function","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-divisible-elements-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int res = 0, n = nums.size();
        vector<int> cnt(201, 0); vector<long long> hash(201, 0);
        for (int sz = 0; sz < n; sz++) {
            unordered_set<int> s;
            for(int i = 0; i + sz < n; i++){

cnt[i] += ((nums[i + sz] % p) == 0);
            if(cnt[i] <= k) {
hash[i] = (hash[i] * 200 + nums[i + sz]) % 1000000007;
                res += s.insert(hash[i]).second;
            }
        }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2261.md" >}}
---
{{< youtube BZdbRvIM-js >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2264: Largest 3-Same-Digit Number in String](https://grid47.xyz/posts/leetcode_2264) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
