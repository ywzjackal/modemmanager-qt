/*
    Copyright 2015 Jan Grulich <jgrulich@redhat.com>

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

#include "modemlocationpropertiestest.h"

#include "dbus/fakedbus.h"
#include "generictypes.h"
#include "manager.h"
#include "modem.h"
#include "modemlocation.h"

#include "fakemodem/modem.h"

#include <QTest>
#include <QSignalSpy>
#include <QtTest/qsignalspy.h>

void ModemLocationPropertiesTest::initTestCase()
{
    fakeModem = new FakeModem();

    modem = new Modem();
    modem->setAccessTechnologies(16);
    modem->SetCurrentBands({0});
    modem->SetCurrentCapabilities(4);
    modem->SetCurrentModes({MM_MODEM_MODE_ANY, MM_MODEM_MODE_NONE});
    modem->setDevice(QLatin1String("/sys/devices/pci0000:00/0000:00:1d.0/usb4/4-1/4-1.2"));
    modem->setDeviceIdentifier(QLatin1String("1c435eb6d74494b5f78d7221e2c5ae9ec526a981"));
    modem->setDrivers({QLatin1String("option1")});
    modem->setEquipmentIdentifier(QLatin1String("353475021085110"));
    modem->setManufacturer(QLatin1String("huawei"));
    modem->setMaxActiveBearers(1);
    modem->setMaxBearers(1);
    modem->setModel(QLatin1String("K2540"));
    //modem->setOwnNumbers();
    modem->setPlugin(QLatin1String("Huawei"));
    modem->setPorts({{QLatin1String("ttyUSB0"), MM_MODEM_PORT_TYPE_AT}, {QLatin1String("ttyUSB1"), MM_MODEM_PORT_TYPE_QCDM}, {QLatin1String("ttyUSB2"), MM_MODEM_PORT_TYPE_AT}});
    modem->SetPowerState(3);
    modem->setPrimaryPort(QLatin1String("ttyUSB2"));
    modem->setRevision(QLatin1String("11.001.05.00.11"));
    modem->setSignalQuality({93, true});
    modem->setSim(QDBusObjectPath("/org/kde/fakemodem/SIM/1"));
    modem->setState(8);
    modem->setStateFailedReason(0);
    modem->setSupportedBands({0});
    modem->setSupportedCapabilities({4});
    modem->setSupportedIpFamilies(3);
    ModemManager::SupportedModesType supportedModes;
    ModemManager::CurrentModesType supportedMode1 = {MM_MODEM_MODE_4G & MM_MODEM_MODE_3G & MM_MODEM_MODE_2G, MM_MODEM_MODE_NONE};
    ModemManager::CurrentModesType supportedMode2 = {MM_MODEM_MODE_4G & MM_MODEM_MODE_3G & MM_MODEM_MODE_2G, MM_MODEM_MODE_2G};
    ModemManager::CurrentModesType supportedMode3 = {MM_MODEM_MODE_4G & MM_MODEM_MODE_3G & MM_MODEM_MODE_2G, MM_MODEM_MODE_3G};
    supportedModes << supportedMode1 << supportedMode2 << supportedMode3;
    modem->setSupportedModes(supportedModes);
    modem->setUnlockRequired(1);
    modem->setUnlockRetries({{MM_MODEM_LOCK_SIM_PIN, 3}, {MM_MODEM_LOCK_SIM_PIN2, 3}, {MM_MODEM_LOCK_SIM_PUK, 10}, {MM_MODEM_LOCK_SIM_PUK2, 10}});

    QSignalSpy addModemSpy(ModemManager::notifier(), SIGNAL(modemAdded(QString)));
    fakeModem->addModem(modem);
    QVERIFY(addModemSpy.wait());

    modemLocation = new ModemLocation(modem);
    modemLocation->setModemPath(modem->modemPath());
    modemLocation->setCapabilities(MM_MODEM_LOCATION_SOURCE_3GPP_LAC_CI & MM_MODEM_LOCATION_SOURCE_GPS_RAW);
    modemLocation->setEnabled(MM_MODEM_LOCATION_SOURCE_3GPP_LAC_CI & MM_MODEM_LOCATION_SOURCE_GPS_RAW);
    QMap<MMModemLocationSource, QVariant> location;
    location.insert(MM_MODEM_LOCATION_SOURCE_3GPP_LAC_CI, QLatin1String("310,26,85CD,D30156"));
    modemLocation->setLocation(location);
    modemLocation->setSignalsLocation(true);

    ModemManager::MMVariantMapMap interfaces;
    interfaces.insert(QLatin1String(MMQT_DBUS_INTERFACE_MODEM_LOCATION), modemLocation->toMap());
    fakeModem->addInterfaces(QDBusObjectPath(modem->modemPath()), interfaces);
    modemLocation->setEnableNotifications(true);
}

void ModemLocationPropertiesTest::testModemLocationProperties()
{
    ModemManager::ModemDevice::Ptr modemDevice = ModemManager::modemDevices().first();
    QVERIFY(modemDevice);
    QVERIFY(modemDevice->hasInterface(ModemManager::ModemDevice::LocationInterface));
    ModemManager::ModemLocation::Ptr modemLocationInterface = modemDevice->interface(ModemManager::ModemDevice::LocationInterface).objectCast<ModemManager::ModemLocation>();
    QVERIFY(modemLocationInterface);

    modemLocation->setCapabilities(MM_MODEM_LOCATION_SOURCE_GPS_RAW);
    QSignalSpy capabilitiesChangedSpy(modemLocationInterface.data(), SIGNAL(capabilitiesChanged(QFlags<MMModemLocationSource>)));
    QVERIFY(capabilitiesChangedSpy.wait());
    QCOMPARE(modemLocationInterface->capabilities(), capabilitiesChangedSpy.at(0).at(0).value<QFlags<MMModemLocationSource> >());

    modemLocation->setEnabled(MM_MODEM_LOCATION_SOURCE_GPS_RAW);
    QSignalSpy enabledChangedSpy(modemLocationInterface.data(), SIGNAL(enabledCapabilitiesChanged(QFlags<MMModemLocationSource>)));
    QVERIFY(enabledChangedSpy.wait());
    QCOMPARE(modemLocationInterface->enabledCapabilities(), enabledChangedSpy.at(0).at(0).value<QFlags<MMModemLocationSource> >());

    QMap<MMModemLocationSource, QVariant> location;
    location.insert(MM_MODEM_LOCATION_SOURCE_3GPP_LAC_CI, QLatin1String("312,27,85CD,D30156"));
    modemLocation->setLocation(location);
    QSignalSpy locationChangedSpy(modemLocationInterface.data(), SIGNAL(locationChanged(ModemManager::LocationInformationMap)));
    QVERIFY(locationChangedSpy.wait());
    QCOMPARE(modemLocationInterface->location().value(MM_MODEM_LOCATION_SOURCE_3GPP_LAC_CI).toString(),
             locationChangedSpy.at(0).at(0).value<ModemManager::LocationInformationMap>().value(MM_MODEM_LOCATION_SOURCE_3GPP_LAC_CI).toString());

    modemLocation->setSignalsLocation(true);
    QSignalSpy signalsLocationChangedSpy(modemLocationInterface.data(), SIGNAL(signalsLocationChanged(bool)));
    QVERIFY(signalsLocationChangedSpy.wait());
    QCOMPARE(modemLocationInterface->signalsLocation(), signalsLocationChangedSpy.at(0).at(0).toBool());
}

QTEST_MAIN(ModemLocationPropertiesTest)
