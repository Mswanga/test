#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include<map.h>
#include<heroplane.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void initScene();//设置定时器
    void playGame();//启动游戏
    void updataPosition();//重置坐标
    void paintEvent(QPaintEvent *);//绘制到屏幕中，函数名称不可改
    void mouseMoveEvent(QMouseEvent *);//鼠标移动的事件
    Map m_map;//创建一个Map对象,用于记录地图的变化
    QTimer m_Time;//创建一个计时器事件
    HeroPlane m_Plane;
};
#endif // WIDGET_H
