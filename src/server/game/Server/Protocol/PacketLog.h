/*
 * Copyright (C) 2013-2018 NuskyCore <http://www.nuskycore.org/>
 * Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2018 MaNGOS <https://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef Nusky_PACKETLOG_H
#define Nusky_PACKETLOG_H

#include "Common.h"
#include <ace/Singleton.h>

enum Direction
{
    CLIENT_TO_SERVER,
    SERVER_TO_CLIENT
};

class WorldPacket;

class PacketLog
{
    friend class ACE_Singleton<PacketLog, ACE_Thread_Mutex>;

    private:
        PacketLog();
        ~PacketLog();

    public:
        void Initialize();
        bool CanLogPacket() const { return (_file != NULL); }
        void LogPacket(WorldPacket const& packet, Direction direction);

    private:
        FILE* _file;
};

#define sPacketLog ACE_Singleton<PacketLog, ACE_Thread_Mutex>::instance()
#endif