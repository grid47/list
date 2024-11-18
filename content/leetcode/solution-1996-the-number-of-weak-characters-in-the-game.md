
+++
authors = ["grid47"]
title = "Leetcode 1996: The Number of Weak Characters in the Game"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1996: The Number of Weak Characters in the Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "DFqwkF9a6KI"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/)

---
**Code:**

{{< highlight cpp >}}

class Solution {

    public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        } else return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prpt) {
        sort(prpt.begin(), prpt.end(), comp);
        
        int mn = INT_MIN;
        int ans = 0;
        
        for(int i = prpt.size() - 1; i >= 0; i--) {
            if(prpt[i][1] < mn) ans++;
            mn = max(mn, prpt[i][1]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1996.md" >}}
---
{{< youtube DFqwkF9a6KI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1997: First Day Where You Have Been in All the Rooms](https://grid47.xyz/leetcode/solution-1997-first-day-where-you-have-been-in-all-the-rooms/) |
| --- |
