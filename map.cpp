#include "map.h"
#include "set.h"
Map::Map() {
    //初始化地图对象
    map_1.load(":/new/photo/new/back.jpeg");//设置图片1
    map_2.load(":/new/photo/new/back.jpeg");//设置图片2

    //初始化y轴坐标
    map_1_posY=-GAME_HEIGHT;
    map_2_posY=0;
    //设置地图的滚动速度
    map_speed=2;//2像素的滚动速度

}

void Map::mapposition()
{
    map_1_posY+=map_speed;//更新map_1的坐标
    if( map_1_posY>=0){//如果map_1的坐标大于等于0，说明map_1到了窗口中央
        map_1_posY=-GAME_HEIGHT;//重置到窗口下面
    }
    map_2_posY+=map_speed;//更新map_2的坐标
    if( map_2_posY>=GAME_HEIGHT){//如果map_2的坐标大于等于GAME_HEIGHT，说明map_2到了窗口上方
        map_2_posY=0;//重置到窗口中央
    }
}

