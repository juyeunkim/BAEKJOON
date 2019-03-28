#include <iostream>
using namespace std;

int arr[6];
bool visited[100][1000000];
int cnt, len, ans =0, num;

void swap(int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void dfs(int depth){
    if(depth == cnt) {
        //cout<<"dfs "<<num<<endl;
        if(ans < num) ans = num;
        return;
        
    }
    
    for(int i=0; i<len ; i++){
        for(int j=i+1; j<len; j++){
            if(arr[j] < arr[i]) continue;
            
            num =0;
            swap(i,j);
            
            for(int k=0; k<len; k++){
                num = num*10 + arr[k];
            }
            
            //cout<<i<<" "<<j<<" "<<num<<" "<<depth<<endl;
            
            
            if(!visited[depth][num]) {visited[depth][num] = true; dfs(depth+1);}
            
            swap(i,j);
            
        }
    }
    
}
int main(){
    int n;
    cin>>n;
    string input;
    for(int t = 1; t<=n; t++){
        
        cin>>input>>cnt;
        len = input.size();
        
        ans = 0;
        
        for(int i=0; i<len; i++)
            arr[i] = input[i]-'0';
        
        dfs(0);
        
        
        cout<<"#"<<t<<" "<<ans<<endl;;
    }
    return 0;
}
