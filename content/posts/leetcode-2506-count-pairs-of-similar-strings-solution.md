
+++
authors = ["grid47"]
title = "Leetcode 2506: Count Pairs Of Similar Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2506: Count Pairs Of Similar Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-pairs-of-similar-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int similarPairs(vector<string>& words) {
		int ans = 0; 
		unordered_map<int, int> freq; 
		for (auto& word : words) {
			int mask = 0; 
			for (auto& c : word) mask |= 1 << (c-'a'); 
			ans += freq[mask]++; 
		}
		return ans;         
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2506.md" >}}
---
{{< youtube uWSEfo1DlwY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2507: Smallest Value After Replacing With Sum of Prime Factors](https://grid47.xyz/posts/leetcode-2507-smallest-value-after-replacing-with-sum-of-prime-factors-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}