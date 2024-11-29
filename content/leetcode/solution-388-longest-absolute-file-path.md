
+++
authors = ["grid47"]
title = "Leetcode 388: Longest Absolute File Path"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 388: Longest Absolute File Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/388.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/388.webp" 
    alt="A file path glowing as it grows, showing the longest path as it is traced step by step."
    caption="Solution to LeetCode 388: Longest Absolute File Path Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
In a file system where both directories and files are stored, we are given a string representation of the system. The string includes the directory structure, with tab characters ('\t') representing subdirectories and newline characters ('\n') representing file and directory boundaries. Each directory and file has a unique absolute path. Compute the length of the longest absolute path to a file. If no file exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string representing the file system's directory and file structure, with directories and files separated by newline ('\n') characters, and subdirectories indicated by tab ('\t') characters.
- **Example:** `input = "root\n\tsubfolder1\n\tsubfolder2\n\t\tfile1.txt"`
- **Constraints:**
	- 1 <= input.length <= 10^4
	- The input may contain lowercase and uppercase English letters, newline ('\n') and tab ('\t') characters, a dot ('.'), space (' '), and digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest absolute path to a file. If no file exists, return 0.
- **Example:** `Output: 21`
- **Constraints:**
	- The path length should include the full path to the file, including directory names separated by '/'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the absolute path length of the longest file in the system.

- Parse the string input to identify directory levels and files.
- Track the current directory level using a stack-like structure.
- Calculate the absolute path for each file and track the longest path found.
{{< dots >}}
### Problem Assumptions ✅
- The input represents a valid file system structure with no file or directory names having length 0.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: "root\n\tsubfolder1\n\tsubfolder2\n\t\tfile1.txt"`  \
  **Explanation:** The longest file path is 'root/subfolder2/file1.txt', which has a length of 21.

{{< dots >}}
## Approach 🚀
We will use a stack to track the length of the current path as we process each directory or file. When we encounter a file, we calculate its total path length and check if it is the longest file path encountered so far.

### Initial Thoughts 💭
- We need to differentiate between directories and files, which can be done by checking for a dot ('.') in the name.
- We can iterate through the string, updating the current path length as we encounter new levels of directories and calculating the file's path length when we find a file.
{{< dots >}}
### Edge Cases 🌐
- Empty input will not be provided as per the problem statement.
- Ensure that the algorithm handles inputs with the maximum allowed length efficiently.
- The input may consist only of directories, in which case the result should be 0.
- Ensure the algorithm handles deeply nested structures and large numbers of files.
{{< dots >}}
## Code 💻
```cpp
int lengthLongestPath(string ipt) {
    
    vector<int> levels(300, 0);
    
    int level = 0;
    bool isFile = false;
    int ans = 0;
    int len = 0;

    for(char c: ipt) {
        switch(c) {
            case '\n':
                level = 0, isFile = false, len = 0; break;
            case '\t':
                level++; break;
            case '.':
                isFile = true;
            default:
                len++;
                levels[level] = len;
                if(isFile) {
                    ans = max(ans, accumulate(levels.begin(), levels.begin() + level + 1, 0) + level); 
                }
        }
    }
    return ans;

}
```

This code finds the longest file path in a directory structure. The input is a string representing the directory structure, and it returns the length of the longest file path.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int lengthLongestPath(string ipt) {
	```
	Define the function 'lengthLongestPath' that takes a string 'ipt' representing a directory structure and returns the length of the longest path to a file.

2. **Data Structure**
	```cpp
	    vector<int> levels(300, 0);
	```
	Declare a vector 'levels' to store the length of the current path at each level (up to 300 levels).

3. **Variable Initialization**
	```cpp
	    int level = 0;
	```
	Initialize 'level' to keep track of the current level in the directory structure.

4. **Variable Initialization**
	```cpp
	    bool isFile = false;
	```
	Initialize 'isFile' to check if the current string represents a file.

5. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize 'ans' to store the length of the longest file path.

6. **Variable Initialization**
	```cpp
	    int len = 0;
	```
	Initialize 'len' to store the current length of the path being processed.

7. **Loop Iteration**
	```cpp
	    for(char c: ipt) {
	```
	Start a loop to iterate through each character in the input string 'ipt'.

8. **Switch Case**
	```cpp
	        switch(c) {
	```
	Use a switch-case statement to handle different types of characters (newlines, tabs, periods, and others).

9. **Case Handling**
	```cpp
	            case '\n':
	```
	Handle the case when a newline character is encountered.

10. **Reset Variables**
	```cpp
	                level = 0, isFile = false, len = 0; break;
	```
	Reset the variables 'level', 'isFile', and 'len' when encountering a newline character.

11. **Case Handling**
	```cpp
	            case '\t':
	```
	Handle the case when a tab character is encountered.

12. **Level Increase**
	```cpp
	                level++; break;
	```
	Increase the 'level' when a tab character is encountered (indicating a deeper directory level).

13. **Case Handling**
	```cpp
	            case '.':
	```
	Handle the case when a period character is encountered (indicating a file).

14. **File Check**
	```cpp
	                isFile = true;
	```
	Set 'isFile' to true when a period character is encountered, indicating that the current string is a file.

15. **Default Case**
	```cpp
	            default:
	```
	Handle the default case for non-special characters (normal directory or file name characters).

16. **Path Length Calculation**
	```cpp
	                len++;
	```
	Increment the 'len' for each character that is part of a directory or file name.

17. **Path Length Calculation**
	```cpp
	                levels[level] = len;
	```
	Store the current path length at the given 'level'.

18. **File Path Calculation**
	```cpp
	                if(isFile) {
	```
	Check if the current string is a file.

19. **Max Path Length Calculation**
	```cpp
	                    ans = max(ans, accumulate(levels.begin(), levels.begin() + level + 1, 0) + level); 
	```
	If it's a file, calculate the path length by summing up the path lengths at each level and update 'ans' if it's the longest path.

20. **Return Statement**
	```cpp
	    return ans;
	```
	Return the longest file path length stored in 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the path lengths for each directory level in a stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-absolute-file-path/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
