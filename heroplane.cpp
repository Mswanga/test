#include "heroplane.h"
#include "set.h"
HeroPlane::HeroPlane() {
    //设置我方飞机图片
    m_Plane.load(HERO_PATH);
    //初始化飞机坐标
    m_X=(GAME_WIDTH-m_Plane.width())*0.5;
    m_Y=GAME_HEIGHT-m_Plane.height();
    //设置矩形边框
    m_Rect.setWidth(m_Plane.width());//设置边框的宽度
    m_Rect.setHeight(m_Plane.height());//设置边框的宽度
    m_Rect.moveTo(m_X,m_Y);
}

void HeroPlane::shoot()
{
    m_recorder++;
    if(m_recorder<BULLET_INTERVAL){
        return;
    }
    m_recorder=0;
    //发射子弹
    for(int i=0;i<BULLET_NUM;i++){
        if(m_bullets[i].m_Free){
            m_bullets[i].m_Free=false;
            //设置子弹坐标
            m_bullets[i].m_X=m_X+m_Rect.width()*0.42;
            m_bullets[i].m_Y=m_Y+19;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;
    m_Rect.moveTo(m_X,m_Y);
}
