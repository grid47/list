
+++
authors = ["grid47"]
title = "Leetcode 2786: Visit Array Positions to Maximize Score"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2786: Visit Array Positions to Maximize Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "JtogyeIxGWE"
youtube_upload_date="2023-07-22"
youtube_thumbnail="https://i.ytimg.com/vi/JtogyeIxGWE/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array 'nums' and a positive integer 'x'. Starting at index 0, you can move to any position j (where i < j). For each position i that you visit, you get a score of nums[i]. If the parities of nums[i] and nums[j] differ, you lose a score of 'x'. Your goal is to find the maximum score you can accumulate by visiting positions in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array nums and a positive integer x.
- **Example:** `Input: nums = [5, 10, 3, 7], x = 4`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- 1 <= nums[i], x <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum score you can achieve by visiting positions in the array according to the given rules.
- **Example:** `Output: 19`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the total score by choosing the optimal positions to visit based on the parity conditions.

- Initialize the scores for the even and odd cases based on nums[0].
- Iterate through the array, updating the scores based on the parity of nums[i] and the maximum possible score from previous positions.
- Return the maximum score from the even or odd score variable.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums contains integers and is not empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [5, 10, 3, 7], x = 4`  \
  **Explanation:** Starting at index 0, we first gain 5 points. Then moving to index 1, we gain 10 but lose 4 points because the parities of 5 (odd) and 10 (even) differ. Then, moving to index 3, we gain 7 but lose another 4 points because the parities of 10 (even) and 7 (odd) differ. The final score is 5 + 10 + 7 - 4 - 4 = 19.

- **Input:** `Input: [2, 4, 6, 8], x = 2`  \
  **Explanation:** All values are even, so no penalties are incurred. The total score is 2 + 4 + 6 + 8 = 20.

{{< dots >}}
## Approach 🚀
We will use dynamic programming to track the maximum possible score at each position based on the parity of the current and previous positions.

### Initial Thoughts 💭
- The problem can be solved by maintaining separate scores for even and odd parities as we iterate through the array.
- I will track the maximum score for both even and odd parities as I move through the array.
{{< dots >}}
### Edge Cases 🌐
- Input: []. Output: 0 (empty array should not be a valid input, but could return 0 if handled).
- Input: A large array with 10^5 elements. The solution should work within time limits.
- Input: All numbers are the same. The result will be the sum of all numbers.
- The solution should run efficiently for up to 10^5 elements.
{{< dots >}}
## Code 💻
```cpp
long long maxScore(vector<int>& n, int x) {
    long long eve = n[0] - (n[0] % 2 ? x : 0);
    long long odd = n[0] - (n[0] % 2 ? 0 : x);
    for (int i = 1; i < n.size(); ++i)
        if (n[i] % 2)   odd = n[i] + max(odd, eve - x);
        else            eve = n[i] + max(eve, odd - x);
    return max(eve, odd);
}
```

This function calculates the maximum score for a sequence of integers `n` while alternating between adding or subtracting a value `x` based on whether the integer is even or odd. The two scores, `eve` and `odd`, track the scores depending on whether the last element was even or odd.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long maxScore(vector<int>& n, int x) {
	```
	The function `maxScore` is declared, taking a vector `n` of integers and an integer `x` as inputs. It returns a long long value, representing the maximum score that can be achieved.

2. **Variable Initialization**
	```cpp
	    long long eve = n[0] - (n[0] % 2 ? x : 0);
	```
	The variable `eve` is initialized to the first element of the array `n`. If the element is odd, it subtracts `x`; if the element is even, no subtraction occurs.

3. **Variable Initialization**
	```cpp
	    long long odd = n[0] - (n[0] % 2 ? 0 : x);
	```
	Similarly, the variable `odd` is initialized to the first element of `n`. If the element is even, it subtracts `x`; if the element is odd, no subtraction occurs.

4. **Loop Initialization**
	```cpp
	    for (int i = 1; i < n.size(); ++i)
	```
	A for loop is initialized starting from index 1 to iterate through the elements of the vector `n` from the second element onward.

5. **Odd Case Calculation**
	```cpp
	        if (n[i] % 2)   odd = n[i] + max(odd, eve - x);
	```
	If the current element `n[i]` is odd (i.e., `n[i] % 2` evaluates to true), the `odd` variable is updated. It takes the maximum of the current `odd` value and the `eve` value minus `x`, then adds the current element `n[i]`.

6. **Even Case Calculation**
	```cpp
	        else            eve = n[i] + max(eve, odd - x);
	```
	If the current element `n[i]` is even, the `eve` variable is updated by adding the maximum of the current `eve` value and the `odd` value minus `x`.

7. **Returning Result**
	```cpp
	    return max(eve, odd);
	```
	After the loop finishes, the function returns the maximum of the `eve` and `odd` scores, which represents the highest achievable score after considering all elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear since we only iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need to store two variables for tracking scores.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/)

---
{{< youtube JtogyeIxGWE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
