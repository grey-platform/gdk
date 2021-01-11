#ifndef __COMPARENUMBER_H__
#define __COMPARENUMBER_H__

#include <include/stdtype.h>
#include <bignumber/bignumber.h>

class CCompareNumber{
public:
    static int Compare( CBigNumber* one, CBigNumber* two );
    static int ComparePlus( CBigNumber* one, CBigNumber* two );
};


#endif

