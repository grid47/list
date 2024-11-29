
+++
authors = ["grid47"]
title = "Leetcode 1249: Minimum Remove to Make Valid Parentheses"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1249: Minimum Remove to Make Valid Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tMzZUDR_cH0"
youtube_upload_date="2020-03-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tMzZUDR_cH0/maxresdefault.webp"
comments = true
+++



---
You are given a string s containing lowercase English letters and parentheses. Your task is to remove the minimum number of parentheses to make the string valid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s that contains parentheses and lowercase English letters.
- **Example:** `s = "abc(de(f)gh)"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s[i] is either '(' , ')', or lowercase English letter

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string after removing the minimum number of parentheses to make it valid.
- **Example:** `"abc(de(f)gh)"`
- **Constraints:**
	- The output string should be valid after removing parentheses.

{{< dots >}}
### Core Logic 🔍
**Goal:** Ensure the string is valid by removing unnecessary parentheses.

- Use a stack to track the indices of unmatched parentheses.
- Iterate through the string, removing parentheses that do not form a valid pair.
- Construct and return the new string without invalid parentheses.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only valid parentheses or lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abc(de(f)gh)"`  \
  **Explanation:** The string is already valid, so no parentheses are removed.

- **Input:** `s = "a)b(c)d"`  \
  **Explanation:** The first ')' is removed to make the string valid, resulting in 'ab(c)d'.

- **Input:** `s = "))(("`  \
  **Explanation:** All parentheses are removed, leaving an empty string, which is valid.

{{< dots >}}
## Approach 🚀
The solution involves using a stack to track unmatched parentheses and iterating over the string to remove invalid ones.

### Initial Thoughts 💭
- The problem requires finding invalid parentheses and removing them.
- A stack is a natural data structure for this type of matching problem.
- We can process the string and ensure parentheses are balanced by using a stack to track unmatched opening parentheses and their indices.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, the result is also empty.
- The algorithm should efficiently handle strings of size up to 100,000.
- If there are no parentheses in the string, return the original string.
- Ensure the algorithm works within the given time complexity constraints for large inputs.
{{< dots >}}
## Code 💻
```cpp
string minRemoveToMakeValid(string s) {
    vector<int> stk, itk;
    for(int i = 0; i < s.length(); i++) {
        char a = s[i];
             if(a == '(') { stk.push_back(i); }
        else if(a == ')') {
                 if(stk.size()    == 0)    stk.push_back(i);
            else if(s[stk.back()] == '(')  stk.pop_back();
            else stk.push_back(i);
        }
    }
    string res = "";
    set<int> st(stk.begin(), stk.end());
    for(int i = 0; i < s.length(); i++) {
        if(st.count(i)) continue;
        res += s[i];
    }
    return res;        
}
```

The function `minRemoveToMakeValid` removes the minimum number of parentheses to make a string valid. It uses a stack to track the indices of unmatched parentheses and removes them from the string by skipping over those indices in the final result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string minRemoveToMakeValid(string s) {
	```
	This is the function definition of `minRemoveToMakeValid`, which takes a string `s` as input and returns a modified string with the minimum number of parentheses removed to make it valid.

2. **Variable Initialization**
	```cpp
	    vector<int> stk, itk;
	```
	Two vectors, `stk` and `itk`, are initialized. `stk` will store the indices of unmatched parentheses, and `itk` is unused in this implementation.

3. **Loop Through String**
	```cpp
	    for(int i = 0; i < s.length(); i++) {
	```
	A loop is used to iterate through each character of the string `s`. The loop index `i` is used to access each character.

4. **Character Assignment**
	```cpp
	        char a = s[i];
	```
	The current character `a` is assigned the value of the character at position `i` in the string `s`.

5. **Handle Opening Parenthesis**
	```cpp
	             if(a == '(') { stk.push_back(i); }
	```
	If the current character is an opening parenthesis '(', its index is pushed onto the `stk` vector to track its position.

6. **Handle Closing Parenthesis**
	```cpp
	        else if(a == ')') {
	```
	If the current character is a closing parenthesis ')', we check if there is an unmatched opening parenthesis.

7. **Handle Unmatched Closing Parenthesis**
	```cpp
	                 if(stk.size() == 0) stk.push_back(i);
	```
	If the `stk` is empty, meaning there is no corresponding opening parenthesis for this closing parenthesis, its index is added to `stk`.

8. **Match Parentheses**
	```cpp
	            else if(s[stk.back()] == '(')  stk.pop_back();
	```
	If the last element in `stk` corresponds to an opening parenthesis, it is removed (the parentheses are matched).

9. **Unmatched Closing Parenthesis**
	```cpp
	            else stk.push_back(i);
	```
	If the current closing parenthesis cannot be matched with the last opening parenthesis, its index is added to `stk`.

10. **Initialize Result String**
	```cpp
	    string res = "";
	```
	A string `res` is initialized to store the final result after removing the invalid parentheses.

11. **Create Set from Stack**
	```cpp
	    set<int> st(stk.begin(), stk.end());
	```
	A set `st` is created from the `stk` vector to efficiently check if an index is in the list of invalid parentheses.

12. **Loop Through String Again**
	```cpp
	    for(int i = 0; i < s.length(); i++) {
	```
	Another loop is used to iterate through the string `s` and build the result string by excluding the indices stored in `st`.

13. **Check Invalid Indices**
	```cpp
	        if(st.count(i)) continue;
	```
	If the current index `i` is found in the set `st` (meaning it corresponds to an invalid parenthesis), skip it and continue with the next character.

14. **Build Result String**
	```cpp
	        res += s[i];
	```
	If the current index `i` is valid, append the character at index `i` to the result string `res`.

15. **Return Statement**
	```cpp
	    return res;        
	```
	Return the result string `res`, which now contains the valid string with the minimum number of parentheses removed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes the string once, so the time complexity is O(n), where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

In the worst case, all parentheses could be unmatched, so the space complexity is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/)

---
{{< youtube tMzZUDR_cH0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
