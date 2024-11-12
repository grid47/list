
+++
authors = ["grid47"]
title = "Leetcode 2452: Words Within Two Edits of Dictionary"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2452: Words Within Two Edits of Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(auto &q: queries)
        for(auto &d: dictionary)
        if(inner_product(begin(q), end(q), begin(d), 0, plus<int>(), not_equal_to<char>()) < 3) {
            res.push_back(q);
            break;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2452.md" >}}
---
{{< youtube 99KTTNdlKns >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2453: Destroy Sequential Targets](https://grid47.xyz/posts/leetcode-2453-destroy-sequential-targets-solution/) |
| --- |
