/***************************************************************************
**
** Copyright (C) 2013 BlackBerry Limited all rights reserved
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtBluetooth module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QLOWENERGYSERVICEINFO_H
#define QLOWENERGYSERVICEINFO_H
#include <QtCore/QSharedPointer>
#include <QtBluetooth/QBluetoothAddress>
#include <QtBluetooth/QBluetoothDeviceInfo>
#include <QtBluetooth/QBluetoothUuid>
#include <QtBluetooth/QLowEnergyCharacteristicInfo>

QT_BEGIN_NAMESPACE

class QLowEnergyServiceInfoPrivate;
class QBluetoothAddress;

class Q_BLUETOOTH_EXPORT QLowEnergyServiceInfo
{
    friend class QBluetoothServiceDiscoveryAgent;
    friend class QBluetoothServiceDiscoveryAgentPrivate;
    friend class QLowEnergyController;
    friend class QLowEnergyControllerPrivate;
public:
    enum ServiceType {
        PrimaryService = 0x00000001,
        IncludedService = 0x00000002
    };

    enum Error {
        ConnectionRefused = 0x001,
        DeviceBusy = 0x002,
        InitializationFailed = 0x003,
        MemoryAllocation = 0x004,
        DisconnectFail = 0x005,
        UnknownError = 0x006
    };

    QLowEnergyServiceInfo();
    QLowEnergyServiceInfo(const QBluetoothUuid &uuid);
    QLowEnergyServiceInfo(const QLowEnergyServiceInfo &other);

    ~QLowEnergyServiceInfo();

    QLowEnergyServiceInfo &operator=(const QLowEnergyServiceInfo &other);

    void setDevice(const QBluetoothDeviceInfo &info);
    QBluetoothDeviceInfo device() const;

    QBluetoothUuid uuid() const;

    QList<QLowEnergyCharacteristicInfo> characteristics() const;

    QString name() const;

    void setServiceType(QLowEnergyServiceInfo::ServiceType type);
    QLowEnergyServiceInfo::ServiceType serviceType() const;

    void setRandomAddress();

    bool isConnected() const;

    QString errorString() const;

    bool isValid() const;

protected:
    QSharedPointer<QLowEnergyServiceInfoPrivate> d_ptr;

};

QT_END_NAMESPACE

#endif // QLOWENERGYSERVICEINFO_H