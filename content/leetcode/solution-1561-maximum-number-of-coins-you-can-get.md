
+++
authors = ["grid47"]
title = "Leetcode 1561: Maximum Number of Coins You Can Get"
date = "2024-06-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1561: Maximum Number of Coins You Can Get in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Sorting","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "hPe9Z3TiUrA"
youtube_upload_date="2020-08-24"
youtube_thumbnail="https://i.ytimg.com/vi/hPe9Z3TiUrA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int max = 0;

        int n = piles.size();

        for (int i : piles) {

            if (max < i) max = i;

        }

        vector<int> freq(max + 1, 0);

        for (int i : piles) {

            freq[i]++;

        }

        int coins = 0;

        int chance = n / 3;

        int turn = 1;

        int i = max;

        while (chance != 0) {

            if (freq[i] > 0) {

                if (turn == 1) turn = 0;

                else {

                    chance--;

                    turn = 1;

                    coins += i;

                }

                freq[i]--;

            } else {

                i--;

            }

        }

        return coins;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1561.md" >}}
---
{{< youtube hPe9Z3TiUrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1562: Find Latest Group of Size M](https://grid47.xyz/leetcode/solution-1562-find-latest-group-of-size-m/) |
| --- |
