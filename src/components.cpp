#include "headers/components.h"

#include <QTimer>
#include <QGraphicsScene>

CCanon::CCanon(EColor eColor, QGraphicsItem *pParent) : QGraphicsPixmapItem(pParent)
{
    setColor(eColor);
}

void CCanon::shoot()
{
    CBullet *pBullet = new CBullet(m_eColor);

    connect(pBullet, &CBullet::sigIncreaseScore, this, &CCanon::sigIncreaseScore);
    connect(pBullet, &CBullet::sigDecreaseScore, this, &CCanon::sigDecreaseScore);

    pBullet->setPos(x() + 27, y() - 10);
    scene()->addItem(pBullet);
}

EColor CCanon::getColor() const
{
    return m_eColor;
}

void CCanon::setColor(EColor eColor)
{
    m_eColor = eColor;

    switch (eColor) {
    case EColor::Red:
    {
        QPixmap oPixmap(":/Resources/RedCannon.png");
        setPixmap(oPixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Pink:
    {
        QPixmap oPixmap(":/Resources/PinkCannon.png");
        setPixmap(oPixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Blue:
    {
        QPixmap oPixmap(":/Resources/BlueCannon.png");
        setPixmap(oPixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    default:
        QPixmap oPixmap(":/Resources/RedCannon.png");
        setPixmap(oPixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
}

CAlien::CAlien(EColor eColor, QGraphicsItem *pParent)
{

}

EColor CAlien::getColor() const
{

}

void CAlien::setColor(EColor eColor)
{

}

void CAlien::onMove()
{

}
