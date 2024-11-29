
+++
authors = ["grid47"]
title = "Leetcode 1722: Minimize Hamming Distance After Swap Operations"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1722: Minimize Hamming Distance After Swap Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "G1vTpGA9Gkc"
youtube_upload_date="2021-01-10"
youtube_thumbnail="https://i.ytimg.com/vi/G1vTpGA9Gkc/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays, `source` and `target`, both of length `n`, and an array `allowedSwaps` containing pairs of indices where swapping is allowed. You can perform multiple swaps between the specified pairs to minimize the Hamming distance between `source` and `target`. The Hamming distance is the number of indices where the elements of `source` and `target` differ.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays `source` and `target`, and an array `allowedSwaps` where each element is a pair of indices representing allowed swaps.
- **Example:** `Input: source = [1, 2, 3, 4], target = [2, 1, 4, 5], allowedSwaps = [[0, 1], [2, 3]]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= source[i], target[i] <= 10^5
	- 0 <= allowedSwaps.length <= 10^5
	- allowedSwaps[i].length == 2
	- 0 <= ai, bi <= n - 1
	- ai != bi

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum Hamming distance between `source` and `target` after performing any number of allowed swaps.
- **Example:** `Output: 1`
- **Constraints:**
	- The arrays `source` and `target` have the same length `n`.

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the Hamming distance, you must swap elements in `source` based on the allowed pairs of indices to make it match `target` as much as possible.

- 1. Initialize a union-find data structure to track connected components formed by the allowed swaps.
- 2. For each component (group of indices), group the corresponding elements of `source` and `target`.
- 3. Compare the two groups and count how many elements can be matched in order to minimize the Hamming distance.
- 4. Return the minimum Hamming distance after all possible swaps.
{{< dots >}}
### Problem Assumptions ✅
- The arrays `source` and `target` are non-empty and have the same length.
- The allowed swaps provide the flexibility to change the arrangement of `source` elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: source = [1, 2, 3, 4], target = [2, 1, 4, 5], allowedSwaps = [[0, 1], [2, 3]]`  \
  **Explanation:** By swapping indices 0 and 1, and then indices 2 and 3, the array `source` becomes [2, 1, 4, 3]. This results in a Hamming distance of 1, since only the element at index 3 is different.

- **Input:** `Input: source = [5, 1, 2, 4, 3], target = [1, 5, 4, 2, 3], allowedSwaps = [[0, 4], [4, 2], [1, 3], [1, 4]]`  \
  **Explanation:** By performing the allowed swaps, the `source` array can be transformed into [1, 5, 4, 2, 3], resulting in a Hamming distance of 0, since the arrays now match exactly.

{{< dots >}}
## Approach 🚀
The approach involves using a union-find data structure to group indices that can be swapped and then comparing the elements at those indices in `source` and `target` to minimize the Hamming distance.

### Initial Thoughts 💭
- The allowed swaps form connected components of indices that can be freely rearranged among themselves.
- We can use union-find to efficiently group the indices that can be swapped, and then we can match the corresponding elements from `source` and `target` within each group.
{{< dots >}}
### Edge Cases 🌐
- An empty array is not a valid input, as the problem assumes that `source` and `target` have at least one element.
- The solution should efficiently handle inputs where `n` and `allowedSwaps.length` are as large as 10^5.
- If no allowed swaps are given, the result will be the original Hamming distance between `source` and `target`.
- The arrays `source` and `target` must have the same length.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> parent, rnk;
public:
int minimumHammingDistance(vector<int>& src, vector<int>& dst, vector<vector<int>>& swp) {
    int n = src.size();
    parent.resize(n, 0);
    rnk.resize(n, 0);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for(vector<int> s: swp) {
        int x = find(s[0]);
        int y = find(s[1]);
        if(rnk[x] < rnk[y]) {
            parent[x] = y;
            rnk[y]++;
        } else {
            parent[y] = x;
            rnk[x]++;                
        }
    }
    
    unordered_map<int, unordered_map<int, int>> mp;
    
    for(int i = 0; i < n; i++) {
        int p = find(i);
        auto &m = mp[p];
        m[src[i]]++;
    }
    
    int res = 0;
    
    for(int i = 0; i < n; i++) {
        int p = find(i);
        auto &m = mp[p];
        if((m[dst[i]]--) <= 0) {
            res += 1;
        }
    }
    
    return res;
    
}

int find(int x) {
    int y = parent[x];
    if(y != x) {
        parent[x] = find(y);
    }
    return parent[x];
}
```

The `minimumHammingDistance` function calculates the minimum Hamming distance between two arrays, `src` and `dst`, after performing swap operations on indices specified in `swp`. The solution uses a union-find (disjoint-set) data structure to efficiently group elements that can be swapped and calculates the number of differing elements between the two arrays within each group.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	The class `Solution` is defined, which contains the function `minimumHammingDistance` that will calculate the minimum Hamming distance between two arrays after performing the allowed swap operations.

2. **Variable Declarations**
	```cpp
	vector<int> parent, rnk;
	```
	Two vectors `parent` and `rnk` are declared. `parent` will store the representative of each element in the union-find structure, and `rnk` will store the rank (or depth) of the trees in the union-find structure to keep the structure balanced.

3. **Access Control**
	```cpp
	public:
	```
	This marks the beginning of the public section of the class, making the function `minimumHammingDistance` accessible from outside the class.

4. **Function Definition**
	```cpp
	int minimumHammingDistance(vector<int>& src, vector<int>& dst, vector<vector<int>>& swp) {
	```
	The function `minimumHammingDistance` is defined. It takes three arguments: two integer vectors `src` and `dst` representing the two arrays, and a 2D vector `swp` representing the allowed swap operations between indices.

5. **Initialize n**
	```cpp
	    int n = src.size();
	```
	The integer `n` is initialized to the size of the `src` array, which is assumed to be the same size as `dst`.

6. **Resize Parent Array**
	```cpp
	    parent.resize(n, 0);
	```
	The `parent` array is resized to size `n` and initialized with zeros. Each element will represent its own parent initially.

7. **Resize Rank Array**
	```cpp
	    rnk.resize(n, 0);
	```
	The `rnk` array is resized to size `n` and initialized with zeros. This array will track the rank of each tree in the union-find structure.

8. **Initialize Parent Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to initialize the `parent` array, setting each element's parent to itself.

9. **Set Parent**
	```cpp
	        parent[i] = i;
	```
	Each element in the `parent` array is set to point to itself, indicating that initially each element is its own representative.

10. **Swap Operation Loop**
	```cpp
	    for(vector<int> s: swp) {
	```
	A loop is started to process each swap operation in the `swp` array. Each swap operation is represented as a vector of two integers.

11. **Find Roots for Swap**
	```cpp
	        int x = find(s[0]);
	```
	The `find` function is called to get the root (representative) of the first element `s[0]` in the swap operation.

12. **Find Roots for Swap**
	```cpp
	        int y = find(s[1]);
	```
	The `find` function is called to get the root (representative) of the second element `s[1]` in the swap operation.

13. **Union by Rank**
	```cpp
	        if(rnk[x] < rnk[y]) {
	```
	If the rank of root `x` is less than that of root `y`, the tree rooted at `x` will be attached to the tree rooted at `y`.

14. **Union by Rank**
	```cpp
	            parent[x] = y;
	```
	The parent of `x` is set to `y`, merging the two sets.

15. **Increase Rank**
	```cpp
	            rnk[y]++;
	```
	The rank of root `y` is increased, indicating the depth of the tree has grown.

16. **Union by Rank**
	```cpp
	        } else {
	```
	If the rank of root `x` is greater than or equal to that of root `y`, the tree rooted at `y` is attached to the tree rooted at `x`.

17. **Union by Rank**
	```cpp
	            parent[y] = x;
	```
	The parent of `y` is set to `x`, merging the two sets.

18. **Increase Rank**
	```cpp
	            rnk[x]++;                
	```
	The rank of root `x` is increased.

19. **Create Map**
	```cpp
	    unordered_map<int, unordered_map<int, int>> mp;
	```
	An unordered map `mp` is created to track the frequencies of elements in the `src` array within each connected component.

20. **Populate Map**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to populate the map `mp` with the frequency of elements in `src`.

21. **Add Frequency**
	```cpp
	        int p = find(i);
	```
	The representative `p` of the current element `i` is found.

22. **Add Frequency**
	```cpp
	        auto &m = mp[p];
	```
	A reference `m` to the map of frequencies for the connected component is obtained.

23. **Add Frequency**
	```cpp
	        m[src[i]]++;
	```
	The frequency of `src[i]` is incremented in the map `m` for the connected component `p`.

24. **Calculate Hamming Distance**
	```cpp
	    int res = 0;
	```
	The integer `res` is initialized to 0. This will store the total Hamming distance.

25. **Update Hamming Distance**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to calculate the Hamming distance.

26. **Update Hamming Distance**
	```cpp
	        int p = find(i);
	```
	The representative `p` of the current element `i` is found.

27. **Update Hamming Distance**
	```cpp
	        auto &m = mp[p];
	```
	A reference `m` to the map of frequencies for the connected component is obtained.

28. **Update Hamming Distance**
	```cpp
	        if((m[dst[i]]--) <= 0) {
	```
	If the frequency of `dst[i]` is not sufficient to match, it indicates a mismatch, and the result is incremented.

29. **Increment Result**
	```cpp
	            res += 1;
	```
	The result is incremented when the frequencies don't match.

30. **Return Result**
	```cpp
	    return res;
	```
	The final Hamming distance is returned.

31. **Find Function**
	```cpp
	int find(int x) {
	```
	The `find` function is defined to find the representative (or root) of a given element `x`.

32. **Path Compression**
	```cpp
	    int y = parent[x];
	```
	The parent of `x` is stored in `y`.

33. **Path Compression**
	```cpp
	    if(y != x) {
	```
	If the parent of `x` is not itself, path compression is applied.

34. **Path Compression**
	```cpp
	        parent[x] = find(y);
	```
	The parent of `x` is set to the representative of `y` recursively.

35. **Return Representative**
	```cpp
	    return parent[x];
	```
	The representative (or root) of `x` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where n is the number of elements in `source` and `target`, and m is the number of allowed swaps.
- **Average Case:** O(n + m), as we process each swap and each element in the arrays once.
- **Worst Case:** O(n + m), where n is the number of elements and m is the number of allowed swaps.

The time complexity is linear in terms of both the number of elements and the number of allowed swaps.

### Space Complexity 💾
- **Best Case:** O(n), as the space used is proportional to the size of the input arrays and the union-find structure.
- **Worst Case:** O(n + m), for storing the union-find data structure and the collections of elements in each group.

The space complexity is linear in terms of the number of elements and the number of allowed swaps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/)

---
{{< youtube G1vTpGA9Gkc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
