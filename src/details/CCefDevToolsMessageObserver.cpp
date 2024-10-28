#include "CCefDevToolsMessageObserver.h"

#include <Qdebug>

CCefDevToolsMessageObserver::CCefDevToolsMessageObserver(QCefViewPrivate* pCefViewPrivate) : pCefViewPrivate_(pCefViewPrivate) {}

CCefDevToolsMessageObserver::~CCefDevToolsMessageObserver() {}

bool CCefDevToolsMessageObserver::OnDevToolsMessage(CefRefPtr<CefBrowser>, const void* message, size_t message_size) {
    return pCefViewPrivate_->onDevToolsMessage(QByteArray::fromRawData(static_cast<const char*>(message), message_size));
}
