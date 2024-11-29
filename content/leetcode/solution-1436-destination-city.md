
+++
authors = ["grid47"]
title = "Leetcode 1436: Destination City"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1436: Destination City in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Hi8vMnnTZHE"
youtube_upload_date="2023-12-15"
youtube_thumbnail="https://i.ytimg.com/vi/Hi8vMnnTZHE/maxresdefault.jpg"
comments = true
+++



---
You are given an array `paths` where each element represents a pair of cities `[cityAi, cityBi]`, indicating a direct route from `cityAi` to `cityBi`. Your task is to find the destination city, which is the city without any outgoing path to another city.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `paths`, where each element is a pair of strings `[cityAi, cityBi]` representing a direct path from `cityAi` to `cityBi`.
- **Example:** `paths = [['Paris', 'Berlin'], ['Berlin', 'Madrid'], ['Madrid', 'Lisbon']]`
- **Constraints:**
	- 1 <= paths.length <= 100
	- paths[i].length == 2
	- 1 <= cityAi.length, cityBi.length <= 10
	- cityAi != cityBi
	- All strings consist of lowercase and uppercase English letters and the space character.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the name of the destination city, which is the city that does not have any outgoing path.
- **Example:** `'Lisbon'`
- **Constraints:**
	- The output is a string representing the destination city.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the city that has no outgoing paths by iterating through the `paths` array.

- Step 1: Create a set to store cities with outgoing paths.
- Step 2: For each pair in the `paths` array, mark `cityAi` as having an outgoing path.
- Step 3: The city that is not in the set of cities with outgoing paths is the destination city.
{{< dots >}}
### Problem Assumptions ✅
- The input paths array contains valid pairs of strings.
- The graph of cities forms a line with no loops.
{{< dots >}}
## Examples 🧩
- **Input:** `paths = [['Paris', 'Berlin'], ['Berlin', 'Madrid'], ['Madrid', 'Lisbon']]`  \
  **Explanation:** Starting from 'Paris', we reach 'Lisbon' by traveling through 'Berlin' and 'Madrid'. 'Lisbon' is the destination city as it has no outgoing path.

- **Input:** `paths = [['A', 'B'], ['B', 'C'], ['C', 'D']]`  \
  **Explanation:** Following the path 'A' -> 'B' -> 'C' -> 'D', we find that 'D' is the destination city as there is no path from it to another city.

{{< dots >}}
## Approach 🚀
To find the destination city, we can iterate over the list of paths and track cities that have outgoing paths. The destination city is the one that is not present in the list of cities with outgoing paths.

### Initial Thoughts 💭
- The graph forms a line, so there is exactly one destination city.
- We can use a set to efficiently track cities with outgoing paths and then identify the city without an outgoing path.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one path, so there will be no empty input.
- The algorithm should handle paths up to the maximum limit efficiently.
- All cities are distinct, and there are no cycles in the graph.
- Ensure that the solution is efficient for input sizes up to the limit.
{{< dots >}}
## Code 💻
```cpp
string destCity(vector<vector<string>>& paths) {
    map<string, string> mp;
    for(auto s: paths)
        mp[s[0]] = s[1];
    
    string ans = paths[0][0];
    while(mp.count(ans)) {
        ans = mp[ans];
    }
    return ans;
}
```

The `destCity` function determines the destination city from a list of direct paths. It uses a map to store the city pairs and iteratively follows the paths to find the final destination city.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string destCity(vector<vector<string>>& paths) {
	```
	Defines the function `destCity`, which takes a reference to a 2D vector of strings `paths` representing direct routes between cities.

2. **Variable Initialization**
	```cpp
	    map<string, string> mp;
	```
	Initializes a map `mp` to store the start and destination city pairs. The key is the starting city, and the value is the destination city.

3. **Loop**
	```cpp
	    for(auto s: paths)
	```
	Iterates through each pair of cities in the `paths` vector.

4. **Map Insertion**
	```cpp
	        mp[s[0]] = s[1];
	```
	Inserts each pair of cities from the `paths` vector into the map `mp`. The start city `s[0]` maps to the destination city `s[1]`.

5. **Variable Initialization**
	```cpp
	    string ans = paths[0][0];
	```
	Initializes the variable `ans` with the first city in the `paths` vector, assuming it is the starting city.

6. **Loop**
	```cpp
	    while(mp.count(ans)) {
	```
	Starts a while loop that continues as long as the current city `ans` is a key in the map `mp`, meaning there's a next city in the path.

7. **Map Lookup**
	```cpp
	        ans = mp[ans];
	```
	Updates `ans` to the destination city by looking up the current city in the map `mp`.

8. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the value of `ans`, which is the final destination city after traversing all the paths.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the number of paths.
- **Average Case:** O(n) for iterating through all paths and set operations.
- **Worst Case:** O(n) where n is the number of paths.

The time complexity is O(n) where n is the number of paths.

### Space Complexity 💾
- **Best Case:** O(n) if all cities are unique.
- **Worst Case:** O(n) where n is the number of cities (since we may store all cities with outgoing paths).

The space complexity is O(n) due to the storage of cities with outgoing paths in a set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/destination-city/description/)

---
{{< youtube Hi8vMnnTZHE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
