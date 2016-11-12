#ifndef GLASS_H
#define GLASS_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // GLASS_H
