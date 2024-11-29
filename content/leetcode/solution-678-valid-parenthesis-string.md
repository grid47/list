
+++
authors = ["grid47"]
title = "Leetcode 678: Valid Parenthesis String"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 678: Valid Parenthesis String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/678.webp"
youtube = "QhPdNS143Qg"
youtube_upload_date="2022-01-29"
youtube_thumbnail="https://i.ytimg.com/vi/QhPdNS143Qg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/678.webp" 
    alt="A string of parentheses being validated, with valid ones glowing softly and invalid ones fading away."
    caption="Solution to LeetCode 678: Valid Parenthesis String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string consisting of '(', ')', and '*', determine if the string is valid according to the following rules. '*' can be treated as a left parenthesis, a right parenthesis, or an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string containing only '(', ')', and '*' characters.
- **Example:** `"(*)"`
- **Constraints:**
	- 1 <= s.length <= 100
	- s[i] is either '(', ')', or '*'

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be true if the string is valid, otherwise false.
- **Example:** `true`
- **Constraints:**
	- The output will be a boolean value, either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently validate the string using a stack to account for both parentheses and '*' characters.

- 1. Traverse the string character by character.
- 2. Use two stacks: one for tracking '(' characters and one for tracking '*' characters.
- 3. If a ')' is encountered, check if there is a matching '(' or '*' to balance it.
- 4. After traversal, check if all '(' have corresponding ')' or '*' to balance them.
{{< dots >}}
### Problem Assumptions ✅
- All parentheses are balanced by either another parenthesis or a '*' character.
{{< dots >}}
## Examples 🧩
- **Input:** `"(*)"`  \
  **Explanation:** In this example, '*' can be treated as either a '(' or a ')', making the string valid.

- **Input:** `"(*))"`  \
  **Explanation:** The string is valid because '*' can be treated as '(', and the remaining parentheses are balanced.

{{< dots >}}
## Approach 🚀
We can use two stacks to track the positions of parentheses and '*' characters, ensuring the string remains valid.

### Initial Thoughts 💭
- We need to ensure that the parentheses are properly balanced, with '*' acting as a wildcard.
- Using two stacks will allow us to handle matching of both '(' and ')' while also utilizing '*' as a flexible placeholder.
{{< dots >}}
### Edge Cases 🌐
- An empty string is considered valid.
- The string length can be up to 100, which is manageable within the time constraints.
- A string consisting only of '*' characters is valid because '*' can be treated as empty, '(' or ')'.
- Ensure efficient handling of edge cases with '*' characters.
{{< dots >}}
## Code 💻
```cpp
bool checkValidString(string s) {
    stack<int> stk, str;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*')
            str.push(i);
        else if(s[i] == '(')
            stk.push(i);
        else {
            if(!stk.empty())
            stk.pop();
            else if(!str.empty()) str.pop();
            else return false;
        }
    }
    while(!stk.empty() && !str.empty() && stk.top() < str.top()) {
        str.pop();
        stk.pop();
    }

    return stk.empty();
}
```

This function checks if a string containing '(', ')', and '*' can be valid, where '*' can act as either '(' or ')'. It uses two stacks to match parentheses and a greedy approach to handle '*' characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	bool checkValidString(string s) {
	```
	Define the method 'checkValidString' that takes a string s and checks whether it contains a valid combination of parentheses and stars.

2. **Container Initialization**
	```cpp
	    stack<int> stk, str;
	```
	Initialize two stacks: one for holding indices of '(' (stk) and another for holding indices of '*' (str).

3. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize a counter variable (cnt), although it's not used in the current implementation.

4. **Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Start a loop to iterate through each character of the string s.

5. **Condition**
	```cpp
	        if(s[i] == '*')
	```
	Check if the current character is a '*' character.

6. **Stack Operation**
	```cpp
	            str.push(i);
	```
	If the character is '*', push its index onto the 'str' stack.

7. **Condition**
	```cpp
	        else if(s[i] == '(')
	```
	Check if the current character is an opening parenthesis '('.

8. **Stack Operation**
	```cpp
	            stk.push(i);
	```
	If the character is '(', push its index onto the 'stk' stack.

9. **Else Block**
	```cpp
	        else {
	```
	Else, when the character is a closing parenthesis ')'.

10. **Condition**
	```cpp
	            if(!stk.empty())
	```
	Check if the 'stk' stack is not empty, indicating there is an unmatched '(' available.

11. **Stack Operation**
	```cpp
	            stk.pop();
	```
	Pop the top element of the 'stk' stack, matching this ')' with an earlier '('.

12. **Condition**
	```cpp
	            else if(!str.empty()) str.pop();
	```
	If the 'stk' stack is empty, check if there is an unmatched '*' character. Pop the '*' from the 'str' stack.

13. **Return**
	```cpp
	            else return false;
	```
	If neither '(' nor '*' are available to match with the closing ')', return false indicating an invalid string.

14. **Block End**
	```cpp
	        }
	```
	End of the 'else' block for processing closing parentheses.

15. **Loop**
	```cpp
	    while(!stk.empty() && !str.empty() && stk.top() < str.top()) {
	```
	Use a while loop to match any remaining '(' in the 'stk' stack with '*' in the 'str' stack.

16. **Stack Operation**
	```cpp
	        str.pop();
	```
	Pop the top element of the 'str' stack to match it with the remaining '(' in the 'stk' stack.

17. **Stack Operation**
	```cpp
	        stk.pop();
	```
	Pop the top element of the 'stk' stack, effectively matching this '(' with a '*'.

18. **Return**
	```cpp
	    return stk.empty();
	```
	Return true if the 'stk' stack is empty (all '(' have been matched) or false if any unmatched '(' remain.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Both the best and worst case scenarios involve traversing the string once, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we may need to store all the parentheses in the stack, which takes O(n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-parenthesis-string/description/)

---
{{< youtube QhPdNS143Qg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
