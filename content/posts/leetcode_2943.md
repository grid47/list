
+++
authors = ["Crafted by Me"]
title = "Leetcode 2943: Maximize Area of Square Hole in Grid"
date = "2016-10-12"
description = "In-depth solution and explanation for Leetcode 2943: Maximize Area of Square Hole in Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2944: Minimum Number of Coins for Fruits](https://grid47.xyz/posts/leetcode_2944) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

