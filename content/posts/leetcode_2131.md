
+++
authors = ["Yasir"]
title = "Leetcode 2131: Longest Palindrome by Concatenating Two Letter Words"
date = "2018-12-28"
description = "Solution to Leetcode 2131"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int unpaired = 0;
        unordered_map<string, int> mp;

        for(string w: words) {
            if(w[0] == w[1]) {
                if(mp[w] > 0) {
                    unpaired--;
                    ans += 4;
                    mp[w]--;
                } else {
                    unpaired++;
                    mp[w]++;
                }
            } else {
                string rev = w;
                reverse(rev.begin(), rev.end());
                if(mp[rev] > 0) {
                    ans += 4;
                    mp[rev]--;
                } else mp[w]++;
            }
        }


        if (unpaired > 0) ans += 2;
        return ans;
    }
};
{{< /highlight >}}

