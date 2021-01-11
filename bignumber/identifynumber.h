#ifndef __IDENTIFYNUMBER_H__
#define __IDENTIFYNUMBER_H__

#include <include/stdtype.h>
#include <bignumber/bignumberconfig.h>

class CIdentifyNumber{
public:
    static bool GetBigNumber( const char* text, TNumberList &intPart, TNumberList &decimalPart );
    static void ValidateNumber( const char* text );
    static int CharToInt( char p );
    static char IntToChar( int n );

};


#endif
