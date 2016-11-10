#ifndef GLASS_H
#define GLASS_H

#include <QObject>
#include <QWidget>

class Glass : public QWidget
{
    Q_OBJECT
public:
    explicit Glass(QWidget *parent = 0);

signals:

public slots:
};

#endif // GLASS_H