//
//  main.cpp
//  temp
//
//  Created by 김주연 on 2017. 10. 31..
//  Copyright © 2017년 김주연. All rights reserved.
//


/*
 숫자 N이 주어졌을 때,
 벌집의 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때
 몇 개의 방을 지나가는지(시작과 끝을 포함하여)를 계산하는 프로그램을 작성하시오.
 */
#include <iostream>

using namespace std;

int main(){
    int n,r = 1;
    cin>>n;
    
    while(1){
        int temp = 3*r*(r-1)+1;
        
        if(n<=temp)
            break;
        else
            r++;
    }
    
    cout<<r<<endl;
    
    return 0;
}

