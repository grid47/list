
+++
authors = ["grid47"]
title = "Leetcode 2657: Find the Prefix Common Array of Two Arrays"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2657: Find the Prefix Common Array of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wpffRfDOBSU"
youtube_upload_date="2023-04-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wpffRfDOBSU/maxresdefault.webp"
comments = true
+++



---
You are given two integer arrays A and B, each of length n, which are permutations of numbers from 1 to n. You need to find the prefix common array of A and B. The prefix common array is defined as an array C where each C[i] represents the number of integers that appear at or before index i in both A and B.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays A and B of length n. Both arrays are permutations of integers from 1 to n.
- **Example:** `Input: A = [4, 1, 3, 2], B = [2, 1, 4, 3]`
- **Constraints:**
	- 1 <= A.length == B.length == n <= 50
	- 1 <= A[i], B[i] <= n
	- A and B are both permutations of integers from 1 to n.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the prefix common array, where each element represents the count of common numbers at or before the index i in both arrays A and B.
- **Example:** `Output: [0, 1, 2, 3]`
- **Constraints:**
	- The output should be an array of integers representing the prefix common array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the prefix common array by checking how many elements from A and B are common up to each index.

- Step 1: Iterate through each index of arrays A and B.
- Step 2: Track the common elements up to each index using sets for quick lookup.
- Step 3: Update the prefix common array at each step based on the count of common elements.
{{< dots >}}
### Problem Assumptions ✅
- Both arrays A and B contain all integers from 1 to n exactly once.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: A = [4, 1, 3, 2], B = [2, 1, 4, 3]`  \
  **Explanation:** At index 0: no numbers are common, so C[0] = 0. At index 1: 1 is common, so C[1] = 1. At index 2: 1 and 4 are common, so C[2] = 2. At index 3: 1, 4, 3, and 2 are common, so C[3] = 4.

- **Input:** `Input: A = [5, 2, 4, 1, 3], B = [3, 1, 5, 4, 2]`  \
  **Explanation:** At index 0: no numbers are common, so C[0] = 0. At index 1: only 2 is common, so C[1] = 1. At index 2: 2 and 5 are common, so C[2] = 2. At index 3: 2, 5, and 4 are common, so C[3] = 3. At index 4: all elements are common, so C[4] = 5.

{{< dots >}}
## Approach 🚀
The approach involves iterating through both arrays while tracking the common elements up to each index using sets. We will update the prefix common array based on how many elements have been seen in both arrays at each point.

### Initial Thoughts 💭
- We can use two sets to track the elements we've seen so far in A and B.
- The use of sets allows for efficient checking of common elements.
- We need to efficiently count the common elements at each index and store the results.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as per the problem constraints.
- The input size can be up to 50, so the solution should be efficient for arrays of size 50.
- If all elements in A and B are in reverse order, the solution should still work efficiently.
- Ensure that the solution respects the constraint of A and B being valid permutations.
{{< dots >}}
## Code 💻
```cpp
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    set<int> a, b, c;
    int n = A.size();
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        if(a.count(B[i])) {
            c.insert(B[i]);
        } 
        if(b.count(A[i])) {
            c.insert(A[i]);                
        } 
        if(A[i] == B[i]) {
            c.insert(A[i]);                
        }
        a.insert(A[i]);
        b.insert(B[i]);
        ans[i] = c.size();
    }
    return ans;
}
```

This function calculates the prefix common array by identifying common elements between two input arrays, A and B, up to each index. It uses sets to track common elements, and the result is an array showing the number of common elements at each index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
	```
	This defines the function `findThePrefixCommonArray`, which takes two vectors, A and B, as input and returns a vector containing the count of common elements at each prefix index.

2. **Set Initialization**
	```cpp
	    set<int> a, b, c;
	```
	Here, three sets are initialized: 'a' and 'b' will store elements from arrays A and B, respectively, while 'c' will store the common elements found in both.

3. **Array Size Calculation**
	```cpp
	    int n = A.size();
	```
	This line calculates the size of array A (which is the same as array B) and stores it in the variable 'n'.

4. **Vector Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	A vector 'ans' of size n is initialized with all elements set to 0. This will store the number of common elements for each prefix.

5. **Looping through Arrays**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The for loop starts, iterating over each index of arrays A and B to check for common elements.

6. **Set Lookup**
	```cpp
	        if(a.count(B[i])) {
	```
	This checks if the current element in array B exists in set 'a' (i.e., if it has already been encountered in array A).

7. **Set Insertion**
	```cpp
	            c.insert(B[i]);
	```
	If the element from array B exists in set 'a', it is inserted into set 'c', indicating a common element.

8. **Set Lookup**
	```cpp
	        if(b.count(A[i])) {
	```
	This checks if the current element in array A exists in set 'b' (i.e., if it has already been encountered in array B).

9. **Set Insertion**
	```cpp
	            c.insert(A[i]);                
	```
	If the element from array A exists in set 'b', it is inserted into set 'c', indicating a common element.

10. **Equality Check**
	```cpp
	        if(A[i] == B[i]) {
	```
	This checks if the current elements from arrays A and B are equal at the same index.

11. **Set Insertion**
	```cpp
	            c.insert(A[i]);                
	```
	If the elements at the same index in both arrays are equal, the element is inserted into set 'c' as a common element.

12. **Set Insertion**
	```cpp
	        a.insert(A[i]);
	```
	This inserts the current element from array A into set 'a'.

13. **Set Insertion**
	```cpp
	        b.insert(B[i]);
	```
	This inserts the current element from array B into set 'b'.

14. **Array Update**
	```cpp
	        ans[i] = c.size();
	```
	The current size of set 'c' (which contains the common elements) is stored in the 'ans' vector at the current index.

15. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the 'ans' vector, which contains the count of common elements for each prefix of arrays A and B.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the arrays once and perform constant time operations (set insertions and lookups) at each step.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the sets tracking the elements seen in A and B.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/)

---
{{< youtube wpffRfDOBSU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
