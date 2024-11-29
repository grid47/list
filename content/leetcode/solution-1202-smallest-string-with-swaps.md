
+++
authors = ["grid47"]
title = "Leetcode 1202: Smallest String With Swaps"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1202: Smallest String With Swaps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Depth-First Search","Breadth-First Search","Union Find","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a string s and an array of pairs of indices pairs where each pair pairs[i] = [a, b] represents two indices in the string. You can swap the characters at any of these index pairs any number of times. Your task is to return the lexicographically smallest string that can be obtained after performing the swaps.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s and a 2D array pairs where each pair represents two indices in the string that can be swapped.
- **Example:** `Input: s = "zaxy", pairs = [[0,3],[1,2]]`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 0 <= pairs.length <= 10^5
	- 0 <= pairs[i][0], pairs[i][1] < s.length
	- s only contains lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest string that can be obtained by swapping the characters at the given pairs of indices.
- **Example:** `Output: "axyz"`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the lexicographically smallest string by performing the allowed swaps.

- Use Union-Find (Disjoint Set Union) to group indices that can be connected through the given pairs.
- For each group, sort the indices and the characters in those positions.
- Assign the sorted characters back to the indices to form the smallest possible string.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that the input string s only contains lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "zaxy", pairs = [[0,3],[1,2]]`  \
  **Explanation:** Swap s[0] and s[3], s = "yazx". Swap s[1] and s[2], s = "axyz".

- **Input:** `Input: s = "xyza", pairs = [[0,3],[1,2],[0,2]]`  \
  **Explanation:** Swap s[0] and s[3], s = "ayzx". Swap s[0] and s[2], s = "axyz".

- **Input:** `Input: s = "acdb", pairs = [[0,1],[1,2],[2,3]]`  \
  **Explanation:** Swap s[0] and s[1], s = "cabd". Swap s[1] and s[2], s = "cdab". Swap s[2] and s[3], s = "abcd".

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we use a Union-Find data structure to group indices that can be swapped and then sort the characters in those groups.

### Initial Thoughts 💭
- Union-Find allows us to efficiently group indices that can be swapped together.
- Sorting the characters within each group gives the lexicographically smallest arrangement.
- The solution can be broken down into finding connected components and sorting them to get the smallest string.
{{< dots >}}
### Edge Cases 🌐
- Ensure the string is not empty, as this case is out of bounds based on the problem constraints.
- Make sure the solution is efficient enough to handle large inputs (strings and pairs up to 10^5 in length).
- Handle cases where all indices are part of the same group or no indices can be swapped.
- The solution must account for up to 10^5 indices and swap pairs efficiently.
{{< dots >}}
## Code 💻
```cpp
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    UF uf = UF(n);
    for(vector<int> each: pairs)
        uf.join(each[0], each[1]);
    
    vector<vector<int>> grps = uf.pairs();
    vector<char> ans(n, '-');
    
    for(vector<int> grp : grps) {

        sort(grp.begin(), grp.end());
        vector<char> chr;
        for(int g : grp) chr.push_back(s[g]);
        sort(chr.begin(), chr.end(), [](unsigned char c1, unsigned char c2){ return std::tolower(c1) < std::tolower(c2); });
        int i = 0;
        for(int x: grp)
            ans[x] = chr[i++];
    }
    
    string ret(ans.begin(), ans.end());
    return ret;
}
```

This function takes a string `s` and swaps characters in the string according to the given pairs of indices, ensuring that characters in the same connected component of indices are sorted lexicographically.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
	```
	Define the function `smallestStringWithSwaps` which takes a string `s` and a list of index pairs `pairs`. The goal is to sort the characters of `s` based on these index pairs, ensuring that the swaps respect the connected components defined by the pairs.

2. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Store the length of the input string `s` in the variable `n`.

3. **Union-Find Initialization**
	```cpp
	    UF uf = UF(n);
	```
	Initialize a union-find data structure `uf` with `n` elements to manage the connected components of the indices.

4. **Loop Through Pairs**
	```cpp
	    for(vector<int> each: pairs)
	```
	Loop through each pair in the `pairs` vector, representing index pairs that can be swapped.

5. **Union-Find Operation**
	```cpp
	        uf.join(each[0], each[1]);
	```
	For each pair, join the two indices into the same connected component using the union-find `join` operation.

6. **Empty Line**
	```cpp
	    
	```
	Empty line for readability, separating sections of code.

7. **Union-Find Result**
	```cpp
	    vector<vector<int>> grps = uf.pairs();
	```
	Get the connected components from the union-find data structure and store them in the vector `grps`.

8. **Vector Initialization**
	```cpp
	    vector<char> ans(n, '-');
	```
	Initialize a vector `ans` of size `n`, filled with `'-'`, to store the result after sorting and swapping characters.

9. **Loop Through Groups**
	```cpp
	    for(vector<int> grp : grps) {
	```
	Iterate through each group of connected indices in `grps` to sort the characters in those positions.

10. **Sorting Indices**
	```cpp
	        sort(grp.begin(), grp.end());
	```
	Sort the indices in the current group to arrange them in ascending order.

11. **Character Vector Initialization**
	```cpp
	        vector<char> chr;
	```
	Initialize an empty vector `chr` to store the characters corresponding to the current group of indices.

12. **Fill Character Vector**
	```cpp
	        for(int g : grp) chr.push_back(s[g]);
	```
	Push the characters from the string `s` corresponding to the current group of indices into the vector `chr`.

13. **Character Sorting**
	```cpp
	        sort(chr.begin(), chr.end(), [](unsigned char c1, unsigned char c2){ return std::tolower(c1) < std::tolower(c2); });
	```
	Sort the characters in `chr` lexicographically, ignoring case, to ensure case-insensitive sorting.

14. **Character Assignment**
	```cpp
	        int i = 0;
	```
	Initialize an index `i` to keep track of the position in the sorted character vector `chr`.

15. **Assign Sorted Characters**
	```cpp
	        for(int x: grp)
	```
	For each index `x` in the current group `grp`, assign the corresponding character from `chr` to the result vector `ans`.

16. **Assign Character from Sorted List**
	```cpp
	            ans[x] = chr[i++];
	```
	Assign the character at position `i` from the sorted `chr` vector to the corresponding position `x` in the result vector `ans`, and increment `i`.

17. **Convert to String**
	```cpp
	    string ret(ans.begin(), ans.end());
	```
	Convert the result vector `ans` into a string `ret`.

18. **Return Statement**
	```cpp
	    return ret;
	```
	Return the final string `ret` which is the result of the character swaps and sorting.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The Union-Find operations take near constant time, and sorting the groups takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space needed for the Union-Find structure and the character arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-string-with-swaps/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
