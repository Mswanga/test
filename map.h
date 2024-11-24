#ifndef MAP_H
#define MAP_H
#include<QPixmap>
class Map
{
public:
    Map();
    void mapposition();//地图坐标的计算
public:
    QPixmap map_1;
    QPixmap map_2;//记录两个图片
    int map_1_posY;//图片1y轴坐标
    int map_2_posY;//图片2y轴坐标
    int map_speed;//设置滚动的幅度
};

#endif // MAP_H
