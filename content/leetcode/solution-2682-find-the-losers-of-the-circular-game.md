
+++
authors = ["grid47"]
title = "Leetcode 2682: Find the Losers of the Circular Game"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2682: Find the Losers of the Circular Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "bNZuwqt1pg0"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/bNZuwqt1pg0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> rcvd(n, 0);
        int i = 0;
        int cnt = 1;
        rcvd[0] = 1;
        while(rcvd[i] == 1) {
            i = (i + cnt * k) % n;            
            if(rcvd[i] == 1) break;
            rcvd[i] = 1;
            cnt++;
        }
        vector<int> ans;
        for(int j = 0; j < n; j++) {
            // cout << rcvd[j] << " ";
            if(rcvd[j] == 0) ans.push_back(j + 1);            
        }

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2682.md" >}}
---
{{< youtube bNZuwqt1pg0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2683: Neighboring Bitwise XOR](https://grid47.xyz/leetcode/solution-2683-neighboring-bitwise-xor/) |
| --- |
