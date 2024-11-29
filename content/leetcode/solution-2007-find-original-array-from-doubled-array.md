
+++
authors = ["grid47"]
title = "Leetcode 2007: Find Original Array From Doubled Array"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2007: Find Original Array From Doubled Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "z40B-Mr9_qk"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/z40B-Mr9_qk/maxresdefault.jpg"
comments = true
+++



---
You are given an array changed, which may have been created by doubling each element of an original array and then shuffling the elements. Your task is to determine if changed can be converted back into the original array, where each element in the original array has its double present in changed. If changed is not a valid doubled array, return an empty array. If it is valid, return the original array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array changed, which may be a shuffled version of the original array with each element doubled.
- **Example:** `changed = [2, 4, 1, 8, 3, 6]`
- **Constraints:**
	- 1 <= changed.length <= 10^5
	- 0 <= changed[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the original array if it is valid, otherwise return an empty array.
- **Example:** `[1, 3, 4]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check whether each element in changed has its double also in changed and return the original array or an empty array if it is not possible.

- 1. Check if the size of changed is even, as there must be pairs of elements.
- 2. Sort the array to easily identify and pair the elements.
- 3. Use a frequency map to count occurrences of each element in changed.
- 4. For each element, check if its double exists in the map and decrease the counts accordingly.
- 5. Return the original array if all pairs are valid, otherwise return an empty array.
{{< dots >}}
### Problem Assumptions ✅
- The solution should efficiently handle arrays of size up to 100,000.
- Handling large numbers and ensuring correctness of doubled pairs is critical.
{{< dots >}}
## Examples 🧩
- **Input:** `changed = [2, 4, 1, 8, 3, 6]`  \
  **Explanation:** The valid pairs are (1, 2), (3, 6), and (4, 8). Hence, the original array is [1, 3, 4].

- **Input:** `changed = [3, 0, 1, 6]`  \
  **Explanation:** Since there are no valid pairs, the output is an empty array.

- **Input:** `changed = [5]`  \
  **Explanation:** Since there is no pair for 5, the output is an empty array.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we can use a frequency map to track the counts of each number in the array and validate if each element has its double present.

### Initial Thoughts 💭
- We need to ensure that for each element in the array, its double exists in the array as well.
- Sorting the array and using a frequency map will help efficiently check if the doubled elements exist.
{{< dots >}}
### Edge Cases 🌐
- If the array has an odd number of elements, return an empty array.
- Ensure that the algorithm runs efficiently for arrays with the maximum size of 100,000.
- If the array contains 0, ensure it pairs correctly with another 0.
- Ensure the solution works within the given constraints of 1 <= changed.length <= 10^5 and 0 <= changed[i] <= 10^5.
{{< dots >}}
## Code 💻
```cpp
vector<int> findOriginalArray(vector<int>& chg) {
    
    if(chg.size() % 2) return vector<int>{};
    
    sort(chg.begin(), chg.end());
    map<int, int> mp;
    for(int i = 0; i < chg.size(); i++)
        mp[chg[i]]++;
    vector<int> ans;
    
    int i = 0;

    while((ans.size() < chg.size() / 2) && i < chg.size()) {
        
        if(chg[i] == 0) {
            if(mp[chg[i]] >= 2) {
                mp[chg[i]] -= 2;
                ans.push_back(chg[i]);                    
            }
            i++;
            continue;
        }
        
        if((mp.count(chg[i]) && mp.count(chg[i] * 2))) {
            ans.push_back(chg[i]);
            
            if(mp[chg[i]] == 1)
            mp.erase(chg[i]);
            else
            mp[chg[i]]--;
            
            if(mp[chg[i] * 2] == 1)
            mp.erase(chg[i] * 2);
            else
            mp[chg[i] * 2]--;                
            
            // cout << chg[i]     << " " << mp[chg[i]    ] << "\n";                
            // cout << chg[i] * 2 << " " << mp[chg[i] * 2] << "\n";
        }
        
        i++;
    }
    
    return ans.size() == chg.size() / 2? ans: vector<int>{};
}
```

This function attempts to find the original array from the modified `chg` array. It checks if each element can pair with a double of itself from the `chg` array and returns the original array if the size conditions are met.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findOriginalArray(vector<int>& chg) {
	```
	Defines the function `findOriginalArray` which accepts a reference to a vector `chg` and returns the original array if possible.

2. **Odd Size Check**
	```cpp
	    if(chg.size() % 2) return vector<int>{};
	```
	Checks if the size of the `chg` array is odd. If so, it returns an empty vector since the original array cannot be formed.

3. **Sorting**
	```cpp
	    sort(chg.begin(), chg.end());
	```
	Sorts the array `chg` in ascending order to ensure elements are processed in a sequential manner.

4. **Frequency Map Setup**
	```cpp
	    map<int, int> mp;
	```
	Declares a map `mp` to store the frequency of each element in `chg`.

5. **Counting Frequency**
	```cpp
	    for(int i = 0; i < chg.size(); i++)
	```
	Iterates through each element in the sorted `chg` array to count its frequency.

6. **Increment Frequency**
	```cpp
	        mp[chg[i]]++;
	```
	Increments the count of the current element `chg[i]` in the frequency map `mp`.

7. **Original Array Setup**
	```cpp
	    vector<int> ans;
	```
	Declares a vector `ans` to store the elements of the original array once identified.

8. **Index Initialization**
	```cpp
	    int i = 0;
	```
	Initializes the index `i` to iterate through the sorted `chg` array.

9. **Loop Condition Check**
	```cpp
	    while((ans.size() < chg.size() / 2) && i < chg.size()) {
	```
	Starts a while loop that continues until half of the elements are found in `ans` or until all elements have been processed.

10. **Zero Check**
	```cpp
	        if(chg[i] == 0) {
	```
	Checks if the current element is zero.

11. **Zero Pairing**
	```cpp
	            if(mp[chg[i]] >= 2) {
	```
	If the count of zero is at least 2, it is valid for pairing.

12. **Update Map for Zero**
	```cpp
	                mp[chg[i]] -= 2;
	```
	Decreases the count of zero by 2 in the frequency map since it forms a valid pair.

13. **Store Zero in Answer**
	```cpp
	                ans.push_back(chg[i]);                    
	```
	Adds zero to the result array `ans`.

14. **Continue Check**
	```cpp
	            i++;
	```
	Increments the index `i` to continue checking the next element.

15. **Skip to Next**
	```cpp
	            continue;
	```
	Skips the rest of the loop and continues to the next iteration.

16. **Pair Check for Non-Zero**
	```cpp
	        if((mp.count(chg[i]) && mp.count(chg[i] * 2))) {
	```
	Checks if the current element `chg[i]` and its double `chg[i]*2` are both present in the map `mp`.

17. **Store Element in Answer**
	```cpp
	            ans.push_back(chg[i]);
	```
	Adds the current element `chg[i]` to the result array `ans`.

18. **Erase or Decrement Map**
	```cpp
	            if(mp[chg[i]] == 1)
	```
	Checks if the frequency of `chg[i]` is 1.

19. **Remove Element from Map**
	```cpp
	            mp.erase(chg[i]);
	```
	Removes the element `chg[i]` from the map `mp`.

20. **Decrement Frequency**
	```cpp
	            else
	            mp[chg[i]]--;
	```
	If there are more than one of `chg[i]`, it decrements its frequency.

21. **Second Element Pair Check**
	```cpp
	            if(mp[chg[i] * 2] == 1)
	```
	Checks if the frequency of `chg[i] * 2` is 1.

22. **Erase Second Element**
	```cpp
	            mp.erase(chg[i] * 2);
	```
	Removes the doubled element from the frequency map.

23. **Decrement Second Element**
	```cpp
	            else
	            mp[chg[i] * 2]--;                
	```
	Decrements the frequency of `chg[i] * 2`.

24. **Increment Index**
	```cpp
	        i++;
	```
	Increments the index `i` to continue checking the next element.

25. **Final Check**
	```cpp
	    return ans.size() == chg.size() / 2? ans: vector<int>{};
	```
	Returns the result array `ans` if it contains half the size of the original array, otherwise returns an empty vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to sorting the array, followed by a linear scan for checking pairs.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of a frequency map for counting elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-original-array-from-doubled-array/description/)

---
{{< youtube z40B-Mr9_qk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
