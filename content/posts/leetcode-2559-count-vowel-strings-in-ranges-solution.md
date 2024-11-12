
+++
authors = ["grid47"]
title = "Leetcode 2559: Count Vowel Strings in Ranges"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2559: Count Vowel Strings in Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-vowel-strings-in-ranges/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        int n = words.size();
        vector<int> cnt(n, 0), ans(q.size(), 0);
        set<char> ch = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++) {
            if(ch.count(words[i][0]) && ch.count(words[i][words[i].size() -1]))
                cnt[i] = 1;
            if(i > 0) cnt[i] += cnt[i - 1];
        }
        for(int i= 0; i < q.size(); i++) {
            ans[i] = cnt[q[i][1]] - ((q[i][0] > 0)? cnt[q[i][0] - 1]: 0);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2559.md" >}}
---
{{< youtube hTXRevcm3kI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2560: House Robber IV](https://grid47.xyz/posts/leetcode-2560-house-robber-iv-solution/) |
| --- |
