
+++
authors = ["grid47"]
title = "Leetcode 1452: People Whose List of Favorite Companies Is Not a Subset of Another List"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1452: People Whose List of Favorite Companies Is Not a Subset of Another List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ok0jYAMnvQI"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ok0jYAMnvQI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& comp) {
        int n = comp.size();
        
        for(auto &c : comp)
            sort(c.begin(), c.end());
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int notSubset = true;
            
            for(int j = 0; j < n && notSubset; j++) {
                if(i == j) continue;
                
                notSubset = !includes(comp[j].begin(), comp[j].end(), comp[i].begin(), comp[i].end());
            }
            if(notSubset)
                res.push_back(i);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1452.md" >}}
---
{{< youtube Ok0jYAMnvQI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1456: Maximum Number of Vowels in a Substring of Given Length](https://grid47.xyz/leetcode/solution-1456-maximum-number-of-vowels-in-a-substring-of-given-length/) |
| --- |