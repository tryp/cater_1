#ifndef FEATUREPOINT_H
#define FEATUREPOINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QRectF>

/**
	@author Chris Douglass <cdouglass@gmail.com>
*/
class FeaturePoint : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    FeaturePoint();

    ~FeaturePoint();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

protected:
private:
    double innerRadius;
    double outerRadius;
    QColor color;
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif
