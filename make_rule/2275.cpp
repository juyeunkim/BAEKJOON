// 2775

#include <iostream>

using namespace std;

int main(){
    int t,k,n;
    cin>>t;// number of testcases
    int resident[14];// number of residents
    
    for(int j = 0;j<t;j++){
        //input floor and room number
        cin>>k>>n;
        
        // initialize resident's number
        for(int m=0;m<14;m++)
            resident[m] = m+1;
        
        int i = 0;
        while(k>0){
            if(i == 0) // #1 room is always 1 resident
                resident[i] = 1;
            else if(i==n){ // changes floor
                k--;
                i=-1;
            }
            else // current resident's number is sum of current and before resident's number
                resident[i] = resident[i-1] + resident[i];
            
            i++; // move next room
        }
        // print k's floor n's room number of resident
        cout<<resident[n-1]<<endl;
    }
    
    
    
    return 0;
}
