
+++
authors = ["grid47"]
title = "Leetcode 1733: Minimum Number of People to Teach"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1733: Minimum Number of People to Teach in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eHk8TQIhvCk"
youtube_upload_date="2021-03-22"
youtube_thumbnail="https://i.ytimg.com/vi/eHk8TQIhvCk/maxresdefault.jpg"
comments = true
+++



---
In a social network consisting of multiple users and their friendships, users can communicate with each other only if they share a common language. You are given a list of languages each user knows and a list of friendships between users. Your task is to teach a single language to some users such that all the users in each friendship can communicate. The goal is to minimize the number of users you need to teach the new language.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays:
1. `languages`: A list of lists, where each inner list represents the languages known by a particular user. `languages[i]` contains the languages known by the i-th user.
2. `friendships`: A list of pairs, where each pair represents a friendship between two users. Friendship `[u, v]` indicates that user `u` and user `v` are friends.
- **Example:** `Input: n = 3, languages = [[1, 2], [2, 3], [1, 3], [2]], friendships = [[1, 2], [1, 3], [2, 3]]`
- **Constraints:**
	- 2 <= n <= 500
	- languages.length == m
	- 1 <= m <= 500
	- 1 <= languages[i].length <= n
	- 1 <= u_i < v_i <= languages.length
	- 1 <= friendships.length <= 500
	- languages[i] contains only unique values

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of users who need to be taught a new language so that all users in each friendship can communicate.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is an integer representing the minimum number of users to teach a new language.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the minimal set of users who need to be taught a new language so that all users in each friendship can communicate, considering the languages they already know.

- 1. Create a set for each user containing the languages they know.
- 2. For each friendship, check if there is a common language between the two users. If not, mark both users as needing to learn a new language.
- 3. Find the language that is most frequently spoken by the users who need to learn a new language and teach that language to the fewest number of users.
- 4. Return the total number of users who need to be taught a language.
{{< dots >}}
### Problem Assumptions ✅
- Each user is a node, and each friendship is an edge in an undirected graph.
- Languages known by users are represented as sets of integers, ensuring no duplicate languages within a user's knowledge.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3, languages = [[1, 2], [2, 3], [1, 3], [2]], friendships = [[1, 2], [1, 3], [2, 3]]`  \
  **Explanation:** In this case, users 1, 2, and 3 each have some overlapping language knowledge, but user 3 does not share any common language with user 1. Teaching user 1 a new language (language 3) would allow all users to communicate.

- **Input:** `Input: n = 2, languages = [[1], [2], [1, 2]], friendships = [[1, 2], [1, 3], [2, 3]]`  \
  **Explanation:** In this case, user 1 knows only language 1, user 2 knows only language 2, and user 3 knows both languages. Teaching user 1 language 2 or user 2 language 1 will ensure that all users can communicate.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we need to consider the friendship relationships and the languages known by each user. The strategy involves finding which users need a language taught to them and selecting the language that minimizes the total number of users to teach.

### Initial Thoughts 💭
- We need to minimize the number of users who need to be taught a new language while ensuring all users in each friendship can communicate.
- We can treat this problem as a graph where each user is a node and each friendship is an edge. We want to ensure there is a common language between all nodes in each connected component.
{{< dots >}}
### Edge Cases 🌐
- An empty input case should not exist due to constraints (m ≥ 1).
- The solution should be efficient enough to handle the largest cases where n, m, and the number of friendships are all near their upper bounds.
- Some users may already be able to communicate with all of their friends.
- Handle cases where multiple users need to be taught a language.
{{< dots >}}
## Code 💻
```cpp
class Solution {

public:

int minimumTeachings(int k, vector<vector<int>>& lang, vector<vector<int>>& frnd) {
    
			int n = lang.size();

			vector<set<int>> langs;

			for(int i = 0; i < n; i++) {
				set<int> s(begin(lang[i]), end(lang[i]));
				langs.push_back(s);
			}

			set<int> ntk;
			for(vector<int> frd: frnd) {
				int u = frd[0] - 1;
				int v = frd[1] - 1;
				set<int> s1 = langs[u];
				set<int> s2 = langs[v];				
				set<int> res;
				set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
				if (res.size() > 0) continue;
				ntk.insert(u);
				ntk.insert(v);
			}
        if (ntk.size() == 0) return 0;
    
        vector<int> lg(k + 1, 0);
			for (int f : ntk)
        for (int l : langs[f]) lg[l]++;
    
        int mx = lg[0];
        for (int c : lg) {
            mx = max(mx, c);
        }
    
			return ntk.size() - mx;
}

```

This solution finds the minimum number of languages a person needs to learn such that all pairs of friends can communicate. The algorithm ensures that friends with no common language are considered for language teaching.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	The class `Solution` is declared. This class will contain the method `minimumTeachings` to solve the problem.

2. **Public Section**
	```cpp
	public:
	```
	This marks the beginning of the public section in the class, where methods that can be accessed from outside the class will be defined.

3. **Function Definition**
	```cpp
	int minimumTeachings(int k, vector<vector<int>>& lang, vector<vector<int>>& frnd) {
	```
	The function `minimumTeachings` is defined. It takes three parameters: `k` (the number of languages), `lang` (a vector of vectors where each inner vector represents the languages spoken by a person), and `frnd` (a vector of pairs representing friendships).

4. **Variable Initialization**
	```cpp
	    int n = lang.size();
	```
	The variable `n` is initialized to the size of `lang`, which represents the total number of people.

5. **Vector Initialization**
	```cpp
	    vector<set<int>> langs;
	```
	A vector of sets `langs` is declared. Each set will hold the languages spoken by a person, making it easier to check common languages.

6. **Populating Language Sets**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to iterate over each person in the `lang` array.

7. **Set Creation**
	```cpp
	        set<int> s(begin(lang[i]), end(lang[i]));
	```
	For each person `i`, a set `s` is created containing the languages they speak.

8. **Adding to Vector**
	```cpp
	        langs.push_back(s);
	```
	The set `s` containing the languages of person `i` is added to the `langs` vector.

9. **Set Initialization**
	```cpp
	    set<int> ntk;
	```
	A set `ntk` is declared. This set will keep track of the people who need to learn a new language.

10. **Friendship Loop**
	```cpp
	    for(vector<int> frd: frnd) {
	```
	A loop is started to iterate over each friendship in the `frnd` array.

11. **Friendship Processing**
	```cpp
	        int u = frd[0] - 1;
	```
	The first person `u` in the friendship pair `frd` is adjusted for zero-based indexing.

12. **Friendship Processing**
	```cpp
	        int v = frd[1] - 1;
	```
	The second person `v` in the friendship pair `frd` is adjusted for zero-based indexing.

13. **Set Initialization**
	```cpp
	        set<int> s1 = langs[u];
	```
	The set `s1` is initialized with the languages spoken by person `u`.

14. **Set Initialization**
	```cpp
	        set<int> s2 = langs[v];
	```
	The set `s2` is initialized with the languages spoken by person `v`.

15. **Set Intersection**
	```cpp
	        set<int> res;
	```
	A set `res` is declared to store the common languages between persons `u` and `v`.

16. **Intersection Operation**
	```cpp
	        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
	```
	The `set_intersection` function is used to find common languages between `s1` and `s2` and store them in `res`.

17. **Check for Common Languages**
	```cpp
	        if (res.size() > 0) continue;
	```
	If there are common languages (i.e., `res.size() > 0`), the friendship pair does not need any additional teaching, so the loop moves to the next pair.

18. **Track People to Teach**
	```cpp
	        ntk.insert(u);
	```
	If no common languages exist, both people in the friendship pair are added to the `ntk` set.

19. **Track People to Teach**
	```cpp
	        ntk.insert(v);
	```
	Both people in the friendship pair are added to the `ntk` set.

20. **No Need for Teaching**
	```cpp
	    if (ntk.size() == 0) return 0;
	```
	If no people need to learn a new language (i.e., `ntk` is empty), the function returns `0`.

21. **Language Frequency Initialization**
	```cpp
	        vector<int> lg(k + 1, 0);
	```
	A vector `lg` of size `k+1` is initialized to store the frequency of each language spoken by the people in `ntk`.

22. **Count Languages for Each Person**
	```cpp
	        for (int f : ntk)
	```
	A loop is started to iterate over the set `ntk` to count the languages spoken by the people who need to learn a new language.

23. **Language Count Update**
	```cpp
	        for (int l : langs[f]) lg[l]++;
	```
	For each person `f` in `ntk`, the languages they speak are counted in the `lg` vector.

24. **Max Frequency Calculation**
	```cpp
	        int mx = lg[0];
	```
	The variable `mx` is initialized with the frequency of the first language.

25. **Max Frequency Calculation**
	```cpp
	        for (int c : lg) {
	```
	A loop is started to calculate the maximum frequency of any language in the `lg` vector.

26. **Max Frequency Update**
	```cpp
	            mx = max(mx, c);
	```
	The variable `mx` is updated to the maximum frequency found in the `lg` vector.

27. **Return Result**
	```cpp
	        return ntk.size() - mx;
	```
	The function returns the number of people in `ntk` minus the maximum frequency of any language spoken by them.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of users and n is the number of languages.
- **Average Case:** O(m * n), since we may need to check each user's languages in the worst case.
- **Worst Case:** O(m * n), as we need to evaluate each friendship and language scenario.

The time complexity is driven by the need to check all friendships and languages.

### Space Complexity 💾
- **Best Case:** O(m), since the space required to store users and their languages depends on the number of users.
- **Worst Case:** O(m * n), where m is the number of users and n is the number of languages.

The space complexity depends on the number of users and languages stored for each user.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-people-to-teach/description/)

---
{{< youtube eHk8TQIhvCk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
