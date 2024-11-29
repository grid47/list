
+++
authors = ["grid47"]
title = "Leetcode 1898: Maximum Number of Removable Characters"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1898: Maximum Number of Removable Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NMP3nRPyX5g"
youtube_upload_date="2021-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/NMP3nRPyX5g/maxresdefault.jpg"
comments = true
+++



---
You are given two strings s and p, where p is a subsequence of s. You are also given an array removable containing distinct indices of s. Your task is to determine the maximum number of indices you can remove from s such that p is still a subsequence of the remaining string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s, a string p, and an array removable of distinct indices in s.
- **Example:** `For s = 'abcacb', p = 'ab', removable = [3, 1, 0]`
- **Constraints:**
	- 1 <= p.length <= s.length <= 105
	- 0 <= removable.length < s.length
	- 0 <= removable[i] < s.length
	- p is a subsequence of s.
	- s and p both consist of lowercase English letters.
	- The elements in removable are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of indices you can remove from s such that p remains a subsequence.
- **Example:** `For s = 'abcacb', p = 'ab', removable = [3, 1, 0], the output will be 2.`
- **Constraints:**
	- The output is an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the maximum number of indices that can be removed without losing the subsequence property of p in s.

- Iterate through the array removable and remove characters from s accordingly.
- For each number of removals, check if p is still a subsequence of the remaining string.
- Use binary search to find the maximum number of removable indices where p remains a subsequence.
{{< dots >}}
### Problem Assumptions ✅
- p is always a subsequence of s.
- The elements in removable are distinct and valid indices of s.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abcacb', p = 'ab', removable = [3, 1, 0]`  \
  **Explanation:** After removing characters at indices 3 and 1, s becomes 'accb', which still contains p as a subsequence. Removing the characters at indices 3, 1, and 0 results in 'ccb', which no longer contains p.

- **Input:** `s = 'abcbddddd', p = 'abcd', removable = [3, 2, 1, 4, 5, 6]`  \
  **Explanation:** After removing the character at index 3, 'abcbddddd' becomes 'abcddddd', and p remains a subsequence.

- **Input:** `s = 'abcab', p = 'abc', removable = [0, 1, 2, 3, 4]`  \
  **Explanation:** If the first index in removable is removed, p is no longer a subsequence of the resulting string.

{{< dots >}}
## Approach 🚀
The approach involves checking whether p is still a subsequence of s after removing characters based on the indices provided in removable. We can use binary search to efficiently find the maximum number of indices to remove.

### Initial Thoughts 💭
- We need to check subsequence status after each potential removal.
- We can use a binary search to find the maximum k such that p is still a subsequence of the resulting string after removing k characters.
{{< dots >}}
### Edge Cases 🌐
- The input s and p will never be empty since p is a subsequence of s.
- The algorithm should be efficient enough to handle the maximum input size where s can have up to 10^5 characters.
- If removable contains no elements, the answer will be the maximum number of removals without affecting p.
- The algorithm should work efficiently within the time constraints for large inputs.
{{< dots >}}
## Code 💻
```cpp

int isSubseq(string &s, string &p, vector<int>& mp, int k) {
    int i = 0, j = 0;
    while(i < s.size() && j < p.size()) {
        if(mp[i] <= k) {
            i++;
            continue;
        }
        if(s[i] == p[j]) {
            i++;
            j++;
            if(j == p.size()) return true;
        } else i++;
    }
    return false;
}

int maximumRemovals(string s, string p, vector<int>& rm) {
    vector<int> mp(s.size(), INT_MAX);
    for(int i = 0; i < rm.size(); i++)
        mp[rm[i]] = i;
    int l = 0, r = rm.size() - 1, ans = -1;
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        if(isSubseq(s, p, mp, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans + 1;
}
```

This is a solution to a problem where we check whether a sequence `p` can be obtained from string `s` by removing a set of characters indexed in `rm`. The function `isSubseq` checks if a sequence is a subsequence, while `maximumRemovals` uses binary search to determine the maximum number of characters that can be removed while keeping `p` as a subsequence of `s`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int isSubseq(string &s, string &p, vector<int>& mp, int k) {
	```
	This line defines the function `isSubseq` which checks if `p` can be formed as a subsequence of `s` after removing certain characters indexed by `mp`.

2. **Variable Initialization**
	```cpp
	    int i = 0, j = 0;
	```
	Two pointers `i` and `j` are initialized to traverse `s` and `p`, respectively.

3. **While Loop**
	```cpp
	    while(i < s.size() && j < p.size()) {
	```
	This `while` loop continues as long as there are characters in both `s` and `p` to compare.

4. **Condition Check**
	```cpp
	        if(mp[i] <= k) {
	```
	This condition checks if the character at index `i` in `s` can be removed (based on the value in `mp`), allowing the pointer `i` to move forward.

5. **Pointer Increment**
	```cpp
	            i++;
	```
	If the character at index `i` is removable, increment `i` and continue to the next iteration.

6. **Control Flow**
	```cpp
	            continue;
	```
	This skips the rest of the loop body and moves to the next character in `s`.

7. **Matching Check**
	```cpp
	        if(s[i] == p[j]) {
	```
	This checks if the current characters in `s` and `p` match.

8. **Pointer Increment**
	```cpp
	            i++;
	```
	If characters match, increment both pointers to move to the next characters.

9. **Pointer Increment**
	```cpp
	            j++;
	```
	This increments pointer `j` to check the next character in `p`.

10. **Match Completion Check**
	```cpp
	            if(j == p.size()) return true;
	```
	If the entire string `p` has been matched, return `true`.

11. **Pointer Increment**
	```cpp
	        } else i++;
	```
	If the characters don't match, move pointer `i` forward.

12. **Return Statement**
	```cpp
	    return false;
	```
	Return `false` if the sequence `p` can't be formed from `s`.

13. **Function Definition**
	```cpp
	int maximumRemovals(string s, string p, vector<int>& rm) {
	```
	This line defines the `maximumRemovals` function which uses binary search to find the maximum number of removable characters in `s` while keeping `p` as a subsequence.

14. **Variable Initialization**
	```cpp
	    vector<int> mp(s.size(), INT_MAX);
	```
	Initialize a vector `mp` of size `s.size()` with values set to `INT_MAX`. This vector will hold the removal indices for characters in `s`.

15. **For Loop**
	```cpp
	    for(int i = 0; i < rm.size(); i++)
	```
	This `for` loop iterates over each index in the removal vector `rm`.

16. **Index Assignment**
	```cpp
	        mp[rm[i]] = i;
	```
	Assign the removal index `i` to the corresponding position in `mp` based on the removal vector `rm`.

17. **Variable Initialization**
	```cpp
	    int l = 0, r = rm.size() - 1, ans = -1;
	```
	Initialize binary search bounds `l` and `r`, and a variable `ans` to store the result.

18. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	This `while` loop performs binary search on the removal indices.

19. **Midpoint Calculation**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculate the midpoint `mid` for the binary search.

20. **Subsequence Check**
	```cpp
	        if(isSubseq(s, p, mp, mid)) {
	```
	Check if `p` can still be a subsequence of `s` after removing the first `mid` elements.

21. **Result Update**
	```cpp
	            ans = mid;
	```
	If the subsequence condition is met, update `ans` with the current value of `mid`.

22. **Binary Search Update**
	```cpp
	            l = mid + 1;
	```
	Update the lower bound `l` to search the higher half of the range.

23. **Binary Search Update**
	```cpp
	        } else {
	```
	If the subsequence condition is not met, search the lower half of the range.

24. **Binary Search Update**
	```cpp
	            r = mid - 1;
	```
	Update the upper bound `r` to search the lower half of the range.

25. **Return Statement**
	```cpp
	    return ans + 1;
	```
	Return the result, incremented by 1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log m)
- **Average Case:** O(n log m)
- **Worst Case:** O(n log m)

The time complexity is O(n log m), where n is the length of s and m is the length of removable.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the state of the removed indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-removable-characters/description/)

---
{{< youtube NMP3nRPyX5g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
