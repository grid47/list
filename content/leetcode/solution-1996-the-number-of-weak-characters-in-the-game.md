
+++
authors = ["grid47"]
title = "Leetcode 1996: The Number of Weak Characters in the Game"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1996: The Number of Weak Characters in the Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DFqwkF9a6KI"
youtube_upload_date="2021-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/DFqwkF9a6KI/maxresdefault.jpg"
comments = true
+++



---
You are given a list of characters' properties, where each character has two main attributes: attack and defense. A character is weak if another character exists with both greater attack and defense values. Return the number of weak characters in the list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array 'properties' of length n (2 <= n <= 100,000), where each element is an array [attack_i, defense_i] representing the attack and defense values of the ith character.
- **Example:** `properties = [[1, 2], [2, 1], [3, 4]]`
- **Constraints:**
	- 2 <= properties.length <= 10^5
	- 1 <= attack_i, defense_i <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of weak characters in the list.
- **Example:** `1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find the weak characters by comparing each character with others to check if there exists a character with strictly greater attack and defense values.

- 1. Sort the characters by their attack value in ascending order. If two characters have the same attack value, sort them by their defense value in descending order.
- 2. Traverse through the sorted list and keep track of the highest defense value encountered.
- 3. If a character's defense value is smaller than the highest defense value encountered so far, it is a weak character.
- 4. Count and return the number of weak characters.
{{< dots >}}
### Problem Assumptions ✅
- All characters have distinct attack and defense values.
{{< dots >}}
## Examples 🧩
- **Input:** `properties = [[3, 5], [6, 3], [7, 8], [4, 7]]`  \
  **Explanation:** Here, the character [3, 5] is weak because there exists a character [6, 3] with strictly greater attack and defense values.

{{< dots >}}
## Approach 🚀
We can approach this problem by sorting the characters based on attack and using a greedy strategy to keep track of the maximum defense value seen so far.

### Initial Thoughts 💭
- The problem boils down to comparing each character with others to see if it's dominated by another one.
- Sorting the array and using a greedy approach allows us to efficiently identify weak characters.
{{< dots >}}
### Edge Cases 🌐
- This problem assumes that the input array will always contain at least two characters.
- The algorithm should be efficient enough to handle the largest input sizes within time limits.
- Ensure that the sorting order works correctly when two characters have the same attack value but different defense values.
- The constraints ensure that the input will always be valid and the solution will work within the given limits.
{{< dots >}}
## Code 💻
```cpp
class Solution {

public:
static bool comp(vector<int> &a, vector<int> &b) {
    if(a[0] == b[0]) {
        return a[1] > b[1];
    } else return a[0] < b[0];
}

int numberOfWeakCharacters(vector<vector<int>>& prpt) {
    sort(prpt.begin(), prpt.end(), comp);
    
    int mn = INT_MIN;
    int ans = 0;
    
    for(int i = prpt.size() - 1; i >= 0; i--) {
        if(prpt[i][1] < mn) ans++;
        mn = max(mn, prpt[i][1]);
    }
    return ans;
}
```

This function determines the number of 'weak' characters from a given 2D vector `prpt` by sorting the characters and comparing their strengths to find those that are weaker than a previously encountered one.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class that contains the function `numberOfWeakCharacters` and the comparator function `comp`.

2. **Access Modifier**
	```cpp
	public:
	```
	Indicates the public section of the class where the methods are accessible.

3. **Comparator Function**
	```cpp
	static bool comp(vector<int> &a, vector<int> &b) {
	```
	Defines a static comparator function `comp` that is used to sort the characters in descending order of their second element and ascending order of their first element.

4. **Comparator Logic**
	```cpp
	    if(a[0] == b[0]) {
	```
	Checks if the first elements of both vectors are equal.

5. **Comparator Logic**
	```cpp
	        return a[1] > b[1];
	```
	If the first elements are equal, sorts based on the second element in descending order.

6. **Comparator Logic**
	```cpp
	    } else return a[0] < b[0];
	```
	If the first elements are different, sorts based on the first element in ascending order.

7. **Main Function Definition**
	```cpp
	int numberOfWeakCharacters(vector<vector<int>>& prpt) {
	```
	Defines the function `numberOfWeakCharacters` which accepts a 2D vector `prpt` representing the characters and returns the number of weak characters.

8. **Sorting**
	```cpp
	    sort(prpt.begin(), prpt.end(), comp);
	```
	Sorts the 2D vector `prpt` using the custom comparator `comp` to arrange the characters in the desired order.

9. **Variable Initialization**
	```cpp
	    int mn = INT_MIN;
	```
	Initializes the variable `mn` to `INT_MIN` to store the maximum second element encountered during the iteration.

10. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes the variable `ans` to 0 to keep track of the count of weak characters.

11. **Loop Start**
	```cpp
	    for(int i = prpt.size() - 1; i >= 0; i--) {
	```
	Starts a loop from the last element of the sorted `prpt` vector and iterates backwards.

12. **Condition Check**
	```cpp
	        if(prpt[i][1] < mn) ans++;
	```
	If the second element of the current vector is less than `mn`, it means the current character is weak, and the count `ans` is incremented.

13. **Update Max Value**
	```cpp
	        mn = max(mn, prpt[i][1]);
	```
	Updates `mn` to be the maximum of `mn` and the second element of the current vector, ensuring that only characters weaker than the current maximum are counted.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final count of weak characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/)

---
{{< youtube DFqwkF9a6KI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
