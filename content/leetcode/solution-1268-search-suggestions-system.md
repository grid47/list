
+++
authors = ["grid47"]
title = "Leetcode 1268: Search Suggestions System"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1268: Search Suggestions System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Binary Search","Trie","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PLNDfB0Vg9Y"
youtube_upload_date="2021-03-01"
youtube_thumbnail="https://i.ytimg.com/vi/PLNDfB0Vg9Y/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/search-suggestions-system/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string w) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : w) {
            cur += c;
            vector<string> sdg;
            it = lower_bound(it, A.end(), cur);
for(int i = 0; i < 3 && (it + i) != A.end(); i++) {
                
        string& s = *(i + it);
        if(s.find(cur)) break;
        sdg.push_back(s);
                
            }
            res.push_back(sdg);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1268.md" >}}
---
{{< youtube PLNDfB0Vg9Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1276: Number of Burgers with No Waste of Ingredients](https://grid47.xyz/leetcode/solution-1276-number-of-burgers-with-no-waste-of-ingredients/) |
| --- |