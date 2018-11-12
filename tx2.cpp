#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
return a>b?true:false;}
int main(){
    int n;cin>>n;
    vector<int>post;
    int t;
    
    for(int i=0;i<n;i++){
        cin>>t;
        post.push_back(t);}
    sort(post.begin(),post.end(),cmp);
    post.push_back(0);
    int sum=0;
    for(int i=0;i<post.size()-1;i+=2){
        sum+=(post[i]-post[i+1]);
    }
    cout<<sum;
}
