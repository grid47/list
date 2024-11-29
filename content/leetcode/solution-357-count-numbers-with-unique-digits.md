
+++
authors = ["grid47"]
title = "Leetcode 357: Count Numbers with Unique Digits"
date = "2024-10-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 357: Count Numbers with Unique Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/357.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/357.webp" 
    alt="A sequence of numbers with each unique digit softly illuminated, showing how many unique digits are present."
    caption="Solution to LeetCode 357: Count Numbers with Unique Digits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, return the count of all numbers with unique digits x, such that 0 <= x < 10^n.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer n, where 0 <= n <= 8.
- **Example:** `n = 3`
- **Constraints:**
	- 0 <= n <= 8

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the count of numbers with unique digits in the range 0 <= x < 10^n.
- **Example:** `Input: n = 3
Output: 739`
- **Constraints:**
	- The output should be the total number of valid numbers with unique digits.

{{< dots >}}
### Core Logic 🔍
**Goal:** To count all the numbers from 0 to 10^n-1 that have unique digits.

- Start with the total valid numbers for n=1 (which is 10).
- Iterate for each subsequent value of n and compute the number of unique digit numbers for that value.
- For each n, reduce the available digits and multiply by the previous number of unique digits to get the total count.
{{< dots >}}
### Problem Assumptions ✅
- The number of digits n is small enough that the approach of reducing the available digits and multiplying is efficient.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3
Output: 739`  \
  **Explanation:** For n = 3, the total numbers in the range of 0 to 999 excluding numbers with repeated digits (such as 11, 22, etc.) is 739.

{{< dots >}}
## Approach 🚀
We will iterate through the possible numbers of digits and calculate the count of numbers with unique digits using combinatorics.

### Initial Thoughts 💭
- The numbers with unique digits are formed by selecting distinct digits from the available pool of digits (0-9).
- We can count how many numbers have unique digits for each number of digits from 1 to n using a decrementing approach.
{{< dots >}}
### Edge Cases 🌐
- When n = 0, the answer should be 1, as there is only one number: 0.
- When n = 8, the result needs to be computed efficiently using the combinatorial approach.
- If n = 1, the result should be 10 (the numbers 0-9).
- Ensure the solution handles n values from 0 to 8.
{{< dots >}}
## Code 💻
```cpp
class Solution {
public int countNumbersWithUniqueDigits(int n) {
    if(n == 0) return 1;
    
    int res = 10;
    int available = 9;
    int unqNums = 9;
    
    while(n-- > 1 && available > 0) {
        unqNums = unqNums * available;
        res += unqNums;
        available--;
    }
    return res;
}
```

This code defines a function `countNumbersWithUniqueDigits` which calculates how many numbers can be formed with unique digits for a given number of digits n. It handles the case where n = 0 separately, returning 1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	This line begins the declaration of the `Solution` class, which contains the method `countNumbersWithUniqueDigits`.

2. **Method Declaration**
	```cpp
	public int countNumbersWithUniqueDigits(int n) {
	```
	This is the declaration of the method `countNumbersWithUniqueDigits`, which takes an integer `n` as input and returns an integer representing the number of unique digit numbers that can be formed.

3. **Conditional Check**
	```cpp
	    if(n == 0) return 1;
	```
	This line checks if `n` is zero, and if so, it returns 1, as there is only one number (0) with zero digits.

4. **Variable Initialization**
	```cpp
	    int res = 10;
	```
	Initializes the variable `res` to 10, which accounts for the numbers with one digit (0-9).

5. **Variable Initialization**
	```cpp
	    int available = 9;
	```
	Initializes the variable `available` to 9, which represents the number of available digits (1-9) for the next digit in multi-digit numbers.

6. **Variable Initialization**
	```cpp
	    int unqNums = 9;
	```
	Initializes the variable `unqNums` to 9, which represents the number of possible unique digits for the next digit.

7. **Variable Initialization**
	```cpp
	    
	```
	This is a placeholder for a blank line or spacing for readability.

8. **Loop Declaration**
	```cpp
	    while(n-- > 1 && available > 0) {
	```
	This is a `while` loop that continues as long as `n` is greater than 1 and there are available digits to use. It iterates through each digit position.

9. **Variable Assignment**
	```cpp
	        unqNums = unqNums * available;
	```
	Multiplies the `unqNums` variable by the number of available digits for the next digit, updating the possible unique numbers.

10. **Variable Update**
	```cpp
	        res += unqNums;
	```
	Adds the newly calculated `unqNums` value to `res`, which keeps track of the total number of unique numbers formed.

11. **Variable Update**
	```cpp
	        available--;
	```
	Decreases the `available` variable by 1, as one less digit is available for use in the next digit position.

12. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total number of unique digit numbers (`res`) after completing the loop.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) when n = 0.
- **Average Case:** O(n) for values of n up to 8, where the time complexity increases linearly with the value of n.
- **Worst Case:** O(8) since n is capped at 8.

The solution iterates up to n times, where n is at most 8.

### Space Complexity 💾
- **Best Case:** O(1) when n = 0.
- **Worst Case:** O(1) as the space complexity is constant and only a few variables are used.

Space complexity is constant as we only store a few variables for calculation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-numbers-with-unique-digits/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
