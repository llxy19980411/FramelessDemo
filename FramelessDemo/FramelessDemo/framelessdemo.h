#ifndef FRAMELESSDEMO_H
#define FRAMELESSDEMO_H

#include <QtWidgets/QWidget>
#include "ui_framelessdemo.h"

class FramelessDemo : public QWidget
{
	Q_OBJECT

public:
	FramelessDemo(QWidget *parent = 0);
	~FramelessDemo();

private:
	Ui::FramelessDemoClass ui;
};

#endif // FRAMELESSDEMO_H
