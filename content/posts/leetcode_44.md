
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 44: Wildcard Matching"
date = "2024-09-15"
description = "Solution to Leetcode 44"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

