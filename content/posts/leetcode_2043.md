
+++
authors = ["Crafted by Me"]
title = "Leetcode 2043: Simple Bank System"
date = "2019-03-31"
description = "In-depth solution and explanation for Leetcode 2043: Simple Bank System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---


| Next : [LeetCode #2044: Count Number of Maximum Bitwise-OR Subsets](grid47.xyz/leetcode_2044) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

