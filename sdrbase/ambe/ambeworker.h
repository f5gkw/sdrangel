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

#ifndef SDRBASE_AMBE_AMBEWORKER_H_
#define SDRBASE_AMBE_AMBEWORKER_H_

#include <QObject>

#include "util/messagequeue.h"
#include "export.h"
#include "dvcontroller.h"

class SDRBASE_API AMBEWorker : public QObject {
    Q_OBJECT
public:
    AMBEWorker();
    ~AMBEWorker();

    bool open(const std::string& serialDevice);
    void close();

    MessageQueue m_inputMessageQueue; //!< Queue for asynchronous inbound communication

private:
    SerialDV::DVController m_dvController;
};

#endif // SDRBASE_AMBE_AMBEWORKER_H_
