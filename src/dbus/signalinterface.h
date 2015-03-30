/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p signalinterface /home/jgrulich/development/projects/libmm-qt/dbus/introspection/org.freedesktop.ModemManager1.Modem.Signal.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef MODEMMANAGERQT_SIGNALINTERFACE_H
#define MODEMMANAGERQT_SIGNALINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generictypes.h"

/*
 * Proxy class for interface org.freedesktop.ModemManager1.Modem.Signal
 */
class OrgFreedesktopModemManager1ModemSignalInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
#ifdef MMQT_STATIC
    { return "org.kde.fakemodem.Modem.Signal"; }
#else
    { return "org.freedesktop.ModemManager1.Modem.Signal"; }
#endif
public:
    OrgFreedesktopModemManager1ModemSignalInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopModemManager1ModemSignalInterface();

    Q_PROPERTY(QVariantMap Cdma READ cdma)
    inline QVariantMap cdma() const
    { return qvariant_cast< QVariantMap >(property("Cdma")); }

    Q_PROPERTY(QVariantMap Evdo READ evdo)
    inline QVariantMap evdo() const
    { return qvariant_cast< QVariantMap >(property("Evdo")); }

    Q_PROPERTY(QVariantMap Gsm READ gsm)
    inline QVariantMap gsm() const
    { return qvariant_cast< QVariantMap >(property("Gsm")); }

    Q_PROPERTY(QVariantMap Lte READ lte)
    inline QVariantMap lte() const
    { return qvariant_cast< QVariantMap >(property("Lte")); }

    Q_PROPERTY(uint Rate READ rate)
    inline uint rate() const
    { return qvariant_cast< uint >(property("Rate")); }

    Q_PROPERTY(QVariantMap Umts READ umts)
    inline QVariantMap umts() const
    { return qvariant_cast< QVariantMap >(property("Umts")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Setup(uint rate)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(rate);
        return asyncCallWithArgumentList(QLatin1String("Setup"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif
