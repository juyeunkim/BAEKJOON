#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string s;
    char ans;
    int cnt=1,max=0,len=1;
    vector<int> count;
    cin>>s;
    
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    sort(s.begin(),s.end());
    
    //cout<<s<<endl;
    //tmp = s[0];
    for(int i=0; i<s.size(); i++){
        if(i==s.size()-1) count.push_back(cnt);
        else if(s[i]==s[i+1]) cnt++;
        else{
            count.push_back(cnt); cnt =1;
        }
    }
    //cout<<count[0]<<" "<<count[1]<<endl;
    for(int i=0; i<count.size(); i++){
        if(count[i]>max) {ans = s[len-1]; max = count[i];}
        else if(count[i]==max) ans = '?';
        
        len += count[i];
    }
    
    cout<<ans;
    
    return 0;
}
