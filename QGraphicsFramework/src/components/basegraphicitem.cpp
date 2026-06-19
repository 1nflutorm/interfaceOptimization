#include "../../include/components/basegraphicitem.h"

BaseGraphicItem::BaseGraphicItem(QGraphicsItem* parent)
    : QGraphicsItem(parent),
    m_rect(QRectF()),
    m_text(QString()),
    m_pressed(false),
    m_hovered(false)
{
}

BaseGraphicItem::BaseGraphicItem(const QRectF &rect, const QString &text, QGraphicsItem *parent)
    : QGraphicsItem(parent),
    m_rect(rect),
    m_text(text),
    m_pressed(false),
    m_hovered(false)
{
}

BaseGraphicItem::BaseGraphicItem(const QRectF &rect, QGraphicsItem *parent)
    : QGraphicsItem(parent),
    m_rect(rect),
    m_text(QString()),
    m_pressed(false),
    m_hovered(false)
{
}

QRectF BaseGraphicItem::boundingRect() const
{
    return m_rect;
}

void BaseGraphicItem::setRect(const QRectF &rect)
{
    m_rect = rect;
}

QRectF BaseGraphicItem::getRect() const
{
    return m_rect;
}

void BaseGraphicItem::setText(const QString &text)
{
    m_text = text;
}

QString BaseGraphicItem::getText() const
{
    return m_text;
}
