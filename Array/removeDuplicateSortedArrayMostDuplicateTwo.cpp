class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> ourmap;
        vector<int> arr;
         for(int i=0;i<nums.size();i++){
            if(ourmap[nums[i]]<2){
                 arr.push_back(nums[i]);
            }
             ourmap[nums[i]]+=1;
        }
        nums=arr;
        return arr.size();
  }
                      
};
