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

#ifndef QLOWENERGYCONTROLLER_H
#define QLOWENERGYCONTROLLER_H

#include <QtCore/QObject>
#include <QtBluetooth/qbluetoothglobal.h>
#include <QtBluetooth/QBluetoothAddress>
#include <QtBluetooth/QLowEnergyCharacteristicInfo>
#include <QtBluetooth/QLowEnergyServiceInfo>

QT_BEGIN_NAMESPACE

class QLowEnergyControllerPrivate;

class Q_BLUETOOTH_EXPORT QLowEnergyController: public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QLowEnergyController)
public:
    QLowEnergyController(QObject *parent = 0);
    ~QLowEnergyController();
    QList<QLowEnergyServiceInfo> services() const;
    void connectToService(const QLowEnergyServiceInfo &leService);
    void disconnectFromService(const QLowEnergyServiceInfo &leService = QLowEnergyServiceInfo());
    bool enableNotifications(const QLowEnergyCharacteristicInfo &characteristic);
    void disableNotifications(const QLowEnergyCharacteristicInfo &characteristic);
    QString errorString() const;

Q_SIGNALS:
    void connected(const QLowEnergyServiceInfo &);
    void error(const QLowEnergyServiceInfo &);
    void error(const QLowEnergyCharacteristicInfo &);
    void disconnected(const QLowEnergyServiceInfo &);
    void valueChanged(const QLowEnergyCharacteristicInfo &);



private:
    QLowEnergyControllerPrivate *d_ptr;

    Q_PRIVATE_SLOT(d_func(), void _q_serviceConnected(const QBluetoothUuid &uuid))
    Q_PRIVATE_SLOT(d_func(), void _q_serviceError(const QBluetoothUuid &uuid))
    Q_PRIVATE_SLOT(d_func(), void _q_characteristicError(const QBluetoothUuid &uuid))
    Q_PRIVATE_SLOT(d_func(), void _q_valueReceived(const QBluetoothUuid &uuid))
    Q_PRIVATE_SLOT(d_func(), void _q_serviceDisconnected(const QBluetoothUuid &uuid))
};

QT_END_NAMESPACE

#endif // QLOWENERGYCONTROLLER_H