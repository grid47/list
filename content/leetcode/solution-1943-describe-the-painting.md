
+++
authors = ["grid47"]
title = "Leetcode 1943: Describe the Painting"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1943: Describe the Painting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "inJXN48LgPo"
youtube_upload_date="2021-07-24"
youtube_thumbnail="https://i.ytimg.com/vi/inJXN48LgPo/maxresdefault.jpg"
comments = true
+++



---
You are given a painting represented by a number line. Multiple overlapping segments are painted with different colors. Your task is to return a minimal set of non-overlapping painted segments, where each segment represents a portion of the painting with a unique set of mixed colors. Each segment should be represented by the sum of the colors in the mixed sets.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of segments, where each segment is represented by [start, end, color]. Each segment is half-closed, meaning it includes the start value and excludes the end value. The color is a positive integer.
- **Example:** `segments = [[1,5,5], [4,7,7], [1,7,9]]`
- **Constraints:**
	- 1 <= segments.length <= 2 * 10^4
	- segments[i].length == 3
	- 1 <= start_i < end_i <= 10^5
	- 1 <= color_i <= 10^9
	- Each color_i is distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of non-overlapping segments represented by [left, right, mixed_color_sum], where mixed_color_sum is the sum of the colors in the mixed set of that segment.
- **Example:** `Output: [[1, 4, 14], [4, 7, 16]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To merge overlapping segments and compute the sum of mixed colors for each non-overlapping segment.

- Sort the segments by their starting position.
- Use a map to track the color sum at each position of the painting.
- Iterate through the segments and update the color sums in the map.
- After processing all segments, extract the non-overlapping segments and their respective color sums.
{{< dots >}}
### Problem Assumptions ✅
- The input segments are valid and the color values are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `segments = [[1,7,9], [6,8,15], [8,10,7]]`  \
  **Explanation:** In this example, the first segment paints [1, 7) with color 9, the second segment paints [6, 8) with color 15, and the third paints [8, 10) with color 7. The resulting segments are [1, 6) with color 9, [6, 7) with mixed colors 9 and 15 (sum = 24), [7, 8) with color 15, and [8, 10) with color 7.

{{< dots >}}
## Approach 🚀
The problem can be solved by sorting the segments and using a map to track the color sums at each position of the number line.

### Initial Thoughts 💭
- Overlapping segments need to be merged to form non-overlapping segments with color sums.
- The map data structure can help us efficiently track the color sums during the iteration.
{{< dots >}}
### Edge Cases 🌐
- If no segments are provided, return an empty result.
- Ensure the solution handles the maximum input size efficiently.
- Handle cases where multiple segments overlap at the same position.
- Manage memory and time complexity effectively for large input sizes.
{{< dots >}}
## Code 💻
```cpp
class Solution {
typedef long long ll;
public:
vector<vector<long long>> splitPainting(vector<vector<int>>& segs) {
    
   // sort(seg.begin(), seg.end());
    
    map<ll, ll> mp;
    
    
    vector<vector<ll>> res;
    int n = segs.size();
    for(vector<int> seg : segs) {
        mp[seg[0]] += seg[2];
        mp[seg[1]] -= seg[2];
        
        
        }
    
    ll prv = -1, clr = 0;
    for(auto & itr : mp) {
        
        if(clr )
            res.push_back({prv, itr.first, clr});
        clr += itr.second;
        prv = itr.first;
        
        }
    
    return res;
}
```

This code implements a solution to split painting segments where each segment is described by a start point, an end point, and the color it covers. It uses a map to track color changes at specific points and calculates the merged segments.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **CodeStructure**
	```cpp
	class Solution {
	```
	This defines the Solution class, which will contain the method to split painting segments.

2. **Typedef**
	```cpp
	typedef long long ll;
	```
	Defines 'll' as a shorthand for 'long long', which is used for larger integer values.

3. **Access Control**
	```cpp
	public:
	```
	Defines the start of the public section of the class, where the method 'splitPainting' will be defined.

4. **Method Definition**
	```cpp
	vector<vector<long long>> splitPainting(vector<vector<int>>& segs) {
	```
	This defines the 'splitPainting' method, which takes a vector of painting segments and returns the merged result.

5. **Data Structure**
	```cpp
	    map<ll, ll> mp;
	```
	Declares a map 'mp' where the key is the position and the value is the color value at that position.

6. **Initialization**
	```cpp
	    vector<vector<ll>> res;
	```
	Declares a vector 'res' to store the final result of merged painting segments.

7. **Variable Declaration**
	```cpp
	    int n = segs.size();
	```
	Stores the number of painting segments into the variable 'n'.

8. **Loop**
	```cpp
	    for(vector<int> seg : segs) {
	```
	Iterates over each painting segment in the input 'segs'.

9. **Map Update**
	```cpp
	        mp[seg[0]] += seg[2];
	```
	Updates the map to reflect the color change at the starting position of the segment.

10. **Map Update**
	```cpp
	        mp[seg[1]] -= seg[2];
	```
	Updates the map to reflect the color removal at the ending position of the segment.

11. **LoopEnd**
	```cpp
	        }
	```
	End of the loop iterating over the segments.

12. **Variable Initialization**
	```cpp
	    ll prv = -1, clr = 0;
	```
	Initializes 'prv' as -1 to keep track of the previous position and 'clr' to track the current color.

13. **Loop**
	```cpp
	    for(auto & itr : mp) {
	```
	Iterates over the map 'mp' to process each position and color change.

14. **Condition**
	```cpp
	        if(clr )
	```
	Checks if the current color is non-zero before adding the segment to the result.

15. **Result Update**
	```cpp
	            res.push_back({prv, itr.first, clr});
	```
	Adds a new merged segment to the result vector 'res'.

16. **Color Update**
	```cpp
	        clr += itr.second;
	```
	Updates the current color based on the map entry, adding the color change at the current position.

17. **Position Update**
	```cpp
	        prv = itr.first;
	```
	Updates the previous position to the current position.

18. **Return**
	```cpp
	    return res;
	```
	Returns the merged painting segments as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), where n is the number of segments.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of a map to store the color sums at each position of the painting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/describe-the-painting/description/)

---
{{< youtube inJXN48LgPo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
