
+++
authors = ["grid47"]
title = "Leetcode 2483: Minimum Penalty for a Shop"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2483: Minimum Penalty for a Shop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0d7ShRoOFVE"
youtube_upload_date="2023-08-29"
youtube_thumbnail="https://i.ytimg.com/vi/0d7ShRoOFVE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int bestClosingTime(string a) {
        int s = a.size();
        vector<int> y,n;
        y.push_back(0);
        n.push_back(0);
        int cnt = 0;
        for (int i = 0; i < s; i++) {
            if(a[i] == 'N') cnt++;
            n.push_back(cnt);
        }
        cnt = 0;
        for (int i = s -1; i >= 0; i--) {
            if(a[i] == 'Y') cnt++;
            y.push_back(cnt);
        }
        
        reverse (y.begin(), y.end());
        int ans = INT_MAX, ind = 0;
        for(int i = 0; i < s +1; i++) {
            int h = n[i] + y[i];
            if(h<ans) {
                ans = h;
                ind = i;
            }
        }
        return ind;        
    }
};
{{< /highlight >}}
---

The provided code is a solution to a problem where we are asked to determine the best time to close a shop, such that the total number of customers left outside the shop (in the "N" state) is minimized, given a string representing customer states during each hour of operation.

Let’s break down the problem, approach, and the code step-by-step to understand how the solution works and how to derive its time and space complexities. This breakdown will be useful for any programmer aiming to optimize or understand such algorithms in a more structured manner.

### Problem Statement

Given a string `a` consisting of characters 'Y' and 'N', where each character represents the state of a customer at an hour of the day:
- 'Y' means the customer has already entered the shop.
- 'N' means the customer has not yet entered the shop.

The goal is to determine the best hour to close the shop such that the total number of customers left outside (those in the 'N' state) is minimized. The shop can be closed at any hour, and we need to calculate how many customers would remain outside for each possible closing time.

The solution must:
- Account for how many customers are inside (`'Y'`).
- Account for how many customers are outside (`'N'`).
- Find the optimal closing time that minimizes the total number of customers left outside.

### Approach

To solve this problem efficiently, we can utilize the following strategy:

1. **Count customers outside ('N') before closing time**: As we scan the string from left to right, we need to keep track of how many customers are still in the 'N' state. This will help us determine the number of customers left outside at any given closing time.
  
2. **Count customers inside ('Y') after closing time**: As we scan the string from right to left, we need to keep track of how many customers have entered the shop (the 'Y' state) after a given closing hour.

3. **Combine the counts**: For each possible closing time, calculate the total number of customers left outside (those who are 'N' before the closing time and those who are 'Y' after the closing time).

4. **Minimize the total**: The objective is to minimize the sum of customers left outside. Hence, we need to find the closing time that results in the minimum sum.

### Code Breakdown (Step by Step)

Let’s break down the solution code in more detail:

#### 1. **Initialization and Variable Setup**

```cpp
int s = a.size();
vector<int> y, n;
y.push_back(0);
n.push_back(0);
int cnt = 0;
```

- `s` stores the size of the input string `a`, which represents the state of the customers at each hour.
- Two vectors `y` and `n` are initialized to store the cumulative counts of customers who have entered (`'Y'`) and the cumulative counts of customers who have not entered (`'N'`).
- The vector `y` keeps track of the count of 'Y' customers from right to left, and `n` tracks the count of 'N' customers from left to right.
  
#### 2. **Count the 'N' Customers from Left to Right**

```cpp
for (int i = 0; i < s; i++) {
    if(a[i] == 'N') cnt++;
    n.push_back(cnt);
}
```

- We iterate over the string `a` from left to right.
- Each time we encounter an 'N', we increment the `cnt` (counter for 'N' customers).
- The cumulative count of 'N' customers is stored in the `n` vector, so `n[i]` represents the number of 'N' customers up to and including hour `i`.

#### 3. **Count the 'Y' Customers from Right to Left**

```cpp
cnt = 0;
for (int i = s - 1; i >= 0; i--) {
    if(a[i] == 'Y') cnt++;
    y.push_back(cnt);
}
```

- After counting the 'N' customers, we reset the counter `cnt` to 0 and begin iterating over the string from right to left.
- For each 'Y' encountered, we increment the `cnt` (counter for 'Y' customers).
- The cumulative count of 'Y' customers is stored in the `y` vector, so `y[i]` represents the number of 'Y' customers from hour `i` onward.

#### 4. **Reverse the 'Y' Vector**

```cpp
reverse (y.begin(), y.end());
```

- After the loop, the `y` vector contains the counts of 'Y' customers from right to left. To use it effectively in subsequent calculations, we reverse the vector so that it represents the count of 'Y' customers from left to right.

#### 5. **Calculate the Best Closing Time**

```cpp
int ans = INT_MAX, ind = 0;
for(int i = 0; i < s + 1; i++) {
    int h = n[i] + y[i];
    if(h < ans) {
        ans = h;
        ind = i;
    }
}
return ind;
```

- We initialize `ans` to store the minimum number of customers left outside, and `ind` to store the index of the optimal closing time.
- We iterate through each possible closing time (from hour 0 to hour `s`), where `i` represents the closing time index.
- For each closing time `i`, the total number of customers left outside is the sum of:
  - `n[i]`: the number of 'N' customers before hour `i`.
  - `y[i]`: the number of 'Y' customers from hour `i` onward.
- If the sum `h` is less than the current `ans`, we update `ans` and set `ind` to the current closing time `i`.
- Finally, we return `ind`, which is the optimal closing time.

### Complexity Analysis

#### Time Complexity:
- The time complexity of this solution is **O(s)**, where `s` is the length of the string `a`. This is because:
  - We scan through the string once to count 'N' customers and once more to count 'Y' customers.
  - The final loop over the closing times also runs `s + 1` times, which is still **O(s)**.

Thus, the overall time complexity is **O(s)**.

#### Space Complexity:
- The space complexity is **O(s)** because we use two vectors `y` and `n`, each of size `s + 1`, to store the cumulative counts.

Thus, the overall space complexity is **O(s)**.

### Conclusion

The given solution efficiently calculates the optimal closing time for the shop by utilizing two vectors to store the cumulative counts of 'N' and 'Y' customers. The code's time and space complexities are both linear, making it a scalable solution for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-penalty-for-a-shop/description/)

---
{{< youtube 0d7ShRoOFVE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
