#ifndef FRAMELESSEVENTFILTER_H
#define FRAMELESSEVENTFILTER_H

#include <QObject>
#include <QWidget>
#include <QEvent>
#include "windows.h"
#include "windowsx.h"
class FramelessEventFilter : public QObject
{
	Q_OBJECT

public:
	FramelessEventFilter(QWidget *parent);
	~FramelessEventFilter();
	void setCaptionWidget(QWidget* w);
signals:
	void windowIsMaximizedChanged(bool b);
public:
	bool nativeEventFilter(const QByteArray& eventType, void* message, long* result);
protected:
	virtual bool eventFilter(QObject* watched, QEvent* event) Q_DECL_OVERRIDE;
private:
	bool isCaption(int x, int y);
private:
	QWidget* m_captionWgt;
	QWidget* m_parentWgt;
	
};

#endif // FRAMELESSEVENTFILTER_H
