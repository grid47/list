
+++
authors = ["Crafted by Me"]
title = "Leetcode 920: Number of Music Playlists"
date = "2022-04-27"
description = "Solution to Leetcode 920"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-music-playlists/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod = (int)pow(10, 9) + 7;
        vector<vector<long>> dp(L+1, vector<long>(N+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= L; i++){
            for (int j = 1; j <= N; j++){
                dp[i][j] = (dp[i-1][j-1] * (N - (j-1)))%mod; 
                if (j > K){
                    dp[i][j] = (dp[i][j] + (dp[i-1][j] * (j-K))%mod)%mod;
                }
            }
        }
        return (int)dp[L][N];
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/920.md" >}}
- by gpt
        
---
{{< youtube 7kqUjOW1Dlw >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

