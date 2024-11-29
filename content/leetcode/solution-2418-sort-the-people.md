
+++
authors = ["grid47"]
title = "Leetcode 2418: Sort the People"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2418: Sort the People in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Zv_gXqqslbw"
youtube_upload_date="2024-07-22"
youtube_thumbnail="https://i.ytimg.com/vi/Zv_gXqqslbw/maxresdefault.jpg"
comments = true
+++



---
Given two arrays, one containing the names and the other containing the corresponding heights of people, return the names sorted in descending order by their heights.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays: one for the names and one for the heights of n people.
- **Example:** `names = ["Tom", "Jerry", "Mickey"], heights = [170, 160, 175]`
- **Constraints:**
	- 1 <= n <= 1000
	- 1 <= names[i].length <= 20
	- 1 <= heights[i] <= 10^5
	- names[i] consists of lower and upper case English letters.
	- All heights are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the names of the people sorted in descending order by height.
- **Example:** `Output: ["Mickey", "Tom", "Jerry"]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the people by their heights in descending order while maintaining the correct mapping of names.

- 1. Create a list of pairs, each containing a height and a corresponding name.
- 2. Sort the pairs in descending order by height.
- 3. Extract and return the sorted names.
{{< dots >}}
### Problem Assumptions ✅
- The names array contains distinct names and corresponds to the heights array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: names = ["Tom", "Jerry", "Mickey"], heights = [170, 160, 175]`  \
  **Explanation:** The heights are sorted as [175, 170, 160], so the corresponding names are sorted as ["Mickey", "Tom", "Jerry"].

{{< dots >}}
## Approach 🚀
We can solve this problem by creating a list of pairs and sorting them based on the heights in descending order.

### Initial Thoughts 💭
- We need to sort the names based on their corresponding heights.
- Since the heights are distinct, we don't need to worry about ties when sorting.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees at least one person in the input, so this case will not occur.
- Ensure the solution efficiently handles cases where n is close to 1000.
- If there is only one person, the list of names is trivially sorted.
- The number of names and heights will always match, and the heights are distinct.
{{< dots >}}
## Code 💻
```cpp
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, string>> A;
    int N = names.size();
    for(int i = 0; i < N; i++) {
        A.push_back({heights[i], names[i]});
    }

    sort(A.rbegin(), A.rend());

    vector<string> ans;
    for(int i = 0; i < N; i++) {
        ans.push_back(A[i].second);
    }
    return ans;
}
```

This function sorts people based on their height in descending order while keeping their names intact. The algorithm first creates a pair of height and name, then sorts the pairs in descending order, and finally retrieves the names in the sorted order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
	```
	This line defines the function 'sortPeople' which takes two arguments: a vector of names and a vector of heights. It returns a vector of strings (sorted names).

2. **Variable Initialization**
	```cpp
	    vector<pair<int, string>> A;
	```
	A vector of pairs is initialized to hold pairs of height (int) and name (string). This will be used to store the corresponding heights and names together.

3. **Variable Initialization**
	```cpp
	    int N = names.size();
	```
	The variable 'N' is set to the size of the 'names' vector, which gives the number of elements (people) to be processed.

4. **Loop**
	```cpp
	    for(int i = 0; i < N; i++) {
	```
	A loop is initiated to iterate through the list of names and heights.

5. **Push to Vector**
	```cpp
	        A.push_back({heights[i], names[i]});
	```
	Each height and corresponding name are added as a pair to the vector 'A'.

6. **Sorting**
	```cpp
	    sort(A.rbegin(), A.rend());
	```
	The vector 'A' is sorted in descending order based on the first element of the pairs (the heights), which is achieved using 'rbegin()' and 'rend()' to reverse the order.

7. **Result Initialization**
	```cpp
	    vector<string> ans;
	```
	An empty vector 'ans' is initialized to store the sorted names.

8. **Loop**
	```cpp
	    for(int i = 0; i < N; i++) {
	```
	Another loop is initiated to extract the sorted names from the vector 'A'.

9. **Push to Result**
	```cpp
	        ans.push_back(A[i].second);
	```
	The second element of each pair (the name) is pushed to the 'ans' vector.

10. **Return**
	```cpp
	    return ans;
	```
	The function returns the 'ans' vector containing the names sorted by their corresponding heights.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to sorting the pairs.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the pairs of names and heights.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-the-people/description/)

---
{{< youtube Zv_gXqqslbw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
