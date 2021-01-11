#ifndef __STANDARD_INT64_H__
#define __STANDARD_INT64_H__

/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: int64.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#include <include/stdtype.h>
#include <include/math.h>

class Int64{
public:
    Int64();
    Int64( float fValue );
    Int64( int32 nValue );
    Int64( uint32 nValue );
    Int64( const char* strValue );
    Int64( const Int64_ value );
    Int64( const Double_ value, int n );
    ~Int64();
    char* ToString( char* strTextBuff );
    int32 ToInt32();
    uint32 ToUint32();
    void ToDouble( Double_ value );

public:
    Int64 operator + () const;
    Int64 operator + ( const Int64 &right ) const;
    Int64 operator + ( const float val ) const;
    Int64 operator + ( const int32 val ) const;
    Int64 operator + ( const uint32 val ) const;
    friend Int64 operator +( float val, const Int64 &value );
    friend Int64 operator +( int32 val, const Int64 &value );
    friend Int64 operator +( uint32 val, const Int64 &value );
    Int64& operator += ( const Int64 &right );
    Int64& operator += ( const float val );
    Int64& operator += ( const int32 val );
    Int64& operator += ( const uint32 val );
    Int64& operator ++ ();
    Int64& operator ++ ( int );


    Int64 operator - () const;
    Int64 operator - ( const Int64 &right ) const;
    Int64 operator - ( const float val ) const;
    Int64 operator - ( const int32 val ) const;
    Int64 operator - ( const uint32 val ) const;
    friend Int64 operator -( float val, const Int64 &value );
    friend Int64 operator -( int32 val, const Int64 &value );
    friend Int64 operator -( uint32 val, const Int64 &value );
    Int64& operator -= ( const Int64 &right );
    Int64& operator -= ( const float val );
    Int64& operator -= ( const int32 val );
    Int64& operator -= ( const uint32 val );
    Int64& operator -- ();
    Int64& operator -- ( int );

    operator byte* ();
    operator const byte* () const;
    Int64 operator * ( const Int64 &right ) const;
    Int64 operator * ( const float val ) const;
    Int64 operator * ( const int32 val ) const;
    Int64 operator * ( const uint32 val ) const;
    friend Int64 operator *( float val, const Int64 &value );
    friend Int64 operator *( int32 val, const Int64 &value );
    friend Int64 operator *( uint32 val, const Int64 &value );
    Int64& operator *= ( const Int64 &right );
    Int64& operator *= ( const float val );
    Int64& operator *= ( const int32 val );
    Int64& operator *= ( const uint32 val );

    Int64 operator / ( const Int64 &right ) const;
    Int64 operator / ( const float val ) const;
    Int64 operator / ( const int32 val ) const;
    Int64 operator / ( const uint32 val ) const;
    friend Int64 operator /( float val, const Int64 &value );
    friend Int64 operator /( int32 val, const Int64 &value );
    friend Int64 operator /( uint32 val, const Int64 &value );
    Int64& operator /= ( const Int64 &right );
    Int64& operator /= ( const float val );
    Int64& operator /= ( const int32 val );
    Int64& operator /= ( const uint32 val );

    Int64 operator % ( const Int64 &right ) const;
    Int64 operator % ( const float val ) const;
    Int64 operator % ( const int32 val ) const;
    Int64 operator % ( const uint32 val ) const;
    friend Int64 operator %( float val, const Int64 &value );
    friend Int64 operator %( int32 val, const Int64 &value );
    friend Int64 operator %( uint32 val, const Int64 &value );
    Int64& operator %= ( const Int64 &right );
    Int64& operator %= ( const float val );
    Int64& operator %= ( const int32 val );
    Int64& operator %= ( const uint32 val );


    Int64& operator = ( const Int64 &right );
    Int64& operator = ( const float right );
    Int64& operator = ( const int32 right );
    Int64& operator = ( const uint32 right );
    Int64& operator = ( const char* right );
    Int64& operator = ( const Double_ right );

    bool operator == ( const Int64 &right ) const;
    bool operator == ( const float right ) const;
    bool operator == ( const int32 right ) const;
    bool operator == ( const uint32 right ) const;

    bool operator != ( const Int64 &right ) const;
    bool operator != ( const float right ) const;
    bool operator != ( const int32 right ) const;
    bool operator != ( const uint32 right ) const;

    bool operator < ( const Int64 &right ) const;
    bool operator < ( const float right ) const;
    bool operator < ( const int32 right ) const;
    bool operator < ( const uint32 right ) const;

    bool operator > ( const Int64 &right ) const;
    bool operator > ( const float right ) const;
    bool operator > ( const int32 right ) const;
    bool operator > ( const uint32 right ) const;

    bool operator <= ( const Int64 &right ) const;
    bool operator <= ( const float right ) const;
    bool operator <= ( const int32 right ) const;
    bool operator <= ( const uint32 right ) const;

    bool operator >= ( const Int64 &right ) const;
    bool operator >= ( const float right ) const;
    bool operator >= ( const int32 right ) const;
    bool operator >= ( const uint32 right ) const;



private:
    Int64_ m_vData;
};

#endif
