
+++
authors = ["grid47"]
title = "Leetcode 1663: Smallest String With A Given Numeric Value"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1663: Smallest String With A Given Numeric Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "o3MRJfsoUrw"
youtube_upload_date="2021-02-15"
youtube_thumbnail="https://i.ytimg.com/vi/o3MRJfsoUrw/maxresdefault.jpg"
comments = true
+++



---
You are given two integers `n` and `k`. Your task is to return the lexicographically smallest string of length `n` with a numeric value equal to `k`. The numeric value of a string is the sum of the numeric values of its characters, where 'a' = 1, 'b' = 2, ..., and 'z' = 26.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers, `n` and `k`. The string should be of length `n` and its numeric value should be equal to `k`.
- **Example:** `n = 4, k = 34`
- **Constraints:**
	- 1 <= n <= 10^5
	- n <= k <= 26 * n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest string of length `n` with a numeric value equal to `k`.
- **Example:** `"aazb"`
- **Constraints:**
	- The string should be of length `n` and have a numeric value equal to `k`.

{{< dots >}}
### Core Logic 🔍
**Goal:** To construct the lexicographically smallest string that has the given numeric value `k` and length `n`.

- Initialize a string of length `n` with all 'a's, since 'a' has the smallest numeric value (1).
- Subtract `n` from `k` to account for the initial 'a's.
- From the end of the string, replace 'a' with other characters (up to 'z') to achieve the desired numeric value, starting with the largest possible character (i.e., 'z').
{{< dots >}}
### Problem Assumptions ✅
- The value of `k` will always be valid for the given `n` according to the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4, k = 34`  \
  **Explanation:** The string 'aazb' has a numeric value of 1 + 1 + 26 + 2 = 34, and is the lexicographically smallest string that satisfies these conditions.

- **Input:** `n = 6, k = 60`  \
  **Explanation:** The string 'aazzzz' has a numeric value of 1 + 1 + 26 + 26 + 26 + 26 = 60, and is the lexicographically smallest string that satisfies these conditions.

{{< dots >}}
## Approach 🚀
The approach involves starting with a string of all 'a's and adjusting the characters from the end to reach the desired numeric value `k`.

### Initial Thoughts 💭
- The smallest string is composed of 'a's, and we need to replace some of them with higher value characters to achieve the total value `k`.
- We can use a greedy approach, modifying the string from the last position towards the first to minimize lexicographical order.
{{< dots >}}
### Edge Cases 🌐
- If `n` is 1, then `k` must be between 1 and 26, inclusive.
- For large values of `n`, the algorithm should efficiently adjust the string to reach the value `k`.
- When `k` equals `n`, the string will consist only of 'a's.
- The solution must handle values of `n` up to 10^5 efficiently.
{{< dots >}}
## Code 💻
```cpp
string getSmallestString(int n, int k) {
    string ans(n, 'a');
    k -= n;
    while(k > 0) {
        ans[--n] += min(25, k);
        k -= min(25, k);
    }
    return ans;
}
```

This function constructs the lexicographically smallest string of length `n` where the sum of the positions of the characters equals `k`. It uses greedy logic to adjust characters from 'a' upwards.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string getSmallestString(int n, int k) {
	```
	Defines the function `getSmallestString` which takes integers `n` (length of the string) and `k` (target sum) as input.

2. **Variable Initialization**
	```cpp
	    string ans(n, 'a');
	```
	Initializes the string `ans` with `n` characters, all set to 'a'.

3. **Mathematical Adjustment**
	```cpp
	    k -= n;
	```
	Decreases `k` by `n` because each 'a' contributes 1 to the total sum.

4. **Looping**
	```cpp
	    while(k > 0) {
	```
	Enters a loop to adjust the string until the remaining sum `k` is zero.

5. **String Update**
	```cpp
	        ans[--n] += min(25, k);
	```
	Adjusts the last unprocessed character in `ans` by increasing its value by the smaller of 25 or `k`, ensuring it remains a valid alphabet character.

6. **Mathematical Adjustment**
	```cpp
	        k -= min(25, k);
	```
	Decreases `k` by the value added to the character, reducing the remaining sum to be distributed.

7. **Return**
	```cpp
	    return ans;
	```
	Returns the final adjusted string `ans`, which is the lexicographically smallest string meeting the criteria.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), as we modify the string in linear time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) since we store the string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/description/)

---
{{< youtube o3MRJfsoUrw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
