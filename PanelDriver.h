﻿#ifndef PANELDRIVER_H
#define PANELDRIVER_H

#include <QObject>
#include <QSocketNotifier>
#include <QMutex>

/*!
 * @brief PanelDriver
 * @details
 * @note
 */
class PanelDriver: public QObject
{
    Q_OBJECT
public:
    PanelDriver(QObject *parent = nullptr);
    ~PanelDriver();

public:
    // file descriptor
    static int mFileDesc;
    // signal number
    static int mSignum;

public:
    // Unix signal handlers.
    static void unixSignalHandler(int unused);
public slots:
    // Qt signal handlers.
    void qtSignalHandler();

private:
    static int mSocketFd[2];
    static int mBufferCounter;
    static QSocketNotifier *mSocketNotifier;

signals:
    void panelChanged();
};

#endif // PANELDRIVER_H
