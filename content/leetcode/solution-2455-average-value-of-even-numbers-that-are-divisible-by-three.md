
+++
authors = ["grid47"]
title = "Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "FJVQfaZo4oA"
youtube_upload_date="2022-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FJVQfaZo4oA/maxresdefault.webp"
comments = true
+++



---
You are given an array of positive integers 'nums'. Your task is to calculate the average value of all even numbers in the array that are also divisible by 3. The average should be rounded down to the nearest integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array 'nums' containing positive integers.
- **Example:** `nums = [2, 3, 6, 9, 12, 18]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the average of all even integers in 'nums' that are divisible by 3. If no such number exists, return 0.
- **Example:** `Output: 9`
- **Constraints:**
	- Return 0 if no valid even numbers divisible by 3 are found.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the average of even integers divisible by 3.

- 1. Loop through each element in 'nums'.
- 2. Check if the element is even and divisible by 3.
- 3. Keep a running sum of the valid numbers and count how many there are.
- 4. If there are valid numbers, return the sum divided by the count, rounded down. If not, return 0.
{{< dots >}}
### Problem Assumptions ✅
- The array 'nums' will always contain at least one positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 3, 6, 9, 12, 18]`  \
  **Explanation:** From the given array, the even numbers divisible by 3 are [6, 12, 18]. The sum of these numbers is 36, and their count is 3. Therefore, the average is 36 / 3 = 12.

- **Input:** `nums = [1, 2, 4, 7, 10]`  \
  **Explanation:** There are no even numbers divisible by 3, so the result is 0.

{{< dots >}}
## Approach 🚀
We will iterate through the array 'nums', check if each number is even and divisible by 3, and keep track of the sum and count of such numbers to calculate the average.

### Initial Thoughts 💭
- We need to check divisibility by both 2 (even number) and 3 for each element in the array.
- We can easily check divisibility using the modulus operator. If a number satisfies both conditions, we will include it in our sum.
{{< dots >}}
### Edge Cases 🌐
- If 'nums' is empty, return 0.
- Ensure the solution works efficiently for arrays of size 1000 and with numbers up to 1000.
- If all elements in 'nums' are either odd or not divisible by 3, return 0.
- The input size is small enough that a linear scan through the array will be efficient.
{{< dots >}}
## Code 💻
```cpp
int averageValue(vector<int>& nums) 
{
 int Total_Sum=0;
    int Total_Number=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]%2==0 && nums[i]%3==0)
        {
            Total_Sum+=nums[i];
            Total_Number++;
        }
    }      
    if(Total_Sum==0) return 0;
    return Total_Sum/Total_Number;   
}
```

This function calculates the average of all integers in the `nums` list that are divisible by both 2 and 3. If no such numbers are found, it returns 0.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int averageValue(vector<int>& nums) 
	```
	Defines the function `averageValue` that takes a vector of integers `nums` as input and returns the average of integers divisible by both 2 and 3.

2. **Variable Initialization**
	```cpp
	 int Total_Sum=0;
	```
	Initializes `Total_Sum` to 0, which will hold the sum of numbers divisible by both 2 and 3.

3. **Variable Initialization**
	```cpp
	    int Total_Number=0;
	```
	Initializes `Total_Number` to 0, which will keep track of the count of numbers divisible by both 2 and 3.

4. **Loop Through List**
	```cpp
	    for(int i=0;i<nums.size();i++)
	```
	Starts a loop that iterates through each number in the `nums` vector.

5. **Divisibility Check**
	```cpp
	        if(nums[i]%2==0 && nums[i]%3==0)
	```
	Checks if the current number `nums[i]` is divisible by both 2 and 3.

6. **Sum Update**
	```cpp
	            Total_Sum+=nums[i];
	```
	Adds the current number `nums[i]` to `Total_Sum` if it is divisible by both 2 and 3.

7. **Count Update**
	```cpp
	            Total_Number++;
	```
	Increments the `Total_Number` to count the number of elements that are divisible by both 2 and 3.

8. **Edge Case Check**
	```cpp
	    if(Total_Sum==0) return 0;
	```
	Checks if no numbers were divisible by both 2 and 3. If true, returns 0 to handle the edge case where no valid numbers exist.

9. **Return Average**
	```cpp
	    return Total_Sum/Total_Number;   
	```
	Returns the average of the numbers divisible by both 2 and 3, by dividing the total sum by the count of such numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We need to check each element of 'nums' to see if it satisfies the conditions, resulting in linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only use a fixed amount of extra space for the sum and count, making the space complexity constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/)

---
{{< youtube FJVQfaZo4oA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
