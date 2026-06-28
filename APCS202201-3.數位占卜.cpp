#include<bits/stdc++.h>
using  namespace std;

int main(){
 int n=0;
 cin >> n;

 set<string> st;
 set<pair<string,string>> ans;
 vector<string> str;


 string a;
 for(int i=0;i<n;i++){
 	 cin >> a;
	 st.insert(a);
	 str.push_back(a);
 }

 for(int i=0;i<n;i++){
 	int l = str[i].length();
	int g = l/2;
	if(l >= 3){
       if(l%2 == 1){
            for(int j =1;j<=(l+1)/2;j++){

                int d = g-j+1;
                if(str[i].substr(0,d) == str[i].substr(g+j,d)){
                    string r = str[i].substr(d,2*j-1);
                    if(st.count(r)&&r!=str[i]){
                        string w = str[i];
                        if(r < w){
                            swap(r,w);
                        }
                        if(!ans.count({r,w})){
                            ans.insert({r,w});
                        }
                    }
                }
            }
        }else{
            for(int j=1;j<=l/2;j++){
                int d = g-j;
                if(str[i].substr(0,d) == str[i].substr(g+j,d)){
                    string r = str[i].substr(d,2*j);
                    if(st.count(r)&&r!=str[i]){
                        string w = str[i];
                        if(r < w){
                            swap(r,w);
                        }
                        if(!ans.count({r,w})){
                            ans.insert({r,w});
                        }
                    }
                }
            }
        }
	}
 }

 cout << ans.size();
}
