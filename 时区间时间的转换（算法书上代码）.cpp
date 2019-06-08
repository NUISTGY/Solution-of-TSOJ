#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;

int difference(char* zone1,char* zone2){//计算两个时区之间的时差，以分钟为单位
    char*zone[32]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
    float time[32]={0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};
    int i,j;
    for(i=0;strcmp(zone[i],zone1);i++);//找到第一个时区对应的位置
    for(j=0;strcmp(zone[j],zone2);j++);//找到第二个时区对应的位置
    return (int)((time[i]-time[j])*60);//计算并返回时差，以分钟为单位
}
int main(){
    int nCases;
    cin>>nCases;                    //读入测试数据数目
    for(int i=0;i<nCases;i++){      //对每组输入数据
        char time[9];               //输入的时间
        int hours,minutes;          //转换成整数
        cin>>time;                  //读入时间
        switch(time[0]){
            case 'n':hours=12;      //输入为“noon”
                minutes=0;
                break;
            case 'm':hours=0;       //输入为“midnight”
                minutes=0;
                break;
            default:sscanf(time,"%d:%d", &hours,&minutes);//输入为 时:分
                hours%=12;
                cin>>time;          //读入为“a.m.”或“p.m.”
                if(time[0]=='p')hours+=12;
        }
        char timezone1[5],timezone2[5];
        cin>>timezone1>>timezone2;  //读入时区
        int newTime;                //以分钟为单位
        newTime=hours*60+minutes+difference(timezone2, timezone1);
        if(newTime<0)newTime+=1440; //提前一天，将负的时间加上一天
        newTime%=1440;              //如果超过一天，将一天的时间减去
        switch (newTime) {
            case 0:
                cout<<"midnight"<<endl; //新时间为凌晨
                break;
            case 720:
                cout<<"noon"<<endl;     //新时间为中午
                break;
            default:
                hours=newTime/60;       //新时间的时
                minutes=newTime%60;     //新时间的分
                if(hours==0)            //凌晨，分不为0
                    printf("12:%02d a.m.\n",minutes);
                else if(hours<12)       //上午
                    printf("%d:%02d a.m.\n",hours,minutes);
                else if(hours==12)      //中午，分不为0
                    printf("12:%02d p.m.\n",minutes);
                else                    //下午
                    printf("%d:%02d p.m.\n",hours%12,minutes);
        }//end of switch
    }//end of for
}//end of main
