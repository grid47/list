
+++
authors = ["grid47"]
title = "Leetcode 1452: People Whose List of Favorite Companies Is Not a Subset of Another List"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1452: People Whose List of Favorite Companies Is Not a Subset of Another List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ok0jYAMnvQI"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ok0jYAMnvQI/maxresdefault.webp"
comments = true
+++



---
Given an array of lists where `favoriteCompanies[i]` represents the favorite companies of the i-th person, find the indices of people whose favorite company lists are not subsets of any other person's list. Return these indices in increasing order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D array where each element is a list of strings representing the favorite companies of a person.
- **Example:** `Input: favoriteCompanies = [["apple","google","amazon"],["apple","microsoft"],["google","apple"],["amazon"]]`
- **Constraints:**
	- 1 <= favoriteCompanies.length <= 100
	- 1 <= favoriteCompanies[i].length <= 500
	- 1 <= favoriteCompanies[i][j].length <= 20
	- All strings in `favoriteCompanies[i]` are distinct.
	- All lists are distinct.
	- Strings consist of lowercase English letters only.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of indices of people whose favorite companies are not subsets of any other list, in increasing order.
- **Example:** `Output: [0,1,3]`
- **Constraints:**
	- The output indices must be in sorted order.
	- If a person's list is not a subset of any other, their index must be included.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify all people whose favorite company lists are unique and not subsets of other people's lists.

- Sort each person's favorite company list for efficient subset checking.
- For each person, compare their list with all other people's lists.
- If their list is not a subset of any other list, mark their index for inclusion.
- Return all such indices in increasing order.
{{< dots >}}
### Problem Assumptions ✅
- The input lists are valid and adhere to the constraints.
- Subset checking is performed using sorted lists for efficiency.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: favoriteCompanies = [["apple","google"],["apple","microsoft"],["google"],["amazon"]]`  \
  **Explanation:** Output: [0,1,3]. Person at index 2 has a list ["google"] which is a subset of ["apple","google"]. Others are unique.

- **Input:** `Input: favoriteCompanies = [["facebook","instagram"],["instagram"],["twitter"],["facebook"]]`  \
  **Explanation:** Output: [0,2,3]. The list at index 1 is a subset of the list at index 0.

- **Input:** `Input: favoriteCompanies = [["youtube"],["netflix"],["amazon"],["hulu"]]`  \
  **Explanation:** Output: [0,1,2,3]. All lists are unique and not subsets of one another.

{{< dots >}}
## Approach 🚀
Use a combination of sorting and subset checking to identify non-subset lists efficiently.

### Initial Thoughts 💭
- The problem revolves around subset checking between lists.
- Sorting each list ensures that the subset check can be efficiently done.
- Direct comparisons between every pair of lists may lead to a quadratic time complexity.
- Sort lists and use an efficient comparison method to minimize redundant checks.
{{< dots >}}
### Edge Cases 🌐
- Input: favoriteCompanies = [] -> Output: []. No input leads to an empty output.
- Input: A list with 100 people each having 500 companies -> Verify performance.
- Input: favoriteCompanies = [["a"],["a","b"],["b"]] -> Handle minimal string sizes and subsets correctly.
- Input: favoriteCompanies = [["apple"]] -> Single list remains unchanged.
- Handle cases where lists are identical after sorting but are not subsets.
{{< dots >}}
## Code 💻
```cpp
vector<int> peopleIndexes(vector<vector<string>>& comp) {
    int n = comp.size();
    
    for(auto &c : comp)
        sort(c.begin(), c.end());
    
    vector<int> res;
    for(int i = 0; i < n; i++) {
        int notSubset = true;
        
        for(int j = 0; j < n && notSubset; j++) {
            if(i == j) continue;
            
            notSubset = !includes(comp[j].begin(), comp[j].end(), comp[i].begin(), comp[i].end());
        }
        if(notSubset)
            res.push_back(i);
    }
    return res;
}
```

This function returns a vector of indices from the input vector of vectors of strings 'comp', where each index corresponds to a vector of strings that is not a subset of any other vector in the input.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> peopleIndexes(vector<vector<string>>& comp) {
	```
	The function 'peopleIndexes' is declared, which takes a reference to a vector of vector of strings ('comp') and returns a vector of integers.

2. **Variable Initialization**
	```cpp
	    int n = comp.size();
	```
	The variable 'n' is initialized to the size of the input vector 'comp', which represents the number of elements in the input.

3. **Loop**
	```cpp
	    for(auto &c : comp)
	```
	A loop is started to iterate over each vector 'c' inside the vector of vectors 'comp'.

4. **Sorting**
	```cpp
	        sort(c.begin(), c.end());
	```
	The current vector 'c' is sorted in lexicographical order using the sort function.

5. **Variable Initialization**
	```cpp
	    vector<int> res;
	```
	An empty vector 'res' is initialized to store the result indices of vectors that are not subsets of any other vectors.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is started to iterate through each vector in 'comp' by index 'i'.

7. **Variable Initialization**
	```cpp
	        int notSubset = true;
	```
	The variable 'notSubset' is initialized to true, which will be used to track whether the current vector is a subset of any other vector.

8. **Loop**
	```cpp
	        for(int j = 0; j < n && notSubset; j++) {
	```
	A nested loop starts to iterate through all other vectors in 'comp' by index 'j'. The 'notSubset' flag ensures that the loop stops once a subset is found.

9. **Conditional Check**
	```cpp
	            if(i == j) continue;
	```
	If the indices 'i' and 'j' are the same (i.e., comparing the same vector with itself), the loop skips to the next iteration.

10. **Subset Check**
	```cpp
	            notSubset = !includes(comp[j].begin(), comp[j].end(), comp[i].begin(), comp[i].end());
	```
	The 'notSubset' flag is updated by checking if vector 'comp[i]' is included in vector 'comp[j]'. If it is, 'notSubset' is set to false.

11. **Conditional Check**
	```cpp
	        if(notSubset)
	```
	If the 'notSubset' flag is still true after checking all other vectors, it means 'comp[i]' is not a subset of any other vector.

12. **Vector Update**
	```cpp
	            res.push_back(i);
	```
	If 'comp[i]' is not a subset of any other vector, the index 'i' is added to the result vector 'res'.

13. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the vector 'res', which contains the indices of vectors that are not subsets of any other vectors.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2 * m)
- **Average Case:** O(n^2 * m)
- **Worst Case:** O(n^2 * m)

Where n is the number of people and m is the average length of their favorite companies list. Sorting and subset checks dominate the complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n * m)

Space is used for storing the sorted lists and the result indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/)

---
{{< youtube Ok0jYAMnvQI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
