#ifndef _USER_CONFIG_H
#define _USER_CONFIG_H

//Project Name
#define APP_NAME "FOCBalanceCar"

// Version
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 0

#define _VerJoin(a, b, c) STRINGIFY(a.b.c)
#define FIRMWARE_VER _VerJoin(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH)
#define FIRMWARE_VER_STR "firmware version " FIRMWARE_VER ", compiled on " __DATE__ " at " __TIME__

#define DEBUG_ENABLE 1
#define LOG_INFO printf

#define DEF_PID_VEL_P -0.028
#define DEF_PID_VEL_I -0.03
#define DEF_PID_VEL_D -0.001

#define DEF_PID_STAND_P -0.3
#define DEF_PID_STAND_I 0.0
#define DEF_PID_STAND_D 0.045

#define DEF_PID_TURN_P 0.1
#define DEF_PID_TURN_I 0.0
#define DEF_PID_TURN_D 0.08

#if DEBUG_ENABLE
#define DEBUG_P(__info,...) printf(__info,##__VA_ARGS__)
#else
#define DEBUG_P(__info,...)
#endif


#endif