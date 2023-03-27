#include "framelesseventfilter.h"

FramelessEventFilter::FramelessEventFilter(QWidget *parent)
	: QObject((QObject*)parent)
{
	m_parentWgt = parent;
	m_captionWgt = NULL;
	if (m_parentWgt != NULL)
	{
		parent->installEventFilter(this);
		parent->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	}
}

FramelessEventFilter::~FramelessEventFilter()
{

}

void FramelessEventFilter::setCaptionWidget(QWidget* w)
{
	m_captionWgt = w;
}

bool FramelessEventFilter::nativeEventFilter(const QByteArray& eventType, void* message, long* result)
{
	if (NULL == m_parentWgt)
	{
		return false;
	}
	int marginWidth = 6;
	MSG* msg = (MSG*)message;
	switch (msg->message)
	{
	case WM_NCHITTEST:
	{
		int posX = GET_X_LPARAM(msg->lParam) - m_parentWgt->frameGeometry().x();
		int posY = GET_Y_LPARAM(msg->lParam) - m_parentWgt->frameGeometry().y();
		//标题栏控制
		if (isCaption(posX, posY))
		{
			*result = HTCAPTION;
			return true;
		}
		//边框调整
		int width = m_parentWgt->width();
		int height = m_parentWgt->height();
		if (posX >= -marginWidth && posX <= marginWidth)
		{
			*result = HTLEFT;//左
			if (posY >= -marginWidth && posY <= marginWidth)
			{
				*result = HTTOPLEFT;//左上
			}
			if (posY >= height - marginWidth && posY <= height + marginWidth)
			{
				*result = HTBOTTOMLEFT;//左下
			}
			return true;
		}
		if(posX >= width - marginWidth && posX <= width + marginWidth)
		{
			*result = HTTOP;
			return true;
		}
		if (posY >= height - marginWidth && posY <= height + marginWidth)
		{
			*result = HTBOTTOM;
			return true;
		}
	}
	break;
	case WM_NCCALCSIZE:
	{
		return true;
	}
	case WM_GETMINMAXINFO:
	{
		if (::IsZoomed(msg->hwnd))
		{
			//最大化会超出屏幕，所以填充框边距
			RECT frame = { 0,0,0,0 };
			AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
			frame.left = abs(frame.left);
			frame.top = abs(frame.bottom);
			m_parentWgt->setContentsMargins(frame.left, frame.top, frame.right, frame.bottom);
		}
		else
		{
			m_parentWgt->setContentsMargins(0, 0, 0, 0);
		}
		*result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
		return true;
	}
	break;
	}
	return false;
}

bool FramelessEventFilter::eventFilter(QObject* watched, QEvent* event)
{
	if (event->type() == QEvent::WindowStateChange)
	{
		QWidget* w = qobject_cast<QWidget*>(watched);
		if (w)
		{
			windowIsMaximizedChanged(w->windowState() & Qt::WindowMaximized);
		}
		return true;
	}
	return QObject::eventFilter(watched, event);
}

bool FramelessEventFilter::isCaption(int x, int y)
{
	if (NULL == m_captionWgt)
	{
		return false;
	}
	QRect rect = m_captionWgt->rect();
	rect.moveTopLeft(m_captionWgt->mapTo(m_captionWgt, QPoint(0, 0)));
	return rect.contains(x, y);
}
