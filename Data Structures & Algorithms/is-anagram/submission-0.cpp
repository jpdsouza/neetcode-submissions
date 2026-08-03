class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        map<char, int> sMap, tMap;
        for(int i=0; i< s.length(); i++)
        {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }
        for(auto &it : sMap)
        {
            if(it.second != tMap[it.first])
                return false;
        }
        return true;
    }
};
