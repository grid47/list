
+++
authors = ["grid47"]
title = "Leetcode 385: Mini Parser"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 385: Mini Parser in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/385.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/385.webp" 
    alt="A series of nested lists being parsed, with each level gently unfolding and being highlighted."
    caption="Solution to LeetCode 385: Mini Parser Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string s representing a serialized nested list, implement a parser to deserialize it and return the deserialized NestedInteger.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s representing the serialized nested list.
- **Example:** `s = '[789, [1011, 1213], 1415]'`
- **Constraints:**
	- 1 <= s.length <= 50,000
	- s consists of digits, square brackets '[]', negative sign '-', and commas ','
	- The string s is the serialization of a valid NestedInteger
	- All values are within the range [-10^6, 10^6]

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a NestedInteger object representing the deserialized nested list.
- **Example:** `Output: [789, [1011, 1213], 1415]`
- **Constraints:**
	- The deserialized object should match the nested list structure.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to parse the serialized string and reconstruct the correct NestedInteger object.

- Traverse the string character by character.
- Identify numbers and handle their potential negative signs.
- Identify opening brackets '[' and create new NestedInteger objects for lists.
- Identify closing brackets ']' and complete the current list.
- Use a stack to maintain the current state while parsing nested lists.
{{< dots >}}
### Problem Assumptions ✅
- The input string is a valid serialized NestedInteger and will not contain malformed lists.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: '[789, [1011, 1213], 1415]'`  \
  **Explanation:** The string represents a list with three elements: 789, a nested list [1011, 1213], and 1415.

{{< dots >}}
## Approach 🚀
The approach involves parsing the string to correctly build a NestedInteger object, using a stack to handle nested lists and ensuring that each element is correctly identified as an integer or list.

### Initial Thoughts 💭
- We need to distinguish between integers and lists while parsing the string.
- A stack will be useful to manage the nesting of lists during parsing.
{{< dots >}}
### Edge Cases 🌐
- Ensure that input strings are non-empty and valid.
- Handle input strings as large as 50,000 characters efficiently.
- Ensure the solution handles negative numbers and deep nesting correctly.
- The solution must parse the string in linear time relative to its length.
{{< dots >}}
## Code 💻
```cpp
NestedInteger deserialize(string s) {
    
    function<bool(char)> isnumber = [](char c) { return (c == '-') || isdigit(c); };
    
    stack<NestedInteger> stk;
    stk.push(NestedInteger());

    for(auto it = s.begin(); it != s.end();) {
        const char &c = *it;
        if(isnumber(c)) {
            auto it2 = find_if_not(it, s.end(), isnumber);
            int val = stoi(string(it, it2));
            stk.top().add(NestedInteger(val));
            it = it2;
        }
        else {
            if(c == '[') {
                stk.push(NestedInteger());
            } else if (c == ']') {
                NestedInteger ni = stk.top();
                stk.pop();
                stk.top().add(ni);
            }
            it++;
        }
    }
    NestedInteger res = stk.top().getList().front();
    return res;
}
```

This function deserializes a string representing a nested integer list structure and returns the corresponding NestedInteger object.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	NestedInteger deserialize(string s) {
	```
	This is the function definition of 'deserialize' which takes a string 's' as input and returns a NestedInteger object.

2. **Lambda Function**
	```cpp
	    function<bool(char)> isnumber = [](char c) { return (c == '-') || isdigit(c); };
	```
	This lambda function checks if a character is a number (including negative sign).

3. **Stack Initialization**
	```cpp
	    stack<NestedInteger> stk;
	```
	A stack to store NestedInteger objects which will help in building the deserialized structure.

4. **Push Operation**
	```cpp
	    stk.push(NestedInteger());
	```
	Push an empty NestedInteger to the stack as the starting point for building the structure.

5. **Iterator**
	```cpp
	    for(auto it = s.begin(); it != s.end();) {
	```
	A for-loop to iterate through each character in the string 's'.

6. **Character Access**
	```cpp
	        const char &c = *it;
	```
	Access the current character of the string 's'.

7. **Check for Number**
	```cpp
	        if(isnumber(c)) {
	```
	Check if the current character is a number (either positive or negative).

8. **Find Non-Number**
	```cpp
	            auto it2 = find_if_not(it, s.end(), isnumber);
	```
	Find the first character in the string 's' that is not a number.

9. **Integer Conversion**
	```cpp
	            int val = stoi(string(it, it2));
	```
	Convert the substring representing a number into an integer.

10. **Add to Stack**
	```cpp
	            stk.top().add(NestedInteger(val));
	```
	Add the integer value as a NestedInteger object to the top of the stack.

11. **Update Iterator**
	```cpp
	            it = it2;
	```
	Update the iterator to the next non-number character.

12. **Else Block**
	```cpp
	        else {
	```
	If the character is not a number, check for the special characters '[' or ']'.

13. **Opening Bracket Check**
	```cpp
	            if(c == '[') {
	```
	Check if the character is an opening bracket '[' which indicates the start of a new list.

14. **Push New NestedInteger**
	```cpp
	                stk.push(NestedInteger());
	```
	Push a new empty NestedInteger to the stack to represent the new list.

15. **Closing Bracket Check**
	```cpp
	            } else if (c == ']') {
	```
	Check if the character is a closing bracket ']' which indicates the end of a list.

16. **Pop and Add to Parent**
	```cpp
	                NestedInteger ni = stk.top();
	```
	Pop the top NestedInteger object from the stack.

17. **Pop Stack**
	```cpp
	                stk.pop();
	```
	Pop the top element from the stack after storing it in 'ni'.

18. **Add to Parent List**
	```cpp
	                stk.top().add(ni);
	```
	Add the popped NestedInteger object to the top NestedInteger in the stack.

19. **Increment Iterator**
	```cpp
	            it++;
	```
	Increment the iterator to move to the next character in the string.

20. **Return Result**
	```cpp
	    NestedInteger res = stk.top().getList().front();
	```
	Get the first element from the list in the top NestedInteger object in the stack.

21. **Return Result**
	```cpp
	    return res;
	```
	Return the deserialized NestedInteger object.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear with respect to the length of the input string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for the stack and NestedInteger objects.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/mini-parser/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
