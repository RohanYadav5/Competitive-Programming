class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,int> v;
        for(int i=0;i<s.length();i++){
            if(v[s[i]]>0){
                v[s[i]]+=1;
                continue;
            }
            v[s[i]]=1;            
        }
        for(int i=0;i<t.size();i++){
            if(v[t[i]]<=0){
                return false;
                break;
            }
            v[t[i]]-=1;            
        }
        return true;
    }
};
