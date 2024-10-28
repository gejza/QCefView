#pragma once

#include "QCefViewPrivate.h"

class CCefDevToolsMessageObserver : public CefDevToolsMessageObserver
{
    QCefViewPrivate* pCefViewPrivate_ = nullptr;
public:
    CCefDevToolsMessageObserver(QCefViewPrivate* pCefViewPrivate);
    virtual ~CCefDevToolsMessageObserver() override;

    bool OnDevToolsMessage(CefRefPtr<CefBrowser>, const void* message, size_t message_size) override;
private:

    IMPLEMENT_REFCOUNTING(CCefDevToolsMessageObserver);
    DISALLOW_COPY_AND_ASSIGN(CCefDevToolsMessageObserver);
};
