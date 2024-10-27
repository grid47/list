
+++
authors = ["Yasir"]
title = "Leetcode 793: Preimage Size of Factorial Zeroes Function"
date = "2022-08-27"
description = "Solution to Leetcode 793"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    long count5(long x) {
        long cnt = 0;
        while(x > 0) {
            cnt += x / 5;
            x /= 5;
        }
        return cnt;
    }
    
    long bigWithK(int k) {
        // if(k == -1) return -1;
        long l = 1, r = LLONG_MAX - 1;
        long ans = -1;
        while(l <= r) {
            long mid = l + (r - l + 1) / 2;
            long cnt = count5(mid);
            if(cnt > k) {
                ans = mid;
                r = mid - 1;
            } else {
                // ans = mid;
                l = mid + 1;
            }
        }
        // cout << ans << " ";
        return ans;
    }
    
    int preimageSizeFZF(int k) {
        if(k == 0) return 5;
        long a1 = bigWithK(k);
        long a2 = bigWithK(k - 1);        
        return a1 - a2;
    }
};
{{< /highlight >}}

