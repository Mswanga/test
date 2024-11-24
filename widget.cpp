#include "widget.h"
#include "set.h"
#include "map.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    this->setFixedSize(GAME_WIDTH, GAME_HEIGHT);//设置界面的长和宽
    this->setWindowTitle(GAME_TITLE);//设置标题

    this->setStyleSheet(":/new/photo/new/back.jpeg");//设置背景

    QIcon icon(":/new/photo/new/plane.png");//icon接受窗口的图标
    this->setWindowIcon(icon);//设置图标

    initScene();//设置定时器
    playGame();//启动定时器

}

Widget::~Widget() {}


//设置定时器的函数
void Widget::initScene()
{
    //定时器的设置
    m_Time.setInterval(10);//设置触发间隔，每十毫秒触发一次
}


//启动定时器的函数
void Widget::playGame()
{

    m_Time.start();//启动定时器
    connect(&m_Time,&QTimer::timeout,[=](){//当定时器超时，会自动调用lambda表达式
        updataPosition();//更新元素坐标
        update();//paintEvent函数被调用，请求更新窗口，刷新到屏幕
    });
}


//更新坐标函数
void Widget::updataPosition()
{
    m_map.mapposition();//调用重置函数
    m_Plane.shoot();
    for(int i=0;i<BULLET_NUM;i++){
        //如果非空闲，计算发射的位置
        if(m_Plane.m_bullets[i].m_Free==false){
            m_Plane.m_bullets[i].updatePositionm();
  }
    }
}


//重绘图像函数
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,m_map.map_1_posY,m_map.map_1);//调用QPainter的drawPixmap方法重绘map_1
    //绘 m_map.map_2
    painter.drawPixmap(0,m_map.map_2_posY,m_map.map_2);//调用QPainter的drawPixmap方法重绘map_2
    //绘飞机
    painter.drawPixmap(m_Plane.m_X,m_Plane.m_Y,m_Plane.m_Plane);


            for(int i=0;i<BULLET_NUM;i++){
                if(m_Plane.m_bullets[i].m_Free==false){
                    painter.drawPixmap(m_Plane.m_bullets[i].m_X,m_Plane.m_bullets[i].m_Y,m_Plane.m_bullets[i].m_Bullet);

            }
}

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->x()-m_Plane.m_Rect.width()*0.5;
    int y=event->y()-m_Plane.m_Rect.height()*0.5;
    m_Plane.setPosition(x,y);
}
