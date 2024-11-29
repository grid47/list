
+++
authors = ["grid47"]
title = "Leetcode 2353: Design a Food Rating System"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2353: Design a Food Rating System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ikp8SgbgbEo"
youtube_upload_date="2023-12-17"
youtube_thumbnail="https://i.ytimg.com/vi/Ikp8SgbgbEo/maxresdefault.jpg"
comments = true
+++



---
Design a food rating system that allows modification of food ratings and can return the highest-rated food item for a given cuisine. In case of a tie, the lexicographically smallest food item should be returned.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the names of food items, the cuisines they belong to, and their corresponding ratings.
- **Example:** `Input: foods = ["pasta", "sushi", "tacos", "paella", "sushi", "pizza"], cuisines = ["italian", "japanese", "mexican", "spanish", "japanese", "italian"], ratings = [9, 12, 8, 15, 14, 7]`
- **Constraints:**
	- 1 <= n <= 2 * 10^4
	- n == foods.length == cuisines.length == ratings.length
	- 1 <= foods[i].length, cuisines[i].length <= 10
	- foods[i], cuisines[i] consist of lowercase English letters
	- 1 <= ratings[i] <= 10^8
	- All food names in the system are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Output the name of the food item with the highest rating for a given cuisine, or the lexicographically smaller one in case of a tie.
- **Example:** `Output: "pasta" for highestRated("italian") when pasta has the highest rating.`
- **Constraints:**
	- The system handles all queries efficiently with a time complexity suited to the input constraints.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently maintain and update the ratings for each food item and return the highest-rated food for each cuisine.

- Store the food items, their ratings, and corresponding cuisines in appropriate data structures.
- For each cuisine, maintain a set of food items ordered by rating (and lexicographically for ties).
- Update the ratings dynamically upon calls to changeRating and ensure the highestRated function returns the correct food item.
{{< dots >}}
### Problem Assumptions ✅
- The system starts with a fixed number of food items and their ratings.
- All food names are distinct and each call to changeRating uses a valid food name.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: foods = ["pasta", "sushi", "tacos", "paella", "sushi", "pizza"], cuisines = ["italian", "japanese", "mexican", "spanish", "japanese", "italian"], ratings = [9, 12, 8, 15, 14, 7]`  \
  **Explanation:** After the initialization, "pasta" is the highest rated italian food, "sushi" is the highest rated japanese food. After changing the rating of "sushi" to 16, "sushi" becomes the highest rated japanese food.

{{< dots >}}
## Approach 🚀
The problem involves managing the food ratings efficiently and performing quick updates and queries on the highest-rated food for a given cuisine.

### Initial Thoughts 💭
- We need to efficiently store and retrieve the highest-rated food for each cuisine.
- The food names should be stored in a way that allows quick comparisons for lexicographical order when ratings are equal.
- We can use hash maps to store the cuisines and food items, along with ordered data structures to efficiently retrieve the highest-rated food.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the system can handle the edge case of having no foods initially.
- The system should efficiently handle the upper limit of 20,000 food items and queries.
- Handle cases where food items share the same rating by returning the lexicographically smaller name.
- The solution must run efficiently even for the maximum input size.
{{< dots >}}
## Code 💻
```cpp
unordered_map<string, string> fd_cus;
unordered_map<string, int> fd_rat;
public:
FoodRatings(vector<string>& fd, vector<string>& cus, vector<int>& rat) {
    int n = fd.size();
    for(int i = 0; i < n; i++) {
        cus_itm[cus[i]].insert(pair(-rat[i], fd[i]));
        fd_cus[fd[i]] = cus[i];
        fd_rat[fd[i]] = rat[i];
    }
}

void changeRating(string fd, int rat) {
    string cus = fd_cus[fd];
    int r = fd_rat[fd];
    cus_itm[cus].erase({-r, fd});
    cus_itm[cus].insert({-rat, fd});
    fd_rat[fd] = rat;
 
}

string highestRated(string cus) {
    return begin(cus_itm[cus])->second;
}
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
```

This solution uses unordered maps to manage food ratings by cuisine and efficiently handles operations like rating changes and querying the highest-rated food for a given cuisine.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Declaration**
	```cpp
	unordered_map<string, string> fd_cus;
	```
	Declares a map to associate each food item with its corresponding cuisine.

2. **Declaration**
	```cpp
	unordered_map<string, int> fd_rat;
	```
	Declares a map to store the rating of each food item.

3. **Access Modifiers**
	```cpp
	public:
	```
	Specifies that the following methods and variables are accessible from outside the class.

4. **Constructor**
	```cpp
	FoodRatings(vector<string>& fd, vector<string>& cus, vector<int>& rat) {
	```
	Constructor to initialize the FoodRatings object with a list of food items, their corresponding cuisines, and ratings.

5. **Variable Initialization**
	```cpp
	    int n = fd.size();
	```
	Initializes the variable 'n' to store the number of food items.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates over each food item to populate the maps and data structures.

7. **Map Insert**
	```cpp
	        cus_itm[cus[i]].insert(pair(-rat[i], fd[i]));
	```
	Inserts each food item into the corresponding cuisine's set, ordered by rating in descending order.

8. **Map Insert**
	```cpp
	        fd_cus[fd[i]] = cus[i];
	```
	Maps each food item to its corresponding cuisine.

9. **Map Insert**
	```cpp
	        fd_rat[fd[i]] = rat[i];
	```
	Maps each food item to its rating.

10. **Function Definition**
	```cpp
	void changeRating(string fd, int rat) {
	```
	Defines a function to change the rating of a specified food item.

11. **Variable Initialization**
	```cpp
	    string cus = fd_cus[fd];
	```
	Retrieves the cuisine associated with the specified food item.

12. **Variable Initialization**
	```cpp
	    int r = fd_rat[fd];
	```
	Retrieves the current rating of the specified food item.

13. **Set Erase**
	```cpp
	    cus_itm[cus].erase({-r, fd});
	```
	Removes the old rating of the food item from the cuisine's set.

14. **Set Insert**
	```cpp
	    cus_itm[cus].insert({-rat, fd});
	```
	Inserts the updated rating of the food item into the cuisine's set.

15. **Map Update**
	```cpp
	    fd_rat[fd] = rat;
	```
	Updates the rating of the specified food item in the map.

16. **Function Definition**
	```cpp
	string highestRated(string cus) {
	```
	Defines a function to return the highest-rated food item for a given cuisine.

17. **Return Statement**
	```cpp
	    return begin(cus_itm[cus])->second;
	```
	Returns the highest-rated food item from the cuisine's set.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n) for each query when using an ordered map or set to store food items.
- **Average Case:** O(log n) per query, assuming efficient updates and lookups.
- **Worst Case:** O(log n) per query.

Both the changeRating and highestRated operations should run in O(log n) time if we use balanced trees or other efficient data structures.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) where n is the number of food items, as we need to store all food items, their cuisines, and their ratings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-a-food-rating-system/description/)

---
{{< youtube Ikp8SgbgbEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
