#include<bits/stdc++.h>
using  namespace std;

int main(){
 int n=0;
 cin >> n;
 
 set<string> st;
 vector<string> str;
 
 string a;
 for(int i=0;i<n;i++){
 	 cin >> a;
	 st.insert(a);
	 str.push_back(a);
 }
 
 int ans=0;
 for(int i=0;i<n;i++){
 	int l = str[i].lengh();
	int g = l/2;
	 if(l%2 == 1){
	 	if(str[i].substr(0,g) == str[i].substr(g+1,g)){
		 	for(int j =1;j<=(l+1)/2;j++){
		 	    string r = str[i].substr(g-j,2*j-1);
			    if(st.count(r)) ans++;
		    }
		 }
	 }
 }
}