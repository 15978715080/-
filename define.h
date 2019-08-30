#ifndef DEFINE_H_
#define DEFINE_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <climits>
#include <algorithm>
#include "iostream"
#include "lib_io.h"
#include "Tools.h"
#include <fstream>

/********************************Car*************************/
struct Car{

    Car()
    {
        id = 0;
        from=0;
        to = 0;
        speed = 0;
        planTime = 0;
        priority = 0;
        preset = 0;
    }
    int id;             //id
    int from;           //始发地
    int to;             //目的地
    int speed;          //最大速度
    int planTime;       //开始时间
    int priority;
    int preset;
};
/*********************************Road************************/
struct Road {
    Road(){
        id =0;
        length=0;
        speed=0;
        channel=0;
        from=0;
        to=0;
        isDuplex=0;
    }
    int id;             //id
    int length;         //道路长度
    int speed;          //最高限速
    int channel;        //车道数目
    int from;           //起始点
    int to;             //终点
    int isDuplex;        //是否双向
    int Max_capacity;    //最大容量
    int  cars;            //当前时间片上面这条道路上的车数目
    double min_time;        //最短时间
    double Crowding_rate;   //每条道路的拥挤率
};
/*******************************Cross*************************/
struct Cross{
    Cross(){
        id=0;
        up_roadid=0;
        right_roadid=0;
        down_roadid=0;
        left_roadid=0;
    }
    int id;              //id
    int up_roadid;       //上道路id
    int right_roadid;    //右道路id
    int down_roadid;     //下道路id
    int left_roadid;     //左道路id
};

/***************************边的结构体*****************************/
struct EdgeData{
    EdgeData(){
        Dstart = 0;
        Dend = 0;
        weight =0;
    }
    int Dstart;   //边的起点
    int Dend;     //边的终点
    int weight;   //边的权重
};

struct PresetAnswer{
    PresetAnswer(){
        id=0;
        starttime=0;
        road.clear();
    }
    int id;
    int starttime;
    std::vector<int> road;
};


#endif