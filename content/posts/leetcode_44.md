
+++
authors = ["Crafted by Me"]
title = "Leetcode 44: Wildcard Matching"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 44: Wildcard Matching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy","Recursion"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/wildcard-matching/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
	string s, p;
	vector<vector<int>> memo;

	bool dp(int i, int j) {
		if(i == s.size() && j == p.size()) return true;
		if(j == p.size()) return false;

		if(memo[i][j] != -1) return memo[i][j];

		int ans = false;
		if(i < s.size() && s[i] == p[j]) {
			ans |= dp(i + 1, j + 1);
		} else if(p[j] == '?') {
			if(i == s.size())
				return false;
			else
				ans |= dp(i+1, j+1);
		} else if(p[j] == '*') {
			if(i < s.size()) ans |= dp(i+1, j);
			ans |= dp(i, j+1);
		}

		return memo[i][j] = ans;
	}


    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/44.md" >}}
---
{{< youtube FJJavs1tyoQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #45: Jump Game II](https://grid47.xyz/posts/leetcode_45) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
