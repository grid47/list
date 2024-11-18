
+++
authors = ["grid47"]
title = "Leetcode 2788: Split Strings by Separator"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2788: Split Strings by Separator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "DdjLhSeodGs"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/split-strings-by-separator/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
        
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++) {
            string cur = "";
            
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] == sep) {
                    if(cur != "")
                    ans.push_back(cur);
                    cur = "";
                } else if(j == words[i].size() - 1) {
                    cur += words[i][j];                    
                    ans.push_back(cur);
                    cur = "";
                } else 
                cur += words[i][j];
            }
            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2788.md" >}}
---
{{< youtube DdjLhSeodGs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2789: Largest Element in an Array after Merge Operations](https://grid47.xyz/leetcode/solution-2789-largest-element-in-an-array-after-merge-operations/) |
| --- |
