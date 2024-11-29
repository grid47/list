
+++
authors = ["grid47"]
title = "Leetcode 71: Simplify Path"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 71: Simplify Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/71.webp"
youtube = "4e1gVeQ0AEs"
youtube_upload_date="2022-02-26"
youtube_thumbnail="https://i.ytimg.com/vi/4e1gVeQ0AEs/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/71.webp" 
    alt="A smooth, glowing path being simplified, with unnecessary elements fading away."
    caption="Solution to LeetCode 71: Simplify Path Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an absolute path for a Unix-style file system, simplify the path by following Unix file system rules. Handle '.' and '..' as current and parent directories, and multiple slashes as a single slash. Return the simplified canonical path.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string representing the absolute path of a file or directory in a Unix-style file system.
- **Example:** `Input: path = "/home//docs/"`
- **Constraints:**
	- 1 <= path.length <= 3000
	- path consists of English letters, digits, period '.', slash '/', or '_'.
	- The path is a valid absolute Unix path.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the simplified canonical path as a string.
- **Example:** `Output: "/home/docs"`
- **Constraints:**
	- The output must be a valid simplified absolute path.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simplify the absolute Unix path by handling '.' and '..' according to file system rules.

- Split the path by the '/' character.
- Iterate through each segment of the path.
- Push valid directory names onto a stack, and pop the stack when encountering '..'.
- Ignore '.' and empty segments.
- Finally, reconstruct the canonical path from the stack.
{{< dots >}}
### Problem Assumptions ✅
- The input path is well-formed and always starts with a slash ('/').
- The path is an absolute Unix-style file system path.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: path = "/home//docs/"`  \
  **Explanation:** Multiple consecutive slashes are treated as a single slash, resulting in the simplified path '/home/docs'.

- **Input:** `Input: path = "/home/user/../data/files/"`  \
  **Explanation:** The '..' refers to the parent directory, simplifying the path to '/home/data/files'.

{{< dots >}}
## Approach 🚀
Use a stack-based approach to simplify the Unix path by processing each component in sequence.

### Initial Thoughts 💭
- The problem requires handling several path components, including valid directory names, '.' (current directory), and '..' (parent directory).
- A stack data structure is useful for maintaining the current directory context.
- The challenge is to correctly handle '..' and '.' while ignoring extraneous slashes and invalid period-based directory names.
{{< dots >}}
### Edge Cases 🌐
- An empty input is not possible due to the constraints (1 <= path.length).
- Handle the largest possible input, where the length of the path is 3000 characters.
- Handle cases like '/..' where going up from the root directory results in the root directory itself.
- The solution must efficiently handle large inputs while simplifying the path.
{{< dots >}}
## Code 💻
```cpp
string simplifyPath(string path) {
    
    set<string> dot = {"..", ".", ""};
    
    string res = "", tmp;
    stringstream ss(path);
    
    stack<string> stk;
    
    while(getline(ss, tmp, '/')) {
        if(tmp == ".." && !stk.empty()) stk.pop();
        else if (!dot.count(tmp)) stk.push(tmp);
    }

    while(!stk.empty()) {
        res = "/" + stk.top() + res;
        stk.pop();
    }
    return res == ""? "/": res;
}
```

This code simplifies a given file path by removing redundant '.' and '..' segments.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string simplifyPath(string path) {
	```
	Declares a function `simplifyPath` that takes a string `path` as input and returns a simplified path as a string.

2. **Set Initialization**
	```cpp
	    set<string> dot = {"..", ".", ""};
	```
	Creates a set `dot` to store invalid path segments: '..', '.', and empty strings.

3. **Variable Initialization**
	```cpp
	    string res = "", tmp;
	```
	Initializes `res` to store the simplified path and `tmp` to hold temporary path segments.

4. **String Stream Initialization**
	```cpp
	    stringstream ss(path);
	```
	Creates a string stream `ss` to parse the input `path`.

5. **Stack Initialization**
	```cpp
	    stack<string> stk;
	```
	Creates a stack `stk` to store valid path segments.

6. **Loop Iteration**
	```cpp
	    while(getline(ss, tmp, '/')) {
	```
	Iterates through each path segment in the string stream `ss`.

7. **Conditions**
	```cpp
	        if(tmp == ".." && !stk.empty()) stk.pop();
	```
	If the current segment is '..' and the stack is not empty, pop the top element from the stack (go back one directory).

8. **Conditions**
	```cpp
	        else if (!dot.count(tmp)) stk.push(tmp);
	```
	If the current segment is not a '.' or '..' or empty, push it onto the stack.

9. **Loop Iteration**
	```cpp
	    while(!stk.empty()) {
	```
	Iterates while the stack is not empty.

10. **String Concatenation**
	```cpp
	        res = "/" + stk.top() + res;
	```
	Concatenates the top element of the stack to the `res` string, prepending a '/'.

11. **Stack Operations**
	```cpp
	        stk.pop();
	```
	Pops the top element from the stack.

12. **Conditional Return**
	```cpp
	    return res == ""? "/": res;
	```
	Returns '/' if the `res` string is empty, otherwise returns the constructed simplified path.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We process each character of the input path once, making the time complexity linear in terms of the path length.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is proportional to the number of components in the path, which can be at most n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/simplify-path/description/)

---
{{< youtube 4e1gVeQ0AEs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
