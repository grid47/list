
+++
authors = ["Yasir"]
title = "Leetcode 866: Prime Palindrome"
date = "2022-06-15"
description = "Solution to Leetcode 866"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/prime-palindrome/description/)

---

**Code:**

{{< highlight html >}}
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

