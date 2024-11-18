
+++
authors = ["grid47"]
title = "Leetcode 837: New 21 Game"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 837: New 21 Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Sliding Window","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zKi4LzjK27k"
youtube_upload_date="2023-05-25"
youtube_thumbnail="https://i.ytimg.com/vi/zKi4LzjK27k/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/new-21-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double new21Game(int n, int k, int w) {
        

        if(k == 0 || n >= k + w)
            return 1;

        
        /*
        
        You will get number x (1 to w) in a draw, with probablity 1 / w
        
        if you need probablity of getting i points in a draw
        
        we can do slecting (i - x) points with probablity dp[i - x] and
        selecting x with probablity x
        
        so doing it together dp[i - x] * 1 / w
        
        and this to every x in [1, w] to get net prob of dp[i].
        
        once the pionts has crossed a limit k, there will be no more selections.
        
        then we look for only the over flows from previous trials.

        why target probablity counted from k onward instead of dp[n].

        */        
        
        vector<double> dp(n+1);
        dp[0] = 1;
        double Wsum = 1.0, res = 0.0;
        for(int i = 1; i <= n; i++) {
            dp[i] = Wsum/ w;
            if(i < k) Wsum += dp[i];
            else res += dp[i];
            if(i - w >= 0) Wsum -= dp[i - w];
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/837.md" >}}
---
{{< youtube zKi4LzjK27k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #838: Push Dominoes](https://grid47.xyz/leetcode/solution-838-push-dominoes/) |
| --- |
