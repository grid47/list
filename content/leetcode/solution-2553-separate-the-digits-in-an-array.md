
+++
authors = ["grid47"]
title = "Leetcode 2553: Separate the Digits in an Array"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2553: Separate the Digits in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wr1TK3mDUVY"
youtube_upload_date="2023-02-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wr1TK3mDUVY/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` consisting of positive integers. Your task is to return a new array where each integer from `nums` is separated into its individual digits, while maintaining the order of the integers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `nums` where each element is a positive integer.
- **Example:** `nums = [14, 39, 58, 60]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element contains the digits of the integers from `nums`, separated in the same order.
- **Example:** `[1, 4, 3, 9, 5, 8, 6, 0]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To break down each integer into its individual digits and return them in the same order.

- 1. For each number in `nums`, extract its digits by repeatedly dividing it by 10 and taking the remainder.
- 2. Store the digits of each number in a new list.
- 3. Append the digits of each number to the final result in order.
{{< dots >}}
### Problem Assumptions ✅
- All numbers in `nums` are positive integers.
- Each number in `nums` can have up to 5 digits.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [14, 39, 58, 60]`  \
  **Explanation:** In this example, we separate each number into its digits and return the combined result as [1, 4, 3, 9, 5, 8, 6, 0].

- **Input:** `nums = [3, 7, 1, 2]`  \
  **Explanation:** Since all the numbers in `nums` are single digits, the output remains [3, 7, 1, 2].

{{< dots >}}
## Approach 🚀
The goal is to convert each integer in `nums` into its constituent digits and return them in the same order.

### Initial Thoughts 💭
- We need to handle each number separately, extract its digits, and concatenate them in the order of appearance.
- The task can be accomplished by repeatedly dividing each number by 10 to get its digits in reverse order and then reversing them.
{{< dots >}}
### Edge Cases 🌐
- The array `nums` will always have at least one element, as per the constraints.
- The solution must handle arrays up to 1000 integers and each integer up to 10^5.
- Single-digit integers in `nums` should be handled as-is.
- Ensure the solution works efficiently for the upper limits of input size and integer value.
{{< dots >}}
## Code 💻
```cpp
vector<int> separateDigits(vector<int>& nums) {
    vector<int> ans;
    
    for(auto x: nums) {
        vector<int> tmp;
        while(x) {
            tmp.push_back(x % 10);
            x /= 10;
        }
        while(!tmp.empty()) {
            ans.push_back(tmp.back());
            tmp.pop_back();
        }
    }
    return ans;
}
```

This function 'separateDigits' takes a vector of integers 'nums' and separates each number's digits into individual elements of a new vector. It uses a helper vector 'tmp' to reverse the digits and ensures the digits of each number are appended in the correct order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> separateDigits(vector<int>& nums) {
	```
	This is the function definition for 'separateDigits'. It accepts a vector of integers, 'nums', and will return a vector containing all the digits from the numbers in 'nums'.

2. **Variable Initialization**
	```cpp
	    vector<int> ans;
	```
	Here, a vector 'ans' is initialized to store the final result, which will contain the separated digits from all the numbers in the input vector 'nums'.

3. **Loop Through Input**
	```cpp
	    for(auto x: nums) {
	```
	This is a for-loop that iterates through each number in the input vector 'nums'. The variable 'x' represents each individual number.

4. **Temporary Vector Initialization**
	```cpp
	        vector<int> tmp;
	```
	For each number 'x', a temporary vector 'tmp' is initialized to store the digits of the current number in reverse order.

5. **Extract Digits**
	```cpp
	        while(x) {
	```
	This while-loop runs as long as 'x' is not zero. It extracts each digit from the number by using modulo 10 and stores it in 'tmp'.

6. **Push Back Digit**
	```cpp
	            tmp.push_back(x % 10);
	```
	This line extracts the last digit of 'x' using modulo 10 and adds it to the 'tmp' vector.

7. **Divide Number**
	```cpp
	            x /= 10;
	```
	This divides 'x' by 10, effectively removing the last digit from the number for the next iteration.

8. **Reverse Digits to Final Vector**
	```cpp
	        while(!tmp.empty()) {
	```
	This while-loop runs as long as 'tmp' is not empty, effectively reversing the digits that were collected in 'tmp'.

9. **Push Back Reversed Digits**
	```cpp
	            ans.push_back(tmp.back());
	```
	This line takes the last digit from 'tmp' (which is the first digit of the original number) and adds it to the 'ans' vector.

10. **Pop Back Reversed Digits**
	```cpp
	            tmp.pop_back();
	```
	This removes the last digit from 'tmp' after it has been added to 'ans', preparing for the next digit.

11. **Return Final Result**
	```cpp
	    return ans;
	```
	The function returns the 'ans' vector, which now contains all the digits from the numbers in 'nums', each digit separated in the correct order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where `n` is the number of elements in `nums`.
- **Average Case:** O(n * m), where `n` is the number of elements and `m` is the maximum number of digits in any number.
- **Worst Case:** O(n * m), where `n` is the number of elements and `m` is the maximum number of digits in any number.

The time complexity depends on the total number of digits across all numbers in the array.

### Space Complexity 💾
- **Best Case:** O(n), where `n` is the number of elements in `nums`.
- **Worst Case:** O(n * m), where `n` is the number of elements in `nums` and `m` is the maximum number of digits in any number.

The space complexity is determined by the space required to store the digits of all numbers in `nums`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/separate-the-digits-in-an-array/description/)

---
{{< youtube wr1TK3mDUVY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
