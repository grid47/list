
+++
authors = ["grid47"]
title = "Leetcode 2788: Split Strings by Separator"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2788: Split Strings by Separator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "DdjLhSeodGs"
youtube_upload_date="2023-07-23"
youtube_thumbnail="https://i.ytimg.com/vi/DdjLhSeodGs/maxresdefault.jpg"
comments = true
+++



---
You are given an array 'words' of strings and a character 'separator'. Your task is to split each string in 'words' by the separator. After the split, return an array of strings containing the new substrings, excluding any empty strings.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of strings 'words' and a character 'separator'.
- **Example:** `Input: words = ['apple.orange.banana', 'pear.grape', 'peach'], separator = '.'`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 20
	- characters in words[i] are either lowercase English letters or characters from the string '.,|$#@'.
	- separator is a character from the string '.,|$#@'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing the resulting substrings formed after splitting by the separator, excluding empty strings.
- **Example:** `Output: ['apple', 'orange', 'banana', 'pear', 'grape', 'peach']`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Split each word in the array by the separator and exclude any empty strings.

- Iterate through each word in the 'words' array.
- For each word, split it by the 'separator' character.
- Push non-empty substrings into the result array.
{{< dots >}}
### Problem Assumptions ✅
- Each string in 'words' contains only lowercase English letters or characters from the set '.,|$#@'.
- The separator character is one of the allowed characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ['apple.orange.banana', 'pear.grape', 'peach'], separator = '.'`  \
  **Explanation:** Split each string by the '.' character, and exclude empty strings. Resulting strings: ['apple', 'orange', 'banana', 'pear', 'grape', 'peach'].

- **Input:** `Input: words = ['###'], separator = '#' `  \
  **Explanation:** The string '###' contains only separators, so the result is an empty array [] because no valid substrings are formed.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating over each string in the input array and using the separator to split them into substrings.

### Initial Thoughts 💭
- The input array is small, so iterating through each string and splitting them by a separator is efficient.
- I will split each string and discard empty results to avoid unnecessary entries.
{{< dots >}}
### Edge Cases 🌐
- If 'words' contains empty strings, make sure to exclude them after splitting.
- Ensure that the algorithm handles the upper bounds of the input size efficiently.
- If all characters are separators (e.g., '###'), the result should be an empty array.
- Make sure to handle all specified edge cases within the constraints.
{{< dots >}}
## Code 💻
```cpp
vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
    
    vector<string> ans;
    
    for(int i = 0; i < words.size(); i++) {
        string cur = "";
        
        for(int j = 0; j < words[i].size(); j++) {
            if(words[i][j] == sep) {
                if(cur != "")
                ans.push_back(cur);
                cur = "";
            } else if(j == words[i].size() - 1) {
                cur += words[i][j];                    
                ans.push_back(cur);
                cur = "";
            } else 
            cur += words[i][j];
        }
        
    }
    return ans;
}
```

This function splits words from a vector of strings `words` by a given separator `sep` and returns a vector of split substrings. It iterates through each word, checking for occurrences of the separator and creating substrings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
	```
	The function `splitWordsBySeparator` is declared, accepting a vector of strings `words` and a character separator `sep`. It returns a vector of strings containing the substrings created by splitting each word at the separator.

2. **Variable Initialization**
	```cpp
	    vector<string> ans;
	```
	A vector `ans` is initialized to store the resulting substrings after splitting the words.

3. **Loop Initialization**
	```cpp
	    for(int i = 0; i < words.size(); i++) {
	```
	A for loop starts to iterate through each word in the vector `words`.

4. **Variable Initialization**
	```cpp
	        string cur = "";
	```
	A string variable `cur` is initialized to temporarily hold each substring as we iterate through the characters of each word.

5. **Inner Loop Initialization**
	```cpp
	        for(int j = 0; j < words[i].size(); j++) {
	```
	A nested for loop starts to iterate through each character of the current word `words[i]`.

6. **Separator Check**
	```cpp
	            if(words[i][j] == sep) {
	```
	An if condition checks whether the current character is equal to the separator `sep`.

7. **Substring Addition**
	```cpp
	                if(cur != "")
	```
	A check to ensure the current substring `cur` is not empty before adding it to the result vector `ans`.

8. **Push Substring**
	```cpp
	                ans.push_back(cur);
	```
	If the current substring `cur` is non-empty, it is added to the result vector `ans`.

9. **Reset Current Substring**
	```cpp
	                cur = "";
	```
	The current substring `cur` is reset to an empty string to start building the next substring.

10. **End Separator Check**
	```cpp
	            } else if(j == words[i].size() - 1) {
	```
	An else if condition checks if the current character is the last one in the word.

11. **Add Last Character**
	```cpp
	                cur += words[i][j];                    
	```
	If it is the last character, it is added to the current substring `cur`.

12. **Push Last Substring**
	```cpp
	                ans.push_back(cur);
	```
	Once the last character is added, the current substring `cur` is pushed into the result vector `ans`.

13. **Reset Current Substring**
	```cpp
	                cur = "";
	```
	The current substring `cur` is reset to an empty string after processing the last character.

14. **Else Condition**
	```cpp
	            } else 
	```
	The else condition handles the case when the current character is not the separator.

15. **Build Substring**
	```cpp
	            cur += words[i][j];
	```
	If the current character is not the separator, it is appended to the current substring `cur`.

16. **End Outer Loop**
	```cpp
	    }
	```
	End of the outer loop that iterates over each word in `words`.

17. **Return Result**
	```cpp
	    return ans;
	```
	The result vector `ans`, containing the split substrings, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Time complexity is linear in relation to the total length of the input strings.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is linear since we store the resulting substrings in a separate array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-strings-by-separator/description/)

---
{{< youtube DdjLhSeodGs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
