#ifndef __MODBUS_FRAME_H__
#define __MODBUS_FRAME_H__

//utils
#define xbit(x)           ( *(struct  bit*)&(x) )
#define xword(x)          ( *(struct word*)&(x) )
#define xbyte(x)          ( *(unsigned char*)&(x) )
#define hig_byte(x)       ( (unsigned  char)((0xff00 & (x)) >> 8) )
#define low_byte(x)       ( (unsigned  char)((0x00ff & (x)) >> 0) )
#define hig_word(x)       ( (unsigned short)((0x00ff & (x)) << 8) )
#define low_word(x)       ( (unsigned short)((0x00ff & (x)) << 0) )
#define set_word(x,v)     ( (xword(x).h = hig_byte(v)) + (xword(x).l = low_byte(v)) )
#define get_word(x)       ( hig_word(xword(x).h) | low_word(xword(x).l) )
#define get_crc(x)        ( hig_word(xword(x).h) | low_word(xword(x).l) )
#define set_crc(x,v)      ( set_word(x,v) )

//bit operate
#define bit_index(i)      ( ((i) / 8) )
#define bit_offset(i)     ( ((i) % 8) )
#define get_bit(x,i)      ( (xbyte(x) >> bit_offset(i)) & 1 )
#define set_bit(x,i,v)    ( (v) ? (xbyte(x) |= (1 << bit_offset(i))) : (xbyte(x) &= ~(1 << bit_offset(i))) )

//slaver struct macro
#define S1(x)             ((x).slaverx01)
#define S2(x)             ((x).slaverx02)
#define S3(x)             ((x).slaverx03)
#define S4(x)             ((x).slaverx04)
#define S5(x)             ((x).slaverx05)
#define S6(x)             ((x).slaverx06)
#define S6(x)             ((x).slaverx06)
#define S15(x)            ((x).slaverx0f)
#define S16(x)            ((x).slaverx10)

//master struct macro
#define M1(x)             ((x).masterx01)
#define M2(x)             ((x).masterx02)
#define M3(x)             ((x).masterx03)
#define M4(x)             ((x).masterx04)
#define M5(x)             ((x).masterx05)
#define M6(x)             ((x).masterx06)
#define M6(x)             ((x).masterx06)
#define M15(x)            ((x).masterx0f)
#define M16(x)            ((x).masterx10)

/*============================== get slaver =================================*/

//get slave
#define S1_slave(x)       ( S1(x).slave )
#define S1_fcode(x)       ( S1(x).fcode )
#define S1_offset(x)      ( get_word(S1(x).offset) )
#define S1_count(x)       ( get_word(S1(x).count) )

#define S2_slave(x)       ( S2(x).slave )
#define S2_fcode(x)       ( S2(x).fcode )
#define S2_offset(x)      ( get_word(S2(x).offset) )
#define S2_count(x)       ( get_word(S2(x).count) )

#define S3_slave(x)       ( S3(x).slave )
#define S3_fcode(x)       ( S3(x).fcode )
#define S3_offset(x)      ( get_word(S3(x).offset) )
#define S3_count(x)       ( get_word(S3(x).count) )

#define S4_slave(x)       ( S4(x).slave )
#define S4_fcode(x)       ( S4(x).fcode )
#define S4_offset(x)      ( get_word(S4(x).offset) )
#define S4_count(x)       ( get_word(S4(x).count) )

#define S5_slave(x)       ( S5(x).slave )
#define S5_fcode(x)       ( S5(x).fcode )
#define S5_offset(x)      ( get_word(S5(x).offset) )
#define S5_count(x)       ( get_word(S5(x).count) )

#define S6_slave(x)       ( S6(x).slave )
#define S6_fcode(x)       ( S6(x).fcode )
#define S6_offset(x)      ( get_word(S6(x).offset) )
#define S6_count(x)       ( get_word(S6(x).count) )

#define S15_slave(x)      ( S15(x).slave )
#define S15_fcode(x)      ( S15(x).fcode )
#define S15_offset(x)     ( get_word(S15(x).offset) )
#define S15_count(x)      ( S15(x).bcount * 8 )
#define S15_bcount(x)     ( S15(x).bcount )

#define S16_slave(x)      ( S16(x).slave )
#define S16_fcode(x)      ( S16(x).fcode )
#define S16_offset(x)     ( get_word(S16(x).offset) )
#define S16_count(x)      ( S16(x).bcount / 2 )
#define S16_bcount(x)     ( S16(x).bcount )

/*============================== set slaver ====================================*/

//set slave
#define S1_set_slave(x,v)     ( S1(x).slave = 0xff & (v) )
#define S1_set_fcode(x)       ( S1(x).fcode = 0xff & (1) )
#define S1_set_offset(x,v)    ( set_word(S1(x).offset, v) )
#define S1_set_count(x,v)     ( set_word(S1(x).count, v)  )

#define S2_set_slave(x,v)     ( S2(x).slave = 0xff & (v) )
#define S2_set_fcode(x)       ( S2(x).fcode = 0xff & (2) )
#define S2_set_offset(x,v)    ( set_word(S2(x).offset, v) )
#define S2_set_count(x,v)     ( set_word(S2(x).count, v)  )

#define S3_set_slave(x,v)     ( S3(x).slave = 0xff & (v) )
#define S3_set_fcode(x)       ( S3(x).fcode = 0xff & (3) )
#define S3_set_offset(x,v)    ( set_word(S3(x).offset, v) )
#define S3_set_count(x,v)     ( set_word(S3(x).count, v)  )

#define S4_set_slave(x,v)     ( S4(x).slave = 0xff & (v) )
#define S4_set_fcode(x)       ( S4(x).fcode = 0xff & (4) )
#define S4_set_offset(x,v)    ( set_word(S4(x).offset, v) )
#define S4_set_count(x,v)     ( set_word(S4(x).count, v)  )

#define S5_set_slave(x,v)     ( S5(x).slave = 0xff & (v) )
#define S5_set_fcode(x)       ( S5(x).fcode = 0xff & (5) )
#define S5_set_offset(x,v)    ( set_word(S5(x).offset, v) )
#define S5_set_count(x,v)     ( set_word(S5(x).count, v)  )

#define S6_set_slave(x,v)     ( S6(x).slave = 0xff & (v) )
#define S6_set_fcode(x)       ( S6(x).fcode = 0xff & (6) )
#define S6_set_offset(x,v)    ( set_word(S6(x).offset, v) )
#define S6_set_count(x,v)     ( set_word(S6(x).count, v)  )

#define S15_set_slave(x,v)    ( S15(x).slave = 0xff & (v)  )
#define S15_set_fcode(x)      ( S15(x).fcode = 0xff & (15) )
#define S15_set_offset(x,v)   ( set_word(S15(x).offset, v) )
#define S15_set_bcount(x,v)   ( S15(x).bcount = 0xff & (v) )
#define S15_set_count(x,v)    ( S15(x).bcount = 0xff & (bit_index(v) + !!bit_offset(v)) )
#define S15_set_bit(x,i,v)    ( set_bit(S15(x).value[bit_index(i)], i, v) )

#define S16_set_slave(x,v)    ( S16(x).slave = 0xff & (v)  )
#define S16_set_fcode(x)      ( S16(x).fcode = 0xff & (16) )
#define S16_set_offset(x,v)   ( set_word(S16(x).offset, v) )
#define S16_set_bcount(x,v)   ( S16(x).bcount = 0xff & (v) )
#define S16_set_count(x,v)    ( S16(x).bcount = 0xff & ((v) * 2) )
#define S16_set_value(x,i,v)  ( set_word(S16(x).value[i], v) )

//slaver get len
#define S1_len(x)             ( 1 + 1 + 2 + 2 + 2 )
#define S2_len(x)             ( 1 + 1 + 2 + 2 + 2 )
#define S3_len(x)             ( 1 + 1 + 2 + 2 + 2 )
#define S4_len(x)             ( 1 + 1 + 2 + 2 + 2 )
#define S5_len(x)             ( 1 + 1 + 2 + 2 + 2 )
#define S6_len(x)             ( 1 + 1 + 2 + 2 + 2 )
#define S15_len(x)            ( 1 + 1 + 2 + 1 + S15_bcount(x) + 2 )
#define S16_len(x)            ( 1 + 1 + 2 + 1 + S16_bcount(x) + 2 )

//slaver crc position
#define S1_crcp(x)            ( S1(x).crc )
#define S2_crcp(x)            ( S2(x).crc )
#define S3_crcp(x)            ( S3(x).crc )
#define S4_crcp(x)            ( S4(x).crc )
#define S5_crcp(x)            ( S5(x).crc )
#define S6_crcp(x)            ( S6(x).crc )
#define S15_crcp(x)           ( xword(S15(x).value[S15_bcount(x)]) )
#define S16_crcp(x)           ( xword(S16(x).value[S16_count(x)]) )

//slaver get crc value
#define S1_crc(x)             ( get_crc(S1_crcp(x))  )
#define S2_crc(x)             ( get_crc(S2_crcp(x))  )
#define S3_crc(x)             ( get_crc(S3_crcp(x))  )
#define S4_crc(x)             ( get_crc(S4_crcp(x))  )
#define S5_crc(x)             ( get_crc(S5_crcp(x))  )
#define S6_crc(x)             ( get_crc(S6_crcp(x))  )
#define S15_crc(x)            ( get_crc(S15_crcp(x)) )
#define S16_crc(x)            ( get_crc(S16_crcp(x)) )

//slaver fill crc macro
#define S1_calc(x)            ( modbus_crc((x).data, S1_len(x)-2)  )
#define S2_calc(x)            ( modbus_crc((x).data, S2_len(x)-2)  )
#define S3_calc(x)            ( modbus_crc((x).data, S3_len(x)-2)  )
#define S4_calc(x)            ( modbus_crc((x).data, S4_len(x)-2)  )
#define S5_calc(x)            ( modbus_crc((x).data, S5_len(x)-2)  )
#define S6_calc(x)            ( modbus_crc((x).data, S6_len(x)-2)  )
#define S15_calc(x)           ( modbus_crc((x).data, S15_len(x)-2) )
#define S16_calc(x)           ( modbus_crc((x).data, S16_len(x)-2) )

//slaver fill crc
#define S1_fill_crc(x)        ( set_crc(S1_crcp(x), S1_calc(x))   )
#define S2_fill_crc(x)        ( set_crc(S2_crcp(x), S2_calc(x))   )
#define S3_fill_crc(x)        ( set_crc(S3_crcp(x), S3_calc(x))   )
#define S4_fill_crc(x)        ( set_crc(S4_crcp(x), S4_calc(x))   )
#define S5_fill_crc(x)        ( set_crc(S5_crcp(x), S5_calc(x))   )
#define S6_fill_crc(x)        ( set_crc(S6_crcp(x), S6_calc(x))   )
#define S15_fill_crc(x)       ( set_crc(S15_crcp(x), S15_calc(x)) )
#define S16_fill_crc(x)       ( set_crc(S16_crcp(x), S16_calc(x)) )

//slaver common
#define S_len(x) (\
        (S1_fcode(x) == 1) ? (S1_len(x)) : \
        (S2_fcode(x) == 2) ? (S2_len(x)) : \
        (S3_fcode(x) == 3) ? (S3_len(x)) : \
        (S4_fcode(x) == 4) ? (S4_len(x)) : \
        (S5_fcode(x) == 5) ? (S5_len(x)) : \
        (S6_fcode(x) == 6) ? (S6_len(x)) : \
        (S15_fcode(x) == 15) ? (S15_len(x)) : \
        (S16_fcode(x) == 16) ? (S16_len(x)) : 0)

#define S_crc(x) (\
        (S1_fcode(x) == 1) ? (S1_crc(x)) : \
        (S2_fcode(x) == 2) ? (S2_crc(x)) : \
        (S3_fcode(x) == 3) ? (S3_crc(x)) : \
        (S4_fcode(x) == 4) ? (S4_crc(x)) : \
        (S5_fcode(x) == 5) ? (S5_crc(x)) : \
        (S6_fcode(x) == 6) ? (S6_crc(x)) : \
        (S15_fcode(x) == 15) ? (S15_crc(x)) : \
        (S16_fcode(x) == 16) ? (S16_crc(x)) : 0)

#define S_calc(x) (\
        (S1_fcode(x) == 1) ? (S1_calc(x)) : \
        (S2_fcode(x) == 2) ? (S2_calc(x)) : \
        (S3_fcode(x) == 3) ? (S3_calc(x)) : \
        (S4_fcode(x) == 4) ? (S4_calc(x)) : \
        (S5_fcode(x) == 5) ? (S5_calc(x)) : \
        (S6_fcode(x) == 6) ? (S6_calc(x)) : \
        (S15_fcode(x) == 15) ? (S15_calc(x)) : \
        (S16_fcode(x) == 16) ? (S16_calc(x)) : 0)

#define S_check(x) (\
        (S1_fcode(x) == 1) ? (S1_crc(x) == S1_calc(x)) : \
        (S2_fcode(x) == 2) ? (S2_crc(x) == S2_calc(x)) : \
        (S3_fcode(x) == 3) ? (S3_crc(x) == S3_calc(x)) : \
        (S4_fcode(x) == 4) ? (S4_crc(x) == S4_calc(x)) : \
        (S5_fcode(x) == 5) ? (S5_crc(x) == S5_calc(x)) : \
        (S6_fcode(x) == 6) ? (S6_crc(x) == S6_calc(x)) : \
        (S15_fcode(x) == 15) ? (S15_crc(x) == S15_calc(x)) : \
        (S16_fcode(x) == 16) ? (S16_crc(x) == S16_calc(x)) : 0)
/*============================== get master =================================*/

//get slave
#define M1_slave(x)       ( M1(x).slave )
#define M1_fcode(x)       ( M1(x).fcode )
#define M1_count(x)       ( M1(x).bcount * 8 )
#define M1_bcount(x)      ( M1(x).bcount )
#define M1_get_bit(x,i)   ( get_bit(M1(x).value[bit_index(i)], i) )

#define M2_slave(x)       ( M2(x).slave )
#define M2_fcode(x)       ( M2(x).fcode )
#define M2_count(x)       ( M2(x).bcount * 8 )
#define M2_bcount(x)      ( M2(x).bcount )
#define M2_get_bit(x,i)   ( get_bit(M2(x).value[bit_index(i)], i) )

#define M3_slave(x)       ( M3(x).slave )
#define M3_fcode(x)       ( M3(x).fcode )
#define M3_count(x)       ( M3(x).bcount / 2 )
#define M3_bcount(x)      ( M3(x).bcount )
#define M3_get_value(x,i) ( get_word(M3(x).value[i]) )

#define M4_slave(x)       ( M4(x).slave )
#define M4_fcode(x)       ( M4(x).fcode )
#define M4_count(x)       ( M4(x).bcount / 2 )
#define M4_bcount(x)      ( M4(x).bcount )
#define M4_get_value(x,i) ( get_word(M4(x).value[i]) )

#define M5_slave(x)       ( M5(x).slave )
#define M5_fcode(x)       ( M5(x).fcode )
#define M5_offset(x)      ( get_word(M5(x).offset) )
#define M5_count(x)       ( get_word(M5(x).count) )

#define M6_slave(x)       ( M6(x).slave )
#define M6_fcode(x)       ( M6(x).fcode )
#define M6_offset(x)      ( get_word(M6(x).offset) )
#define M6_count(x)       ( get_word(M6(x).count) )

#define M15_slave(x)      ( M15(x).slave )
#define M15_fcode(x)      ( M15(x).fcode )
#define M15_offset(x)     ( get_word(M15(x).offset) )
#define M15_count(x)      ( get_word(M15(x).count) )

#define M16_slave(x)      ( M16(x).slave )
#define M16_fcode(x)      ( M16(x).fcode )
#define M16_offset(x)     ( get_word(M16(x).offset) )
#define M16_count(x)      ( get_word(M16(x).count) )

/*======================= set master =========================*/

//set slave
#define M1_set_slave(x,v)    ( M1(x).slave   = 0xff & (v) )
#define M1_set_fcode(x)      ( M1(x).fcode   = 0xff & (1) )
#define M1_set_count(x,v)    ( M1(x).bcount  = 0xff & (bit_index(v) + !!bit_offset(v)) )
#define M1_set_bcount(x,v)   ( M1(x).bcount  = 0xff & (v) )
#define M1_set_bit(x,i,v)    ( set_bit(M1(x).value[bit_index(i)], i, v) )

#define M2_set_slave(x,v)    ( M2(x).slave   = 0xff & (v) )
#define M2_set_fcode(x)      ( M2(x).fcode   = 0xff & (2) )
#define M2_set_count(x,v)    ( M2(x).bcount  = 0xff & (bit_index(v) + !!bit_offset(v)) )
#define M2_set_bcount(x,v)   ( M2(x).bcount  = 0xff & (v) )
#define M2_set_bit(x,i,v)    ( set_bit(M2(x).value[bit_index(i)], i, v) )

#define M3_set_slave(x,v)    ( M3(x).slave   = 0xff & (v)  )
#define M3_set_fcode(x)      ( M3(x).fcode   = 0xff & (3)  )
#define M3_set_count(x,v)    ( M3(x).bcount  = 0xff & ((v)*2)  )
#define M3_set_bcount(x,v)   ( M3(x).bcount  = 0xff & (v)  )
#define M3_set_value(x,i,v)  ( set_word(M3(x).value[i], v) )

#define M4_set_slave(x,v)    ( M4(x).slave   = 0xff & (v)  )
#define M4_set_fcode(x)      ( M4(x).fcode   = 0xff & (4)  )
#define M4_set_count(x,v)    ( M4(x).bcount  = 0xff & ((v)*2)  )
#define M4_set_bcount(x,v)   ( M4(x).bcount  = 0xff & (v)  )
#define M4_set_value(x,i,v)  ( set_word(M4(x).value[i], v) )

#define M5_set_slave(x,v)    ( M5(x).slave  = 0xff & (v) )
#define M5_set_fcode(x)      ( M5(x).fcode  = 0xff & (5) )
#define M5_set_offset(x,v)   ( set_word(M5(x).offset, v) )
#define M5_set_count(x,v)    ( set_word(M5(x).count,  v) )

#define M6_set_slave(x,v)    ( M6(x).slave  = 0xff & (v) )
#define M6_set_fcode(x)      ( M6(x).fcode  = 0xff & (6) )
#define M6_set_offset(x,v)   ( set_word(M6(x).offset, v) )
#define M6_set_count(x,v)    ( set_word(M6(x).count,  v) )

#define M15_set_slave(x,v)   ( M15(x).slave = 0xff & (v)  )
#define M15_set_fcode(x)     ( M15(x).fcode = 0xff & (15) )
#define M15_set_offset(x,v)  ( set_word(M15(x).offset, v) )
#define M15_set_count(x,v)   ( set_word(M15(x).count,  v) )

#define M16_set_slave(x,v)   ( M16(x).slave = 0xff & (v)  )
#define M16_set_fcode(x)     ( M16(x).fcode = 0xff & (16) )
#define M16_set_offset(x,v)  ( set_word(M16(x).offset, v) )
#define M16_set_count(x,v)   ( set_word(M16(x).count,  v) )

//master get len
#define M1_len(x)            ( 1 + 1 + 1 + M1_bcount(x) + 2 )
#define M2_len(x)            ( 1 + 1 + 1 + M2_bcount(x) + 2 )
#define M3_len(x)            ( 1 + 1 + 1 + M3_bcount(x) + 2 )
#define M4_len(x)            ( 1 + 1 + 1 + M4_bcount(x) + 2 )
#define M5_len(x)            ( 1 + 1 + 2 + 2 + 2 )
#define M6_len(x)            ( 1 + 1 + 2 + 2 + 2 )
#define M15_len(x)           ( 1 + 1 + 2 + 2 + 2 )
#define M16_len(x)           ( 1 + 1 + 2 + 2 + 2 )

//master crc position
#define M1_crcp(x)           ( xword(M1(x).value[M1(x).bcount]) )
#define M2_crcp(x)           ( xword(M2(x).value[M2(x).bcount]) )
#define M3_crcp(x)           ( xword(M3(x).value[M3_count(x)]) )
#define M4_crcp(x)           ( xword(M4(x).value[M4_count(x)]) )
#define M5_crcp(x)           ( xword(M5(x).crc)  )
#define M6_crcp(x)           ( xword(M6(x).crc)  )
#define M15_crcp(x)          ( xword(M15(x).crc) )
#define M16_crcp(x)          ( xword(M16(x).crc) )

//master get crc value
#define M1_crc(x)            ( get_crc(M1_crcp(x))  )
#define M2_crc(x)            ( get_crc(M2_crcp(x))  )
#define M3_crc(x)            ( get_crc(M3_crcp(x))  )
#define M4_crc(x)            ( get_crc(M4_crcp(x))  )
#define M5_crc(x)            ( get_crc(M5_crcp(x))  )
#define M6_crc(x)            ( get_crc(M5_crcp(x))  )
#define M15_crc(x)           ( get_crc(M15_crcp(x)) )
#define M16_crc(x)           ( get_crc(M16_crcp(x)) )

//master fill crc macro
#define M1_calc(x)           ( modbus_crc((x).data, M1_len(x)-2)  )
#define M2_calc(x)           ( modbus_crc((x).data, M2_len(x)-2)  )
#define M3_calc(x)           ( modbus_crc((x).data, M3_len(x)-2)  )
#define M4_calc(x)           ( modbus_crc((x).data, M4_len(x)-2)  )
#define M5_calc(x)           ( modbus_crc((x).data, M5_len(x)-2)  )
#define M6_calc(x)           ( modbus_crc((x).data, M6_len(x)-2)  )
#define M15_calc(x)          ( modbus_crc((x).data, M15_len(x)-2) )
#define M16_calc(x)          ( modbus_crc((x).data, M16_len(x)-2) )

//master fill crc
#define M1_fill_crc(x)       ( set_crc(M1_crcp(x), M1_calc(x))  )
#define M2_fill_crc(x)       ( set_crc(M2_crcp(x), M2_calc(x))  )
#define M3_fill_crc(x)       ( set_crc(M3_crcp(x), M3_calc(x))  )
#define M4_fill_crc(x)       ( set_crc(M4_crcp(x), M4_calc(x))  )
#define M5_fill_crc(x)       ( set_crc(M5_crcp(x), M5_calc(x))  )
#define M6_fill_crc(x)       ( set_crc(M6_crcp(x), M6_calc(x))  )
#define M15_fill_crc(x)      ( set_crc(M15_crcp(x), M15_calc(x)) )
#define M16_fill_crc(x)      ( set_crc(M16_crcp(x), M16_calc(x)) )

//master common
#define M_len(x) (\
        (M1_fcode(x) == 1) ? (M1_len(x)) : \
        (M2_fcode(x) == 2) ? (M2_len(x)) : \
        (M3_fcode(x) == 3) ? (M3_len(x)) : \
        (M4_fcode(x) == 4) ? (M4_len(x)) : \
        (M5_fcode(x) == 5) ? (M5_len(x)) : \
        (M6_fcode(x) == 6) ? (M6_len(x)) : \
        (M15_fcode(x) == 15) ? (M15_len(x)) : \
        (M16_fcode(x) == 16) ? (M16_len(x)) : 0)

#define M_crc(x) (\
        (M1_fcode(x) == 1) ? (M1_crc(x)) : \
        (M2_fcode(x) == 2) ? (M2_crc(x)) : \
        (M3_fcode(x) == 3) ? (M3_crc(x)) : \
        (M4_fcode(x) == 4) ? (M4_crc(x)) : \
        (M5_fcode(x) == 5) ? (M5_crc(x)) : \
        (M6_fcode(x) == 6) ? (M6_crc(x)) : \
        (M15_fcode(x) == 15) ? (M15_crc(x)) : \
        (M16_fcode(x) == 16) ? (M16_crc(x)) : 0)

#define M_calc(x) (\
        (M1_fcode(x) == 1) ? (M1_calc(x)) : \
        (M2_fcode(x) == 2) ? (M2_calc(x)) : \
        (M3_fcode(x) == 3) ? (M3_calc(x)) : \
        (M4_fcode(x) == 4) ? (M4_calc(x)) : \
        (M5_fcode(x) == 5) ? (M5_calc(x)) : \
        (M6_fcode(x) == 6) ? (M6_calc(x)) : \
        (M15_fcode(x) == 15) ? (M15_calc(x)) : \
        (M16_fcode(x) == 16) ? (M16_calc(x)) : 0)

#define M_check(x) (\
        (M1_fcode(x) == 1) ? (M1_crc(x) == M1_calc(x)) : \
        (M2_fcode(x) == 2) ? (M2_crc(x) == M2_calc(x)) : \
        (M3_fcode(x) == 3) ? (M3_crc(x) == M3_calc(x)) : \
        (M4_fcode(x) == 4) ? (M4_crc(x) == M4_calc(x)) : \
        (M5_fcode(x) == 5) ? (M5_crc(x) == M5_calc(x)) : \
        (M6_fcode(x) == 6) ? (M6_crc(x) == M6_calc(x)) : \
        (M15_fcode(x) == 15) ? (M15_crc(x) == M15_calc(x)) : \
        (M16_fcode(x) == 16) ? (M16_crc(x) == M16_calc(x)) : 0)

//master slaver common
#define MS_len(x)    ( M_check(x) ? M_len(x)  : S_len(x)  )
#define MS_crc(x)    ( M_check(x) ? M_crc(x)  : S_crc(x)  )
#define MS_calc(x)   ( M_check(x) ? M_calc(x) : S_calc(x) )
#define MS_check(x)  ( M_check(x) | S_check(x) )

/*============================== frame struct =============================*/

//base struct
struct bit
{
    unsigned char bit7:1;
    unsigned char bit6:1;
    unsigned char bit5:1;
    unsigned char bit4:1;
    unsigned char bit3:1;
    unsigned char bit2:1;
    unsigned char bit1:1;
    unsigned char bit0:1;
};
struct word
{
    unsigned char h;
    unsigned char l;
};

//slaver frame
struct slaverx01
{
    unsigned char slave;
    unsigned char fcode;
    struct word offset;
    struct word count;
    struct word crc;
};
struct slaverx0f
{
    unsigned char slave;
    unsigned char fcode;
    struct word offset;
    unsigned char bcount;
    struct bit value[1];
};
struct slaverx10
{
    unsigned char slave;
    unsigned char fcode;
    struct word offset;
    unsigned char bcount;
    struct word value[1];
};
typedef struct slaverx01 slaverx01_t;
typedef struct slaverx01 slaverx02_t;
typedef struct slaverx01 slaverx03_t;
typedef struct slaverx01 slaverx04_t;
typedef struct slaverx01 slaverx05_t;
typedef struct slaverx01 slaverx06_t;
typedef struct slaverx0f slaverx0f_t;
typedef struct slaverx10 slaverx10_t;

//master frame
struct masterx01
{
    unsigned char slave;
    unsigned char fcode;
    unsigned char bcount;
    struct bit value[1];
};
struct masterx03
{
    unsigned char slave;
    unsigned char fcode;
    unsigned char bcount;
    struct word value[1];
};
struct masterx05
{
    unsigned char slave;
    unsigned char fcode;
    struct word offset;
    struct word count;
    struct word crc;
};
typedef struct masterx01 masterx01_t;
typedef struct masterx01 masterx02_t;
typedef struct masterx03 masterx03_t;
typedef struct masterx03 masterx04_t;
typedef struct masterx05 masterx05_t;
typedef struct masterx05 masterx06_t;
typedef struct masterx05 masterx0f_t;
typedef struct masterx05 masterx10_t;

//modbus frame
typedef union modbus_frame
{
    unsigned char data[256];

    slaverx01_t  slaverx01;
    slaverx02_t  slaverx02;
    slaverx03_t  slaverx03;
    slaverx04_t  slaverx04;
    slaverx05_t  slaverx05;
    slaverx06_t  slaverx06;
    slaverx0f_t  slaverx0f;
    slaverx10_t  slaverx10;

    masterx01_t  masterx01;
    masterx02_t  masterx02;
    masterx03_t  masterx03;
    masterx04_t  masterx04;
    masterx05_t  masterx05;
    masterx06_t  masterx06;
    masterx0f_t  masterx0f;
    masterx10_t  masterx10;
}modbus_frame_t;

unsigned short modbus_crc(unsigned char*, unsigned short); 

#endif//__MODBUS_FRAME_H__

