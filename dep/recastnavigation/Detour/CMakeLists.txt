# Copyright (C) 2013-2018 NuskyCore <http://www.nuskycore.org/>
# Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(Detour_STAT_SRCS
    DetourAlloc.cpp 
    DetourCommon.cpp 
    DetourNavMesh.cpp 
    DetourNavMeshBuilder.cpp 
    DetourNavMeshQuery.cpp 
    DetourNode.cpp 
)

if(WIN32)
  include_directories(
    ${CMAKE_SOURCE_DIR}/dep/zlib
  )
endif()

add_library(Detour STATIC ${Detour_STAT_SRCS})

target_link_libraries(Detour ${ZLIB_LIBRARIES})
