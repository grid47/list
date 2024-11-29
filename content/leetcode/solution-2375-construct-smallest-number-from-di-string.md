
+++
authors = ["grid47"]
title = "Leetcode 2375: Construct Smallest Number From DI String"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2375: Construct Smallest Number From DI String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-vIB0xikOw"
youtube_upload_date="2022-08-14"
youtube_thumbnail="https://i.ytimg.com/vi/b-vIB0xikOw/maxresdefault.jpg"
comments = true
+++



---
You are given a string `pattern` consisting of the characters 'I' and 'D', where 'I' indicates that the next number in a sequence should be greater, and 'D' means the next number should be smaller. You need to construct the lexicographically smallest string `num` of length `n + 1` such that the digits in `num` follow the conditions set by the `pattern`. The digits in `num` must be distinct and range from '1' to '9'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `pattern` of length `n`, where each character is either 'I' or 'D'.
- **Example:** `pattern = 'IIDID'`
- **Constraints:**
	- 1 <= pattern.length <= 8
	- pattern consists only of 'I' and 'D'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest string `num` that satisfies the pattern.
- **Example:** `Output: '123549876'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to construct the smallest lexicographical string `num` by following the constraints defined by the pattern.

- 1. Traverse through the pattern and push the smallest available digits to a stack whenever encountering 'I'.
- 2. When encountering 'D', push digits into the stack and reverse them once 'I' is encountered or the end of the string is reached.
- 3. Append the digits from the stack to form the final number.
{{< dots >}}
### Problem Assumptions ✅
- The string `pattern` will always be valid, containing only 'I' and 'D'.
- The length of the string `num` will be equal to the length of the pattern plus one.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: pattern = 'IIDID'`  \
  **Explanation:** In this case, we need to create a string such that at positions with 'I', the next number is greater, and at positions with 'D', the next number is smaller. The smallest valid string satisfying the pattern is '123549876'.

- **Input:** `Input: pattern = 'DIDI'`  \
  **Explanation:** Here, the smallest number satisfying the conditions is '4321'.

{{< dots >}}
## Approach 🚀
We can approach this problem by iterating through the `pattern` and using a stack to temporarily store numbers when encountering 'D'. When we encounter 'I', we pop from the stack to ensure the lexicographically smallest result.

### Initial Thoughts 💭
- We need to find a way to handle 'I' and 'D' constraints while maintaining the smallest lexicographical order.
- A stack will help us manage the numbers and reverse them when encountering a 'D'.
{{< dots >}}
### Edge Cases 🌐
- The pattern will always have at least one character.
- The pattern length can go up to 8, and the solution must handle this efficiently.
- If the pattern consists entirely of 'I's or 'D's, handle the sequence accordingly.
- Ensure that the digits used in `num` are between '1' and '9' and are distinct.
{{< dots >}}
## Code 💻
```cpp
string smallestNumber(string ptn) {
    string res, stk;
    int n = ptn.size();
    for(int i = 0; i <= n; i++) {
        stk.push_back(i + '1');
        if(i == n || ptn[i] == 'I') {
            while(!stk.empty()) {
                res.push_back(stk.back());
                stk.pop_back();
            }
        }
    }
    return res;
}
```

This function takes a pattern `ptn` consisting of characters 'I' (for increasing) and 'D' (for decreasing) and returns the smallest number that follows this pattern using a stack to handle the decreasing sequences.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string smallestNumber(string ptn) {
	```
	Defines the function `smallestNumber` that accepts a string `ptn` representing a pattern of 'I' (increasing) and 'D' (decreasing) and returns a string representing the smallest number that can be formed based on the pattern.

2. **Variable Initialization**
	```cpp
	    string res, stk;
	```
	Initializes two strings: `res` to store the result and `stk` to act as a stack to manage the number sequence.

3. **Size Calculation**
	```cpp
	    int n = ptn.size();
	```
	Calculates the length of the input pattern `ptn` and stores it in variable `n`.

4. **Loop Start**
	```cpp
	    for(int i = 0; i <= n; i++) {
	```
	Starts a loop that iterates from `i = 0` to `i = n` to process each character in the pattern and the final number.

5. **Push to Stack**
	```cpp
	        stk.push_back(i + '1');
	```
	Pushes the next number (i + 1) as a character (i.e., '1', '2', etc.) onto the stack `stk`.

6. **Check Pattern**
	```cpp
	        if(i == n || ptn[i] == 'I') {
	```
	Checks if the end of the string has been reached (`i == n`) or if the current character in the pattern is 'I' (indicating an increasing sequence).

7. **Pop from Stack**
	```cpp
	            while(!stk.empty()) {
	```
	Starts a while loop that runs as long as the stack is not empty, to pop elements from the stack in reverse order when a 'I' (increase) is encountered or when the end of the pattern is reached.

8. **Store in Result**
	```cpp
	                res.push_back(stk.back());
	```
	Pops the top element from the stack and appends it to the result string `res`.

9. **Remove from Stack**
	```cpp
	                stk.pop_back();
	```
	Removes the top element from the stack after adding it to the result.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the resulting string `res`, which contains the smallest number formed according to the given pattern.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we iterate through the string once and perform constant time operations for each character.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the stack used to hold intermediate values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-smallest-number-from-di-string/description/)

---
{{< youtube b-vIB0xikOw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
