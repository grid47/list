
+++
authors = ["grid47"]
title = "Leetcode 2644: Find the Maximum Divisibility Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2644: Find the Maximum Divisibility Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-maximum-divisibility-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& div) {
        int n = div.size();
        int m = nums.size();
        vector<int> cnt(n, 0);
        int mx = 0, idx = *min_element(div.begin(), div.end());
        map<int, vector<int>> mp;
        for(int i = 0; i < m; i++) {
            if(mp.count(nums[i])) {
                for(int x: mp[nums[i]]) {
                    cnt[x]++;
                    if(cnt[x] > mx || (cnt[x] == mx && div[x] < div[idx])) {
                        mx = cnt[x];
                        idx = x;
                    }
                }
            } else {
                for(int j = 0; j < n; j++) {
                    if(nums[i] % div[j] == 0) {
                        mp[nums[i]].push_back(j);
                        cnt[j]++;
                        if(cnt[j] > mx || (cnt[j] == mx && div[j] < div[idx])) {
                            mx = cnt[j];
                            idx = j;
                        }                        
                    }
                }
            }
        }
        return mx == 0? idx:div[idx];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2644.md" >}}
---
{{< youtube Aqhrp1nYMqo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2645: Minimum Additions to Make Valid String](https://grid47.xyz/posts/leetcode-2645-minimum-additions-to-make-valid-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}