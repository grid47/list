
+++
authors = ["grid47"]
title = "Leetcode 916: Word Subsets"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 916: Word Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/word-subsets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> frq(26, 0);
        for(auto s: words2) {
            vector<int> tmp(26, 0);
            for(char c: s) {
                tmp[c - 'a']++;
                frq[c - 'a'] = max(frq[c - 'a'], tmp[c-'a']);
            }
        }
        vector<string> res;
        for(auto s: words1) {
            vector<int> tmp(26, 0);
            for(char c: s) tmp[c - 'a']++;
            int flag = true;
            for(int i = 0; i < 26; i++) {
                if(tmp[i] < frq[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(s);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/916.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #918: Maximum Sum Circular Subarray](https://grid47.xyz/leetcode/solution-918-maximum-sum-circular-subarray/) |
| --- |
