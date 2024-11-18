
+++
authors = ["grid47"]
title = "Leetcode 528: Random Pick with Weight"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 528: Random Pick with Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Prefix Sum","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "oYjDXfo-mt0"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/528.webp"
+++



[`Problem Link`](https://leetcode.com/problems/random-pick-with-weight/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/528.webp" 
    alt="A series of objects with different weights, each object softly glowing based on its probability of being picked."
    caption="Solution to LeetCode 528: Random Pick with Weight Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> wc;
    public:
    Solution(vector<int>& w) {
        int n = w.size();
        for(int i = 1; i < n; i++)
            w[i] += w[i - 1];
        wc = w;
    }
    
    int pickIndex() {
        
        int x = rand() % wc.back()+1;//[(wc.size() - 1)];        
        int l = 0, r = wc.size() - 1;
    
        while(l < r) {

            int mid = l + (r - l) / 2;            
            if(wc[mid] == x) return mid;

            if(wc[mid] < x) l = mid + 1;
            else            r = mid;
        
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/528.md" >}}
---
{{< youtube oYjDXfo-mt0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #529: Minesweeper](https://grid47.xyz/leetcode/solution-529-minesweeper/) |
| --- |
