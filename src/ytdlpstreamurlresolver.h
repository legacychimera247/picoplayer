#ifndef YTDLPSTREAMURLRESOLVER_H
#define YTDLPSTREAMURLRESOLVER_H

#include <QObject>
#include <QProcess>

class YtdlpStreamUrlResolver : public QObject
{
    Q_OBJECT
public:
    explicit YtdlpStreamUrlResolver(QObject *parent = nullptr);

    Q_INVOKABLE void resolve(QString url);
    Q_INVOKABLE QString getStreamUrl() const;

signals:
    void gotStreamUrl(QString url);

private slots:
    void onYtdlpFinished(int);

private:
    QString _streamUrl{};
    QProcess* _ytdlpProcess;
};

#endif // YTDLPSTREAMURLRESOLVER_H
