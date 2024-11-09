
+++
authors = ["grid47"]
title = "Leetcode 2584: Split the Array to Make Coprime Products"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2584: Split the Array to Make Coprime Products in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Number Theory"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> primes(int n) {
        vector<int> res;
        for(int i = 2; i < 1000 && n > 1; i += 1 + (i % 2)) {
            if(n % i == 0) {
                res.push_back(i);
                while((n% i) == 0) n /= i;
            }
        }
        if(n > 1) res.push_back(n);
        return res;
    }
    
    int findValidSplit(vector<int>& nums) {
        
        map<int, int> mp;
        vector<long long> line(10001, 0);
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
            for(int f: primes(nums[i])) {
                if(!mp.count(f)) {
                    mp[f] = i;
                }
                line[mp[f]]++;
                line[i]--;
            }
        
        partial_sum(line.begin(), line.end(), line.begin());
        int res = find(line.begin(), line.end(), 0) - line.begin();
        return res < (nums.size() - 1)? res : -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2584.md" >}}
---
{{< youtube 9raE-fiwK-w >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2585: Number of Ways to Earn Points](https://grid47.xyz/posts/leetcode-2584-split-the-array-to-make-coprime-products-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
