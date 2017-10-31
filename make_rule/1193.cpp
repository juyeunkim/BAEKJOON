//
//  1193.cpp
//  temp
//
//  Created by 김주연 on 2017. 10. 31..
//  Copyright © 2017년 김주연. All rights reserved.
//

#include <iostream>

/*
분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과
 같은 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
 
 X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
 */
using namespace std;

int main(){
    int n,i = 1,temp;
    int a,b;
    cin>>n;
    
    while(1){
        temp = i*(i+1)/2;
        if(n<=temp)
            break;
        else
            i++;
    }
    
    a=1; b=i;
    
    int j= i-temp+n;
    
    a= a +j-1;
    b= b -(j-1);
    
    if(i%2!=0)
    {
        int t = a;
        a=b;
        b=t;
    }
    
    cout<<a<<"/"<<b<<endl;
    
    return 0;
}

