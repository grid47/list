
+++
authors = ["grid47"]
title = "Leetcode 2531: Make Number of Distinct Characters Equal"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2531: Make Number of Distinct Characters Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MoYeUVe-xPY"
youtube_upload_date="2023-01-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MoYeUVe-xPY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isItPossible(string w1, string w2) {
        
        map<char, int> ma1, ma2;
        for(int x: w1)
            ma1[x]++;
        for(int x: w2)
            ma2[x]++;
        
        for(auto it1: ma1) {
            for(auto it2: ma2) {
                map<char, int> d1 = ma1, d2 = ma2;
                d1[it2.first]++;
                d2[it1.first]++;
                
                d1[it1.first]--;
                d2[it2.first]--;
                
                if(d1[it1.first] == 0)
                    d1.erase(it1.first);
                if(d2[it2.first] == 0)
                    d2.erase(it2.first);
                
                if(d1.size() == d2.size()) return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2531.md" >}}
---
{{< youtube MoYeUVe-xPY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2535: Difference Between Element Sum and Digit Sum of an Array](https://grid47.xyz/leetcode/solution-2535-difference-between-element-sum-and-digit-sum-of-an-array/) |
| --- |