
+++
authors = ["Yasir"]
title = "Leetcode 2043: Simple Bank System"
date = "2019-03-26"
description = "Solution to Leetcode 2043"
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

{{< highlight html >}}
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

