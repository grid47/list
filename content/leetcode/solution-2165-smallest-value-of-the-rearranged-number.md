
+++
authors = ["grid47"]
title = "Leetcode 2165: Smallest Value of the Rearranged Number"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2165: Smallest Value of the Rearranged Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fe3yn96MAoI"
youtube_upload_date="2022-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fe3yn96MAoI/maxresdefault.webp"
comments = true
+++



---
You are given an integer 'num'. Your task is to rearrange the digits of 'num' such that its value is minimized, with the constraint that the number must not contain any leading zeros. The sign of the number should not change after rearranging the digits.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer 'num'.
- **Example:** `num = 210`
- **Constraints:**
	- -1015 <= num <= 1015

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number formed by rearranging the digits of 'num' to get the smallest possible value without leading zeros and keeping the sign unchanged.
- **Example:** `102`
- **Constraints:**
	- The rearranged number must not contain leading zeros.

{{< dots >}}
### Core Logic 🔍
**Goal:** Rearrange the digits to form the smallest number while respecting the leading zero constraint.

- Convert the number to a string and extract the digits.
- Sort the digits in non-decreasing order for positive numbers and non-increasing order for negative numbers.
- Ensure no leading zeros by swapping the first non-zero digit to the front if the number is positive.
{{< dots >}}
### Problem Assumptions ✅
- The input number 'num' is always within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: num = 210`  \
  **Explanation:** The digits [2, 1, 0] can be rearranged to form [1, 0, 2]. Since we cannot have leading zeros, the smallest possible value is 102.

- **Input:** `Example 2: num = -4306`  \
  **Explanation:** The digits [4, 3, 0, 6] for the negative number can be rearranged to form -6430, which is the smallest value without leading zeros.

{{< dots >}}
## Approach 🚀
The approach involves sorting the digits of the number based on whether it's positive or negative, and then ensuring the result has no leading zeros.

### Initial Thoughts 💭
- For positive numbers, sorting the digits in non-decreasing order should yield the smallest number.
- For negative numbers, sorting the digits in non-increasing order should yield the smallest value.
- We must carefully handle the case where leading zeros could be produced.
{{< dots >}}
### Edge Cases 🌐
- The number is never empty as it is always a valid integer within the constraints.
- The solution must handle large numbers within the range of -1015 to 1015.
- The input number may have a single digit or multiple identical digits.
- The solution must work efficiently within the given constraints of -1015 <= num <= 1015.
{{< dots >}}
## Code 💻
```cpp
long long smallestNumber(long long num) {
    auto s = to_string(abs(num));
    sort(s.begin(), s.end(), [&](char a, char b){
        return num > 0? a < b: b < a;
    });
    if(num > 0)
    swap(s[0], s[s.find_first_not_of('0')]);
    return stoll(s) * (num < 0? -1: 1);
}
```

This function returns the smallest possible number that can be formed by the digits of the input number. It handles both positive and negative numbers, adjusting for zero-padding when needed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long smallestNumber(long long num) {
	```
	This is the function declaration where we define a function 'smallestNumber' that takes a long long integer as input and returns a long long integer.

2. **Variable Initialization**
	```cpp
	    auto s = to_string(abs(num));
	```
	The absolute value of the input number is converted to a string and stored in the variable 's'. This is to manipulate the digits of the number.

3. **Sorting Logic**
	```cpp
	    sort(s.begin(), s.end(), [&](char a, char b){
	```
	The string 's' is sorted based on the value of the original number, in ascending order for positive numbers, and descending order for negative numbers.

4. **Sorting Condition**
	```cpp
	        return num > 0? a < b: b < a;
	```
	If the number is positive, the digits are sorted in ascending order; otherwise, they are sorted in descending order.

5. **Zero Handling**
	```cpp
	    if(num > 0)
	```
	If the number is positive, this block of code handles the case where the smallest non-zero digit needs to be swapped to the first position.

6. **Zero Padding Fix**
	```cpp
	    swap(s[0], s[s.find_first_not_of('0')]);
	```
	This swaps the first digit of the string with the first non-zero digit to avoid leading zeros.

7. **Final Conversion**
	```cpp
	    return stoll(s) * (num < 0? -1: 1);
	```
	The string is converted back to a long long integer, and the sign of the number is adjusted accordingly for negative inputs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity of sorting the digits is O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We need O(n) space for storing the digits of the number.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/)

---
{{< youtube fe3yn96MAoI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
