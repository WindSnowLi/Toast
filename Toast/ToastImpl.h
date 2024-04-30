﻿#pragma once

#include "Toast.h"

class QReadWriteLock;
class QWidget;
namespace Ui {
class ToastClass;
}
class ToastImpl : public Toast {

public:
    ToastImpl(QWidget* parent = nullptr);

    ~ToastImpl() override;

    void setText(const QString& text) override;

    /**
     * @brief 动画方式show出，默认2秒后消失
     * @param timeout 时间
     */
    void showAnimation(int timeout = 2000) override;

    /**
     * @brief 显示提示
     * @param text 提示内容
     */
    static void showTip(const QString& text);

protected:
    virtual void paintEvent(QPaintEvent* event);

    static QList<QWidget*>& Widgets();

    static QReadWriteLock& Lock();

private:
    Ui::ToastClass* ui = nullptr;
};
