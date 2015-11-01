#include <stdio.h>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       if(nums.size()<=1)return false;
        map <int,int> myMap;
        map<int,int>::iterator it;
        myMap.insert(pair<int,int>(nums[0],0));
        for (int i = 1;i<nums.size();i++){
            if (i>k)
                myMap.erase(nums[i-k-1]);
            it = myMap.find(nums[i]);
            if (it!=myMap.end()){
                return true;
            }else{
                myMap.insert(pair<int,int>(nums[i],i));
            }
        }
        return false;
    }
};
