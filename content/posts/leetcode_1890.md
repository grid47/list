
+++
authors = ["Crafted by Me"]
title = "Leetcode 1890: The Latest Login in 2020"
date = "2019-08-31"
description = "Solution to Leetcode 1890"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-latest-login-in-2020/description/)

---

**Code:**

{{< highlight cpp >}}
SELECT
    user_id,
    MAX(time_stamp) AS last_stamp #obtaining latest login for all users
FROM Logins
WHERE YEAR(time_stamp) = 2020 #filtering for login dates with year 2020 in timestamp
GROUP BY user_id;
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

