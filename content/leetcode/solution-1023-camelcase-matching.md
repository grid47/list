
+++
authors = ["grid47"]
title = "Leetcode 1023: Camelcase Matching"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1023: Camelcase Matching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Trie","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "h9I_yFNeMgo"
youtube_upload_date="2024-07-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/h9I_yFNeMgo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/camelcase-matching/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool> res;
        
        for(string q: queries) {
            
            bool ret = match(q, pattern);
            
            res.push_back(ret);
        }

        return res;
    }
    
    bool match(string q, string p) {
        
        int j = 0;
        
        for(int i = 0; i < q.size(); i++) {
            
            if(j < p.size()&&q[i] == p[j]) {
                j++;
                continue;
            }else if(q[i] >= 'A' && 
               q[i] <= 'Z')
                return false;               
               
        }
        
        return j == p.size();
        
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1023.md" >}}
---
{{< youtube h9I_yFNeMgo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1024: Video Stitching](https://grid47.xyz/leetcode/solution-1024-video-stitching/) |
| --- |