#ifndef __BIGCALCULATE_H__
#define __BIGCALCULATE_H__

#include <include/stdtype.h>
#include <bignumber/bignumber.h>

class CBigCalculate{
public:
    static void RemoveStartZero( TNumberList *one );
    static void Add( CBigNumber *one, CBigNumber *two, CBigNumber *ret );
    static void Minus( CBigNumber *one, CBigNumber *two, CBigNumber *ret );

    static void PlusAdd( CBigNumber *one, CBigNumber *two, CBigNumber *ret );
    static int DecimalAdd( TNumberList *one, TNumberList *two, TNumberList *result );
    static void IntAdd( TNumberList *one, TNumberList *two, int intAdd, TNumberList *result );
    static void IntAddBigAddSmall( TNumberList *one, TNumberList *two, int intAdd, TNumberList *result );

    static void PlusMinus( CBigNumber *one, CBigNumber *two, CBigNumber *ret );
    static int DecimalMinus( TNumberList *one, TNumberList *two, TNumberList *result );
    static void IntMinus( TNumberList *one, TNumberList *two, int Minus, TNumberList *result );

    static void Multiply( CBigNumber *one, CBigNumber *two, CBigNumber *result );
    static void Multiply( TNumberList *one, TNumberList *two, TNumberList *result );


    static void Division( CBigNumber *one, CBigNumber *two, CBigNumber *result );
    static void Division( CBigNumber *one, CBigNumber *two, int precision, CBigNumber *result );
    static int Division( TNumberList* one, TNumberList* two );
    static int CompareList( TNumberList *one, TNumberList *two );
};


#endif
