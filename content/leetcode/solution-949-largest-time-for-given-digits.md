
+++
authors = ["grid47"]
title = "Leetcode 949: Largest Time for Given Digits"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 949: Largest Time for Given Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "sn6r0ZV_2y4"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/sn6r0ZV_2y4/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGEgZShHMA8=&rs=AOn4CLCRrVpzGGgx18QwTzZjGamfSnIVlw"
comments = true
+++



---
Given an array of 4 digits, your task is to form the latest possible 24-hour time using each digit exactly once. The time is represented in the format 'HH:MM' where 'HH' is between 00 and 23, and 'MM' is between 00 and 59. If no valid time can be formed, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers representing 4 digits.
- **Example:** `Input: arr = [9, 1, 2, 4]`
- **Constraints:**
	- The array will always have exactly 4 digits.
	- Each digit will be between 0 and 9.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the latest valid time in the format 'HH:MM'. If no valid time can be formed, return an empty string.
- **Example:** `Output: '21:49'`
- **Constraints:**
	- The returned string should be in the format 'HH:MM'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all possible times using the given digits and return the latest valid time.

- 1. Sort the digits in descending order to try the largest possible times first.
- 2. Try all permutations of the digits to form potential times.
- 3. For each permutation, check if the resulting time is valid (HH:MM format).
- 4. Return the latest valid time, or an empty string if none can be formed.
{{< dots >}}
### Problem Assumptions ✅
- The digits provided are valid integers between 0 and 9.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [9, 1, 2, 4]`  \
  **Explanation:** The largest valid time possible from these digits is '21:49'. The other permutations are not valid 24-hour times.

- **Input:** `Input: arr = [3, 3, 3, 2]`  \
  **Explanation:** The largest valid time possible is '23:33'.

{{< dots >}}
## Approach 🚀
The approach involves generating all permutations of the digits and checking each one for validity in a 24-hour time format.

### Initial Thoughts 💭
- Since there are only 4 digits, the problem is manageable by checking all permutations.
- Sorting the digits in descending order first helps in quickly finding the largest valid time.
- The key observation is that only a few permutations need to be checked to find the largest valid time.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return an empty string.
- This problem always assumes exactly 4 digits, so there are no cases for large inputs.
- If all the digits are the same, the approach still works as we generate permutations of identical digits.
- The solution must efficiently handle checking up to 24 permutations (4!) of the digits.
{{< dots >}}
## Code 💻
```cpp
string largestTimeFromDigits(vector<int>& A) {
    sort(begin(A), end(A), greater<int>());
    do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
        return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
    while(prev_permutation(begin(A), end(A)));
        
    return "";
}
```

This function returns the largest possible time that can be formed from the digits in the given vector `A`. The function sorts the digits in descending order, checks if a valid time can be formed, and then iterates through all permutations to find the largest valid time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string largestTimeFromDigits(vector<int>& A) {
	```
	The function `largestTimeFromDigits` takes a vector of integers representing the digits of a time and returns the largest valid time as a string, or an empty string if no valid time can be formed.

2. **Sorting Digits**
	```cpp
	    sort(begin(A), end(A), greater<int>());
	```
	Sort the digits in descending order to maximize the first digits of the time and try to form the largest possible valid time.

3. **Check Valid Time**
	```cpp
	    do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
	```
	Check if the current permutation of digits forms a valid time. A valid time must have the first two digits as a number less than 24 and the last two digits as a number less than 60.

4. **Form Time String**
	```cpp
	        return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
	```
	If the current permutation forms a valid time, convert the digits into a string in the format `HH:MM` and return it.

5. **Generate Previous Permutation**
	```cpp
	    while(prev_permutation(begin(A), end(A)));
	```
	If no valid time has been found, generate the next permutation of the digits in descending order and check again.

6. **Return Empty String**
	```cpp
	    return "";
	```
	If no valid time can be formed from the digits, return an empty string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(24)
- **Worst Case:** O(24)

Generating permutations of 4 digits results in at most 24 permutations. Checking each one takes constant time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only storing a few permutations at a time.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-time-for-given-digits/description/)

---
{{< youtube sn6r0ZV_2y4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
