
+++
authors = ["Yasir"]
title = "Leetcode 1517: Find Users With Valid E-Mails"
date = "2020-09-02"
description = "Solution to Leetcode 1517"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-users-with-valid-e-mails/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE REGEXP_LIKE(mail, '^[A-Za-z][A-Za-z0-9\.\_\-]*@leetcode[.]com$');
{{< /highlight >}}

