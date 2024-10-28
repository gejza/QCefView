#include "CCefDevToolsMessageObserver.h"

#include <Qdebug>

CCefDevToolsMessageObserver::CCefDevToolsMessageObserver(QCefViewPrivate* pCefViewPrivate) : pCefViewPrivate_(pCefViewPrivate) {}

CCefDevToolsMessageObserver::~CCefDevToolsMessageObserver() {}

bool CCefDevToolsMessageObserver::OnDevToolsMessage(CefRefPtr<CefBrowser>, const void* message, size_t message_size) {
    const char* data = static_cast<const char*>(message);
    QString msg = QString::fromUtf8(data, message_size);
    qInfo() << "Received" << msg;
    return pCefViewPrivate_->onDevToolsMessage(msg);
}
