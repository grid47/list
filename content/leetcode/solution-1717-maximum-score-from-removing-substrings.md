
+++
authors = ["grid47"]
title = "Leetcode 1717: Maximum Score From Removing Substrings"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1717: Maximum Score From Removing Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9wZ-TWBreTg"
youtube_upload_date="2021-03-15"
youtube_thumbnail="https://i.ytimg.com/vi/9wZ-TWBreTg/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s` and two integers `x` and `y`. You can perform two types of operations any number of times:

1. Remove the substring "ab" and gain `x` points.
2. Remove the substring "ba" and gain `y` points.

Each time a substring is removed, the characters are deleted from the string, and the corresponding points are added to your total score. Your task is to maximize the total score after applying these operations any number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` of lowercase English letters and two integers `x` and `y`.
- **Example:** `Input: s = "dcbaba", x = 3, y = 4`
- **Constraints:**
	- 1 <= s.length <= 100000
	- 1 <= x, y <= 10000
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum points you can gain after applying the operations.
- **Example:** `Output: 12`
- **Constraints:**
	- The result will be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the score by performing the optimal sequence of substring removal operations.

- 1. Check which substring, 'ab' or 'ba', gives the higher points and prioritize removing that.
- 2. Use a greedy approach to simulate the removals of 'ab' or 'ba' from the string, adjusting the score accordingly.
- 3. After each removal, check if further operations can be performed until no more 'ab' or 'ba' can be removed.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` will always be valid and consist of lowercase English letters.
- The operations on 'ab' and 'ba' are independent, and they can be performed multiple times.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "dcbaba", x = 3, y = 4`  \
  **Explanation:** In this case, removing 'ba' first (giving 4 points) and then 'ab' (giving 3 points) results in a total score of 12.

- **Input:** `Input: s = "aabbab", x = 5, y = 4`  \
  **Explanation:** First, remove 'ab' (5 points), then remove 'ba' (4 points), giving a total score of 9.

{{< dots >}}
## Approach 🚀
The solution involves applying a greedy approach to remove the highest scoring substrings first, maximizing the total score.

### Initial Thoughts 💭
- We need to remove substrings in the most beneficial order (either 'ab' or 'ba').
- Since we can perform operations on the string repeatedly, using a greedy approach will help us maximize the points.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one character.
- Ensure that the solution handles strings with lengths up to 100,000 characters efficiently.
- If the string contains no 'ab' or 'ba', the total score should be 0.
- The algorithm should handle both small and large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
    if(y > x) {
        swap(a, b);
        swap(x, y);
    }
    
    auto s1 = greedy(s, a, b), s2 = greedy(s1,  b, a);
    
    return ((s.size() - s1.size()) / 2) * x + ((s1.size() - s2.size()) / 2) * y;
}
string greedy(string s, char a, char b) {
    
    string st;
    
    for(char c : s) {
        if(!st.empty() && st.back() == a && c == b)
            st.pop_back();
        else st.push_back(c);
    }
    return st;
}

```

This function calculates the maximum gain from a string of characters by repeatedly removing pairs of specific characters. The greedy function processes the string to perform the removal, and the main function computes the total gain from these operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
	```
	Defines the `maximumGain` function that computes the maximum gain by repeatedly removing pairs of characters (`a`, `b`) from the string `s`.

2. **Condition Check**
	```cpp
	    if(y > x) {
	```
	Checks if the value of `y` is greater than `x`. If true, it swaps the characters `a` and `b`, as well as their respective values `x` and `y`, to ensure the correct order of operations.

3. **Swap Characters**
	```cpp
	        swap(a, b);
	```
	Swaps the characters `a` and `b` to prioritize the character associated with the larger gain (either `x` or `y`).

4. **Swap Gains**
	```cpp
	        swap(x, y);
	```
	Swaps the values of `x` and `y` to ensure the correct association with characters `a` and `b` after the swap.

5. **Greedy Function Call 1**
	```cpp
	    auto s1 = greedy(s, a, b), s2 = greedy(s1,  b, a);
	```
	Calls the `greedy` function twice: first with characters `a` and `b`, and then with characters `b` and `a` to maximize the number of pair removals from the string.

6. **Return Calculation**
	```cpp
	    return ((s.size() - s1.size()) / 2) * x + ((s1.size() - s2.size()) / 2) * y;
	```
	Calculates and returns the total gain by multiplying the number of pair removals with their respective gains (`x` for `a`, `y` for `b`).

7. **Greedy Function Definition**
	```cpp
	string greedy(string s, char a, char b) {
	```
	Defines the `greedy` function that processes the string `s`, removing pairs of characters `a` and `b` using a stack-based approach.

8. **Initialize Stack**
	```cpp
	    string st;
	```
	Initializes an empty stack `st` to store characters as they are processed.

9. **Iterate Through String**
	```cpp
	    for(char c : s) {
	```
	Starts a loop to iterate through each character `c` in the string `s`.

10. **Condition to Remove Pair**
	```cpp
	        if(!st.empty() && st.back() == a && c == b)
	```
	Checks if the stack is not empty and if the last character in the stack is `a` and the current character is `b`. If true, it removes the pair from the stack.

11. **Pop Pair**
	```cpp
	            st.pop_back();
	```
	Pops the last character (`a`) from the stack, effectively removing the pair `a, b`.

12. **Push Character**
	```cpp
	        else st.push_back(c);
	```
	If the condition to remove a pair is not met, it adds the current character `c` to the stack.

13. **Return Stack**
	```cpp
	    return st;
	```
	Returns the final stack, which contains the string after all possible pairs of characters `a` and `b` have been removed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string. In the best case, we only process the string once.
- **Average Case:** O(n), as we process each character in the string linearly.
- **Worst Case:** O(n), since we iterate over the string to check and remove 'ab' and 'ba' substrings.

The time complexity is O(n), as we iterate through the string at most once, performing constant time operations.

### Space Complexity 💾
- **Best Case:** O(1), if no changes to the string are needed.
- **Worst Case:** O(n), since we store a modified version of the string during processing.

The space complexity is O(n), as the string is processed and stored in memory during the solution.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-score-from-removing-substrings/description/)

---
{{< youtube 9wZ-TWBreTg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
