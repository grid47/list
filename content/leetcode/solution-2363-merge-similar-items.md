
+++
authors = ["grid47"]
title = "Leetcode 2363: Merge Similar Items"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2363: Merge Similar Items in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Ordered Set"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "KjqRqf4KZxE"
youtube_upload_date="2022-08-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/KjqRqf4KZxE/maxresdefault.webp"
comments = true
+++



---
You are given two 2D integer arrays, items1 and items2, each representing a set of items. Each item has a value and a weight. You need to combine both arrays by summing the weights of items with the same value, and return the result as a 2D array, sorted by the item values in ascending order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two 2D arrays, items1 and items2. Each array contains pairs of integers where the first integer is the item's value and the second integer is the item's weight.
- **Example:** `items1 = [[2,3],[5,7],[4,1]], items2 = [[4,2],[2,4]]`
- **Constraints:**
	- 1 <= items1.length, items2.length <= 1000
	- items1[i].length == items2[i].length == 2
	- 1 <= valuei, weighti <= 1000
	- Each valuei in items1 is unique.
	- Each valuei in items2 is unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a 2D array where each element is a pair [value, weight], where the weight is the sum of weights of all items with the same value. The result should be sorted by value in ascending order.
- **Example:** `[[2,7],[4,3],[5,7]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to combine the items from both arrays and sum the weights for the same values, then return the sorted result.

- Create a map to store the value and weight pairs.
- Iterate through the items of the first array and add the value-weight pairs to the map.
- For each item in the second array, check if the value already exists in the map. If it does, add the weight; if it doesn't, create a new entry.
- Convert the map to a 2D array and sort it by the value.
{{< dots >}}
### Problem Assumptions ✅
- The value of each item is unique within the respective arrays.
- Each array contains at least one item.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: items1 = [[2,3],[5,7],[4,1]], items2 = [[4,2],[2,4]]`  \
  **Explanation:** Here, the item with value 2 has a weight of 3 in items1 and a weight of 4 in items2, so the total weight becomes 7. Similarly, for value 4, the total weight is 3 (1 from items1 and 2 from items2). After merging, the result is sorted by the values: [[2,7],[4,3],[5,7]].

{{< dots >}}
## Approach 🚀
The problem can be solved using a hashmap to track the sum of weights for each unique value. This allows us to efficiently combine the arrays and sort the results.

### Initial Thoughts 💭
- We need to efficiently combine the weights of matching items from two arrays.
- The output should be sorted by value.
- Using a hashmap is an efficient way to accumulate the total weight for each unique value.
{{< dots >}}
### Edge Cases 🌐
- If either items1 or items2 is empty, the result should be the other array sorted by values.
- If the input arrays are large, the hashmap approach will still work efficiently.
- If two arrays contain the same value but different weights, the result should reflect the sum of the weights.
- Ensure that the input arrays follow the specified constraints.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
{
    map<int,int> m;
    for(int i=0;i<items1.size();i++)
    {
        m[items1[i][0]]=items1[i][1];
    }
    for(int i=0;i<items2.size();i++)
    {
        if(m.find(items2[i][0])!=m.end())
        {
            m[items2[i][0]]+=items2[i][1];
        }
        else
        {
            m[items2[i][0]]=items2[i][1];
        }
    }
    vector<vector<int>> ans;
    for(auto it : m)
    {
        ans.push_back({it.first,it.second});
    }
    return ans;
    
}
```

This function merges two lists of items, where each item is represented by a pair (ID, value). It sums the values of items with the same ID from both lists and returns the merged list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
	```
	Define a function that takes two vectors of pairs as input: `items1` and `items2`. The function returns a vector of pairs where each pair contains an ID and its corresponding total value.

2. **Data Structures**
	```cpp
	    map<int,int> m;
	```
	Declare a map `m` that will store each item's ID as the key and its value as the associated value.

3. **Iteration**
	```cpp
	    for(int i=0;i<items1.size();i++)
	```
	Start iterating over the first input list `items1`.

4. **Map Update**
	```cpp
	        m[items1[i][0]]=items1[i][1];
	```
	Insert the item ID and value from `items1` into the map `m`. If the ID is already present, it will be overwritten.

5. **Iteration**
	```cpp
	    for(int i=0;i<items2.size();i++)
	```
	Start iterating over the second input list `items2`.

6. **Condition Check**
	```cpp
	        if(m.find(items2[i][0])!=m.end())
	```
	Check if the item ID from `items2` already exists in the map `m`.

7. **Map Update**
	```cpp
	            m[items2[i][0]]+=items2[i][1];
	```
	Add the value from `items2` to the existing value for that item ID in the map `m`.

8. **Add New Entry**
	```cpp
	        else
	```
	If the item ID is not found in the map, insert a new entry.

9. **Map Update**
	```cpp
	            m[items2[i][0]]=items2[i][1];
	```
	Insert the new item ID and its value from `items2` into the map `m`.

10. **Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Declare a vector `ans` to store the final merged and summed items.

11. **Iteration**
	```cpp
	    for(auto it : m)
	```
	Iterate over the map `m` to extract the summed items.

12. **Vector Update**
	```cpp
	        ans.push_back({it.first,it.second});
	```
	Push each item (ID and value) from the map `m` into the result vector `ans`.

13. **Return Statement**
	```cpp
	    return ans;
	```
	Return the final result vector `ans` containing the merged items.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step after populating the hashmap.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the hashmap.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-similar-items/description/)

---
{{< youtube KjqRqf4KZxE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
