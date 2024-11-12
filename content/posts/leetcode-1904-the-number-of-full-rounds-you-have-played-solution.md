
+++
authors = ["grid47"]
title = "Leetcode 1904: The Number of Full Rounds You Have Played"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1904: The Number of Full Rounds You Have Played in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfRounds(string login, string logout) {
        
        int in = (((login[0] - '0') * 10 + (login[1]- '0')) * 60) + ((login[3] - '0') * 10 + (login[4] - '0'));
        int out = (((logout[0] - '0') * 10 + (logout[1]- '0')) * 60) + ((logout[3] - '0') * 10 + (logout[4] - '0'));
        // cout << in << " " << out;
        int cnt = 0;
        if(in > out) {
            for(int i = 0; i < 24 * 60; i += 15) {
                if(i + 15 <= out || i >= in) cnt++;
            }
            return cnt;
        }

        for(int i = 0; i < 24 * 60; i += 15) {
            // cout << "\n" << i; 
            if(i >= in && (i + 15) <= out) cnt++;
        }
        return cnt;
        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1904.md" >}}
---
{{< youtube kwvB82HHvoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1905: Count Sub Islands](https://grid47.xyz/posts/leetcode-1905-count-sub-islands-solution/) |
| --- |
