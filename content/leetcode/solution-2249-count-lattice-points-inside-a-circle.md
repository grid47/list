
+++
authors = ["grid47"]
title = "Leetcode 2249: Count Lattice Points Inside a Circle"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2249: Count Lattice Points Inside a Circle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Geometry","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HCLinlC-JWY"
youtube_upload_date="2022-04-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HCLinlC-JWY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& cir) {
        set<int> cnt;
        
        for(auto it: cir) {
            
            for(int i = it[0] - it[2]; i <= it[0] + it[2]; i++)
            for(int j = it[1] - it[2]; j <= it[1] + it[2]; j++)                
                if((i - it[0]) * (i - it[0]) + (j - it[1]) * (j - it[1]) <= (it[2] * it[2]))
                    cnt.insert(i * 1000 + j);
            
        }
        return cnt.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2249.md" >}}
---
{{< youtube HCLinlC-JWY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2250: Count Number of Rectangles Containing Each Point](https://grid47.xyz/leetcode/solution-2250-count-number-of-rectangles-containing-each-point/) |
| --- |