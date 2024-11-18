
+++
authors = ["grid47"]
title = "Leetcode 2810: Faulty Keyboard"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2810: Faulty Keyboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "HuCSgRBf-B8"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi/HuCSgRBf-B8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/faulty-keyboard/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(auto c : s){
            if(c == 'i'){
                if(res.size()){
                    reverse(res.begin(), res.end());
                }
                
            }else
             res+=c;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2810.md" >}}
---
{{< youtube HuCSgRBf-B8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2811: Check if it is Possible to Split Array](https://grid47.xyz/leetcode/solution-2811-check-if-it-is-possible-to-split-array/) |
| --- |
