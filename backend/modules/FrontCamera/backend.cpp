#include <QtQml>
#include <QtQml/QQmlContext>
#include "backend.h"
#include "mytype.h"
#include "cameraselector.h"


void BackendPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("FrontCamera"));

    qmlRegisterType<MyType>(uri, 1, 0, "MyType");
    qmlRegisterType<CameraSelector>(uri, 1, 0, "CameraSelector");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}

