
+++
authors = ["grid47"]
title = "Leetcode 2043: Simple Bank System"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2043: Simple Bank System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ouflA0KmCnI"
youtube_upload_date="2021-10-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ouflA0KmCnI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/simple-bank-system/description/)

---
**Code:**

{{< highlight cpp >}}
class Bank {
public:
    int n;
    vector<long long> bal;
    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }
    
    bool transfer(int acc1, int acc2, long long money) {
        int ac1 = acc1 - 1 , ac2 = acc2 - 1;
        if(ac1 < 0 || ac1 >= n || ac2 < 0 || ac2 >= n || bal[ac1] < money)
            return false;
        
        bal[ac1] -= money;
        bal[ac2] += money;
        return true;
    }
    
    bool deposit(int acc, long long money) {
        
        if(acc < 1 || acc > n) return false;
        
        bal[acc - 1] += money;
        return true;
    }
    
    bool withdraw(int acc, long long money) {
        if(acc < 1 || acc > n || bal[acc - 1] < money) return false;        
        bal[acc - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2043.md" >}}
---
{{< youtube ouflA0KmCnI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2044: Count Number of Maximum Bitwise-OR Subsets](https://grid47.xyz/leetcode/solution-2044-count-number-of-maximum-bitwise-or-subsets/) |
| --- |