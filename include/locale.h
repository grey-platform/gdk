/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: locale.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_LOCALE_H__
#define __GRAY_SDK_LOCALE_H__

#include <include/stdtype.h>

#define localeconv ___localeconv___

struct _lconv{
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
};


EXTERN struct _lconv *___localeconv___( void );

#endif