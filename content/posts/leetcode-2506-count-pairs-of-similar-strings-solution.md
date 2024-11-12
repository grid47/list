
+++
authors = ["grid47"]
title = "Leetcode 2506: Count Pairs Of Similar Strings"
date = "2024-03-01"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2507: Smallest Value After Replacing With Sum of Prime Factors](https://grid47.xyz/posts/leetcode-2507-smallest-value-after-replacing-with-sum-of-prime-factors-solution/) |
| --- |
