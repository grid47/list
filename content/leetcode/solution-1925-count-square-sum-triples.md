
+++
authors = ["grid47"]
title = "Leetcode 1925: Count Square Sum Triples"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1925: Count Square Sum Triples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rWLEDxwWwiU"
youtube_upload_date="2021-07-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rWLEDxwWwiU/maxresdefault.webp"
comments = true
+++



---
Given an integer n, count how many square triples (a, b, c) satisfy the equation a^2 + b^2 = c^2 where 1 <= a, b, c <= n. The order of a, b, and c matters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer n.
- **Example:** `n = 6`
- **Constraints:**
	- 1 <= n <= 250

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of square triples (a, b, c) where 1 <= a, b, c <= n and a^2 + b^2 = c^2.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find pairs (a, b) where a^2 + b^2 = c^2 and check if c is within the range of 1 to n.

- Iterate through all pairs (a, b) where 1 <= a, b <= n.
- For each pair, compute a^2 + b^2.
- Check if the result is a perfect square and if the corresponding c value is within the range 1 to n.
- Count such pairs where the condition holds.
{{< dots >}}
### Problem Assumptions ✅
- The problem assumes that n is always positive and within the given range.
- The solution should be able to handle the maximum value of n efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6`  \
  **Explanation:** For n = 6, the valid square triples are (3, 4, 5) and (4, 3, 5), which gives the output 2.

{{< dots >}}
## Approach 🚀
The approach is to iterate through all possible pairs (a, b) and check if the sum of their squares is a perfect square. If it is, check if the resulting c value lies within the range of 1 to n.

### Initial Thoughts 💭
- We need to efficiently check if a^2 + b^2 is a perfect square.
- The solution needs to check for all pairs (a, b), and for each pair, verify if c^2 exists in the range of 1 to n. This involves calculating squares and checking for perfect squares.
{{< dots >}}
### Edge Cases 🌐
- The input n will always be positive, so no empty inputs will occur.
- Since n can be as large as 250, ensure the solution is efficient enough to handle the maximum input size.
- The smallest valid input is n = 1, which will have no valid square triples.
- Ensure the algorithm efficiently handles up to 250 iterations for n.
{{< dots >}}
## Code 💻
```cpp
int countTriples(int n) {
vector<bool> squares(n * n + 1);
for (int i = 1; i <= n; ++i)
    squares[i * i] = true;
int res = 0;
for (int i = 1; i <= n; ++i)
    for (int j = i; i * i + j * j <= n * n; ++j)
        res += squares[i * i + j * j] * 2;
return res;
}
```

This function calculates the number of valid Pythagorean triples up to a given limit 'n'. It uses a vector to track square numbers and iterates over pairs of integers to find combinations that satisfy the Pythagorean theorem.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countTriples(int n) {
	```
	Defines the function 'countTriples' that takes an integer 'n' as input and returns the count of valid Pythagorean triples less than or equal to 'n'.

2. **Array Initialization**
	```cpp
	vector<bool> squares(n * n + 1);
	```
	Initializes a vector 'squares' of size 'n * n + 1' to store boolean values, where each index represents whether the index is a perfect square.

3. **Loop Start**
	```cpp
	for (int i = 1; i <= n; ++i)
	```
	Begins a loop to iterate over integers 'i' from 1 to 'n' to mark squares in the 'squares' vector.

4. **Square Marking**
	```cpp
	    squares[i * i] = true;
	```
	Marks 'squares[i * i]' as true to indicate that 'i * i' is a perfect square.

5. **Variable Initialization**
	```cpp
	int res = 0;
	```
	Initializes the result variable 'res' to 0, which will store the number of valid Pythagorean triples.

6. **Outer Loop Start**
	```cpp
	for (int i = 1; i <= n; ++i)
	```
	Begins the outer loop over integer 'i' to iterate through possible sides of the Pythagorean triple.

7. **Inner Loop Start**
	```cpp
	    for (int j = i; i * i + j * j <= n * n; ++j)
	```
	Begins the inner loop with integer 'j' starting from 'i' to ensure 'i <= j' and continues while 'i * i + j * j' is less than or equal to 'n * n'.

8. **Count Triples**
	```cpp
	        res += squares[i * i + j * j] * 2;
	```
	Checks if 'i * i + j * j' is a perfect square by looking up its value in the 'squares' vector. If it is, it increments 'res' by 2 (accounting for both (i, j) and (j, i) pairs).

9. **Return**
	```cpp
	return res;
	```
	Returns the final count of Pythagorean triples.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the two nested loops that iterate over all pairs (a, b).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-square-sum-triples/description/)

---
{{< youtube rWLEDxwWwiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
