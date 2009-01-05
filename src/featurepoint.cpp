#include <QPainter>

#include "featurepoint.h"

FeaturePoint::FeaturePoint()
 :  innerRadius(3.5), outerRadius(10.5),
    color(Qt::red)
{
}


FeaturePoint::~FeaturePoint()
{
}


/*!
    \fn featurePoint::boundingRect() const
 */
QRectF FeaturePoint::boundingRect() const
{
    qreal adjust = 0.5;

    return QRectF( QPointF(-outerRadius-adjust, -outerRadius-adjust), 
                    QPointF(outerRadius+adjust, outerRadius+adjust));
}


/*!
    \fn featurePoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
 */
void FeaturePoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(color);

    // draw 'X' strokes
    painter->drawLine(  QPointF(-outerRadius, -outerRadius),
                        QPointF(-innerRadius, -innerRadius));
    painter->drawLine(  QPointF(innerRadius, innerRadius),
                         QPointF(outerRadius, outerRadius));
    painter->drawLine(  QPointF(-outerRadius, outerRadius), 
                        QPointF(-innerRadius, innerRadius));
    painter->drawLine(  QPointF(outerRadius, -outerRadius), 
                        QPointF(innerRadius, -innerRadius));
    
    // draw inner circle
    painter->drawEllipse(QRectF(QPointF(-innerRadius, -innerRadius), 
                                QPointF(innerRadius, innerRadius)));

}


