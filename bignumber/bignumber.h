#ifndef __BIGNUMBER_H__
#define __BIGNUMBER_H__

#include <include/stdtype.h>
#include <bignumber/bignumberconfig.h>

class CBigNumber{
public:
    //static CBigNumber Zero();
    CBigNumber();
    CBigNumber( const char* text );
    CBigNumber( const TNumberList &i, const TNumberList &d, bool plus );
    //
    int IntLength();
    //
    int DecimalLength();
    int CompareTo( CBigNumber *other );
    bool IsZero();
    void SetValue( const char* strText );
    char* GetText( char* strText );

    CBigNumber& operator=( const CBigNumber& cls );
    CBigNumber& operator += ( const CBigNumber& rhs );
    CBigNumber& operator -= ( const CBigNumber& rhs );
    CBigNumber& operator-();

public:
    //
    TNumberList intPart;
    TNumberList decimalPart;
    bool isPlus;
};

CBigNumber operator +( const CBigNumber& a, const CBigNumber& b );
CBigNumber operator -( const CBigNumber& a, const CBigNumber& b );
CBigNumber operator *( const CBigNumber& a, const CBigNumber& b );
CBigNumber operator /( const CBigNumber& a, const CBigNumber& b );


#endif
