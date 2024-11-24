#include "bullet.h"

Bullet::Bullet() {
    //加载子弹的资源
    m_Bullet.load(BULLET_PATH);
    //子弹的坐标
    m_X=GAME_WIDTH*0.5-m_Bullet.width()*0.5;
    m_Y=GAME_HEIGHT;
    m_Free=true;//默认空闲
    m_Speed=BULLET_SPEED;
    //子弹的边框
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePositionm()
{
    if(m_Free){
        return;
    }
    m_Y-=m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    //子弹的位置超出了边框，变为空闲状态
    if(m_Y<=-m_Rect.height()){
        m_Free=true;
    }
}
