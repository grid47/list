
+++
authors = ["Crafted by Me"]
title = "Leetcode 1415: The k-th Lexicographical String of All Happy Strings of Length n"
date = "2019-12-18"
description = "Solution to Leetcode 1415"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string ans = "";
    int cnt = 0;
    int k, n;
    
    string getHappyString(int n, int k) {
        this->k = k;
        this->n = n;
        string tmp = "";
        bt(-1, tmp);
        return ans;
    }
    
    void bt(int prv, string &tmp) {
        if(tmp.size() == n) {
            cnt++;
            if(cnt == k){
              ans = tmp;  
            } 
            return;
        }

        for(int i = 0; i < 3; i++) {
            if(prv == i) continue;
            if(i == 0) {
                tmp += 'a';
            } else if(i == 1) {
                tmp += 'b';
            } else if(i == 2) {
                tmp += 'c';
            }
            bt(i, tmp);
            tmp.pop_back();
        }
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

