#ifndef BACKCOLOURCOM_H
#define BACKCOLOURCOM_H
#include <QWidget>
#include <QHeaderView>

/* 设置窗口背景色函数 */
void com_setBackColour(const QString &,QWidget *target);

void btnBlue_style_sheet(QWidget *target);
void groupBox_background_icon(QWidget *target);
void set_background_icon(QWidget *widget, const QString &icon);
void set_background_color(QWidget *widget, const QColor &color);
void set_background_icon(QWidget *widget, const QString &icon, const QSize &size);

#endif // BACKCOLOURCOM_H
