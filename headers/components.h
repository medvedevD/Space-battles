#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "settings.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsItem>
#include <QKeyEvent>

enum class EColor
{
    Red, Pink, Blue
};

class CBullet;

class CCanon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CCanon(EColor eColor, QGraphicsItem *pParent = nullptr);

    void shoot();

    EColor getColor() const;
    void setColor(EColor eColor);

signals:
    void sigIncreaseScore();
    void sigDecreaseScore();

private:
    EColor m_eColor;

    ~CCanon();
};

///--------------------------///

class CAlien : public QObject, QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CAlien(EColor eColor, QGraphicsItem *pParent = nullptr);

    EColor getColor() const;
    void setColor(EColor eColor);

signals:
    void sigDecreaseHealth();
    void sigGameOver();

public slots:
    void onMove();

private:
    EColor m_eColor;

};

///--------------------------///

class CBullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    CBullet(EColor eColor, QGraphicsItem *pParent = nullptr);

    EColor getColor() const;
    void setColor(EColor eColor);

signals:
    void sigIncreaseScore();
    void sigDecreaseScore();

public slots:
    void onMove();

private:
    EColor m_eColor;
};

///--------------------------///

class CPoints : QGraphicsTextItem
{
public:
    CPoints(QGraphicsTextItem *pParent = nullptr);

    void increasePoints();
    void decreasePoints();
    void decreaseHealth();

    int getHealth() const;
    int getScore() const;

    void reset();

private:
    int m_nHealth = gMaxHealth;
    int m_nScore = 0;
};
#endif // COMPONENTS_H
