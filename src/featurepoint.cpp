#include <QtGui>

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
    qreal adjust = 2;

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




/*!
    \fn FeaturePoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
 */
void FeaturePoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) {
        event->ignore();
        return;
    }

    setCursor(Qt::CrossCursor);
}


/*!
    \fn FeaturePoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 */
void FeaturePoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    setPos(event->scenePos());

}


/*!
    \fn FeaturePoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
 */
void FeaturePoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
}
