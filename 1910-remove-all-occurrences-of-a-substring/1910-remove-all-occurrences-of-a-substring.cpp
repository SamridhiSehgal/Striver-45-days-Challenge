class Solution {
public:
    string removeOccurrences(string s, string part) {
        int found = s.find(part);
        if(found==string::npos)
        {return s;}
            string left=s.substr(0,found);
            string right=s.substr(found+part.size());
            s=left+right;
        
        return removeOccurrences(s,part);
        
        
    }
};