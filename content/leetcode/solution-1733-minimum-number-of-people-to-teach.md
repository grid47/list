
+++
authors = ["grid47"]
title = "Leetcode 1733: Minimum Number of People to Teach"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1733: Minimum Number of People to Teach in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "eHk8TQIhvCk"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1734: Decode XORed Permutation](https://grid47.xyz/leetcode/solution-1734-decode-xored-permutation/) |
| --- |
