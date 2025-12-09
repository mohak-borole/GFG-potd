class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_set<int>st;
        vector<int>ans;
        for(int &it:arr){
            if(st.find(it)==st.end()){
                st.insert(it);
            }else ans.push_back(it);
        }
        return ans;
    }
};