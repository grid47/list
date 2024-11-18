
+++
authors = ["grid47"]
title = "Leetcode 1487: Making File Names Unique"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1487: Making File Names Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B9hKZonstN0"
youtube_upload_date="2020-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/B9hKZonstN0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/making-file-names-unique/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> mp;
        
        for(int i = 0; i < names.size(); i++) {
            
            if(mp.count(names[i])) {
                int k = mp[names[i]];
                while(mp.count(names[i] + "(" + to_string(k) + ")")) {
                    k++;
                    mp[names[i]]++;
                }
                mp[names[i]]++;
                names[i] = names[i] + "(" + to_string(k) + ")";
            }

            mp[names[i]] = 1;
        }
        return names;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1487.md" >}}
---
{{< youtube B9hKZonstN0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1488: Avoid Flood in The City](https://grid47.xyz/leetcode/solution-1488-avoid-flood-in-the-city/) |
| --- |
