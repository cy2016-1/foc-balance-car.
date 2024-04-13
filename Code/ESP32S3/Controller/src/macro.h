#ifndef _MACRO_H
#define _MACRO_H

#define STRINGIFY(x) #x

#define CONST_PI 3.1415926535898

#define COUNT_OF(a) (sizeof(a) / sizeof(a[0]))

#define TO_RAD(DEG) ({ DEG *CONST_PI / 180; })

#define TO_DEG(RAD) ({ RAD * 180 / CONST_PI; })

#endif