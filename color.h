#ifndef __COLOR_H__
#define __COLOR_H__

//foreground color
#define color_black              "\033[0;30m"
#define color_red                "\033[0;31m"
#define color_green              "\033[0;32m"
#define color_yellow             "\033[0;33m"
#define color_blue               "\033[0;34m"
#define color_purple             "\033[0;35m"
#define color_cyan               "\033[0;36m"
#define color_white              "\033[0;37m"

//foreground bold
#define color_bd_black           "\033[1;30m"
#define color_bd_red             "\033[1;31m"
#define color_bd_green           "\033[1;32m"
#define color_bd_yellow          "\033[1;33m"
#define color_bd_blue            "\033[1;34m"
#define color_bd_purple          "\033[1;35m"
#define color_bd_cyan            "\033[1;36m"
#define color_bd_white           "\033[1;37m"

//under line
#define color_ul_black           "\033[4;30m"
#define color_ul_red             "\033[4;31m"
#define color_ul_green           "\033[4;32m"
#define color_ul_yellow          "\033[4;33m"
#define color_ul_blue            "\033[4;34m"
#define color_ul_purple          "\033[4;35m"
#define color_ul_cyan            "\033[4;36m"
#define color_ul_white           "\033[4;37m"

//back ground color
#define color_bg_black           "\033[40m"
#define color_bg_red             "\033[41m"
#define color_bg_green           "\033[42m"
#define color_bg_yellow          "\033[43m"
#define color_bg_blue            "\033[44m"
#define color_bg_purple          "\033[45m"
#define color_bg_cyan            "\033[46m"
#define color_bg_white           "\033[47m"

//high intensity
#define color_hi_black           "\033[0;90m"
#define color_hi_red             "\033[0;91m"
#define color_hi_green           "\033[0;92m"
#define color_hi_yellow          "\033[0;93m"
#define color_hi_blue            "\033[0;94m"
#define color_hi_purple          "\033[0;95m"
#define color_hi_cyan            "\033[0;96m"
#define color_hi_white           "\033[0;97m"

//bold high intensity
#define color_bi_black           "\033[1;90m"
#define color_bi_red             "\033[1;91m"
#define color_bi_green           "\033[1;92m"
#define color_bi_yellow          "\033[1;93m"
#define color_bi_blue            "\033[1;94m"
#define color_bi_purple          "\033[1;95m"
#define color_bi_cyan            "\033[1;96m"
#define color_bi_white           "\033[1;97m"

//high intensity background
#define color_hb_black           "\033[0;100m"
#define color_hb_red             "\033[0;101m"
#define color_hb_green           "\033[0;102m"
#define color_hb_yellow          "\033[0;103m"
#define color_hb_blue            "\033[0;104m"
#define color_hb_purple          "\033[0;105m"
#define color_hb_cyan            "\033[0;106m"
#define color_hb_white           "\033[0;107m"

//end
#define color_end                "\033[m"

//printf foreground
#define printf_black(fmt,...)        printf(color_black   fmt  color_end, ##__VA_ARGS__)
#define printf_red(fmt,...)          printf(color_red     fmt  color_end, ##__VA_ARGS__)
#define printf_green(fmt,...)        printf(color_green   fmt  color_end, ##__VA_ARGS__)
#define printf_yellow(fmt,...)       printf(color_yellow  fmt  color_end, ##__VA_ARGS__)
#define printf_blue(fmt,...)         printf(color_blue    fmt  color_end, ##__VA_ARGS__)
#define printf_purple(fmt,...)       printf(color_purple  fmt  color_end, ##__VA_ARGS__)
#define printf_cyan(fmt,...)         printf(color_cyan    fmt  color_end, ##__VA_ARGS__)
#define printf_white(fmt,...)        printf(color_white   fmt  color_end, ##__VA_ARGS__)

//printf bold
#define printf_bd_black(fmt,...)      printf(color_bd_black   fmt  color_end, ##__VA_ARGS__)
#define printf_bd_red(fmt,...)        printf(color_bd_red     fmt  color_end, ##__VA_ARGS__)
#define printf_bd_green(fmt,...)      printf(color_bd_green   fmt  color_end, ##__VA_ARGS__)
#define printf_bd_yellow(fmt,...)     printf(color_bd_yellow  fmt  color_end, ##__VA_ARGS__)
#define printf_bd_blue(fmt,...)       printf(color_bd_blue    fmt  color_end, ##__VA_ARGS__)
#define printf_bd_purple(fmt,...)     printf(color_bd_purple  fmt  color_end, ##__VA_ARGS__)
#define printf_bd_cyan(fmt,...)       printf(color_bd_cyan    fmt  color_end, ##__VA_ARGS__)
#define printf_bd_white(fmt,...)      printf(color_bd_white   fmt  color_end, ##__VA_ARGS__)

//printf under line
#define printf_ul_black(fmt,...)      printf(color_ul_black   fmt  color_end, ##__VA_ARGS__)
#define printf_ul_red(fmt,...)        printf(color_ul_red     fmt  color_end, ##__VA_ARGS__)
#define printf_ul_green(fmt,...)      printf(color_ul_green   fmt  color_end, ##__VA_ARGS__)
#define printf_ul_yellow(fmt,...)     printf(color_ul_yellow  fmt  color_end, ##__VA_ARGS__)
#define printf_ul_blue(fmt,...)       printf(color_ul_blue    fmt  color_end, ##__VA_ARGS__)
#define printf_ul_purple(fmt,...)     printf(color_ul_purple  fmt  color_end, ##__VA_ARGS__)
#define printf_ul_cyan(fmt,...)       printf(color_ul_cyan    fmt  color_end, ##__VA_ARGS__)
#define printf_ul_white(fmt,...)      printf(color_ul_white   fmt  color_end, ##__VA_ARGS__)

//printf background color
#define printf_bg_black(fmt,...)      printf(color_bg_black   fmt  color_end, ##__VA_ARGS__)
#define printf_bg_red(fmt,...)        printf(color_bg_red     fmt  color_end, ##__VA_ARGS__)
#define printf_bg_green(fmt,...)      printf(color_bg_green   fmt  color_end, ##__VA_ARGS__)
#define printf_bg_yellow(fmt,...)     printf(color_bg_yellow  fmt  color_end, ##__VA_ARGS__)
#define printf_bg_blue(fmt,...)       printf(color_bg_blue    fmt  color_end, ##__VA_ARGS__)
#define printf_bg_purple(fmt,...)     printf(color_bg_purple  fmt  color_end, ##__VA_ARGS__)
#define printf_bg_cyan(fmt,...)       printf(color_bg_cyan    fmt  color_end, ##__VA_ARGS__)
#define printf_bg_white(fmt,...)      printf(color_bg_white   fmt  color_end, ##__VA_ARGS__)

//printf high intensity
#define printf_hi_black(fmt,...)      printf(color_hi_black   fmt  color_end, ##__VA_ARGS__)
#define printf_hi_red(fmt,...)        printf(color_hi_red     fmt  color_end, ##__VA_ARGS__)
#define printf_hi_green(fmt,...)      printf(color_hi_green   fmt  color_end, ##__VA_ARGS__)
#define printf_hi_yellow(fmt,...)     printf(color_hi_yellow  fmt  color_end, ##__VA_ARGS__)
#define printf_hi_blue(fmt,...)       printf(color_hi_blue    fmt  color_end, ##__VA_ARGS__)
#define printf_hi_purple(fmt,...)     printf(color_hi_purple  fmt  color_end, ##__VA_ARGS__)
#define printf_hi_cyan(fmt,...)       printf(color_hi_cyan    fmt  color_end, ##__VA_ARGS__)
#define printf_hi_white(fmt,...)      printf(color_hi_white   fmt  color_end, ##__VA_ARGS__)

//printf bold high intensity
#define printf_bi_black(fmt,...)      printf(color_bi_black   fmt  color_end, ##__VA_ARGS__)
#define printf_bi_red(fmt,...)        printf(color_bi_red     fmt  color_end, ##__VA_ARGS__)
#define printf_bi_green(fmt,...)      printf(color_bi_green   fmt  color_end, ##__VA_ARGS__)
#define printf_bi_yellow(fmt,...)     printf(color_bi_yellow  fmt  color_end, ##__VA_ARGS__)
#define printf_bi_blue(fmt,...)       printf(color_bi_blue    fmt  color_end, ##__VA_ARGS__)
#define printf_bi_purple(fmt,...)     printf(color_bi_purple  fmt  color_end, ##__VA_ARGS__)
#define printf_bi_cyan(fmt,...)       printf(color_bi_cyan    fmt  color_end, ##__VA_ARGS__)
#define printf_bi_white(fmt,...)      printf(color_bi_white   fmt  color_end, ##__VA_ARGS__)

//printf high intensity background
#define printf_hb_black(fmt,...)      printf(color_hb_black   fmt  color_end, ##__VA_ARGS__)
#define printf_hb_red(fmt,...)        printf(color_hb_red     fmt  color_end, ##__VA_ARGS__)
#define printf_hb_green(fmt,...)      printf(color_hb_green   fmt  color_end, ##__VA_ARGS__)
#define printf_hb_yellow(fmt,...)     printf(color_hb_yellow  fmt  color_end, ##__VA_ARGS__)
#define printf_hb_blue(fmt,...)       printf(color_hb_blue    fmt  color_end, ##__VA_ARGS__)
#define printf_hb_purple(fmt,...)     printf(color_hb_purple  fmt  color_end, ##__VA_ARGS__)
#define printf_hb_cyan(fmt,...)       printf(color_hb_cyan    fmt  color_end, ##__VA_ARGS__)
#define printf_hb_white(fmt,...)      printf(color_hb_white   fmt  color_end, ##__VA_ARGS__)

#endif//__COLOR_H__

