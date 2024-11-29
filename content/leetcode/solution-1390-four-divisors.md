
+++
authors = ["grid47"]
title = "Leetcode 1390: Four Divisors"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1390: Four Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given an integer array nums, find the sum of divisors of all integers in that array that have exactly four divisors. If there are no such integers, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array nums.
- **Example:** `For nums = [21, 7, 6, 35], the output is 92.`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of divisors of the numbers that have exactly four divisors.
- **Example:** `For nums = [21, 7, 6, 35], the output is 92.`
- **Constraints:**
	- If no number has exactly four divisors, return 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find numbers with exactly four divisors and sum those divisors.

- 1. Loop through each number in nums.
- 2. For each number, find its divisors.
- 3. Check if the number has exactly four divisors.
- 4. If so, sum those divisors and add to the final sum.
- 5. Return the final sum after processing all numbers.
{{< dots >}}
### Problem Assumptions ✅
- You can assume that the input will always be valid.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [21, 7, 6, 35], the divisors of 21 are [1, 3, 7, 21] (exactly 4), and the divisors of 6 are [1, 2, 3, 6] (exactly 4). The sum of divisors is 92.`  \
  **Explanation:** We only consider numbers with exactly four divisors. For each such number, we calculate and sum the divisors.

{{< dots >}}
## Approach 🚀
To solve the problem, for each number in the array, find its divisors and check if it has exactly four divisors. If so, add the sum of its divisors to the final result.

### Initial Thoughts 💭
- We need an efficient way to find divisors for large numbers.
- Iterating through each number and finding its divisors up to the square root of the number can help minimize time complexity.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty.
- The algorithm must handle arrays of size up to 10^4 and values up to 10^5.
- If no number has exactly four divisors, return 0.
- Consider the upper bounds when finding divisors efficiently.
{{< dots >}}
## Code 💻
```cpp

int sumFourDivisors(vector<int>& nums) {
    
    int sum = 0;
    
    for(auto n: nums) {
        int d = 0;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                if(d == 0) {
                    d = i;
                } else {
                    d = 0;
                    break;
                }
            }
        }
        if(d > 0 && d != n/d) {
            sum += 1 + n + d + n/d;
        }            
    }
    return sum;
}
```

The function `sumFourDivisors` calculates the sum of the divisors of each number in the `nums` array, only if the number has exactly four divisors. The function uses nested loops to find divisors and checks if a number has exactly four divisors before summing them.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumFourDivisors(vector<int>& nums) {
	```
	Define the function `sumFourDivisors`, which takes a vector of integers `nums` and returns the sum of divisors for numbers with exactly four divisors.

2. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initialize the variable `sum` to 0. This will hold the running total of divisors for the numbers in `nums`.

3. **Loop**
	```cpp
	    for(auto n: nums) {
	```
	Start a loop to iterate over each number `n` in the `nums` array.

4. **Variable Initialization**
	```cpp
	        int d = 0;
	```
	Initialize the variable `d` to 0. This will track the divisor of `n` while checking for exactly four divisors.

5. **Nested Loop**
	```cpp
	        for(int i = 2; i * i <= n; i++) {
	```
	Start a loop to iterate through potential divisors `i` starting from 2, going up to the square root of `n`.

6. **Divisor Check**
	```cpp
	            if(n % i == 0) {
	```
	Check if `i` is a divisor of `n`.

7. **Divisor Assignment**
	```cpp
	                if(d == 0) {
	```
	If this is the first divisor found, assign `i` to `d`.

8. **Divisor Reset**
	```cpp
	                    d = i;
	```
	Assign `i` to `d` as the first divisor of `n`.

9. **Divisor Conflict**
	```cpp
	                } else {
	```
	If a second divisor is found, reset `d` to 0 and break the loop.

10. **Reset Divisor**
	```cpp
	                    d = 0;
	```
	Reset `d` to 0, indicating that the number has more than two divisors, so it won't have exactly four divisors.

11. **Break Loop**
	```cpp
	                    break;
	```
	Exit the loop since more than two divisors have been found.

12. **Divisor Validation**
	```cpp
	        if(d > 0 && d != n/d) {
	```
	Check if exactly four divisors are found: `d` and `n/d` must be distinct, and `d` must be greater than 0.

13. **Sum Calculation**
	```cpp
	            sum += 1 + n + d + n/d;
	```
	If the number has exactly four divisors, add them to the `sum`. The divisors are `1`, `n`, `d`, and `n/d`.

14. **Return Statement**
	```cpp
	    return sum;
	```
	Return the final sum of divisors for all numbers with exactly four divisors.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * sqrt(m))
- **Average Case:** O(n * sqrt(m))
- **Worst Case:** O(n * sqrt(m))

The time complexity is O(n * sqrt(m)) where n is the length of the array and m is the largest value in nums.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/four-divisors/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
