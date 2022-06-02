class Solution {
public:
    #if 0
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;

        for (auto e : nums) {
            std::pair<std::set<int>::iterator,bool> ret;

            ret = s.insert(e);
            if (!ret.second)
                return true;
        }

        return false;
    }
    #endif

    #if 0
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        int i;

        i = 0;
        for (auto e : nums) {

            auto search = m.find(e);
            if (search != m.end())
                return true;

            m[e] = i++;
        }

        return false;
    }
    #endif
};
