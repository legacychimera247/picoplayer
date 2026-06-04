#include "ytdlpstreamurlresolver.h"

#include <QDebug>

YtdlpStreamUrlResolver::YtdlpStreamUrlResolver(QObject *parent) : QObject(parent), _ytdlpProcess(nullptr)
{

}

void YtdlpStreamUrlResolver::resolve(QString url)
{
    if (_ytdlpProcess != nullptr) {
        return;
    }

    _ytdlpProcess = new QProcess();
    QStringList params = {"-g", url};
    qDebug() << "Executing: " << params;
    _ytdlpProcess->start("yt-dlp", params, QIODevice::OpenModeFlag::ReadWrite);
    connect(_ytdlpProcess, static_cast<void (QProcess::*)(int)>(&QProcess::finished), this, &YtdlpStreamUrlResolver::onYtdlpFinished);
}

QString YtdlpStreamUrlResolver::getStreamUrl() const
{
    return _streamUrl;
}

void YtdlpStreamUrlResolver::onYtdlpFinished(int)
{
    QString output = _ytdlpProcess->readAllStandardOutput();

    _streamUrl = output;
    emit gotStreamUrl(_streamUrl);

    QProcess* process = _ytdlpProcess;
    _ytdlpProcess = nullptr;
    process->deleteLater();
}
