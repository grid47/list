
+++
authors = ["grid47"]
title = "Leetcode 402: Remove K Digits"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 402: Remove K Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/402.webp"
youtube = "cFabMOnJaq0"
youtube_upload_date="2022-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/cFabMOnJaq0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/remove-k-digits/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/402.webp" 
    alt="A string of digits where each one is gently erased one by one, leaving the smallest number behind, glowing softly."
    caption="Solution to LeetCode 402: Remove K Digits Problem"
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
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.size();
        if(num.size() <= k) return "0";
        
        for(char c : num) {
            
            while(!ans.empty() && (ans.back() > c) && k) {
                ans.pop_back();
                k--;
            }
            
            if(!ans.empty() || c != '0') {
                ans.push_back(c);
            }
            
        }
        while(!ans.empty() && k--)
            ans.pop_back();
        if (ans.empty()) return "0";
        while (!ans.empty()) {
            num[n - 1] = ans.back();
            ans.pop_back(), n--;
        }
        return num.substr(n);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/402.md" >}}
---
{{< youtube cFabMOnJaq0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #406: Queue Reconstruction by Height](https://grid47.xyz/leetcode/solution-406-queue-reconstruction-by-height/) |
| --- |
