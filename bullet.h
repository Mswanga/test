#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>
#include"set.h"
class Bullet
{
public:
    Bullet();
    void updatePositionm();//更新子弹坐标
public:
    QPixmap m_Bullet;//子弹资源对象
    //子弹的坐标
    int m_X;
    int m_Y;
    //子弹的速度
    int m_Speed;
    //子弹是否闲置
    bool m_Free;
    //子弹的矩形边框
    QRect m_Rect;
};

#endif // BULLET_H
