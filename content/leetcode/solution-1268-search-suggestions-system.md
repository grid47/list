
+++
authors = ["grid47"]
title = "Leetcode 1268: Search Suggestions System"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1268: Search Suggestions System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Binary Search","Trie","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PLNDfB0Vg9Y"
youtube_upload_date="2021-03-01"
youtube_thumbnail="https://i.ytimg.com/vi/PLNDfB0Vg9Y/maxresdefault.jpg"
comments = true
+++



---
You are given a list of unique product names and a search word. As each character of the search word is typed, you need to suggest up to three products that have a prefix matching the current search word. If there are more than three products with the same prefix, return the three lexicographically smallest products.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A list of unique product names and a search word string.
- **Example:** `products = ["tablet","telescope","test","terrace","time"]
searchWord = "test"`
- **Constraints:**
	- 1 <= products.length <= 1000
	- 1 <= products[i].length <= 3000
	- 1 <= sum(products[i].length) <= 2 * 10^4
	- All the strings in products are unique.
	- 1 <= searchWord.length <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of lists where each list contains at most three products that start with the prefix corresponding to the characters typed so far in searchWord.
- **Example:** `[["tablet", "telescope", "test"], ["tablet", "telescope", "test"], ["test", "telescope"], ["test", "telescope"], ["test"]]`
- **Constraints:**
	- Each list in the output should contain at most three products.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the products that match the current prefix and return the three lexicographically smallest products at each step.

- 1. Sort the product names lexicographically.
- 2. For each character in the search word, create the current prefix.
- 3. Find products that match the current prefix and return at most three of them.
{{< dots >}}
### Problem Assumptions ✅
- The products list contains unique strings.
- The search word is a non-empty string.
{{< dots >}}
## Examples 🧩
- **Input:** `products = ["tablet","telescope","test","terrace","time"]
searchWord = "test"`  \
  **Explanation:** As each character of 'test' is typed, the system suggests products that start with the corresponding prefix. At each step, it returns up to three products, sorted lexicographically.

- **Input:** `products = ["banana","berry","cherry","date"]
searchWord = "berry"`  \
  **Explanation:** In this case, the search word is 'berry'. Since 'berry' is the only product starting with 'b', after each character is typed, only 'berry' will be suggested.

{{< dots >}}
## Approach 🚀
We can implement the system by sorting the product list lexicographically and finding products that match the current prefix at each step.

### Initial Thoughts 💭
- Sorting the products lexicographically allows us to easily get the smallest lexicographical products when a prefix matches.
- After each character of the search word, we can use binary search to quickly find products that start with the current prefix.
{{< dots >}}
### Edge Cases 🌐
- If the product list is empty, return an empty list.
- The solution should efficiently handle large inputs with up to 1000 products and long search words.
- If there are fewer than three products matching a prefix, return all matching products.
- Ensure that the solution efficiently handles sorting and finding products for each prefix.
{{< dots >}}
## Code 💻
```cpp
vector<vector<string>> suggestedProducts(vector<string>& A, string w) {
    auto it = A.begin();
    sort(it, A.end());
    vector<vector<string>> res;
    string cur = "";
    for (char c : w) {
        cur += c;
        vector<string> sdg;
        it = lower_bound(it, A.end(), cur);
for(int i = 0; i < 3 && (it + i) != A.end(); i++) {
            
    string& s = *(i + it);
    if(s.find(cur)) break;
    sdg.push_back(s);
            
        }
        res.push_back(sdg);
    }
    
    return res;
}
```

This code defines the function `suggestedProducts` which takes a list of products and a prefix string. It returns a list of up to three products that match each prefix in the string `w`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<string>> suggestedProducts(vector<string>& A, string w) {
	```
	This defines the function `suggestedProducts`, which takes a vector of strings `A` and a string `w` representing the prefix. The function returns a vector of vectors of strings, where each vector contains up to 3 suggestions for the corresponding prefix of `w`.

2. **Iterator Initialization**
	```cpp
	    auto it = A.begin();
	```
	This initializes an iterator `it` to the beginning of the list `A` (the product list).

3. **Sorting**
	```cpp
	    sort(it, A.end());
	```
	This sorts the vector `A` in lexicographical order to make it easier to find matching products for each prefix.

4. **Result Initialization**
	```cpp
	    vector<vector<string>> res;
	```
	This initializes the result vector `res` to store the list of product suggestions for each prefix.

5. **Prefix Initialization**
	```cpp
	    string cur = "";
	```
	This initializes the string `cur` as an empty string, which will be used to store the current prefix being considered.

6. **Prefix Iteration**
	```cpp
	    for (char c : w) {
	```
	This begins a loop that iterates through each character `c` in the string `w`.

7. **Building Prefix**
	```cpp
	        cur += c;
	```
	This adds the current character `c` to the string `cur`, building the prefix incrementally.

8. **Suggestion Vector Initialization**
	```cpp
	        vector<string> sdg;
	```
	This initializes an empty vector `sdg` that will hold the suggestions for the current prefix.

9. **Lower Bound Search**
	```cpp
	        it = lower_bound(it, A.end(), cur);
	```
	This uses `lower_bound` to find the first product in `A` that is greater than or equal to the current prefix `cur`.

10. **Suggestion Loop**
	```cpp
	for(int i = 0; i < 3 && (it + i) != A.end(); i++) {
	```
	This begins a loop that tries to find up to 3 products matching the current prefix `cur`.

11. **End Suggestion Loop**
	```cpp
	            
	```
	This section marks the continuation of the loop for adding suggestions, but there is no actual code inside.

12. **Checking Prefix Match**
	```cpp
	    string& s = *(i + it);
	```
	This dereferences the iterator `it + i` to get the product string `s` and checks if it matches the current prefix.

13. **Breaking on No Match**
	```cpp
	    if(s.find(cur)) break;
	```
	If the product string `s` does not start with the current prefix `cur`, the loop breaks as no further products will match.

14. **Adding Valid Suggestions**
	```cpp
	    sdg.push_back(s);
	```
	This adds the valid product `s` to the suggestion vector `sdg`.

15. **End Suggestion Loop**
	```cpp
	            
	```
	This section marks the continuation of the loop, but no additional code is inside this block.

16. **Appending Suggestions to Result**
	```cpp
	        res.push_back(sdg);
	```
	This appends the current suggestion vector `sdg` to the result vector `res`.

17. **Returning Result**
	```cpp
	    return res;
	```
	This returns the final result vector `res`, which contains the product suggestions for each prefix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n + m)
- **Average Case:** O(n log n + m)
- **Worst Case:** O(n log n + m)

The time complexity is dominated by the sorting step (O(n log n)) and the time to find matching products for each prefix (O(m)).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the sorted list of products.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/search-suggestions-system/description/)

---
{{< youtube PLNDfB0Vg9Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
