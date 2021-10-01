#ifndef KONAMICOMPRESSION_H
#define KONAMICOMPRESSION_H


#include <QObject>
#include <../../compressioninterface.h>

class KonamiCompression : public QObject, public CompressionInterface
{
    Q_OBJECT
    Q_INTERFACES(CompressionInterface)
    Q_PLUGIN_METADATA(IID "fr.nyo.SNESTilesKitten.KonamiCompression" FILE "konami.json")

public:
    KonamiCompression();
    QList<CompressionInfo>  compressionList();
    char*   compress(QString name, const char *data, const size_t start, const unsigned int lenght, unsigned int *compressedSize);
    char*   unCompress(QString name, const char *data, const size_t start, const unsigned int lenght, unsigned int *uncompressedSize, unsigned int* compressedLength);
    QString compressionError();
    QString decompressionError();

};
#endif // KONAMICOMPRESSION_H
