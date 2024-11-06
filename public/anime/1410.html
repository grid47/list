class Solution {
public:
    string entityParser(string text) {
        
        map<string, string> mp;
        mp["&quot;"] = "\"";
        mp["&apos;"] = "\'";
        mp["&amp;"] = "&";
        mp["&gt;"] = ">";
        mp["&lt;"] = "<";
        mp["&frasl;"] = "/";
        
        string res = "";        
        int i = 0;
        while(i < text.size()) {
            if(text[i] == '&') {
                string tmp = "";
                while(i < text.size() && text[i] != ';'){
                    tmp += text[i++];
                    if(i < text.size() && text[i] == '&') {
                        res += tmp;
                        tmp = "";
                    }
                } 
                if(text[i] == ';') {
                    i++;
                    tmp += ';';
                    if(mp.count(tmp)) {
                        res += mp[tmp];
                    } else {
                        res += tmp;
                    }
                } else {
                    res += tmp;
                }
            } else {
                res += text[i++];
            }
        }
        return res;
    }
};