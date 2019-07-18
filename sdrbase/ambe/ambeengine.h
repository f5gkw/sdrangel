///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef SDRBASE_AMBE_AMBEENGINE_H_
#define SDRBASE_AMBE_AMBEENGINE_H_

#include <QObject>
#include <QMutex>
#include <vector>
#include <string>
#include <list>

#include "export.h"

class QThread;
class AMBEWorker;

class SDRBASE_API AMBEEngine : public QObject
{
    Q_OBJECT
public:
    AMBEEngine();
    ~AMBEEngine();

    bool scan(std::vector<std::string>& ambeDevices);
    void getDevicesNames(std::vector<std::string>& devicesNames);
    bool registerController(const std::string& ambeRef);

private:
    struct AMBEController
    {
        QThread *thread;
        AMBEWorker *worker;
        std::string device;
    };

#ifndef __WINDOWS__
    static std::string get_driver(const std::string& tty);
    static void register_comport(std::list<std::string>& comList, std::list<std::string>& comList8250, const std::string& dir);
    static void probe_serial8250_comports(std::list<std::string>& comList, std::list<std::string> comList8250);
#endif
    void getComList();

    std::list<std::string> m_comList;
    std::list<std::string> m_comList8250;
    std::vector<std::string> m_ambeSerial;
    std::vector<AMBEController>  m_controllers;
    QMutex m_mutex;
};



#endif /* SDRBASE_AMBE_AMBEENGINE_H_ */
