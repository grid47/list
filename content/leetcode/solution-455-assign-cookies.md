
+++
authors = ["grid47"]
title = "Leetcode 455: Assign Cookies"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 455: Assign Cookies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/455.webp"
youtube = "AXaPmVMkVAE"
youtube_upload_date="2019-11-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AXaPmVMkVAE/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/assign-cookies/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/455.webp" 
    alt="A series of cookies and children with glowing indicators of the best cookie assignment."
    caption="Solution to LeetCode 455: Assign Cookies Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i])
                i++; // when the child get the cookie, foward child by 1
            j++;
        }
        return i;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/455.md" >}}
---
{{< youtube AXaPmVMkVAE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #456: 132 Pattern](https://grid47.xyz/leetcode/solution-456-132-pattern/) |
| --- |
