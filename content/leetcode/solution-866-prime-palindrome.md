
+++
authors = ["grid47"]
title = "Leetcode 866: Prime Palindrome"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 866: Prime Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MZSbndVpxH8"
youtube_upload_date="2019-11-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MZSbndVpxH8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/prime-palindrome/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int primePalindrome(int n) {
        if(8 <= n && n <= 11) return 11;
        for(int x = 1; x < 100000; x++) {
            string s = to_string(x), r(s.rbegin(), s.rend());
            int y = stoi(s + r.substr(1));
            if(y >= n && isPrime(y)) return y;
        }
        return -1;
    }
    
    bool isPrime(int num) {
        if(num < 2 || num %2 == 0) return num == 2;
        for(int i = 3; i * i <= num; i += 2) {
            if(num%i == 0) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/866.md" >}}
---
{{< youtube MZSbndVpxH8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #867: Transpose Matrix](https://grid47.xyz/leetcode/solution-867-transpose-matrix/) |
| --- |
