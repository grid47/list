
+++
authors = ["grid47"]
title = "Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lHzdbjyqBG4"
youtube_upload_date="2024-05-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lHzdbjyqBG4/maxresdefault.webp"
comments = true
+++



---
A string consisting of only '(' and ')' characters is considered a valid parentheses string (VPS) if it satisfies the following conditions: it is empty, can be split into two valid VPS's, or can be written in the form of '(A)' where A is a VPS. You are given a VPS string `seq`. The task is to split it into two subsequences, A and B, such that both A and B are valid parentheses strings. The goal is to minimize the maximum nesting depth between A and B, and you need to return an array where each element is 0 if the character is part of A, and 1 if it's part of B.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string `seq` consisting only of '(' and ')' characters representing a valid parentheses string.
- **Example:** `Input: seq = '(())(())'`
- **Constraints:**
	- 1 <= seq.size <= 10000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of length `seq.length`, where each element is 0 if the character at that index is part of subsequence A, and 1 if it is part of subsequence B.
- **Example:** `Output: [0, 1, 0, 0, 1, 1, 0, 1]`
- **Constraints:**
	- The array should satisfy the condition that both subsequences are valid parentheses strings.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to split the given VPS string into two subsequences, A and B, while minimizing the maximum depth of the subsequences.

- Initialize a variable `d` to track the current depth of parentheses.
- Iterate through the string and for each character, increment or decrement `d` based on whether the character is '(' or ')'.
- For each character, assign it to subsequence A (0) or B (1) based on the parity of the current depth.
- Return the array representing the split subsequences.
{{< dots >}}
### Problem Assumptions ✅
- The input string is guaranteed to be a valid parentheses string.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: seq = '(())(())'`  \
  **Explanation:** The optimal split would be into subsequences A = '(())' and B = '(())', where the resulting depths are both 1. The answer array could be [0, 1, 0, 0, 1, 1, 0, 1].

- **Input:** `Input: seq = '(()())()'`  \
  **Explanation:** An optimal split would be into subsequences A = '(())' and B = '()()', where the depths are 1 and 1, respectively. The answer array could be [0, 1, 1, 0, 0, 1, 1, 1].

{{< dots >}}
## Approach 🚀
We will split the string into two subsequences by iterating through it and assigning characters to subsequences A and B based on their nesting depth. This will minimize the maximum depth of both subsequences.

### Initial Thoughts 💭
- We can use a greedy approach to assign characters to subsequences while keeping track of the nesting depth.
- The depth of a parentheses string can be tracked as we traverse it, and we can alternate between subsequences based on this depth.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty because it is guaranteed to be a valid parentheses string.
- The solution should efficiently handle inputs up to the size limit of 10,000 characters.
- A string with alternating parentheses like '()()()' will split evenly between A and B, maintaining the balance.
- Ensure that the solution adheres to the problem constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> maxDepthAfterSplit(string seq) {
    vector<int> groups;
    int d = 0;
    for(char c: seq) {
        bool open = c == '(';
        if(open) d++;
        groups.push_back(d%2);
        if(!open) d--;
    }
    return groups;
}
```

This function determines the maximum depth of a sequence of parentheses and returns an array where each position corresponds to the depth of the parentheses in a balanced manner (alternating between two groups).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> maxDepthAfterSplit(string seq) {
	```
	The function `maxDepthAfterSplit` is defined, taking a string `seq` representing a sequence of parentheses. It returns a vector of integers representing the depth of each parenthesis in two alternating groups.

2. **Variable Declaration**
	```cpp
	    vector<int> groups;
	```
	A vector `groups` is declared to store the resulting depth group (0 or 1) for each parenthesis in the sequence.

3. **Variable Declaration**
	```cpp
	    int d = 0;
	```
	An integer `d` is initialized to 0, which will track the current depth of the parentheses during traversal.

4. **Loop**
	```cpp
	    for(char c: seq) {
	```
	A `for` loop begins to iterate over each character `c` in the input string `seq`.

5. **Boolean Check**
	```cpp
	        bool open = c == '(';
	```
	A boolean variable `open` is set to `true` if the character `c` is an opening parenthesis ('('), otherwise it is `false`.

6. **Condition Check**
	```cpp
	        if(open) d++;
	```
	If the current character is an opening parenthesis, the depth `d` is incremented.

7. **Vector Operation**
	```cpp
	        groups.push_back(d%2);
	```
	The current depth modulo 2 (`d%2`) is added to the `groups` vector, ensuring alternating group assignment (0 or 1) for each level of depth.

8. **Condition Check**
	```cpp
	        if(!open) d--;
	```
	If the current character is a closing parenthesis, the depth `d` is decremented.

9. **Return Statement**
	```cpp
	    return groups;
	```
	The function returns the `groups` vector, which contains the alternating depth groups (0 or 1) for each parenthesis in the sequence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we traverse the string exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the result array of the same length as the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/)

---
{{< youtube lHzdbjyqBG4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
