#ifndef BASEGRAPHICITEM_H
#define BASEGRAPHICITEM_H

#include <QGraphicsItem>
#include <QObject>

class BaseGraphicItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    explicit BaseGraphicItem(QGraphicsItem* parent = nullptr);
    BaseGraphicItem(const QRectF& rect, const QString& text, QGraphicsItem* parent = nullptr);
    BaseGraphicItem(const QRectF& rect, QGraphicsItem* parent = nullptr);

    virtual ~BaseGraphicItem() = default;

public:
    virtual QRectF boundingRect() const override;

    void setRect(const QRectF& rect);
    QRectF getRect() const;

    void setText(const QString& text);
    QString getText() const;

protected:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                       QWidget* widget = nullptr) override = 0;

    /*virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;*/

signals:
    void clicked();
    void pressed();
    void released();
    void hovered();
    void doubleClicked();

protected:
    QRectF          m_rect;
    QString         m_text;
    bool            m_pressed;
    bool            m_hovered;
};

#endif // BASEGRAPHICITEM_H
