//
//  1924.cpp
//  temp
//
//  Created by 김주연 on 2017. 10. 31..
//  Copyright © 2017년 김주연. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/*
 오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까?
 첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.
 */
int main(){
    int x,y,d=0;
    
    cin>>x>>y;
    if((x<1 || x>12) || (y<1 || y>31)) return -1;
    
    string week[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    
    d+= y;
    if(x!=1)
        d+=31;
    
    for(int i=2;i<x;i++){
        if(i==4 || i==6 || i==9 || i==11)
            d+=30;
        else if(i==2)
            d+=28;
        else
            d+=31;
    }
    
    d = d % 7;
    cout<<week[d]<<endl;
    
    return 0;
}

