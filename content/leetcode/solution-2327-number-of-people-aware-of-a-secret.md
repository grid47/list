
+++
authors = ["grid47"]
title = "Leetcode 2327: Number of People Aware of a Secret"
date = "2024-03-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2327: Number of People Aware of a Secret in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Queue","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rOnTeyl_njo"
youtube_upload_date="2022-07-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rOnTeyl_njo/maxresdefault.webp"
comments = true
+++



---
On day 1, one person discovers a secret. Each person will share the secret after a delay and forget it after a certain number of days. Return the number of people who know the secret at the end of day n, modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given integers n (number of days), delay (days after which a person starts sharing the secret), and forget (days after which a person forgets the secret).
- **Example:** `n = 6, delay = 2, forget = 4`
- **Constraints:**
	- 2 <= n <= 1000
	- 1 <= delay < forget <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of people who know the secret at the end of day n, modulo 10^9 + 7.
- **Example:** `Output: 5`
- **Constraints:**
	- The answer can be very large, so return it modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the process of sharing and forgetting the secret over n days.

- Initialize an array to track the number of people sharing the secret each day.
- Use dynamic programming to calculate how the secret spreads over time, considering the delay and forget intervals.
- Return the sum of the people who know the secret at the end of day n.
{{< dots >}}
### Problem Assumptions ✅
- There is at least one person who knows the secret on day 1.
- Each person can share the secret only once during the period they know it.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6, delay = 2, forget = 4`  \
  **Explanation:** This example demonstrates how the secret spreads over 6 days, with the delay and forget intervals affecting how many people eventually learn the secret.

{{< dots >}}
## Approach 🚀
The goal is to simulate the process of how a secret is shared and forgotten over time using dynamic programming.

### Initial Thoughts 💭
- Each person can only share the secret once, and they will forget after a certain number of days.
- We need to track how many people share the secret each day, considering the delay and forget intervals.
{{< dots >}}
### Edge Cases 🌐
- n = 2, delay = 1, forget = 2
- n = 1000, delay = 500, forget = 800
- delay = 1, forget = 3
- The number of people sharing the secret and forgetting it must be correctly managed with respect to the provided constraints.
{{< dots >}}
## Code 💻
```cpp
int peopleAwareOfSecret(int n, int delay, int forget) {
    
    int res = 0, share = 0;
    vector<long> dp(n + 2, 0);
    dp[1] = 1;
    int mod = 1e9 + 7;
    for(int i = 2; i <= n; i++)
        dp[i] = share = (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + mod) % mod;
    
    for(int i = n + 1 - forget; i <= n; i++)
        res = (res + dp[i]) % mod;
    
    return res;
}
```

This function calculates how many people are aware of a secret after `n` days, with a delay of `delay` days before a person can share the secret and a forget period of `forget` days after which a person forgets the secret. It uses dynamic programming to calculate the number of people aware on each day.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int peopleAwareOfSecret(int n, int delay, int forget) {
	```
	Declares the function `peopleAwareOfSecret` that takes three parameters: `n` (the total number of days), `delay` (the number of days before a person can share the secret), and `forget` (the number of days after which a person forgets the secret). It returns the total number of people aware of the secret modulo `1e9 + 7`.

2. **Variable Initialization**
	```cpp
	    int res = 0, share = 0;
	```
	Initializes two variables: `res` to store the result (number of people aware of the secret) and `share` to track the number of people who can share the secret on any given day.

3. **Dynamic Programming Setup**
	```cpp
	    vector<long> dp(n + 2, 0);
	```
	Initializes a dynamic programming (DP) vector `dp` of size `n + 2` to store the number of people who are aware of the secret on each day. The extra space is for handling boundary conditions safely.

4. **Base Case**
	```cpp
	    dp[1] = 1;
	```
	Sets the base case: on day 1, one person knows the secret.

5. **Modular Arithmetic**
	```cpp
	    int mod = 1e9 + 7;
	```
	Defines a constant `mod` with the value `1e9 + 7` for performing modular arithmetic to prevent overflow and ensure the result fits within standard integer limits.

6. **Dynamic Programming Loop**
	```cpp
	    for(int i = 2; i <= n; i++)
	```
	Iterates through each day from 2 to `n` to calculate the number of people who are aware of the secret on that day.

7. **State Transition**
	```cpp
	        dp[i] = share = (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + mod) % mod;
	```
	Updates the value of `dp[i]`, which represents the number of people who become aware of the secret on day `i`. It adds the number of people who can share the secret (after the `delay` period) and subtracts those who forget it (after the `forget` period). The result is taken modulo `mod`.

8. **Final Summation**
	```cpp
	    for(int i = n + 1 - forget; i <= n; i++)
	```
	Iterates through the last `forget` days to sum the number of people who are still aware of the secret.

9. **Result Update**
	```cpp
	        res = (res + dp[i]) % mod;
	```
	Adds the number of people aware of the secret on day `i` to `res`, taking care to apply modular arithmetic to avoid overflow.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total number of people who are aware of the secret, modulo `1e9 + 7`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of n, as we iterate through each day once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is also linear, as we need an array to track people each day.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/)

---
{{< youtube rOnTeyl_njo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
