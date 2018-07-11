#ifndef __MODBUS_SHOW_H__
#define __MODBUS_SHOW_H__
#include <stdio.h>
#include "color.h"
#include "modbus-frame.h"

//slaver
#define S1_show(x) \
do{\
    printf("[");\
    printf_bi_red   ("%02X ", S1(x).slave);\
    printf_bi_cyan  ("%02X ", S1(x).fcode);\
    printf_bi_yellow("%02X ", S1(x).offset.h);\
    printf_bi_yellow("%02X ", S1(x).offset.l);\
    printf_bi_blue  ("%02X ", S1(x).count.h);\
    printf_bi_blue  ("%02X ", S1(x).count.l);\
    printf_bi_purple("%02X ", S1(x).crc.h);\
    printf_bi_purple("%02X ", S1(x).crc.l);\
    printf("\b]=%04X", S_calc(x));\
}while(0)

#define S2_show(x) S1_show(x)
#define S3_show(x) S1_show(x)
#define S4_show(x) S1_show(x)
#define S5_show(x) S1_show(x)
#define S6_show(x) S1_show(x)

#define S15_show(x) \
do{\
    int i = 0;\
    printf("[");\
    printf_bi_red   ("%02X ", S15(x).slave);\
    printf_bi_cyan  ("%02X ", S15(x).fcode);\
    printf_bi_yellow("%02X ", S15(x).offset.h);\
    printf_bi_yellow("%02X ", S15(x).offset.l);\
    printf_bi_black ("%02X ", S15(x).bcount);\
    for(i = 0; i < S15_bcount(x); i++)\
    {\
        printf_bi_green ("%02X ", xbyte(S15(x).value[i]));\
    }\
    printf_bi_purple("%02X ", S15_crcp(x).h);\
    printf_bi_purple("%02X ", S15_crcp(x).l);\
    printf("\b]=%04X (%d coils)", S_calc(x), S15_count(x));\
    for(i = 0; i < S15_bcount(x); i++)\
    {\
        int j = 0;\
        unsigned char d = xbyte(S15(x).value[i]);\
        ((i % 4) == 0) ? printf("\n%d>[%04d] {", i/4, (i * 8)) :  printf("{");\
        for(j = 7; j >= 0; j--)\
        {\
            ((d >> j) & 1) ? printf_hi_green("1") : printf_ul_white("0");\
            if( j == 4 )\
            {\
                printf(" ");\
            }\
            if( j == 0 )\
            {\
                printf("} ");\
            }\
        }\
    }\
}while(0)

#define S16_show(x) \
do{\
    int i = 0;\
    printf("[");\
    printf_bi_red   ("%02X ", S16(x).slave);\
    printf_bi_cyan  ("%02X ", S16(x).fcode);\
    printf_bi_yellow("%02X ", S16(x).offset.h);\
    printf_bi_yellow("%02X ", S16(x).offset.l);\
    printf_bi_black ("%02X ", S16(x).bcount);\
    for(i = 0; i < S16_count(x); i++)\
    {\
        printf_ul_green ("%02X ", S16(x).value[i].h);\
        printf_ul_green ("%02X",  S16(x).value[i].l);\
        printf(" ");\
    }\
    printf_bi_purple("%02X ", S16_crcp(x).h);\
    printf_bi_purple("%02X ", S16_crcp(x).l);\
    printf("\b]=%04X (%d registers)", S_calc(x), S16_count(x));\
    for(i = 0; i < S16_count(x); i++)\
    {\
        printf("\n[%04d]={", i);\
        printf_bi_green("%04X", S16_value(x,i));\
        printf("H,");\
        printf_bi_green("%5d", S16_value(x,i));\
        printf("}");\
    }\
}while(0)

#define S_show(x) \
    do{\
        switch(S1_fcode(x))\
        {\
            case 1: S1_show(x); break;\
            case 2: S2_show(x); break;\
            case 3: S3_show(x); break;\
            case 4: S4_show(x); break;\
            case 5: S5_show(x); break;\
            case 6: S6_show(x); break;\
            case 15: S15_show(x); break;\
            case 16: S16_show(x); break;\
        }\
    }while(0)

//master
#define M1_show(x) \
    do{\
        int i = 0;\
        printf("[");\
        printf_bi_red  ("%02X ", M1(x).slave);\
        printf_bi_cyan ("%02X ", M1(x).fcode);\
        printf_bi_black("%02X ", M1(x).bcount);\
        for(i = 0; i < M1(x).bcount; i++)\
        {\
            printf_bi_green("%02X ", xbyte(M1(x).value[i]));\
        }\
        printf_bi_purple("%02X ",  M1_crcp(x).h);\
        printf_bi_purple("%02X ",  M1_crcp(x).l);\
        printf("\b]=%04X (%d coils)", M_calc(x), M1_count(x));\
        for(i = 0; i < M1_bcount(x); i++)\
        {\
            int j = 0;\
            unsigned char d = xbyte(M1(x).value[i]);\
            ((i % 4) == 0) ? printf("\n%d>[%04d] {", i/4, (i * 8)) :  printf("{");\
            for(j = 7; j >= 0; j--)\
            {\
                ((d >> j) & 1) ? printf_hi_green("1") : printf_ul_white("0");\
                if( j == 4 )\
                {\
                    printf(" ");\
                }\
                if( j == 0 )\
                {\
                    printf("} ");\
                }\
            }\
        }\
    }while(0)

#define M2_show(x) M1_show(x)

#define M3_show(x) \
do{\
    int i = 0;\
    printf("[");\
    printf_bi_red  ("%02X ", M3(x).slave);\
    printf_bi_cyan ("%02X ", M3(x).fcode);\
    printf_bi_black("%02X ", M3(x).bcount);\
    for(i = 0; i < M3_count(x); i += 2)\
    {\
        printf_ul_green("%02X ", M3(x).value[i].h);\
        printf_ul_green("%02X",  M3(x).value[i].l);\
        printf(" ");\
    }\
    printf_bi_purple("%02X ", M3_crcp(x).h);\
    printf_bi_purple("%02X ", M3_crcp(x).l);\
    printf("\b]=%04X (%d registers)", M_calc(x), M3_count(x));\
    for(i = 0; i < M3_count(x); i++)\
    {\
        printf("\n[%04d]={", i);\
        printf_bi_green("%04X", M3_get_value(x,i));\
        printf("H,");\
        printf_bi_green("%5d", M3_get_value(x,i));\
        printf("}  ");\
    }\
}while(0)

#define M4_show(x) M3_show(x)

#define M5_show(x) \
    do{\
        printf("[");\
        printf_bi_red   ("%02X ", M5(x).slave);\
        printf_bi_cyan  ("%02X ", M5(x).fcode);\
        printf_bi_yellow("%02X ", M5(x).offset.h);\
        printf_bi_yellow("%02X ", M5(x).offset.l);\
        printf_bi_blue  ("%02X ", M5(x).count.h);\
        printf_bi_blue  ("%02X ", M5(x).count.l);\
        printf_bi_purple("%02X ", M5_crcp(x).h);\
        printf_bi_purple("%02X ", M5_crcp(x).l);\
        printf("\b]=%04X ", M_calc(x));\
    }while(0)

#define M6_show(x)  M5_show(x)
#define M15_show(x) M5_show(x)
#define M16_show(x) M5_show(x)

#define M_show(x) \
    do{\
        switch(M1_fcode(x))\
        {\
            case 1: M1_show(x); break;\
            case 2: M2_show(x); break;\
            case 3: M3_show(x); break;\
            case 4: M4_show(x); break;\
            case 5: M5_show(x); break;\
            case 6: M6_show(x); break;\
            case 15: M15_show(x); break;\
            case 16: M16_show(x); break;\
        }\
    }while(0)

#define MS_show(x) \
    if( S_check(x) )\
    {\
        S_show(x);\
    }\
    else\
    {\
        M_show(x);\
    }

#endif//__MODBUS_SHOW_H__

