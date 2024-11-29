
+++
authors = ["grid47"]
title = "Leetcode 1061: Lexicographically Smallest Equivalent String"
date = "2024-07-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1061: Lexicographically Smallest Equivalent String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YQ-q0oydRl4"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/YQ-q0oydRl4/maxresdefault.jpg"
comments = true
+++



---
You are given two strings, s1 and s2, which contain the same length, and a third string baseStr. Each pair of corresponding characters from s1 and s2 represent equivalent characters. Your task is to return the lexicographically smallest equivalent string for baseStr, where each character is replaced with its lexicographically smallest equivalent based on the equivalency information from s1 and s2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings s1 and s2 of the same length, and a string baseStr. The strings s1 and s2 represent equivalency information where corresponding characters in the two strings are considered equivalent. The baseStr is the string that needs to be transformed according to these equivalencies.
- **Example:** `Input: s1 = "abc", s2 = "xyz", baseStr = "def"`
- **Constraints:**
	- 1 <= s1.length, s2.length, baseStr <= 1000
	- s1.length == s2.length
	- s1, s2, and baseStr consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the lexicographically smallest equivalent string derived from baseStr, with each character transformed according to the equivalency information provided by s1 and s2.
- **Example:** `Output: "dff"`
- **Constraints:**
	- The output string must be a valid transformation of baseStr, following the equivalency rules from s1 and s2.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the lexicographically smallest string by transforming baseStr, using the equivalency relationships defined by s1 and s2.

- 1. Create a union-find (disjoint set) data structure to track equivalencies between characters.
- 2. Process each pair of characters from s1 and s2, linking them in the union-find structure to establish equivalency.
- 3. For each character in baseStr, find its equivalent character from the union-find structure and replace it with the lexicographically smallest option.
{{< dots >}}
### Problem Assumptions ✅
- The input strings s1, s2, and baseStr are all valid and follow the specified constraints.
- The equivalency relations form an equivalence relation (reflexive, symmetric, and transitive).
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s1 = "parker", s2 = "morris", baseStr = "parser"`  \
  **Explanation:** The equivalency groups are [m, p], [a, o], [k, r, s], and [e, i]. The smallest lexicographically equivalent string is 'makkek'.

- **Input:** `Input: s1 = "hello", s2 = "world", baseStr = "hold"`  \
  **Explanation:** The equivalency groups are [h, w], [d, e, o], and [l, r]. The transformed base string is 'hdld'.

{{< dots >}}
## Approach 🚀
We solve this problem by modeling equivalencies using a union-find data structure. This helps efficiently group equivalent characters and ensures that we can replace each character in baseStr with its lexicographically smallest equivalent.

### Initial Thoughts 💭
- Each pair of corresponding characters in s1 and s2 represents an equivalency relation.
- We can use a union-find data structure to group equivalent characters efficiently.
- The problem is essentially about finding equivalence classes of characters, and then replacing characters in baseStr with their lexicographically smallest representatives.
{{< dots >}}
### Edge Cases 🌐
- The problem does not expect empty inputs, as the length of strings is at least 1.
- The solution must be efficient enough to handle inputs of up to 1000 characters.
- In cases where all characters in baseStr are already equivalent, the baseStr remains unchanged.
- The solution must adhere to the time and space complexity constraints to handle inputs efficiently.
{{< dots >}}
## Code 💻
```cpp

int cnv(char x) {
    return x - 'a';
}

string smallestEquivalentString(string s1, string s2, string base) {
    
    int n = s1.size();
    UF* uf = new UF(26);
    
    for(int i = 0; i < n; i++) {
        uf->uni(cnv(s1[i]), cnv(s2[i]));
        uf->uni(cnv(s2[i]), cnv(s1[i]));            
    }
    
    string res = "";
    for(int i = 0; i < base.size(); i++) {
        res += uf->find(cnv(base[i])) + 'a';
    }
    return res;
}
```

This code implements a function that returns the smallest equivalent string by converting each character in the base string to its equivalent based on the relationships given by strings s1 and s2. A union-find (disjoint-set) data structure is used to group equivalent characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int cnv(char x) {
	```
	This function `cnv` converts a character `x` to an integer corresponding to its position in the alphabet (0 for 'a', 1 for 'b', etc.).

2. **Character Conversion**
	```cpp
	    return x - 'a';
	```
	The `cnv` function subtracts the ASCII value of 'a' from the character `x`, effectively mapping 'a' to 0, 'b' to 1, and so on.

3. **Function Definition**
	```cpp
	string smallestEquivalentString(string s1, string s2, string base) {
	```
	This line defines the function `smallestEquivalentString`, which takes two strings `s1`, `s2`, and a `base` string, and returns the smallest equivalent string according to the character relationships defined in `s1` and `s2`.

4. **String Length Calculation**
	```cpp
	    int n = s1.size();
	```
	This line calculates the length of the string `s1` (which is the same as `s2`) and stores it in `n`.

5. **Union-Find Initialization**
	```cpp
	    UF* uf = new UF(26);
	```
	An instance of the Union-Find (disjoint-set) data structure is created. It is initialized to handle 26 elements, one for each letter of the alphabet.

6. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates through each pair of characters from `s1` and `s2`.

7. **Union Operation**
	```cpp
	        uf->uni(cnv(s1[i]), cnv(s2[i]));
	```
	For each character pair from `s1` and `s2`, the `uni` function is called to unify the corresponding sets of the two characters.

8. **Symmetric Union Operation**
	```cpp
	        uf->uni(cnv(s2[i]), cnv(s1[i]));
	```
	This line ensures that the relationship is symmetric by also unifying the sets of `s2[i]` and `s1[i]`.

9. **String Initialization**
	```cpp
	    string res = "";
	```
	The result string `res` is initialized as an empty string, which will store the smallest equivalent string.

10. **Base String Loop**
	```cpp
	    for(int i = 0; i < base.size(); i++) {
	```
	This loop iterates over each character in the base string `base`.

11. **Character Conversion & Find**
	```cpp
	        res += uf->find(cnv(base[i])) + 'a';
	```
	For each character in `base`, the function `find` is used to find the representative of the character's set, and the result is converted back to a character. This character is then appended to the result string `res`.

12. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the result string `res`, which contains the smallest equivalent string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the union-find operations and character transformations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the union-find structure and baseStr.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/)

---
{{< youtube YQ-q0oydRl4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
