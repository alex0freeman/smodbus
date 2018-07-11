# smodbus
A simple implementation of modbus, written by pure C code

# 文件说明
## modbus-frame.h
用宏封装了0x01、0x02、0x03、0x04、0x05、0x06、0x0f、0x10这几条指令
## modbus-frome.c
实现了modbus crc计算函数
## modbus-show.h
彩色打印modbus数据帧
## color.h
色彩定义

```c
#include <stdio.h>
#include "modbus-show.h"

#define showhex(x) \
    do{\
        printf("\n%s(%d):", __func__, MS_check(x));\
        MS_show(x);\
    }while(0)

//test slaver
void test_slaver_x01(void)
{
    union modbus_frame x;

    S1_set_slave(x,1);
    S1_set_fcode(x);
    S1_set_offset(x,0);
    S1_set_count(x,1);
    S1_fill_crc(x);

    showhex(x);
}
void test_slaver_x02(void)
{
    union modbus_frame x;

    S2_set_slave(x,1);
    S2_set_fcode(x);
    S2_set_offset(x,0);
    S2_set_count(x,1);
    S2_fill_crc(x);

    showhex(x);
}
void test_slaver_x03(void)
{
    union modbus_frame x;

    S3_set_slave(x,2);
    S3_set_fcode(x);
    S3_set_offset(x,0);
    S3_set_count(x,10);
    S3_fill_crc(x);

    showhex(x);
}
void test_slaver_x04(void)
{
    union modbus_frame x;

    S4_set_slave(x,1);
    S4_set_fcode(x);
    S4_set_offset(x,0);
    S4_set_count(x,1);
    S4_fill_crc(x);

    showhex(x);
}
void test_slaver_x05(void)
{
    union modbus_frame x;

    S5_set_slave(x,1);
    S5_set_fcode(x);
    S5_set_offset(x,0);
    S5_set_count(x,1);
    S5_fill_crc(x);

    showhex(x);
}
void test_slaver_x06(void)
{
    union modbus_frame x;

    S6_set_slave(x,1);
    S6_set_fcode(x);
    S6_set_offset(x,0);
    S6_set_count(x,1);
    S6_fill_crc(x);

    showhex(x);
}
void test_slaver_x0f(void)
{
    int i = 0;
    union modbus_frame x;

    S15_set_slave(x,1);
    S15_set_fcode(x);
    S15_set_offset(x,0);
    S15_set_bcount(x,11);
    for(i = 0; i < S15_count(x); i++)
    {
        S15_set_bit(x, i, i%8==0);
    }
    S15_fill_crc(x);

    showhex(x);
}
void test_slaver_x10(void)
{
    int i = 0;
    union modbus_frame x;

    S16_set_slave(x,1);
    S16_set_fcode(x);
    S16_set_offset(x,0);
    S16_set_bcount(x,8);
    for(i = 0; i < S16_count(x); i++)
    {
        S16_set_value(x, i, 0x2111 + i);
    }
    S15_fill_crc(x);

    showhex(x);
}

//test master
void test_master_x01(void)
{
    int i = 0;
    union modbus_frame x;

    M1_set_slave(x,1);
    M1_set_fcode(x);
    M1_set_count(x,98);
    for(i = 0; i < M1_count(x); i++)
    {
        M1_set_bit(x, i, i%11==10);
    }
    M1_fill_crc(x);

    showhex(x);
}
void test_master_x02(void)
{
    int i = 0;
    union modbus_frame x;

    M2_set_slave(x,1);
    M2_set_fcode(x);
    M2_set_count(x,91);
    for(i = 0; i < M2_count(x); i++)
    {
        M2_set_bit(x, i, i%8==7);
    }
    M2_fill_crc(x);

    showhex(x);
}
void test_master_x03(void)
{
    int i = 0;
    union modbus_frame x;

    M3_set_slave(x,1);
    M3_set_fcode(x);
    M3_set_count(x,5);
    for(i = 0; i < M3_count(x); i++)
    {
        M3_set_value(x, i, 0x1234);
    }
    M3_fill_crc(x);

    showhex(x);
}
void test_master_x04(void)
{
    int i = 0;
    union modbus_frame x;

    M4_set_slave(x,1);
    M4_set_fcode(x);
    M4_set_count(x,7);
    for(i = 0; i < M4_count(x); i++)
    {
        M4_set_value(x, i, 0x9999);
    }
    M4_fill_crc(x);

    showhex(x);
}
void test_master_x05(void)
{
    union modbus_frame x;

    M5_set_slave(x,1);
    M5_set_fcode(x);
    M5_set_offset(x,0);
    M5_set_count(x,1);
    M5_fill_crc(x);

    showhex(x);
}
void test_master_x06(void)
{
    union modbus_frame x;

    M6_set_slave(x,1);
    M6_set_fcode(x);
    M6_set_offset(x,0);
    M6_set_count(x,1);
    M6_fill_crc(x);

    showhex(x);
}
void test_master_x0f(void)
{
    union modbus_frame x;

    M15_set_slave(x,1);
    M15_set_fcode(x);
    M15_set_offset(x,0);
    M15_set_count(x,2);
    M15_fill_crc(x);

    showhex(x);
}
void test_master_x10(void)
{
    union modbus_frame x;

    M16_set_slave(x,1);
    M16_set_fcode(x);
    M16_set_offset(x,0);
    M16_set_count(x,8);
    M15_fill_crc(x);

    showhex(x);
}

int main(void)
{
    test_slaver_x01();
    test_slaver_x02();
    test_slaver_x03();
    test_slaver_x04();
    test_slaver_x05();
    test_slaver_x06();
    test_slaver_x0f();
    test_slaver_x10();
    printf("\n");
    test_master_x01();
    test_master_x02();
    test_master_x03();
    test_master_x04();
    test_master_x05();
    test_master_x06();
    test_master_x0f();
    test_master_x10();

    return 0;
}
```c

