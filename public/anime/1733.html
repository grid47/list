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