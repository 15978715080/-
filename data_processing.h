#ifndef DATA_PROCESSING_H_
#define DATA_PROCESSING_H_

#include "define.h"
#include "Graph.h"
class AdjMatrix;

class DataProcess{
public:

    DataProcess();
    ~DataProcess();

    void readcardata(std::vector<std::string> data);
    void readroaddata(std::vector<std::string> data);
    void readcrossdata(std::vector<std::string> data);
    void readpresentAnswerdata(std::vector<std::string> data);
    void Updataroad_car(std::vector<int> from_to_cross, AdjMatrix &AM);   //更新每条道路上的车
    void Clearroad_car();                                        //清除每条道路上的车
    void UpdataCrowding_rate();                                  //更新拥堵率
    double countCrowd();                                            //统计拥堵率

    std::vector<Car> Sortcar( std::vector<Car> &carList, int flag );  //按照car.plantime进行排序 0:代表升序  1：代表降序
    std::map<int, Road> get_roadList();
    std::vector<Cross> get_crossList();
    std::vector<Car> get_carList();
    int get_road_cap();

    std::vector<std::string> readdata(std::string filename);


private:
    //input
//    char **inputCar;
    int  input_car_num;

//    char **inputCross;
    int  input_cross_num;

//    char **inputRoad;
    int  input_road_num;

    int road_total_cap;

    //汽车属性
    std::vector<Car> carList;
    //道路属性
    std::map<int,Road> roadList;
    //节点属性
    std::vector<Cross> crossList;

    std::vector<PresetAnswer> presetanswerList;
};

extern bool lessmark(const Car&   s1, const  Car&   s2);  //升序
extern bool greatermark( const Car&   s1,  const Car&   s2);  //降序

#endif

