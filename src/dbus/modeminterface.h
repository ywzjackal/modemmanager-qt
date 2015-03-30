/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p modeminterface /home/jgrulich/development/projects/libmm-qt/dbus/introspection/org.freedesktop.ModemManager1.Modem.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef MODEMMANAGERQT_MODEMINTERFACE_H
#define MODEMMANAGERQT_MODEMINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generictypes.h"
#include "generictypes_p.h"

/*
 * Proxy class for interface org.freedesktop.ModemManager1.Modem
 */
class OrgFreedesktopModemManager1ModemInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
#ifdef MMQT_STATIC
    { return "org.kde.fakemodem.Modem"; }
#else
    { return "org.freedesktop.ModemManager1.Modem"; }
#endif
public:
    OrgFreedesktopModemManager1ModemInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopModemManager1ModemInterface();

    Q_PROPERTY(uint AccessTechnologies READ accessTechnologies)
    inline uint accessTechnologies() const
    { return qvariant_cast< uint >(property("AccessTechnologies")); }

    Q_PROPERTY(QList<QDBusObjectPath> Bearers READ bearers)
    inline QList<QDBusObjectPath> bearers() const
    { return qvariant_cast< QList<QDBusObjectPath> >(property("Bearers")); }

    Q_PROPERTY(ModemManager::UIntList CurrentBands READ currentBands)
    inline ModemManager::UIntList currentBands() const
    { return qvariant_cast< ModemManager::UIntList >(property("CurrentBands")); }

    Q_PROPERTY(uint CurrentCapabilities READ currentCapabilities)
    inline uint currentCapabilities() const
    { return qvariant_cast< uint >(property("CurrentCapabilities")); }

    Q_PROPERTY(ModemManager::CurrentModesType CurrentModes READ currentModes)
    inline ModemManager::CurrentModesType currentModes() const
    { return qvariant_cast< ModemManager::CurrentModesType >(property("CurrentModes")); }

    Q_PROPERTY(QString Device READ device)
    inline QString device() const
    { return qvariant_cast< QString >(property("Device")); }

    Q_PROPERTY(QString DeviceIdentifier READ deviceIdentifier)
    inline QString deviceIdentifier() const
    { return qvariant_cast< QString >(property("DeviceIdentifier")); }

    Q_PROPERTY(QStringList Drivers READ drivers)
    inline QStringList drivers() const
    { return qvariant_cast< QStringList >(property("Drivers")); }

    Q_PROPERTY(QString EquipmentIdentifier READ equipmentIdentifier)
    inline QString equipmentIdentifier() const
    { return qvariant_cast< QString >(property("EquipmentIdentifier")); }

    Q_PROPERTY(QString Manufacturer READ manufacturer)
    inline QString manufacturer() const
    { return qvariant_cast< QString >(property("Manufacturer")); }

    Q_PROPERTY(uint MaxActiveBearers READ maxActiveBearers)
    inline uint maxActiveBearers() const
    { return qvariant_cast< uint >(property("MaxActiveBearers")); }

    Q_PROPERTY(uint MaxBearers READ maxBearers)
    inline uint maxBearers() const
    { return qvariant_cast< uint >(property("MaxBearers")); }

    Q_PROPERTY(QString Model READ model)
    inline QString model() const
    { return qvariant_cast< QString >(property("Model")); }

    Q_PROPERTY(QStringList OwnNumbers READ ownNumbers)
    inline QStringList ownNumbers() const
    { return qvariant_cast< QStringList >(property("OwnNumbers")); }

    Q_PROPERTY(QString Plugin READ plugin)
    inline QString plugin() const
    { return qvariant_cast< QString >(property("Plugin")); }

    Q_PROPERTY(ModemManager::PortList Ports READ ports)
    inline ModemManager::PortList ports() const
    { return qvariant_cast< ModemManager::PortList >(property("Ports")); }

    Q_PROPERTY(uint PowerState READ powerState)
    inline uint powerState() const
    { return qvariant_cast< uint >(property("PowerState")); }

    Q_PROPERTY(QString PrimaryPort READ primaryPort)
    inline QString primaryPort() const
    { return qvariant_cast< QString >(property("PrimaryPort")); }

    Q_PROPERTY(QString Revision READ revision)
    inline QString revision() const
    { return qvariant_cast< QString >(property("Revision")); }

    Q_PROPERTY(ModemManager::SignalQualityPair SignalQuality READ signalQuality)
    inline ModemManager::SignalQualityPair signalQuality() const
    { return qvariant_cast< ModemManager::SignalQualityPair >(property("SignalQuality")); }

    Q_PROPERTY(QDBusObjectPath Sim READ sim)
    inline QDBusObjectPath sim() const
    { return qvariant_cast< QDBusObjectPath >(property("Sim")); }

    Q_PROPERTY(int State READ state)
    inline int state() const
    { return qvariant_cast< int >(property("State")); }

    Q_PROPERTY(uint StateFailedReason READ stateFailedReason)
    inline uint stateFailedReason() const
    { return qvariant_cast< uint >(property("StateFailedReason")); }

    Q_PROPERTY(ModemManager::UIntList SupportedBands READ supportedBands)
    inline ModemManager::UIntList supportedBands() const
    { return qvariant_cast< ModemManager::UIntList >(property("SupportedBands")); }

    Q_PROPERTY(ModemManager::UIntList SupportedCapabilities READ supportedCapabilities)
    inline ModemManager::UIntList supportedCapabilities() const
    { return qvariant_cast< ModemManager::UIntList >(property("SupportedCapabilities")); }

    Q_PROPERTY(uint SupportedIpFamilies READ supportedIpFamilies)
    inline uint supportedIpFamilies() const
    { return qvariant_cast< uint >(property("SupportedIpFamilies")); }

    Q_PROPERTY(ModemManager::SupportedModesType SupportedModes READ supportedModes)
    inline ModemManager::SupportedModesType supportedModes() const
    { return qvariant_cast< ModemManager::SupportedModesType >(property("SupportedModes")); }

    Q_PROPERTY(uint UnlockRequired READ unlockRequired)
    inline uint unlockRequired() const
    { return qvariant_cast< uint >(property("UnlockRequired")); }

    Q_PROPERTY(ModemManager::UnlockRetriesMap UnlockRetries READ unlockRetries)
    inline ModemManager::UnlockRetriesMap unlockRetries() const
    { return qvariant_cast< ModemManager::UnlockRetriesMap >(property("UnlockRetries")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QString> Command(const QString &cmd, uint timeout)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(cmd) << QVariant::fromValue(timeout);
        return asyncCallWithArgumentList(QLatin1String("Command"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> CreateBearer(const QVariantMap &properties)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(properties);
        return asyncCallWithArgumentList(QLatin1String("CreateBearer"), argumentList);
    }

    inline QDBusPendingReply<> DeleteBearer(const QDBusObjectPath &bearer)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(bearer);
        return asyncCallWithArgumentList(QLatin1String("DeleteBearer"), argumentList);
    }

    inline QDBusPendingReply<> Enable(bool enable)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(enable);
        return asyncCallWithArgumentList(QLatin1String("Enable"), argumentList);
    }

    inline QDBusPendingReply<> FactoryReset(const QString &code)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(code);
        return asyncCallWithArgumentList(QLatin1String("FactoryReset"), argumentList);
    }

    inline QDBusPendingReply<QList<QDBusObjectPath> > ListBearers()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("ListBearers"), argumentList);
    }

    inline QDBusPendingReply<> Reset()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Reset"), argumentList);
    }

    inline QDBusPendingReply<> SetCurrentBands(const QList<uint> &bands)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(bands);
        return asyncCallWithArgumentList(QLatin1String("SetCurrentBands"), argumentList);
    }

    inline QDBusPendingReply<> SetCurrentCapabilities(uint capabilities)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(capabilities);
        return asyncCallWithArgumentList(QLatin1String("SetCurrentCapabilities"), argumentList);
    }

    inline QDBusPendingReply<> SetCurrentModes(ModemManager::CurrentModesType modes)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(modes);
        return asyncCallWithArgumentList(QLatin1String("SetCurrentModes"), argumentList);
    }

    inline QDBusPendingReply<> SetPowerState(uint state)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(state);
        return asyncCallWithArgumentList(QLatin1String("SetPowerState"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void StateChanged(int oldState, int newState, uint reason);
};

#endif
