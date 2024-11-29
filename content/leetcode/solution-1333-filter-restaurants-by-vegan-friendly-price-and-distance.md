
+++
authors = ["grid47"]
title = "Leetcode 1333: Filter Restaurants by Vegan-Friendly, Price and Distance"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1333: Filter Restaurants by Vegan-Friendly, Price and Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a list of restaurants where each restaurant is represented by an array: [id, rating, veganFriendly, price, distance]. Filter these restaurants based on three criteria: vegan friendliness, maximum price, and maximum distance. Return the restaurant IDs, ordered by rating (highest first), and by ID (highest first) when ratings are tied.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of lists where each inner list represents a restaurant. The structure of each inner list is [id, rating, veganFriendly, price, distance]. Three additional parameters are provided: veganFriendly (1 or 0), maxPrice, and maxDistance.
- **Example:** `[[1,5,1,40,10], [2,8,0,50,5], [3,7,1,20,3], [4,9,0,15,6], [5,2,1,25,7]]`
- **Constraints:**
	- 1 <= restaurants.length <= 10^4
	- restaurants[i].length == 5
	- 1 <= id, rating, price, distance <= 10^5
	- 1 <= maxPrice, maxDistance <= 10^5
	- veganFriendly is 0 or 1
	- All ids are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of restaurant IDs after applying the filters, sorted by rating in descending order and by ID in descending order for restaurants with the same rating.
- **Example:** `[4,2,3,1,5]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to filter the restaurants based on vegan friendliness, maximum price, and maximum distance. Then, sort the remaining restaurants by rating and ID.

- Loop through each restaurant and apply the filters based on veganFriendly, maxPrice, and maxDistance.
- After filtering, sort the remaining restaurants based on their rating (highest to lowest) and ID (highest to lowest).
{{< dots >}}
### Problem Assumptions ✅
- Restaurants with the same rating should be sorted by their ID.
- All restaurant IDs are unique.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1,5,1,40,10], [2,8,0,50,5], [3,7,1,20,3], [4,9,0,15,6], [5,2,1,25,7]]`  \
  **Explanation:** This example demonstrates filtering based on vegan friendliness and maximum price and distance. After filtering, restaurants are sorted by rating (highest first) and ID (highest first).

{{< dots >}}
## Approach 🚀
To solve this problem, we need to filter and sort the restaurants based on the given criteria.

### Initial Thoughts 💭
- Restaurants need to be filtered before sorting.
- Sorting should be done based on two criteria: rating and ID.
- The best approach is to first filter the restaurants and then sort them according to the rating and ID.
{{< dots >}}
### Edge Cases 🌐
- If there are no restaurants after applying filters, the output should be an empty list.
- The solution should be efficient enough to handle large inputs (up to 10^4 restaurants).
- All restaurants being excluded due to filters.
- Restaurants' IDs are distinct.
{{< dots >}}
## Code 💻
```cpp
static bool cmp(vector<int> &a, vector<int> &b) {
    if(a[1] == b[1]) return a[0] > b[0];
    else return a[1] > b[1];
}

vector<int> filterRestaurants(vector<vector<int>>& rest, int veg, int mxp, int mxd) {
    
    vector<vector<int>> ans;
    
    for(auto r: rest) {
        if((!veg || (veg == r[2])) && r[3] <= mxp && r[4] <= mxd) {
            ans.push_back({r[0], r[1]});
        }
    }
    
    sort(ans.begin(), ans.end(), cmp);
    
    vector<int> res;
    for(auto x: ans) {
        res.push_back(x[0]);
    }
    return res;
}
```

This function filters and sorts a list of restaurants based on specific conditions. It uses a custom comparator to sort the restaurants first by rating, and then by ID in descending order. The filtered list is returned.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Comparator Function**
	```cpp
	static bool cmp(vector<int> &a, vector<int> &b) {
	```
	This defines a comparator function 'cmp' which is used to sort restaurants. It compares two restaurants based on their ratings, and in case of a tie, it compares by restaurant ID.

2. **Comparator - Rating Tie**
	```cpp
	    if(a[1] == b[1]) return a[0] > b[0];
	```
	If the ratings are equal, the function compares the restaurant IDs, and returns true if the ID of 'a' is greater than that of 'b'.

3. **Comparator - Rating Comparison**
	```cpp
	    else return a[1] > b[1];
	```
	If the ratings are not equal, the function compares them and returns true if 'a' has a higher rating than 'b'.

4. **Function Declaration**
	```cpp
	vector<int> filterRestaurants(vector<vector<int>>& rest, int veg, int mxp, int mxd) {
	```
	The 'filterRestaurants' function is declared, which takes the list of restaurants and three integer parameters (veg, mxp, mxd) as inputs. It returns a vector of restaurant IDs.

5. **Initialize Answer List**
	```cpp
	    vector<vector<int>> ans;
	```
	A 2D vector 'ans' is initialized to store the filtered restaurants' IDs and ratings.

6. **Loop Over Restaurants**
	```cpp
	    for(auto r: rest) {
	```
	The function begins looping over each restaurant in the input list 'rest'.

7. **Filter Condition**
	```cpp
	        if((!veg || (veg == r[2])) && r[3] <= mxp && r[4] <= mxd) {
	```
	This condition filters restaurants based on whether they are vegetarian (if 'veg' is true), and if their price and distance meet the given thresholds ('mxp' and 'mxd').

8. **Add to Answer List**
	```cpp
	            ans.push_back({r[0], r[1]});
	```
	If the restaurant satisfies the filtering conditions, its ID and rating are added to the 'ans' vector.

9. **Sort the Filtered List**
	```cpp
	    sort(ans.begin(), ans.end(), cmp);
	```
	The filtered list of restaurants is sorted using the 'cmp' comparator function defined earlier.

10. **Initialize Result List**
	```cpp
	    vector<int> res;
	```
	A vector 'res' is initialized to store the final result, which will be the restaurant IDs after sorting.

11. **Populate Result List**
	```cpp
	    for(auto x: ans) {
	```
	This loop goes through the sorted list 'ans' and extracts the restaurant IDs to store them in the 'res' vector.

12. **Add ID to Result**
	```cpp
	        res.push_back(x[0]);
	```
	The restaurant ID 'x[0]' is added to the 'res' vector.

13. **Return the Result**
	```cpp
	    return res;
	```
	The function returns the final sorted and filtered list of restaurant IDs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) where n is the number of restaurants.
- **Average Case:** O(n log n) due to the sorting step.
- **Worst Case:** O(n log n) due to the sorting step.

The main time complexity comes from sorting the restaurants.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the filtered restaurants before sorting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
