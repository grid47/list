
+++
authors = ["grid47"]
title = "Leetcode 1593: Split a String Into the Max Number of Unique Substrings"
date = "2024-05-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1593: Split a String Into the Max Number of Unique Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fLjeVALxzjg"
youtube_upload_date="2024-10-21"
youtube_thumbnail="https://i.ytimg.com/vi/fLjeVALxzjg/maxresdefault.jpg"
comments = true
+++



---
Given a string s, your task is to split it into the maximum number of non-empty substrings such that all substrings are unique. You are allowed to split the string in any way, but each substring in the split must not repeat.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s, where the length of s is between 1 and 16. The string contains only lowercase English letters.
- **Example:** `Input: s = "abcab"`
- **Constraints:**
	- 1 <= s.length <= 16
	- s consists of lowercase English letters only

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of unique substrings that the string can be split into.
- **Example:** `Output: 4`
- **Constraints:**
	- The substrings must be unique and non-empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of unique substrings by splitting the string. You should use backtracking to explore all possible splits and track the uniqueness of each substring.

- 1. Start by initializing an empty set to store unique substrings.
- 2. Use a backtracking approach to try different substrings at each position.
- 3. For each substring, check if it's already in the set of unique substrings. If not, add it to the set and continue exploring further.
- 4. When a valid split is reached, keep track of the maximum number of unique substrings found.
{{< dots >}}
### Problem Assumptions ✅
- The string s is non-empty.
- We are only dealing with lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "abcab"`  \
  **Explanation:** One possible maximal split is ['a', 'b', 'c', 'ab']. In this split, all substrings are unique, and we have 4 unique substrings.

- **Input:** `Input: s = "aaaa"`  \
  **Explanation:** The only valid split is ['a'], as all other possible splits repeat substrings. Hence, the maximum number of unique substrings is 1.

{{< dots >}}
## Approach 🚀
The approach involves using backtracking to explore all possible splits of the string while ensuring that the substrings are unique. We will maintain a set of substrings to keep track of uniqueness.

### Initial Thoughts 💭
- The problem requires checking different ways to split the string while ensuring uniqueness at each step.
- Backtracking will help in exploring all possible splits.
- Using backtracking with a set for uniqueness seems to be a good strategy. The constraints are small enough (with string length ≤ 16) to allow exploring all possible splits.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, the result should be 0.
- Even though the string length is small, ensure that the backtracking approach can handle the largest possible input of length 16 efficiently.
- If all characters in the string are the same, the maximum number of unique substrings will be 1.
- Make sure the solution works efficiently within the time and space constraints, especially for the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int mx = 1, n;
string s;

int maxUniqueSplit(string s) {
    set<string> cnt;
    string tmp = "";
    n = s.size();
    this->s = s;
    bt(0, tmp, cnt);
    
    return mx;
}

void bt(int idx, string tmp, set<string> cnt) {
    if(idx == n) {
        mx = max(mx, (int)cnt.size());
        return;
    }
    
    for(int i = idx; i < n; i++) {
        tmp += s[i];
        if(!cnt.count(tmp)) {
            cnt.insert(tmp);
            bt(i + 1, "", cnt);
            cnt.erase(tmp);
        }
    }
}
```

This solution aims to find the maximum number of unique splits of a string, using a backtracking approach where substrings are considered for splitting, and a set is used to track unique splits.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int mx = 1, n;
	```
	This line initializes the variable `mx` to store the maximum number of unique splits (set to 1 initially) and `n` to store the length of the string.

2. **Variable Declaration**
	```cpp
	string s;
	```
	This declares the string variable `s`, which will hold the input string for the unique splits calculation.

3. **Function Declaration**
	```cpp
	int maxUniqueSplit(string s) {
	```
	This is the declaration of the main function `maxUniqueSplit`, which takes a string `s` and returns an integer, representing the maximum number of unique splits.

4. **Set Initialization**
	```cpp
	    set<string> cnt;
	```
	This initializes a set `cnt` to store the substrings that have been used as splits. The set automatically handles duplicate values.

5. **String Initialization**
	```cpp
	    string tmp = "";
	```
	This initializes an empty string `tmp` which will hold the current substring being considered for splitting.

6. **Length Calculation**
	```cpp
	    n = s.size();
	```
	This sets the variable `n` to the size of the string `s`, which represents the length of the input string.

7. **String Assignment**
	```cpp
	    this->s = s;
	```
	This assigns the input string `s` to the class's string `s`. This line assumes that `s` is a member variable of a class.

8. **Recursive Call**
	```cpp
	    bt(0, tmp, cnt);
	```
	This calls the backtracking function `bt`, passing the initial index (`0`), the empty string `tmp`, and the set `cnt` to start the recursive process of finding unique splits.

9. **Return Statement**
	```cpp
	    return mx;
	```
	This returns the value of `mx`, which holds the maximum number of unique splits found by the backtracking function.

10. **Empty Line**
	```cpp
	
	```
	This is an empty line before the declaration of the backtracking function.

11. **Backtracking Function Declaration**
	```cpp
	void bt(int idx, string tmp, set<string> cnt) {
	```
	This is the declaration of the backtracking function `bt`, which takes the current index `idx`, a temporary string `tmp`, and a set of previously seen substrings `cnt`.

12. **Base Case**
	```cpp
	    if(idx == n) {
	```
	This is the base case of the recursion, which checks if the index `idx` has reached the length of the string `n`. If it has, the function processes the result.

13. **Updating Maximum**
	```cpp
	        mx = max(mx, (int)cnt.size());
	```
	This updates the value of `mx` to be the maximum of its current value and the size of the set `cnt`, which represents the number of unique substrings found so far.

14. **Return Statement**
	```cpp
	        return;
	```
	This returns from the backtracking function, ending the recursion for the current path.

15. **Loop (Backtracking)**
	```cpp
	    for(int i = idx; i < n; i++) {
	```
	This loop iterates from the current index `idx` to the end of the string `n`, trying all possible substrings starting from `idx`.

16. **Substring Construction**
	```cpp
	        tmp += s[i];
	```
	This appends the character `s[i]` to the string `tmp`, gradually building up the current substring.

17. **Checking for Uniqueness**
	```cpp
	        if(!cnt.count(tmp)) {
	```
	This checks if the substring `tmp` is already in the set `cnt`. If it is not, the substring is unique and can be considered for the next step.

18. **Inserting Substring**
	```cpp
	            cnt.insert(tmp);
	```
	This inserts the substring `tmp` into the set `cnt`.

19. **Recursive Call**
	```cpp
	            bt(i + 1, "", cnt);
	```
	This recursively calls the backtracking function, passing the next index `i + 1`, an empty string for the next substring, and the updated set `cnt`.

20. **Removing Substring**
	```cpp
	            cnt.erase(tmp);
	```
	This removes the substring `tmp` from the set `cnt` after the recursive call, ensuring that the set only contains substrings for the current path.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - If the string can be split in a way that no further exploration is needed.
- **Average Case:** O(2^n) - In the worst case, backtracking explores all possible splits of the string.
- **Worst Case:** O(2^n) - The backtracking approach explores all subsets of the string, where n is the length of the string.

The time complexity is exponential due to the backtracking approach that explores all possible splits.

### Space Complexity 💾
- **Best Case:** O(n) - Space is mainly used by the set of substrings and the recursion stack.
- **Worst Case:** O(n) - Space is required to store the set of substrings and recursive function calls.

The space complexity is linear in the worst case due to the storage of substrings in a set and the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/)

---
{{< youtube fLjeVALxzjg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
