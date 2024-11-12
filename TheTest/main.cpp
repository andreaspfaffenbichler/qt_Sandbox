#include "Test.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	const QUrl url(u"qrc:/TheTest/main.qml"_qs);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty( "test", new Test( engine.rootContext() ) );

	engine.load(url);

	return app.exec();
}
