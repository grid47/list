
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
+++



---
**Code:**

{{< highlight cpp >}}
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

};
{{< /highlight >}}
---

### Problem Statement

The problem is about determining the minimum number of languages that need to be taught to ensure that all pairs of friends can communicate with each other. Given a number of languages, an array of languages known by each person, and an array of friendships, the goal is to identify how many languages need to be taught to eliminate any communication barriers among friends.

### Approach

To solve this problem, we can break it down into several key steps:

1. **Data Structure Initialization**: We will use a vector of sets to store the languages known by each individual. This will allow us to efficiently check for common languages between friends.

2. **Identify Friend Pairs Without Common Languages**: For each pair of friends, we will check if they share any languages. If they do not share a language, we will keep track of those individuals who need to learn new languages.

3. **Count Language Requirements**: For the individuals who need to learn languages, we will count how many people know each language and identify the language that the maximum number of those individuals already know. This helps us minimize the total number of teachings required.

4. **Calculate Minimum Teachings**: Finally, we will compute the minimum number of new languages that need to be taught by subtracting the maximum count of a known language from the number of individuals who need to learn languages.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

1. **Class Definition**: The solution is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   ```

2. **Public Method**: The method `minimumTeachings` takes in the number of languages `k`, a vector of vectors representing the languages known by individuals `lang`, and a vector of friend pairs `frnd`.

   ```cpp
   public:
       int minimumTeachings(int k, vector<vector<int>>& lang, vector<vector<int>>& frnd) {
   ```

3. **Initialization**: We determine the number of individuals and create a vector of sets to hold the languages each person knows.

   ```cpp
   int n = lang.size();
   vector<set<int>> langs;
   ```

4. **Populate Language Sets**: We iterate through each individual and convert their language array into a set for easier intersection operations later.

   ```cpp
   for(int i = 0; i < n; i++) {
       set<int> s(begin(lang[i]), end(lang[i]));
       langs.push_back(s);
   }
   ```

5. **Identify Non-Communicating Friend Pairs**: We create a set to track individuals who need to learn new languages. For each friendship pair, we check if they share any languages using set intersection. If they don’t share a language, we add them to the `ntk` (need to know) set.

   ```cpp
   set<int> ntk;
   for(vector<int> frd: frnd) {
       int u = frd[0] - 1; // Friend index adjustment
       int v = frd[1] - 1; // Friend index adjustment
       set<int> s1 = langs[u];
       set<int> s2 = langs[v];                
       set<int> res;
       set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
       if (res.size() > 0) continue; // They can communicate
       ntk.insert(u); // They need to learn languages
       ntk.insert(v);
   }
   ```

6. **Early Exit**: If no individuals need to learn new languages (`ntk` is empty), return 0, indicating no teachings are necessary.

   ```cpp
   if (ntk.size() == 0) return 0;
   ```

7. **Count Language Knowledge**: We create a vector to count how many people know each language among those who need to learn. We then iterate through each individual in `ntk`, updating our counts based on the languages they know.

   ```cpp
   vector<int> lg(k + 1, 0); // Language count
   for (int f : ntk) // Count languages known by those in ntk
       for (int l : langs[f]) lg[l]++;
   ```

8. **Determine Maximum Known Language**: We find the language that is known by the maximum number of individuals in `ntk`.

   ```cpp
   int mx = lg[0];
   for (int c : lg) {
       mx = max(mx, c);
   }
   ```

9. **Calculate Minimum Teachings**: Finally, the minimum teachings required will be the number of individuals in `ntk` minus the maximum number of individuals that already know a language.

   ```cpp
   return ntk.size() - mx;
   }
   ```

### Complexity

- **Time Complexity**: The overall time complexity is \(O(n + m \cdot k)\), where \(n\) is the number of individuals, \(m\) is the number of friendships, and \(k\) is the maximum number of languages. This accounts for iterating through the friends and the languages known by individuals.

- **Space Complexity**: The space complexity is \(O(n + k)\), where \(n\) is the number of individuals for the sets of languages and \(k\) for the language count vector.

### Conclusion

This solution efficiently determines the minimum number of new languages that need to be taught to ensure all pairs of friends can communicate. By employing sets for language representation and counting known languages among those who need to learn, we minimize the teachings required. The approach effectively handles the problem with clear logic and efficient data structures, making it well-suited for situations involving language learning and communication barriers. The implementation is robust and can be extended or modified to adapt to variations of the problem, such as varying friendship structures or additional constraints on language learning.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-people-to-teach/description/)

---
{{< youtube eHk8TQIhvCk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
