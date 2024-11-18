
+++
authors = ["grid47"]
title = "Leetcode 1624: Largest Substring Between Two Equal Characters"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1624: Largest Substring Between Two Equal Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "rfjeFs3JuYM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char, int> mp;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(mp.count(s[i])) {
                ans = max(ans, i - mp[s[i]] - 1);
            }
            if(!mp.count(s[i])) {
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1624.md" >}}
---
{{< youtube rfjeFs3JuYM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1625: Lexicographically Smallest String After Applying Operations](https://grid47.xyz/leetcode/solution-1625-lexicographically-smallest-string-after-applying-operations/) |
| --- |
