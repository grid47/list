
+++
authors = ["grid47"]
title = "Leetcode 2226: Maximum Candies Allocated to K Children"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2226: Maximum Candies Allocated to K Children in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Y2V4hLvjn10"
youtube_upload_date="2022-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Y2V4hLvjn10/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `candies`, where each element represents the number of candies in a pile. You also have an integer `k`, which is the number of children. You need to distribute the candies into `k` piles such that each child gets the same number of candies. Each child can receive at most one pile, and some piles may go unused. Your task is to return the maximum number of candies each child can receive.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `candies`, where each element is the size of a pile of candies, and an integer `k`, the number of children.
- **Example:** `candies = [7, 4, 10], k = 3`
- **Constraints:**
	- 1 <= candies.length <= 10^5
	- 1 <= candies[i] <= 10^7
	- 1 <= k <= 10^12

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of candies each child can receive, such that each child gets the same number of candies.
- **Example:** `Output: 4`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the maximum number of candies each child can get, ensuring that each child gets the same number of candies, by distributing the candies from the available piles.

- First, calculate the total sum of all candies in the piles.
- Check if the total candies are sufficient to satisfy `k` children.
- Use binary search to find the maximum number of candies each child can get. For each mid value, check if it's possible to divide the piles such that at least `k` children get the same number of candies.
{{< dots >}}
### Problem Assumptions ✅
- Each child can receive at most one pile of candies.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: candies = [7, 4, 10], k = 3`  \
  **Explanation:** In this case, we can divide the candies into piles of size 4 (from the 10 candy pile) and 3 (from the 7 candy pile), leaving one pile of size 4 unused. Each of the three children can then receive 4 candies.

- **Input:** `Input: candies = [1, 2, 3], k = 4`  \
  **Explanation:** There are only 6 candies, but 4 children need to be satisfied, so it's impossible to give each child at least one candy, and the answer is 0.

{{< dots >}}
## Approach 🚀
The approach involves using binary search to find the maximum number of candies each child can get. We first calculate the total number of candies and use binary search to explore the possible values of the number of candies each child can get. For each value, we check if it's possible to divide the candies such that at least `k` children receive that number.

### Initial Thoughts 💭
- Binary search is useful for finding the maximum value in this type of optimization problem.
- Start with the total sum of candies and search for the maximum possible number of candies each child can get using binary search.
{{< dots >}}
### Edge Cases 🌐
- If the `candies` array is empty, the result is 0 since there are no candies to distribute.
- The solution should handle cases where `candies.length` is large (up to 100,000) and `k` can be as large as 10^12 efficiently.
- If the total number of candies is less than `k`, return 0 since it's impossible to satisfy all children.
- The solution should optimize for time complexity to handle the large input sizes.
{{< dots >}}
## Code 💻
```cpp

bool can(vector<int>& candies, long long kids, int per) {
    long long cnt = 0;
    for(int i = 0; i < candies.size(); i++) {
        if(candies[i] < per) continue;
        
        int tmp = candies[i];
        cnt+= tmp/per;
    }
    
    return cnt >= kids;
}

int maximumCandies(vector<int>& candies, long long k) {
    
    long long sum = accumulate(candies.begin(), candies.end(), 0L);
    if(sum < k) return 0;
    
    int l = 1, r = *max_element(candies.begin(), candies.end());
    int ans = 0;
    
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        if(can(candies, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
```

This code contains two functions: 'can', which checks if it's possible to distribute candies equally among kids, and 'maximumCandies', which uses binary search to find the maximum number of candies each kid can get.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool can(vector<int>& candies, long long kids, int per) {
	```
	The `can` function is declared, which checks whether it's possible to distribute `per` candies to `kids` based on the number of candies available.

2. **Variable Initialization**
	```cpp
	    long long cnt = 0;
	```
	A variable `cnt` is initialized to 0 to keep track of how many kids can receive at least `per` candies.

3. **Loop**
	```cpp
	    for(int i = 0; i < candies.size(); i++) {
	```
	A loop iterates through each candy count in the `candies` vector to determine how many candies can be given to the kids.

4. **Condition Check**
	```cpp
	        if(candies[i] < per) continue;
	```
	If a particular candy count is less than `per`, the loop skips that entry as it cannot be used to distribute to a kid.

5. **Variable Assignment**
	```cpp
	        int tmp = candies[i];
	```
	The number of candies available in the current iteration is assigned to the variable `tmp`.

6. **Candy Distribution**
	```cpp
	        cnt+= tmp/per;
	```
	The number of kids that can receive `per` candies from the current candy count (`tmp`) is added to `cnt`.

7. **Return Statement**
	```cpp
	    return cnt >= kids;
	```
	The function returns `true` if the total number of kids that can receive at least `per` candies is greater than or equal to the number of kids (`k`). Otherwise, it returns `false`.

8. **Function Declaration**
	```cpp
	int maximumCandies(vector<int>& candies, long long k) {
	```
	The `maximumCandies` function is declared, which uses binary search to determine the maximum number of candies that can be distributed equally to the kids.

9. **Variable Initialization**
	```cpp
	    long long sum = accumulate(candies.begin(), candies.end(), 0L);
	```
	The variable `sum` is initialized with the total sum of candies available by accumulating all elements in the `candies` vector.

10. **Condition Check**
	```cpp
	    if(sum < k) return 0;
	```
	If the total number of candies is less than the number of kids, the function returns 0 as it's impossible to distribute candies.

11. **Variable Initialization**
	```cpp
	    int l = 1, r = *max_element(candies.begin(), candies.end());
	```
	Two variables `l` and `r` are initialized to represent the lower and upper bounds for binary search. `l` starts at 1, and `r` is set to the maximum value in the `candies` vector.

12. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to 0 to store the maximum number of candies that can be distributed equally to all kids.

13. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	A while loop is used to perform binary search between the lower and upper bounds (`l` and `r`) to find the optimal number of candies per kid.

14. **Binary Search Calculation**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	The midpoint `mid` is calculated to check how many candies can be distributed equally to all the kids.

15. **Condition Check**
	```cpp
	        if(can(candies, k, mid)) {
	```
	If the `can` function returns `true` for the midpoint number of candies, it means it's possible to distribute candies equally to all the kids.

16. **Update Result**
	```cpp
	            ans = mid;
	```
	If the distribution is possible, the `ans` variable is updated to store the current `mid` value, which represents the maximum candies that can be distributed to each kid.

17. **Binary Search Update**
	```cpp
	            l = mid + 1;
	```
	The lower bound `l` is updated to `mid + 1` to search for larger values in the next iteration of the binary search.

18. **Else Condition**
	```cpp
	        } else {
	```
	If the `can` function returns `false`, it means the current `mid` value is too large, and we need to search for smaller values.

19. **Binary Search Update**
	```cpp
	            r = mid - 1;
	```
	The upper bound `r` is updated to `mid - 1` to search for smaller values in the next iteration of the binary search.

20. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the maximum number of candies that can be distributed equally to the kids.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log(max(candies[i])))
- **Average Case:** O(n log(max(candies[i])))
- **Worst Case:** O(n log(max(candies[i])))

The binary search process runs in `log(max(candies[i]))` time, and for each search step, we calculate the possible piles which takes linear time O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only use a few variables and do not require additional space proportional to the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/)

---
{{< youtube Y2V4hLvjn10 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
