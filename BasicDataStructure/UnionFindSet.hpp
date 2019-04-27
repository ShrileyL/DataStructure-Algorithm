//
//  UnionFindSet.hpp
//  leetcode_structure
//
//  Created by Shulin on 2019/4/27.
//  Copyright © 2019 Shulin. All rights reserved.
//

#ifndef UnionFindSet_h
#define UnionFindSet_h
#include <vector>
class UnionFindSet
{
public:
    UnionFindSet(int n)
    {
        _parents = std::vector<int>(n+1,0);
        _ranks = std::vector<int>(n+1,0);
        
        for(int i = 0; i < _parents.size(); i++)
            _parents[i] = i;
    }
    
    //Merge set contains u and v
    //return true if merge seccuessful, false if u and v already in one set
    bool Union(int u, int v)
    {
        int pu = Find(u);
        int pv = Find(v);
        
        if(pu == pv)
            return false;
        
        if(_ranks[pu] < _ranks[pv])
            _parents[pu] = pv;
        else if(_ranks[pu] > _ranks[pv])
            _parents[pv] = pu;
        else
        {
            _parents[pu] = pv;
            _ranks[pv] += 1;
        }
        return true;
    }
    
    //Get the root of u
    int Find(int u)
    {
        //compress the path during traversal
        if(u != _parents[u])
            _parents[u] = Find(_parents[u]);
        return _parents[u];
    }
private:
    std::vector<int> _parents;
    std::vector<int> _ranks;
};

#endif /* UnionFindSet_h */
