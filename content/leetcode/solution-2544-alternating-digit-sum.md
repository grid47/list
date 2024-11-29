
+++
authors = ["grid47"]
title = "Leetcode 2544: Alternating Digit Sum"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2544: Alternating Digit Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "IFRYDmhEWGw"
youtube_upload_date="2023-01-22"
youtube_thumbnail="https://i.ytimg.com/vi/IFRYDmhEWGw/maxresdefault.jpg"
comments = true
+++



---
You are given a positive integer n. Each digit of n has a sign according to the following rules: The most significant digit is assigned a positive sign. Each other digit has an opposite sign to its adjacent digits. Return the sum of all digits with their corresponding sign.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a positive integer n.
- **Example:** `n = 324`
- **Constraints:**
	- 1 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of all digits with their corresponding signs.
- **Example:** `1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the sum of the digits of the integer n, where each digit has a sign based on its position.

- 1. Extract each digit from the number n, starting from the least significant to the most significant.
- 2. Alternate the sign for each digit based on its position.
- 3. Compute the sum of the digits, considering their corresponding signs.
{{< dots >}}
### Problem Assumptions ✅
- The input number n is a positive integer.
- The number has at least one digit.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 324`  \
  **Explanation:** For n = 324, the sum is (+3) + (-2) + (+4) = 1.

- **Input:** `n = 101`  \
  **Explanation:** For n = 101, the sum is (+1) + (-0) + (+1) = 2.

{{< dots >}}
## Approach 🚀
The approach is to alternate the signs of the digits in the number and compute their sum.

### Initial Thoughts 💭
- The problem asks us to sum digits with alternating signs based on their position.
- This is a straightforward problem of alternating signs and summing values.
- We can extract digits one by one and alternate their signs using a simple loop.
{{< dots >}}
### Edge Cases 🌐
- The input is always a positive integer, so no need to handle empty inputs.
- Handle inputs where n is close to the upper constraint of 10^9.
- Handle cases where all digits are the same, such as n = 111.
- The algorithm should run efficiently even for large numbers up to 10^9.
{{< dots >}}
## Code 💻
```cpp
int alternateDigitSum(int n) {
    int sum = 0;
    int sgn = 1;
    while(n) {
        sum += sgn * (n % 10);
        n /= 10;
        sgn *= -1;
    }
    return sgn == -1? sum : -sum;
}
```

This function calculates the alternating digit sum of an integer by adding and subtracting the digits of the number in an alternating pattern, starting with addition.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int alternateDigitSum(int n) {
	```
	The function 'alternateDigitSum' is defined to compute the alternating sum of digits of an integer 'n'.

2. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	The variable 'sum' is initialized to zero. This will accumulate the alternating sum of the digits.

3. **Variable Initialization**
	```cpp
	    int sgn = 1;
	```
	The variable 'sgn' is initialized to 1. This will help alternate the sign (positive or negative) for each digit in the number.

4. **Loop Setup**
	```cpp
	    while(n) {
	```
	A while loop is initiated to iterate over the digits of the integer 'n'. The loop will continue until all digits are processed.

5. **Digit Extraction and Summing**
	```cpp
	        sum += sgn * (n % 10);
	```
	The last digit of 'n' (n % 10) is multiplied by 'sgn' (which alternates between 1 and -1) and added to 'sum'.

6. **Digit Removal**
	```cpp
	        n /= 10;
	```
	The last digit of 'n' is removed by dividing it by 10, effectively shifting to the next digit.

7. **Sign Alternation**
	```cpp
	        sgn *= -1;
	```
	The sign alternator 'sgn' is multiplied by -1 to switch between adding and subtracting for the next digit.

8. **Return Statement**
	```cpp
	    return sgn == -1? sum : -sum;
	```
	Once the loop is complete, the function returns the sum. If 'sgn' is -1, the sum is returned as is; otherwise, it is negated to account for the final sign.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(d), where d is the number of digits in n.
- **Average Case:** O(d), where d is the number of digits in n.
- **Worst Case:** O(d), where d is the number of digits in n.

The time complexity is O(d), where d is the number of digits in n (which is log(n) with respect to the input number).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we only use a fixed amount of space for the sum and a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/alternating-digit-sum/description/)

---
{{< youtube IFRYDmhEWGw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
