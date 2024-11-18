
+++
authors = ["grid47"]
title = "Leetcode 2024: Maximize the Confusion of an Exam"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2024: Maximize the Confusion of an Exam in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "XYJv2pySK44"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int ans = 1;
        int fidx = 0, tidx = 0, fcnt = 0, tcnt = 0;
        for(int i = 0; i < key.size(); i++) {
            if(key[i] == 'F') fcnt++;
            else tcnt++;
            while(fcnt > k) {
                if(key[tidx] == 'F') fcnt--;
                tidx++;
            }
            ans = max(ans, i - tidx + 1);
            while(tcnt > k) {
                if(key[fidx] == 'T') tcnt--;
                fidx++;
            }
            ans = max(ans, i - fidx + 1);            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2024.md" >}}
---
{{< youtube XYJv2pySK44 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2027: Minimum Moves to Convert String](https://grid47.xyz/leetcode/solution-2027-minimum-moves-to-convert-string/) |
| --- |
