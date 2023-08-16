#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int> v(n);
	    priority_queue<int> pq;
	    
	    for(int i=0 ; i<n ; ++i) cin>>v[i];
	    
	    int pos = n - 1;
	    
	    for(int i=n-1 ; i>=0 ; --i){
	        if(pq.size() <=  k) pq.push(v[i]);
	        else{
	            v[pos--] = pq.top();
	            pq.pop();
	            
	            pq.push(v[i]);
	        }
	    }
	    
	    while(!pq.empty()){
	        v[pos--] = pq.top();
	        pq.pop();
	    }
	    
	    for(int i=0 ; i<n ; ++i) cout<<v[i]<<" ";
	    cout<<endl;
	    
	    
	}
	
	return 0;
}