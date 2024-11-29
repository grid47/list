
+++
authors = ["grid47"]
title = "Leetcode 2434: Using a Robot to Print the Lexicographically Smallest String"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2434: Using a Robot to Print the Lexicographically Smallest String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-8gRuQFSuX8"
youtube_upload_date="2022-10-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-8gRuQFSuX8/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` and a robot that starts with an empty string `t`. The robot can perform two operations: one, it can remove the first character of string `s` and append it to `t`, and two, it can remove the last character of string `t` and write it down. The goal is to return the lexicographically smallest string that can be written on paper using these operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` consisting of lowercase English letters.
- **Example:** `s = "hello"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of only lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest string that can be written on paper.
- **Example:** `Output: "ehllo"`
- **Constraints:**
	- The string must be lexicographically smallest.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to determine the lexicographically smallest string that can be obtained by performing the allowed operations on `s` and `t`.

- 1. Traverse through the string `s` and push its characters onto the stack `t`.
- 2. After each push, check if the top character of `t` is lexicographically smaller than any remaining character in `s` and pop the character from `t` if it is.
- 3. Keep a record of the characters written down on paper to form the result string.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` contains only lowercase English letters.
- The solution must efficiently handle input strings up to the maximum length of 10^5.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "hello"`  \
  **Explanation:** In this example, the robot will push the characters from `s` onto `t` and pop the smallest character to write down on paper. The smallest lexicographical string that can be written down is "ehllo".

- **Input:** `s = "abc"`  \
  **Explanation:** For the string `s = 'abc'`, the robot can directly pop all the characters from `t` to get the string "abc" written on paper.

{{< dots >}}
## Approach 🚀
The solution relies on using a stack to simulate the operations of the robot. By comparing characters in `s` and keeping track of the smallest lexicographical order, we can determine the correct sequence of characters to write down.

### Initial Thoughts 💭
- We need to ensure that the robot writes the lexicographically smallest string by carefully selecting which characters to pop from `t`.
- We can leverage a stack to store characters and write them down when the smallest available option is at the top of the stack.
{{< dots >}}
### Edge Cases 🌐
- The input string `s` will never be empty, as the length constraint ensures at least one character.
- The solution must efficiently handle strings with a length of up to 10^5.
- Consider the case when `s` is already sorted lexicographically.
- Ensure the solution handles strings where multiple operations might occur simultaneously.
{{< dots >}}
## Code 💻
```cpp

char low(vector<int> &frq) {
    for(int i = 0; i < 26; i++)
        if(frq[i] != 0) return 'a'+i;
    return 'z';
}

string robotWithString(string s) {
    
    vector<int> frq(26, 0);
    for(char c: s)
        frq[c - 'a']++;
    
    stack<int> t;
    string ans = "";
    
    for(char c : s) {
        t.push(c);
        frq[c - 'a']--;
        while(!t.empty() && t.top() <= low(frq)) {
            ans += t.top();
            t.pop();
        }
    }
    
    return ans;
}
```

The function 'robotWithString' generates a string by using a stack to manage character frequencies and ensures the characters are placed in lexicographical order using a helper function 'low'. It iterates through the input string 's', adjusting the stack and frequency count, and builds the resulting string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	char low(vector<int> &frq) {
	```
	The function 'low' is defined to find the lexicographically smallest character from the remaining available characters based on their frequencies.

2. **Loop**
	```cpp
	    for(int i = 0; i < 26; i++)
	```
	A loop is initiated to iterate through each character of the English alphabet (26 letters).

3. **Frequency Check**
	```cpp
	        if(frq[i] != 0) return 'a'+i;
	```
	The first character with a non-zero frequency is returned as the smallest remaining character.

4. **Return**
	```cpp
	    return 'z';
	```
	If no remaining characters are found, return 'z' as a default.

5. **Function Definition**
	```cpp
	string robotWithString(string s) {
	```
	The 'robotWithString' function is defined to transform the input string 's' using a stack to build a lexicographically ordered string.

6. **Vector Initialization**
	```cpp
	    vector<int> frq(26, 0);
	```
	Initialize a vector 'frq' to track the frequency of each letter in the input string 's'.

7. **Frequency Calculation**
	```cpp
	    for(char c: s)
	```
	A loop is initiated to calculate the frequency of each character in the string 's'.

8. **Frequency Increment**
	```cpp
	        frq[c - 'a']++;
	```
	For each character 'c' in the string, increment the frequency count in the 'frq' vector.

9. **Stack Initialization**
	```cpp
	    stack<int> t;
	```
	Initialize an empty stack 't' to temporarily hold characters for the result string.

10. **Result Initialization**
	```cpp
	    string ans = "";
	```
	Initialize an empty string 'ans' to store the final lexicographically ordered string.

11. **Loop**
	```cpp
	    for(char c : s) {
	```
	A loop is started to iterate over each character 'c' in the string 's'.

12. **Push to Stack**
	```cpp
	        t.push(c);
	```
	Push the current character 'c' onto the stack 't'.

13. **Update Frequency**
	```cpp
	        frq[c - 'a']--;
	```
	Decrement the frequency of the character 'c' in the 'frq' vector, as it's been processed.

14. **Check Stack**
	```cpp
	        while(!t.empty() && t.top() <= low(frq)) {
	```
	Check if the top of the stack contains a character that can be added to the result string based on the 'low' function.

15. **Add to Result**
	```cpp
	            ans += t.top();
	```
	Add the character from the top of the stack to the result string 'ans'.

16. **Pop from Stack**
	```cpp
	            t.pop();
	```
	Pop the character from the stack after it has been added to the result string.

17. **Return Result**
	```cpp
	    return ans;
	```
	Return the final lexicographically ordered string 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where `n` is the length of the string `s`. We traverse the string once and perform constant-time operations for each character.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of a stack to store the characters of `s`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/)

---
{{< youtube -8gRuQFSuX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
