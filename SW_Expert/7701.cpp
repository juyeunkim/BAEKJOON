#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 문자열길이 비교 후 -> 사전형 정렬하는 함수
 */
bool comp (const string& a, const string& b){
    // 길이가 같을때는 문자열 사전형으로 비교
    if(a.size() == b.size()){
        return a < b;
    }
    // 길이가 더 긴 문자열 선택
    return a.size() < b.size();
}

int main(){
    // 수행시간 초과로 cin,cout 대신 scanf, printf사용
 
    /*
    cin.tie(NULL);
    ios::sync_with_stdio(false); 
    
    사용후 endl 대신에 '\n' 사용해도 같은 결과 나옴 !
    */
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        int n;
        scanf("%d", &n);
        vector<string> input;
        
        for(int i=0; i<n; i++){
            char s[50];
            scanf("%s", s);
            input.push_back(s);
        }
        
        // 같은 길이 정렬 + 중복제거
        sort(input.begin(), input.end(),comp);
        input.erase(unique(input.begin(), input.end()), input.end());
        
        printf("#%d\n", t);
        for(int i=0; i<input.size(); i++){
            printf("%s\n", input[i].c_str());
        }
    
        
        
    }
}

