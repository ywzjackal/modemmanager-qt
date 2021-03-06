/*
    Copyright 2008,2011 Will Stephenson <wstephenson@kde.org>
    Copyright 2010 Lamarque Souza <lamarque@kde.org>
    Copyright 2013 Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MODEMMANAGERQT_MANAGER_P_H
#define MODEMMANAGERQT_MANAGER_P_H

#include <QObject>
#include <QDBusServiceWatcher>

#include "dbus/modem3gppinterface.h"
#include "dbus/modemmanager1interface.h"
#include "dbus/dbus_manager.h"

#include "manager.h"
#include "modemdevice.h"

namespace ModemManager
{
class Modem;
class ModemManagerPrivate : public Notifier
{
Q_OBJECT

public:
    ModemManagerPrivate();
    ~ModemManagerPrivate();
    QDBusServiceWatcher watcher;
    OrgFreedesktopModemManager1Interface iface;
    QMap<QString, ModemDevice::Ptr> modemList;
    OrgFreedesktopDBusObjectManagerInterface manager;
    ModemManager::ModemDevice::Ptr findModemDevice(const QString &uni);
    ModemManager::ModemDevice::List modemDevices();

    void scanDevices();
protected Q_SLOTS:
    void init();
    void daemonRegistered();
    void daemonUnregistered();
    void onInterfacesAdded(const QDBusObjectPath &object_path, const MMVariantMapMap &interfaces_and_properties);
    void onInterfacesRemoved(const QDBusObjectPath &object_path, const QStringList &interfaces);
};
} // namespace ModemManager


#endif
