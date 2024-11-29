
+++
authors = ["grid47"]
title = "Leetcode 1625: Lexicographically Smallest String After Applying Operations"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1625: Lexicographically Smallest String After Applying Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Depth-First Search","Breadth-First Search","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "S_WnsW5cdgI"
youtube_upload_date="2020-10-18"
youtube_thumbnail="https://i.ytimg.com/vi/S_WnsW5cdgI/maxresdefault.jpg"
comments = true
+++



---
Given a string s of even length consisting of digits from 0 to 9, and two integers a and b, return the lexicographically smallest string that can be obtained by applying two operations any number of times: adding a to all odd indices of s (with wrapping) and rotating s to the right by b positions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s of even length, containing digits from 0 to 9, and two integers a and b.
- **Example:** `s = "3637", a = 7, b = 2`
- **Constraints:**
	- 2 <= s.length <= 100
	- s.length is even.
	- s consists of digits from 0 to 9 only.
	- 1 <= a <= 9
	- 1 <= b <= s.length - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest string that can be obtained by applying the two operations any number of times, in any order.
- **Example:** `Output: "3036"`
- **Constraints:**
	- The output should be a string of the same length as s.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the lexicographically smallest string after applying the operations any number of times.

- Apply rotations to s in all possible ways to generate different versions of s.
- For each version, apply the addition operation on odd indices of s.
- Track the lexicographically smallest result by comparing the modified strings.
{{< dots >}}
### Problem Assumptions ✅
- The input string s will always have even length and consist of digits from 0 to 9.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "3637", a = 7, b = 2`  \
  **Explanation:** By rotating the string twice and adding 7 to odd positions, we get the smallest possible string, which is "3036".

- **Input:** `s = "9783", a = 3, b = 1`  \
  **Explanation:** After rotating the string and adding 3 to odd indices, we get the smallest possible string, which is "3789".

- **Input:** `s = "1567", a = 4, b = 2`  \
  **Explanation:** In this case, the string is already the lexicographically smallest, and no further operations can make it smaller.

{{< dots >}}
## Approach 🚀
To solve this problem, we apply the operations in various combinations, keeping track of the lexicographically smallest string generated.

### Initial Thoughts 💭
- The operations can be applied multiple times, and we need to explore all possibilities to find the smallest string.
- We will rotate the string and apply the addition operation to each resulting string, comparing to find the smallest possible string.
{{< dots >}}
### Edge Cases 🌐
- The string is guaranteed to have a length of at least 2, so we do not need to handle empty inputs.
- Ensure the solution works for strings of length up to 100.
- Handle cases where no further operations can produce a smaller string.
- Ensure all operations are applied efficiently, especially when dealing with large strings.
{{< dots >}}
## Code 💻
```cpp
class Solution {

string ans;
int a, b;
int n;
unordered_set<string> seen;

bool isVisited(string s) {
    return seen.find(s) != seen.end();
}

void visit(string s) {
    ans = min(ans, s);
    seen.insert(s);
}    

string rotate(string s, int x) {
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin()+x);
    reverse(s.begin()+x, s.end());
    return s;
}

 string add(string s, int x) {
    for (int i=1; i<n; i += 2) {
        char &c = s[i];
        c = '0' + (c-'0'+x)%10;
    }
    return s;
}
public:
string findLexSmallestString(string s, int a, int b) {
    ans = s;
    this->a = a;
    this->b = b;
    n = s.size();
    dfs(s);
    return ans;
}
void dfs(string s){
    if(isVisited(s)) return;
    visit(s);
    dfs(rotate(s, b));
    dfs(add(s, a));
}
```

This code defines the Solution class with methods to manipulate and rotate a string in specific ways, as well as find the lexicographically smallest string by applying transformations based on the values of a and b.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Class definition starts. This class encapsulates the solution for the problem.

2. **Variable Initialization**
	```cpp
	string ans;
	```
	String variable 'ans' is used to store the lexicographically smallest string found.

3. **Variable Initialization**
	```cpp
	int a, b;
	```
	Integers 'a' and 'b' are parameters that control the transformation of the string.

4. **Variable Initialization**
	```cpp
	int n;
	```
	Integer 'n' stores the size of the string 's'.

5. **Set Initialization**
	```cpp
	unordered_set<string> seen;
	```
	An unordered_set 'seen' is used to track visited strings to avoid cycles.

6. **Method Definition**
	```cpp
	bool isVisited(string s) {
	```
	Method to check if a string 's' has already been visited.

7. **Set Operations**
	```cpp
	    return seen.find(s) != seen.end();
	```
	Returns true if the string 's' has already been visited by checking the 'seen' set.

8. **Method Definition**
	```cpp
	void visit(string s) {
	```
	Method to process and record a visited string.

9. **String Manipulations**
	```cpp
	    ans = min(ans, s);
	```
	Update 'ans' to be the lexicographically smallest string between the current 'ans' and 's'.

10. **Set Operations**
	```cpp
	    seen.insert(s);
	```
	Insert the string 's' into the 'seen' set to mark it as visited.

11. **Method Definition**
	```cpp
	string rotate(string s, int x) {
	```
	Method to rotate the string 's' by 'x' positions.

12. **String Manipulations**
	```cpp
	    reverse(s.begin(), s.end());
	```
	Reverse the entire string 's'.

13. **String Manipulations**
	```cpp
	    reverse(s.begin(), s.begin()+x);
	```
	Reverse the first 'x' characters of the string 's'.

14. **String Manipulations**
	```cpp
	    reverse(s.begin()+x, s.end());
	```
	Reverse the remaining part of the string from index 'x' to the end.

15. **Return Statement**
	```cpp
	    return s;
	```
	Return the rotated string 's'.

16. **Method Definition**
	```cpp
	 string add(string s, int x) {
	```
	Method to add 'x' to every alternate digit of the string 's'.

17. **Loop Constructs**
	```cpp
	    for (int i=1; i<n; i += 2) {
	```
	Loop through the string 's', starting at index 1 and skipping every other character.

18. **String Manipulations**
	```cpp
	        char &c = s[i];
	```
	Get a reference to the character 'c' at the current position 'i' in the string 's'.

19. **Mathematical Operations**
	```cpp
	        c = '0' + (c-'0'+x)%10;
	```
	Add 'x' to the character 'c', mod 10 to keep it a single digit, and update 'c'.

20. **Return Statement**
	```cpp
	    return s;
	```
	Return the modified string 's'.

21. **Access Modifiers**
	```cpp
	public:
	```
	Start of the public section, where the main function is defined.

22. **Method Definition**
	```cpp
	string findLexSmallestString(string s, int a, int b) {
	```
	Main method to find the lexicographically smallest string using the transformations.

23. **Variable Initialization**
	```cpp
	    ans = s;
	```
	Initialize 'ans' with the original string 's'.

24. **Variable Initialization**
	```cpp
	    this->a = a;
	```
	Assign the value of 'a' to the class variable 'a'.

25. **Variable Initialization**
	```cpp
	    this->b = b;
	```
	Assign the value of 'b' to the class variable 'b'.

26. **Variable Initialization**
	```cpp
	    n = s.size();
	```
	Set 'n' to the size of the string 's'.

27. **Recursive Calls**
	```cpp
	    dfs(s);
	```
	Call the depth-first search (DFS) to explore all possible transformations.

28. **Return Statement**
	```cpp
	    return ans;
	```
	Return the lexicographically smallest string found.

29. **Method Definition**
	```cpp
	void dfs(string s){
	```
	Method to perform depth-first search on the string 's'.

30. **Conditional Statements**
	```cpp
	    if(isVisited(s)) return;
	```
	If the string 's' has already been visited, return immediately to avoid cycles.

31. **Method Calls**
	```cpp
	    visit(s);
	```
	Mark the current string 's' as visited and possibly update 'ans'.

32. **Recursive Calls**
	```cpp
	    dfs(rotate(s, b));
	```
	Recursively explore the rotated version of 's'.

33. **Recursive Calls**
	```cpp
	    dfs(add(s, a));
	```
	Recursively explore the version of 's' after applying the 'add' transformation.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The worst case occurs when all rotations and additions must be explored.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is O(n) due to the storage of strings in the recursion stack and visited set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/)

---
{{< youtube S_WnsW5cdgI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
