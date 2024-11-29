
+++
authors = ["grid47"]
title = "Leetcode 1653: Minimum Deletions to Make String Balanced"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1653: Minimum Deletions to Make String Balanced in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WDStNufBUQ8"
youtube_upload_date="2024-07-30"
youtube_thumbnail="https://i.ytimg.com/vi/WDStNufBUQ8/maxresdefault.jpg"
comments = true
+++



---
You are given a string s consisting of the characters 'a' and 'b'. The goal is to delete the minimum number of characters from s to make it balanced. A string is balanced if no 'b' precedes an 'a'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s, consisting only of the characters 'a' and 'b'.
- **Example:** `s = "abbbba"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- Each character in s is either 'a' or 'b'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the minimum number of deletions required to make the string balanced.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of deletions required to make the string balanced.

- Iterate through the string and track the number of 'b' characters.
- For each 'a' encountered, determine the minimum deletions by comparing the current state with the previous state where 'b' characters are deleted.
- Return the minimum deletions found.
{{< dots >}}
### Problem Assumptions ✅
- The string will always contain valid characters 'a' and 'b'.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abbbba"`  \
  **Explanation:** We need to ensure that no 'b' appears before 'a'. By deleting the minimum number of characters, we can balance the string.

{{< dots >}}
## Approach 🚀
The approach involves tracking the number of 'b' characters and minimizing deletions based on the appearance of 'a' characters.

### Initial Thoughts 💭
- We need to carefully handle 'b' characters and count the necessary deletions to make the string balanced.
- This problem can be solved by using dynamic programming to track the minimum deletions required for each position in the string.
{{< dots >}}
### Edge Cases 🌐
- Consider the case where the string has only one character.
- Ensure that the solution works efficiently with strings of length up to 100,000.
- Handle cases where the string is already balanced, such as a string with only 'a's or only 'b's.
- The solution must handle both small and large input sizes efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimumDeletions(string s) {
    int n = s.size(), bcnt = 0;
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++) {
        char a = s[i];
        if(a == 'a') {                
            dp[i + 1] = min(dp[i] + 1, bcnt);
        } else {
            bcnt++;
            dp[i + 1] = dp[i];
        }
    }
    return dp[n];
}
```

This function calculates the minimum deletions required to make the string 's' valid by removing 'a' or 'b' to ensure all 'a's appear before all 'b's.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumDeletions(string s) {
	```
	Defines the function that calculates the minimum deletions needed to make the string valid.

2. **Variable Initialization**
	```cpp
	    int n = s.size(), bcnt = 0;
	```
	Initializes the string size and a counter for the number of 'b's encountered.

3. **Array Initialization**
	```cpp
	    vector<int> dp(n + 1, 0);
	```
	Creates a dynamic programming array to store intermediate results.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates through each character in the string.

5. **Variable Initialization**
	```cpp
	        char a = s[i];
	```
	Stores the current character for processing.

6. **Conditional Statement**
	```cpp
	        if(a == 'a') {                
	```
	Checks if the current character is 'a'.

7. **Dynamic Programming**
	```cpp
	            dp[i + 1] = min(dp[i] + 1, bcnt);
	```
	Updates the dp array for 'a' by choosing the minimum deletions needed.

8. **Conditional Statement**
	```cpp
	        } else {
	```
	Handles the case where the current character is 'b'.

9. **Counter Increment**
	```cpp
	            bcnt++;
	```
	Increments the count of 'b' characters encountered.

10. **Dynamic Programming**
	```cpp
	            dp[i + 1] = dp[i];
	```
	Carries forward the dp value for 'b', as no deletion is required.

11. **Return Statement**
	```cpp
	    return dp[n];
	```
	Returns the minimum deletions needed to make the string valid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string, since we iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the dynamic programming array used to store the minimum deletions at each step.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/)

---
{{< youtube WDStNufBUQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
