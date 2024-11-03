
+++
authors = ["Crafted by Me"]
title = "Leetcode 1733: Minimum Number of People to Teach"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1733: Minimum Number of People to Teach in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-people-to-teach/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {

public:

    int minimumTeachings(int k, vector<vector<int>>& lang, vector<vector<int>>& frnd) {
        
			int n = lang.size();

			vector<set<int>> langs;

			for(int i = 0; i < n; i++) {
				set<int> s(begin(lang[i]), end(lang[i]));
				langs.push_back(s);
			}

			set<int> ntk;
			for(vector<int> frd: frnd) {
				int u = frd[0] - 1;
				int v = frd[1] - 1;
				set<int> s1 = langs[u];
				set<int> s2 = langs[v];				
				set<int> res;
				set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
				if (res.size() > 0) continue;
				ntk.insert(u);
				ntk.insert(v);
			}
            if (ntk.size() == 0) return 0;
        
            vector<int> lg(k + 1, 0);
			for (int f : ntk)
            for (int l : langs[f]) lg[l]++;
        
            int mx = lg[0];
            for (int c : lg) {
                mx = max(mx, c);
            }
        
			return ntk.size() - mx;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1733.md" >}}
---
{{< youtube eHk8TQIhvCk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1734: Decode XORed Permutation](https://grid47.xyz/posts/leetcode_1734) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

