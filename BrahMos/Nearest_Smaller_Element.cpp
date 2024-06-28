vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<pair<int,int>>st;
    int n =A.size();
    st.push({A[n-1],n-1});
    vector<int>ans(n);
    for(int i=n-2;i>=0;i--){
        
        while(st.empty()==false and st.top().first>A[i]){
            ans[st.top().second]=A[i];
            st.pop();
        }
        st.push({A[i],i});
    }
    while(st.empty()==false){
        ans[st.top().second]=-1;
        st.pop();
    }
    
    return ans;
}
