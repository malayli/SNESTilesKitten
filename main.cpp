#include "mainui.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    // Windows hack to have output in the console
    QApplication a(argc, argv);

    QApplication::setApplicationName("SNESTilesKitten");
    QApplication::setApplicationVersion(QString(__DATE__));

    QDir pluginsDir(qApp->applicationDirPath());
//TODO Linux handling
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");
    QDir patternDir = qApp->applicationDirPath();
    if (patternDir.dirName().toLower() == "debug" || patternDir.dirName().toLower() == "release")
    {
        patternDir.cdUp();
        patternDir.cdUp();
        patternDir.cd("SNESTilesKitten");
    }
    patternDir.cd("TilesPatterns");
    ROMDataEngine::loadCompressionPlugins(pluginsDir);
    TilesPattern::loadPatterns(patternDir);
    /*QList<tile8> someTiles;
    for (unsigned int i = 0; i < 32; i++)
    {
        tile8 t;
        t.id = i;
        someTiles.append(t);
    }
    qDebug() << TilesPattern::transform(TilesPattern::pattern("normal"), someTiles);
    qDebug() << TilesPattern::transform(TilesPattern::pattern("32x32 B (4x4)"), someTiles);
    qDebug() << TilesPattern::transform(TilesPattern::pattern("32x32 A (2x2*4)"), someTiles);
    return 0;*/
    MainUI w;
    w.show();
    return a.exec();
}
