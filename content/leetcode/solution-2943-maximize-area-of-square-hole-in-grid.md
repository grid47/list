
+++
authors = ["grid47"]
title = "Leetcode 2943: Maximize Area of Square Hole in Grid"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2943: Maximize Area of Square Hole in Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "PwzZ9UVWqBk"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        vector<int>h;
        vector<int>v;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(auto i:hBars)
            h.push_back(i);
        for(auto i:vBars)
            v.push_back(i);
        int mv=1,mh=1;
        int c=1;
        for(int i=1;i<h.size();i++)
        {   
            
            if(h[i]==h[i-1]+1)
                c++;
            else
                c=1;
            mh=max(mh,c);
        }
        c=1;
        for(int i=1;i<v.size();i++)
        {   
            if(v[i]==v[i-1]+1)
                c++;
            else
                c=1;
            mv=max(mv,c);
        }
        int x=min(mh+1,mv+1);
        return x*x;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2943.md" >}}
---
{{< youtube PwzZ9UVWqBk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2944: Minimum Number of Coins for Fruits](https://grid47.xyz/leetcode/solution-2944-minimum-number-of-coins-for-fruits/) |
| --- |
