
+++
authors = ["grid47"]
title = "Leetcode 1090: Largest Values From Labels"
date = "2024-07-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1090: Largest Values From Labels in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "E0OkE3G95vU"
youtube_upload_date="2020-12-06"
youtube_thumbnail="https://i.ytimg.com/vi/E0OkE3G95vU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/largest-values-from-labels/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        multimap<int, int> s;
        unordered_map<int, int> m;
        for(int i = 0; i < values.size(); i++) 
            s.insert({values[i], labels[i]});
        int res = 0;
        for(auto it = rbegin(s); it != rend(s) && numWanted > 0; it++) {
            if(++m[it->second] <= useLimit) {
                res += it->first;
                --numWanted;                
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1090.md" >}}
---
{{< youtube E0OkE3G95vU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1091: Shortest Path in Binary Matrix](https://grid47.xyz/leetcode/solution-1091-shortest-path-in-binary-matrix/) |
| --- |