
+++
authors = ["grid47"]
title = "Leetcode 1209: Remove All Adjacent Duplicates in String II"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1209: Remove All Adjacent Duplicates in String II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "w6LcypDgC4w"
youtube_upload_date="2022-05-06"
youtube_thumbnail="https://i.ytimg.com/vi/w6LcypDgC4w/maxresdefault.jpg"
comments = true
+++



---
You are given a string s and an integer k. A k duplicate removal consists of selecting k adjacent and equal letters from the string and removing them, causing the left and the right side of the deleted substring to concatenate together. Repeat this operation until no more such removals are possible. Return the final string after all removals are done.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s and an integer k.
- **Example:** `Input: s = "aabbcc", k = 2`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 2 <= k <= 10^4
	- s consists of lowercase English letters only.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final string after all k duplicate removals have been made.
- **Example:** `Output: ""`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to continuously remove adjacent duplicate letters from the string until no more removals can be made.

- Iterate through the string and check for k adjacent equal letters.
- Whenever such a substring is found, remove it and concatenate the remaining parts of the string.
- Repeat this process until no more substrings can be removed.
{{< dots >}}
### Problem Assumptions ✅
- The string s may contain substrings with duplicate characters that need to be removed.
- The solution should handle cases where there are no substrings to remove, as well as when all characters can be removed.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "aabbcc", k = 2`  \
  **Explanation:** Since the string contains only pairs of identical characters, all of them will be removed, leaving the string empty.

- **Input:** `Input: s = "aaaabbbcccddeee", k = 3`  \
  **Explanation:** After removing 'aaa', 'bbb', 'ccc', and 'ddd', the string reduces to 'ddee'.

{{< dots >}}
## Approach 🚀
We can use a stack-based approach to efficiently remove duplicate substrings from the string. The stack will help us keep track of consecutive characters and their counts, allowing us to easily identify and remove substrings of length k.

### Initial Thoughts 💭
- A stack can be used to keep track of characters and their counts.
- When a character appears k times consecutively, it can be removed.
- The stack will help in managing the characters and removing the substrings efficiently without needing to traverse the string multiple times.
{{< dots >}}
### Edge Cases 🌐
- The string should never be empty as per the constraints.
- The algorithm must handle large strings efficiently, up to a length of 10^5.
- Consider cases where no duplicates are found or where the entire string consists of the same character.
- The solution should efficiently handle the maximum possible input size.
{{< dots >}}
## Code 💻
```cpp
string removeDuplicates(string s, int k) {
    vector<pair<int, char>> stk = {{0, '#'}};
    
    for(char c : s) {
        if(stk.back().second != c)
            stk.push_back({1, c});
        else if(++stk.back().first == k)
            stk.pop_back();
    }
    
    string res;
    for(auto x: stk)
        res.append(x.first, x.second);
    
    return res;
    
}
```

This function removes adjacent duplicates from a string, where a character that appears consecutively `k` times is completely removed. The function uses a stack to keep track of characters and their counts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string removeDuplicates(string s, int k) {
	```
	Define the function `removeDuplicates` which takes a string `s` and an integer `k` as inputs. The goal is to remove adjacent characters that appear consecutively `k` times.

2. **Stack Initialization**
	```cpp
	    vector<pair<int, char>> stk = {{0, '#'}};
	```
	Initialize a stack `stk` that will hold pairs of integers and characters. The stack starts with a dummy pair `{0, '#'}` to simplify the logic of checking the first character.

3. **Loop Through Input String**
	```cpp
	    for(char c : s) {
	```
	Start a loop that iterates over each character `c` in the input string `s`.

4. **Check for Non-Matching Character**
	```cpp
	        if(stk.back().second != c)
	```
	If the current character `c` does not match the character at the top of the stack, proceed to the next step.

5. **Push New Character to Stack**
	```cpp
	            stk.push_back({1, c});
	```
	Push a new pair `{1, c}` to the stack, indicating that the character `c` has appeared once consecutively.

6. **Check for Consecutive Duplicates**
	```cpp
	        else if(++stk.back().first == k)
	```
	If the current character `c` matches the top of the stack, increment the count of consecutive occurrences. If the count reaches `k`, proceed to the next step.

7. **Pop the Stack**
	```cpp
	            stk.pop_back();
	```
	Pop the top element from the stack, as the character has occurred `k` times consecutively and should be removed.

8. **Result String Initialization**
	```cpp
	    string res;
	```
	Initialize an empty string `res` to store the final result after removing the duplicates.

9. **Rebuild Result String**
	```cpp
	    for(auto x: stk)
	```
	Iterate over the stack `stk` to rebuild the result string. Each element in the stack is a pair, where the first element is the count and the second element is the character.

10. **Append Characters to Result**
	```cpp
	        res.append(x.first, x.second);
	```
	For each pair in the stack, append the character `x.second` to the result string `res`, `x.first` times.

11. **Return Final Result**
	```cpp
	    return res;
	```
	Return the result string `res`, which contains the characters after removing all adjacent duplicates that appeared consecutively `k` times.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string. Each character is processed at most twice.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we need to store the stack to manage the characters and their counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/)

---
{{< youtube w6LcypDgC4w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
