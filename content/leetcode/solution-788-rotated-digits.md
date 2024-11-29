
+++
authors = ["grid47"]
title = "Leetcode 788: Rotated Digits"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 788: Rotated Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/788.webp"
youtube = "QOQL3S2BHPs"
youtube_upload_date="2020-02-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QOQL3S2BHPs/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/788.webp" 
    alt="A set of digits where the rotated digits are found, glowing softly as the valid rotations are made."
    caption="Solution to LeetCode 788: Rotated Digits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, find how many integers in the range [1, n] are 'good' integers. A number is considered 'good' if after rotating each of its digits by 180 degrees, it becomes a valid different number. The rotation rules for digits are as follows: 0, 1, and 8 stay the same, 2 and 5 swap places, 6 and 9 swap places, and other digits are not valid when rotated.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n representing the upper bound of the range. You need to check for all integers from 1 to n which are 'good'.
- **Example:** `n = 15`
- **Constraints:**
	- 1 <= n <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the count of 'good' integers between 1 and n, inclusive.
- **Example:** `Output: 6`
- **Constraints:**
	- The output will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine how many integers in the range [1, n] are 'good' by rotating their digits and ensuring the result is a valid, different number.

- For each number in the range [1, n], break the number into its individual digits.
- For each digit, check if its rotation results in a valid number (refer to the rotation rules).
- If the number becomes valid and different from the original, count it as 'good'.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that the input number is valid and within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 10`  \
  **Explanation:** The integers from 1 to 10 include 2, 5, 6, and 9, which are the 'good' numbers. Other numbers remain unchanged after rotation.

- **Input:** `Input: n = 1`  \
  **Explanation:** The only integer in the range is 1, which remains unchanged after rotation. Therefore, the count of 'good' integers is 0.

- **Input:** `Input: n = 15`  \
  **Explanation:** The 'good' integers in this range are 2, 5, 6, 9, 10, 11, 12, 15. Therefore, the output will be 6.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate through each integer from 1 to n and check if rotating its digits results in a valid and different number. We can map each digit to its rotated counterpart and verify whether the number changes or not.

### Initial Thoughts 💭
- We need to check each digit of the number and ensure it can be rotated into another valid digit.
- The main challenge is checking each digit of the number and ensuring that the rotated version is different from the original number.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since n is always a valid integer.
- For large inputs up to 10^4, ensure the algorithm runs efficiently by iterating through all numbers from 1 to n.
- If n is very small (like 1 or 2), check that the edge cases are handled correctly.
- Ensure the solution works within the provided constraints (1 <= n <= 10^4).
{{< dots >}}
## Code 💻
```cpp
int rotatedDigits(int n) {
    int f[] = {1,1,2,0,0,2,2,0,1,2};
    int res = 0;
    for(int i = 0; i <= n; i++) {
        int p = i;
        int s = 1;
        while(p) {
            s *= f[p%10];
            p /= 10;
        }
        if (s >= 2) res +=1;
    }        
    return res;
}
```

This function counts the numbers between 1 and n whose digits, when rotated 180 degrees, are valid digits. It uses a predefined mapping for each digit to determine if the rotated number is valid.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int rotatedDigits(int n) {
	```
	This is the function definition for 'rotatedDigits', where 'n' is the upper limit for the range of numbers to check.

2. **Array Initialization**
	```cpp
	    int f[] = {1,1,2,0,0,2,2,0,1,2};
	```
	An array 'f' is initialized to represent the valid transformations for each digit. Digits 0, 1, 8 are valid and map to themselves, while digits 2, 5, 6, 9 are valid and map to each other.

3. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	The variable 'res' is initialized to count the number of valid numbers.

4. **Loop**
	```cpp
	    for(int i = 0; i <= n; i++) {
	```
	A loop is set to iterate from 0 to 'n' to check all numbers in this range.

5. **Variable Assignment**
	```cpp
	        int p = i;
	```
	The current number 'i' is stored in variable 'p' to process its digits.

6. **Variable Initialization**
	```cpp
	        int s = 1;
	```
	The variable 's' is initialized to 1. This will track the validity of the digits as they are processed.

7. **Loop**
	```cpp
	        while(p) {
	```
	This while loop processes each digit of the number 'p' one by one.

8. **Digit Processing**
	```cpp
	            s *= f[p%10];
	```
	This line checks the validity of the current digit by looking it up in the array 'f'. If the digit is invalid, 's' will become 0, marking the number as invalid.

9. **Digit Reduction**
	```cpp
	            p /= 10;
	```
	The number 'p' is reduced by removing its last digit, preparing for the next iteration.

10. **Condition Check**
	```cpp
	        if (s >= 2) res +=1;
	```
	If 's' is greater than or equal to 2, it means the number is valid after rotation, and the result counter 'res' is incremented.

11. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the total count of valid numbers after checking all numbers from 0 to 'n'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the input number.
- **Average Case:** O(n * d), where d is the average number of digits in the numbers from 1 to n.
- **Worst Case:** O(n * d), where n is up to 10^4 and d is the number of digits in the largest number.

The time complexity is linear in terms of the number of integers to check, with an additional factor of d for processing each digit.

### Space Complexity 💾
- **Best Case:** O(1), if no additional space is required beyond the iteration.
- **Worst Case:** O(d), where d is the number of digits in the largest number (since we store the digits of the number).

The space complexity is constant for each number, only requiring space for storing its digits during the check.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rotated-digits/description/)

---
{{< youtube QOQL3S2BHPs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
