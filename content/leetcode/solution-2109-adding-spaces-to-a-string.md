
+++
authors = ["grid47"]
title = "Leetcode 2109: Adding Spaces to a String"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2109: Adding Spaces to a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HhsyccqLHDw"
youtube_upload_date="2021-12-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HhsyccqLHDw/maxresdefault.webp"
comments = true
+++



---
You are given a string s and an array spaces. The array contains indices where spaces need to be inserted into the string. Each space should be added before the character at the respective index. Return the modified string with the spaces inserted.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s consisting of lowercase and uppercase English letters and an array spaces where each element is an index at which a space should be inserted.
- **Example:** `s = "HelloWorld", spaces = [5]`
- **Constraints:**
	- 1 <= s.length <= 3 * 10^5
	- 1 <= spaces.length <= 3 * 10^5
	- 0 <= spaces[i] <= s.length - 1
	- The values in spaces are strictly increasing

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string with spaces inserted before the characters at the indices specified in the array spaces.
- **Example:** `For s = "HelloWorld", spaces = [5], the output should be "Hello World".`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to modify the string by inserting spaces at the specified indices.

- Iterate through the string and check if the current index matches an index from the spaces array.
- If the index matches, insert a space before the current character.
- Continue processing the remaining characters in the string after inserting the spaces.
{{< dots >}}
### Problem Assumptions ✅
- The input string s only contains English letters.
- The array spaces is sorted and does not contain duplicate values.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: s = "ProgrammingIsFun", spaces = [11, 14]`  \
  **Explanation:** We insert spaces before 'I' at index 11 and before 'F' at index 14 to obtain the string: "Programming Is Fun".

- **Input:** `Example 2: s = "CodingChallenges", spaces = [6, 11]`  \
  **Explanation:** We insert spaces before 'C' at index 6 and before 'C' at index 11 to obtain the string: "Coding Challenges".

{{< dots >}}
## Approach 🚀
The approach is to process the string by adding spaces at the specified indices while maintaining the order of the original characters.

### Initial Thoughts 💭
- We can keep track of the current index and compare it to the indices in the spaces array.
- After each insertion, we can continue from the next character.
- This can be done in a single pass through the string with efficient space management.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, the output should also be an empty string.
- The solution should efficiently handle the maximum input size of 300,000 characters and indices.
- If the spaces array contains all indices of the string, spaces will be inserted before every character.
- The solution should handle up to 300,000 spaces efficiently.
{{< dots >}}
## Code 💻
```cpp
string addSpaces(string s, vector<int>& spaces) {
    int i = 0;
    string res = "";
    for(int idx : spaces) {
        while(i < idx) res += s[i++];
        if(i == idx) res += ' ';
    }
    while(i < s.size()) res += s[i++];        
    return res;
}
```

This function adds spaces to a string `s` at specified indices provided in the `spaces` vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string addSpaces(string s, vector<int>& spaces) {
	```
	Define the function `addSpaces` that takes a string `s` and a vector of integers `spaces` to insert spaces at specified positions in `s`.

2. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initialize the index `i` to keep track of the position in the string `s`.

3. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Initialize the result string `res` to store the modified string with spaces inserted.

4. **Loop Start**
	```cpp
	    for(int idx : spaces) {
	```
	Start a loop to iterate over each index in the `spaces` vector.

5. **Loop Body**
	```cpp
	        while(i < idx) res += s[i++];
	```
	Copy characters from the string `s` to `res` until the current index `idx` is reached.

6. **Condition Check**
	```cpp
	        if(i == idx) res += ' ';
	```
	When the current index `i` matches the index in `spaces`, add a space to `res`.

7. **Final Copy**
	```cpp
	    while(i < s.size()) res += s[i++];
	```
	Copy any remaining characters from `s` to `res` after the last specified space position.

8. **Return Statement**
	```cpp
	    return res;
	```
	Return the modified string `res` which now includes the spaces.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string, as we process each character once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we construct the result string, which can be at most the length of the input string plus the number of spaces.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/adding-spaces-to-a-string/description/)

---
{{< youtube HhsyccqLHDw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
