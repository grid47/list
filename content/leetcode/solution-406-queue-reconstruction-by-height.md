
+++
authors = ["grid47"]
title = "Leetcode 406: Queue Reconstruction by Height"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 406: Queue Reconstruction by Height in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Indexed Tree","Segment Tree","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/406.webp"
youtube = "6plztg2nnjY"
youtube_upload_date="2020-06-06"
youtube_thumbnail="https://i.ytimg.com/vi/6plztg2nnjY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/406.webp" 
    alt="A series of people with heights, arranging themselves in a queue with each step glowing as they are positioned."
    caption="Solution to LeetCode 406: Queue Reconstruction by Height Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of people, where each person is represented by two integers: their height hi and the number of people ki in front of them who have a height greater than or equal to hi. Your task is to reconstruct the queue based on these attributes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array people where each element represents a person with their height and the number of people taller or of equal height in front of them.
- **Example:** `For people = [[6, 0], [5, 0], [4, 3], [3, 2], [2, 2], [1, 4]], the reconstructed queue is [[4, 3], [5, 0], [6, 0], [3, 2], [2, 2], [1, 4]].`
- **Constraints:**
	- 1 <= people.length <= 2000
	- 0 <= hi <= 10^6
	- 0 <= ki < people.length
	- It is guaranteed that the queue can be reconstructed.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the reconstructed queue where each element represents a person with their height and the number of people taller or of equal height in front of them.
- **Example:** `For people = [[7, 0], [4, 2], [7, 1], [6, 0], [5, 1], [5, 2]], the reconstructed queue is [[7, 0], [5, 1], [6, 0], [5, 2], [7, 1], [4, 2]].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Reconstruct the queue by sorting the people by height in descending order and inserting each person based on their ki value.

- 1. Sort the people in descending order based on their height. If two people have the same height, sort by their ki value in ascending order.
- 2. For each person, insert them at the index specified by their ki value in the current reconstructed queue.
- 3. Return the reconstructed queue.
{{< dots >}}
### Problem Assumptions ✅
- The input list contains valid people data and can always be reconstructed into a valid queue.
{{< dots >}}
## Examples 🧩
- **Input:** `For people = [[6, 0], [5, 0], [4, 3], [3, 2], [2, 2], [1, 4]], the reconstructed queue is [[4, 3], [5, 0], [6, 0], [3, 2], [2, 2], [1, 4]].`  \
  **Explanation:** Sort the people by height in descending order and insert them into the queue based on their ki values.

{{< dots >}}
## Approach 🚀
Sort the people in descending order by height and insert them into the queue using their ki values to ensure the correct order.

### Initial Thoughts 💭
- The key observation is to sort the people first by their height and then by the ki value.
- After sorting the list, inserting each person at their respective position using their ki value will give the correct order.
{{< dots >}}
### Edge Cases 🌐
- For large inputs, ensure that the sorting and insertion steps are efficient enough to handle up to 2000 people.
- The queue can be reconstructed even if the people are already in the correct order.
- The solution must handle inputs with varying heights and ki values, ensuring that the final queue meets the given conditions.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    
    sort( people.begin(), people.end(), [] (vector<int> a, vector<int> b) {
        
        return a[0] > b[0] || ((a[0] == b[0]) && a[1] < b[1]);
        
    });
    
    vector<vector<int>> ans;
    for(auto p: people) 
        ans.insert(ans.begin() + p[1], p);
    
    return ans;
    
}
```

This function reconstructs a queue based on the given list of people where each person is represented as a pair [height, number of people in front with greater or equal height]. It sorts the list of people, then inserts each person at their correct position in the result list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	```
	Define the function `reconstructQueue`, which takes a reference to a 2D vector `people` and returns a 2D vector with the reconstructed queue.

2. **Sorting**
	```cpp
	    sort( people.begin(), people.end(), [] (vector<int> a, vector<int> b) {
	```
	Sort the `people` vector. The custom comparator sorts primarily by height (in descending order) and, if the heights are the same, by the number of people in front (in ascending order).

3. **Sorting Logic**
	```cpp
	        return a[0] > b[0] || ((a[0] == b[0]) && a[1] < b[1]);
	```
	The sorting logic ensures that taller people come first. If two people have the same height, the one with fewer people ahead of them (based on the second value in the pair) comes first.

4. **Vector Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Initialize an empty 2D vector `ans` to store the reconstructed queue.

5. **For Loop**
	```cpp
	    for(auto p: people) 
	```
	Start a `for` loop to iterate through each person `p` in the sorted `people` vector.

6. **Vector Insertion**
	```cpp
	        ans.insert(ans.begin() + p[1], p);
	```
	Insert the person `p` at the correct position in the `ans` vector. The position is determined by the second value of the pair `p[1]`, which represents the number of people in front of them with greater or equal height.

7. **Return Statement**
	```cpp
	    return ans;
	```
	Return the `ans` vector, which now contains the reconstructed queue.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the reconstructed queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/queue-reconstruction-by-height/description/)

---
{{< youtube 6plztg2nnjY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
