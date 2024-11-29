
+++
authors = ["grid47"]
title = "Leetcode 2810: Faulty Keyboard"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2810: Faulty Keyboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "HuCSgRBf-B8"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi/HuCSgRBf-B8/maxresdefault.jpg"
comments = true
+++



---
You are given a string s. On your faulty keyboard, whenever you press 'i', the string typed so far is reversed. Pressing any other character types it normally. Simulate typing the entire string and return the final string displayed on the screen.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string s consisting of lowercase English letters, where the first character is not 'i'.
- **Example:** `Input: s = "hello"`
- **Constraints:**
	- 1 <= s.length <= 100
	- s consists of lowercase English letters
	- s[0] != 'i'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final string that will be displayed on the screen after typing all characters in the string s.
- **Example:** `Output: "hll"`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the process of typing each character of the string on a faulty keyboard, where typing 'i' reverses the string.

- 1. Initialize an empty string to simulate the screen content.
- 2. For each character in the string s, add it to the string unless it is 'i'.
- 3. If the character is 'i', reverse the string typed so far.
{{< dots >}}
### Problem Assumptions ✅
- The string length will not exceed 100 characters.
- The input string will always begin with a character other than 'i'.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "hello"`  \
  **Explanation:** Typing the characters one by one and applying the reverse operation on encountering 'i' leads to the final string 'hll'.

- **Input:** `Input: s = "worldi"`  \
  **Explanation:** After typing 'world' and then encountering 'i', the string is reversed to 'dworl'.

{{< dots >}}
## Approach 🚀
We will simulate the process of typing the string and apply the reverse operation when encountering 'i'.

### Initial Thoughts 💭
- We only need to reverse the string when 'i' is encountered, which makes the problem manageable.
- We need to ensure that the string is updated after every character input, and we reverse only when needed.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one character in the string.
- Ensure the solution works efficiently for strings of length up to 100.
- If the string contains no 'i', the output will simply be the same as the input string.
- The solution must handle the string reversal operation efficiently.
{{< dots >}}
## Code 💻
```cpp
string finalString(string s) {
    string res = "";
    for(auto c : s){
        if(c == 'i'){
            if(res.size()){
                reverse(res.begin(), res.end());
            }
            
        }else
         res+=c;
    }
    return res;
}
```

This function processes the input string 's'. It reverses the string 'res' whenever the character 'i' is encountered. The final string is returned after applying this operation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string finalString(string s) {
	```
	The function 'finalString' takes a string 's' as input and returns a string as output after processing.

2. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Initialize an empty string 'res' to store the modified characters of the input string.

3. **Looping**
	```cpp
	    for(auto c : s){
	```
	Iterate through each character 'c' in the input string 's'.

4. **Condition Check**
	```cpp
	        if(c == 'i'){
	```
	Check if the current character 'c' is 'i'. If true, the string 'res' will be reversed.

5. **Condition Check**
	```cpp
	            if(res.size()){
	```
	Check if the string 'res' is non-empty before attempting to reverse it.

6. **String Reversal**
	```cpp
	                reverse(res.begin(), res.end());
	```
	Reverse the contents of the string 'res' using the 'reverse' function from the C++ standard library.

7. **Condition Check**
	```cpp
	        }else
	```
	If the character is not 'i', continue processing the character by adding it to 'res'.

8. **String Concatenation**
	```cpp
	         res+=c;
	```
	Append the current character 'c' to the string 'res'.

9. **Return Statement**
	```cpp
	    return res;
	```
	Return the modified string 'res' after all characters have been processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we reverse the string on each 'i' encounter, leading to a linear time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store the result string which can grow up to the size of the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/faulty-keyboard/description/)

---
{{< youtube HuCSgRBf-B8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
