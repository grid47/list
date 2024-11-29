
+++
authors = ["grid47"]
title = "Leetcode 202: Happy Number"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 202: Happy Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/202.webp"
youtube = "4IroNy8fmNA"
youtube_upload_date="2022-06-25"
youtube_thumbnail="https://i.ytimg.com/vi/4IroNy8fmNA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/202.webp" 
    alt="A glowing number slowly transforming into a smiley face, symbolizing happiness and positivity."
    caption="Solution to LeetCode 202: Happy Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
A happy number is a number that eventually reaches 1 when replaced by the sum of the squares of its digits. If the process results in an endless loop of numbers, the number is not happy. Your task is to determine whether a given number is a happy number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a positive integer n, where 1 <= n <= 231 - 1.
- **Example:** `n = 23`
- **Constraints:**
	- 1 <= n <= 231 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the number n is a happy number, otherwise return false.
- **Example:** `Output: false`
- **Constraints:**
	- The output should be a boolean value indicating whether the number is happy or not.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the number n becomes 1 by repeatedly replacing it with the sum of the squares of its digits, or if it falls into an endless loop.

- Create a helper function to calculate the sum of the squares of the digits of a number.
- Use the Floyd's Cycle detection algorithm (also known as the slow and fast pointers technique) to detect if the number falls into a cycle. If the number becomes 1, it's happy, otherwise it's not.
{{< dots >}}
### Problem Assumptions ✅
- The input number is always a valid positive integer within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 19`  \
  **Explanation:** In this case, the sum of the squares of digits is 12 + 92 = 82, then 82 + 22 = 68, then 62 + 82 = 100, and 12 + 02 + 02 = 1. Since the number eventually reaches 1, it's a happy number.

- **Input:** `n = 2`  \
  **Explanation:** For n = 2, the sum of the squares of digits is 4, then 4 becomes 16, then 37, and so on. Since it falls into a cycle, it is not a happy number.

{{< dots >}}
## Approach 🚀
To determine if a number is happy, we use the process of repeatedly replacing the number by the sum of the squares of its digits. If the number eventually reaches 1, it's happy. If it falls into a cycle, it's not.

### Initial Thoughts 💭
- A brute force approach of tracking the numbers could be inefficient due to the potential for cycles.
- Using the Floyd's Cycle detection method is an optimal approach to detect cycles.
- Using slow and fast pointers will allow us to detect a cycle in linear time, improving efficiency.
{{< dots >}}
### Edge Cases 🌐
- Since n is always a positive integer, there will be no empty inputs.
- For large values of n, the approach should work efficiently due to the cycle detection method.
- The value n = 1 is trivially a happy number since it stays at 1.
- The solution should handle all valid inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
int sqr(int n) {
    int res = 0;
    while(n) {
        int tmp = n % 10;
        res += tmp * tmp;
        n = n / 10;
    }
    return res;
}
bool isHappy(int n) {
    int slow = n;
    int fast = n;
    do {
        slow = sqr(slow);
        fast = sqr(sqr(fast));
    } while(slow != fast);
    return slow == 1;
}
```

This code solves the Happy Number problem by calculating the sum of squares of digits repeatedly. The function `sqr` calculates the sum of squares of digits for a number, while `isHappy` checks if a number is happy by using the Floyd's Cycle-Finding Algorithm (Tortoise and Hare) to detect cycles.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sqr(int n) {
	```
	Define the function `sqr` that calculates the sum of squares of digits for a given integer.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize a variable `res` to store the sum of the squares of the digits.

3. **While Loop Condition**
	```cpp
	    while(n) {
	```
	Start a while loop that continues until `n` becomes 0. This will process each digit of `n`.

4. **Extract Last Digit**
	```cpp
	        int tmp = n % 10;
	```
	Extract the last digit of `n` using the modulus operator.

5. **Sum of Squares of Digits**
	```cpp
	        res += tmp * tmp;
	```
	Square the extracted digit and add it to `res`.

6. **Remove Last Digit**
	```cpp
	        n = n / 10;
	```
	Remove the last digit of `n` by performing integer division by 10.

7. **Return Result**
	```cpp
	    return res;
	```
	Return the sum of the squares of the digits stored in `res`.

8. **Function Definition**
	```cpp
	bool isHappy(int n) {
	```
	Define the `isHappy` function which checks if a number `n` is a happy number by using the Tortoise and Hare algorithm.

9. **Variable Initialization**
	```cpp
	    int slow = n;
	```
	Initialize `slow` pointer to `n`. It will move one step at a time.

10. **Variable Initialization**
	```cpp
	    int fast = n;
	```
	Initialize `fast` pointer to `n`. It will move two steps at a time.

11. **Do While Loop**
	```cpp
	    do {
	```
	Start a do-while loop to calculate the sum of squares of digits for `slow` and `fast` until they meet.

12. **Slow Pointer Update**
	```cpp
	        slow = sqr(slow);
	```
	Move the `slow` pointer by calculating the sum of squares of its digits using the `sqr` function.

13. **Fast Pointer Update**
	```cpp
	        fast = sqr(sqr(fast));
	```
	Move the `fast` pointer by calculating the sum of squares of its digits twice (two steps).

14. **Loop Condition**
	```cpp
	    } while(slow != fast);
	```
	Repeat the loop until `slow` and `fast` pointers meet. If they meet at 1, the number is happy.

15. **Check if Happy**
	```cpp
	    return slow == 1;
	```
	Return true if `slow` equals 1, indicating that `n` is a happy number. Otherwise, return false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(n))
- **Average Case:** O(log(n))
- **Worst Case:** O(log(n))

The time complexity is logarithmic due to the number of digits in the number n and the cycle detection method.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we are only using a few variables for the pointers and digit calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/happy-number/description/)

---
{{< youtube 4IroNy8fmNA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
