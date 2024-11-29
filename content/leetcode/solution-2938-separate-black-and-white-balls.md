
+++
authors = ["grid47"]
title = "Leetcode 2938: Separate Black and White Balls"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2938: Separate Black and White Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-VVN0FI0KFo"
youtube_upload_date="2024-10-15"
youtube_thumbnail="https://i.ytimg.com/vi/-VVN0FI0KFo/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string s of length n, where each character represents a ball: '1' for black and '0' for white. The goal is to arrange the balls such that all the white balls are on the left side and all the black balls are on the right side, by swapping two adjacent balls in each step. You need to find the minimum number of adjacent swaps required to achieve this arrangement.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string s of length n where each character is either '1' or '0'.
- **Example:** `s = '110'`
- **Constraints:**
	- 1 <= n <= 10^5
	- s[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of adjacent swaps required to group all black balls to the right and all white balls to the left.
- **Example:** `For s = '110', the output is 1.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the minimum number of adjacent swaps required to sort all black balls to the right and all white balls to the left.

- Iterate through the string while counting the number of white balls ('0') encountered.
- For each black ball ('1'), count how many white balls are to the left of it, as this indicates how many swaps are needed to move the black ball to its correct position.
{{< dots >}}
### Problem Assumptions ✅
- The string contains at least one ball, and no more than 100,000 balls.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '110'`  \
  **Explanation:** One swap is needed to move the black ball at position 1 to the right.

- **Input:** `s = '01010'`  \
  **Explanation:** Four swaps are needed to move all black balls to the right.

- **Input:** `s = '000111'`  \
  **Explanation:** No swaps are needed because all black balls are already grouped to the right.

{{< dots >}}
## Approach 🚀
The approach is to iterate through the string, counting how many swaps are needed to move each black ball to its correct position by counting the number of white balls before it.

### Initial Thoughts 💭
- The problem is about calculating the number of swaps needed to order the black and white balls correctly.
- We can keep a running count of the number of white balls encountered so far, and for each black ball, we add this count to the total number of swaps.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return 0 as no swaps are needed.
- The solution must efficiently handle strings with lengths up to 100,000.
- If the string is already in the desired arrangement (all white balls on the left and black balls on the right), return 0.
- The input string will not be empty.
{{< dots >}}
## Code 💻
```cpp
long long minimumSteps(string s) {
    long long res = 0;
    for (int i = 0, cnt = 0; i < s.size(); ++i) {
        if (s[i] == '1')
            ++cnt;
        else
            res += cnt;
    }
    return res;        
}
```

This function calculates the minimum number of steps needed to transform a binary string into another, where each step is defined as the number of '1's encountered before a '0'. The result is the total count of such steps in the input string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long minimumSteps(string s) {
	```
	Defines the function 'minimumSteps' which takes a binary string 's' as input and returns the minimum number of steps required to transform it based on the logic described.

2. **Result Initialization**
	```cpp
	    long long res = 0;
	```
	Initializes a variable 'res' to zero, which will store the total number of steps (sum of '1's encountered before each '0').

3. **Loop Setup**
	```cpp
	    for (int i = 0, cnt = 0; i < s.size(); ++i) {
	```
	Sets up a loop to iterate through the characters of the string 's'. The variable 'cnt' tracks the number of '1's encountered during the iteration.

4. **Check for '1'**
	```cpp
	        if (s[i] == '1')
	```
	Checks if the current character is a '1'. If true, it increments the 'cnt' variable.

5. **Increment Count of '1's**
	```cpp
	            ++cnt;
	```
	Increments the 'cnt' variable by 1, tracking the number of '1's encountered so far.

6. **Check for '0'**
	```cpp
	        else
	```
	If the current character is not '1', meaning it's a '0', the code inside this block is executed.

7. **Add Steps for '0'**
	```cpp
	            res += cnt;
	```
	Adds the value of 'cnt' to 'res', indicating that each '1' encountered before the '0' adds to the total steps.

8. **Return Statement**
	```cpp
	    return res;        
	```
	Returns the total number of steps stored in 'res'. This is the final result after iterating through the entire string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution requires a single pass over the string, which is O(n) in all cases.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since only a few variables are used to track the count of white balls and the swaps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/separate-black-and-white-balls/description/)

---
{{< youtube -VVN0FI0KFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
