#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include<bullet.h>
class HeroPlane
{
public:
    HeroPlane();
    void shoot();//子弹发射
    void setPosition(int x,int y);//设置飞机位置
public:
    //飞机的资源图片
    QPixmap m_Plane;
    //飞机坐标
    int m_X;
    int m_Y;
    QRect m_Rect;//飞机矩形边框
    Bullet m_bullets[BULLET_NUM];//弹匣
    int m_recorder;//发射间隔记录

};

#endif // HEROPLANE_H
