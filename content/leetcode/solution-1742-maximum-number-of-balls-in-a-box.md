
+++
authors = ["grid47"]
title = "Leetcode 1742: Maximum Number of Balls in a Box"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1742: Maximum Number of Balls in a Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "bRjEkQZ1R7Y"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/bRjEkQZ1R7Y/maxresdefault.jpg"
comments = true
+++



---
You are working in a ball factory with `n` balls numbered from `lowLimit` to `highLimit` (inclusive). You have an infinite number of boxes numbered from 1 to infinity. Your task is to place each ball into the box where the box number equals the sum of the digits of the ball's number. For example, a ball numbered 321 will go into box 6 (since 3 + 2 + 1 = 6), and a ball numbered 10 will go into box 1 (since 1 + 0 = 1). The goal is to find the box with the most balls and return the number of balls in that box.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers `lowLimit` and `highLimit`, which represent the range of ball numbers.
- **Example:** `Input: lowLimit = 15, highLimit = 25`
- **Constraints:**
	- 1 <= lowLimit <= highLimit <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of balls in any box.
- **Example:** `Output: 3`
- **Constraints:**
	- The ball numbers are between 1 and 100,000.

{{< dots >}}
### Core Logic 🔍
**Goal:** To place balls into boxes based on the sum of digits of the ball numbers and find the box with the most balls.

- 1. For each ball number, calculate the sum of its digits.
- 2. Track how many balls are placed into each box using an array.
- 3. Find the maximum count from the array and return it.
{{< dots >}}
### Problem Assumptions ✅
- The ball numbers are valid integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: lowLimit = 15, highLimit = 25`  \
  **Explanation:** For the numbers 15 through 25, the sum of digits for each ball is calculated, and the balls are placed into their respective boxes. The box with the most balls contains 3 balls.

- **Input:** `Input: lowLimit = 30, highLimit = 40`  \
  **Explanation:** For the numbers 30 through 40, the sum of digits for each ball is calculated, and the ball count in each box is tracked. Box 3 has the most balls.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the ball numbers, calculating the sum of their digits, and storing the count of balls in each corresponding box.

### Initial Thoughts 💭
- The sum of digits function is straightforward to implement for each ball number.
- We can use an array to track how many balls are placed in each box.
- The solution will need to handle up to 100,000 ball numbers efficiently, so the operations need to be optimized.
{{< dots >}}
### Edge Cases 🌐
- This case is not applicable as `lowLimit` and `highLimit` are always at least 1.
- Ensure that the solution handles the maximum possible input size (lowLimit = 1, highLimit = 100000) efficiently.
- Consider cases where the sum of digits leads to many balls being placed in the same box.
- The algorithm should efficiently handle input sizes up to 100,000.
{{< dots >}}
## Code 💻
```cpp
int countBalls(int lowLimit, int highLimit) {
    
    vector<int> box (46,0);
    for(int i = lowLimit;i<=highLimit;i++)
    {
        int sum = 0;
        int temp = i;
        while(temp)
        {
            sum = sum + temp%10;
            temp = temp/10;
        }
        box[sum]++;
    }
    
    return *max_element(box.begin(),box.end());
}
```

This function counts the number of balls that can be placed in boxes, where each ball is assigned to a box based on the sum of digits of the ball number. It returns the maximum number of balls placed in any single box.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countBalls(int lowLimit, int highLimit) {
	```
	This is the function declaration for `countBalls`, which takes two integers, `lowLimit` and `highLimit`, as input and returns the maximum number of balls placed in any box.

2. **Variable Initialization**
	```cpp
	    vector<int> box (46,0);
	```
	This line initializes a vector `box` of size 46 (to handle sums of digits from 0 to 45) with all values set to 0. It will store the count of balls in each box.

3. **Loop Start**
	```cpp
	    for(int i = lowLimit;i<=highLimit;i++)
	```
	This loop iterates over all the ball numbers from `lowLimit` to `highLimit`.

4. **Variable Initialization**
	```cpp
	        int sum = 0;
	```
	The variable `sum` is initialized to 0 and will be used to store the sum of the digits of the current ball number.

5. **Variable Initialization**
	```cpp
	        int temp = i;
	```
	The variable `temp` is initialized with the current ball number `i` and will be used to compute the sum of digits.

6. **Loop Start**
	```cpp
	        while(temp)
	```
	This `while` loop runs as long as `temp` is not 0, to extract and sum the digits of the number.

7. **Sum Calculation**
	```cpp
	            sum = sum + temp%10;
	```
	This line adds the last digit of `temp` (obtained by `temp % 10`) to `sum`.

8. **Variable Update**
	```cpp
	            temp = temp/10;
	```
	This line removes the last digit of `temp` by performing integer division (`temp / 10`).

9. **Array Operation**
	```cpp
	        box[sum]++;
	```
	This line increments the count of balls placed in the box corresponding to the digit sum `sum`.

10. **Return**
	```cpp
	    return *max_element(box.begin(),box.end());
	```
	This line returns the maximum value from the `box` vector, which represents the maximum number of balls placed in any box.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where `n` is the number of ball numbers in the range.
- **Average Case:** O(n), since calculating the sum of digits and updating the box counts is done in constant time for each number.
- **Worst Case:** O(n), as we must compute the sum of digits for each number from `lowLimit` to `highLimit`.

The time complexity is linear in the number of ball numbers.

### Space Complexity 💾
- **Best Case:** O(46), since the space needed is constant regardless of input size.
- **Worst Case:** O(46), as the sum of digits for any number between 1 and 100,000 cannot exceed 45.

The space complexity is constant, as we use a fixed-size array to count the balls in boxes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/)

---
{{< youtube bRjEkQZ1R7Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
