/*
There is a country of n cities numbered from 0 to n - 1. In this country, there is a road connecting every pair of cities.

There are m friends numbered from 0 to m - 1 who are traveling through the country. Each one of them will take a path consisting of some cities. Each path is represented by an integer array that contains the visited cities in order. The path may contain a city more than once, but the same city will not be listed consecutively.

Given an integer n and a 2D integer array paths where paths[i] is an integer array representing the path of the ith friend, return the length of the longest common subpath that is shared by every friend's path, or 0 if there is no common subpath at all.

A subpath of a path is a contiguous sequence of cities within that path.
*/


// Ques: https://leetcode.com/problems/longest-common-subpath/
// Ref: https://leetcode.com/problems/longest-common-subpath/discuss/1319639/C%2B%2B-Easy-Solution-using-Rolling-Hash-with-Explanation

#define R (8417508174513LL)
#define X (165131LL)

#define MOD(x) ((x % R + R) % R)

class Solution
{
public:
    bool isValid(int L, vector<vector<int>> &paths)
    {
        long long hash = 1;
        for (int i = 0; i < L - 1; ++i)
            hash = MOD(hash * X); // calculates hash of first path of length L in paths[0]

        map<long long, int> mark;
        auto &p0 = paths[0];
        long long v = 0;
        for (int i = 0; i < p0.size(); ++i)
        {
            v = MOD(v * X + p0[i]); // calculates running hash
            if (i >= L - 1)
            {
                mark[v] = 1; // when L length subpath is found, hash it

                // here the value can be negative
                // that's why MOD is defined that way
                v = MOD(v - p0[i - L + 1] * hash); // subtract the previous part of hash to include the
                                                   // next part
            }
        }

        for (int p = 1; p < paths.size(); ++p)
        {
            v = 0;
            auto &pth = paths[p]; // traverse all paths to check if any of the hash value is present

            for (int i = 0; i < pth.size(); ++i)
            {
                v = MOD(v * X + pth[i]);
                if (i >= L - 1)
                {
                    if (mark.count(v) > 0 && mark[v] == p) // only the hash which is present in all
                    {                                      // previous paths is increased
                        mark[v] += 1;
                    }
                    v = MOD(v - pth[i - L + 1] * hash); // subtract the previous part of hash to include the
                                                        // next part
                }
            }
        }

        for (auto it : mark)
        {
            if (it.second == paths.size()) // a hash that is present in all paths
                return true;
        }
        return false;
    }

    static bool compare(vector<int> a, vector<int> b)
    {
        return (a.size() < b.size());
    }

    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
        int best = 0;

        // sort paths in increasing order of size
        sort(paths.begin(), paths.end(), compare);

        int l = 0, r = paths[0].size() + 1;
        while (r - l > 1)
        {
            int mid = (r + l) / 2; // choose a length for subpath in smallest length path
            if (isValid(mid, paths))
                l = mid; // m will be an ans, but we want the largest subpath
            else
                r = mid;
        }
        return l;
    }
};