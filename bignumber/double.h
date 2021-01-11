#ifndef __STANDARD_DOUBLE_H__
#define __STANDARD_DOUBLE_H__

/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: double.h
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

class Double{
public:
    Double();
    Double( float fValue );
    Double( int32 nValue );
    Double( uint32 nValue );
    Double( const char* strValue );
    Double( const Double_ value );
    Double( const Int64_ value, int n );
    ~Double();
    char* ToString( char* strTextBuff );
    float ToFloat();
    int32 ToInt32();
    uint32 ToUint32();
    void ToInt64( Int64_ value );

    Double Floor();
    Double Ceil();
    Double Round();
    Double Abs();

public:
    Double operator + () const;
    Double operator + ( const Double &right ) const;
    Double operator + ( const float val ) const;
    Double operator + ( const int32 val ) const;
    Double operator + ( const uint32 val ) const;
    friend Double operator +( float val, const Double &value );
    friend Double operator +( int32 val, const Double &value );
    friend Double operator +( uint32 val, const Double &value );
    Double& operator += ( const Double &right );
    Double& operator += ( const float val );
    Double& operator += ( const int32 val );
    Double& operator += ( const uint32 val );
    Double& operator ++ ();
    Double& operator ++ ( int );


    Double operator - () const;
    Double operator - ( const Double &right ) const;
    Double operator - ( const float val ) const;
    Double operator - ( const int32 val ) const;
    Double operator - ( const uint32 val ) const;
    friend Double operator -( float val, const Double &value );
    friend Double operator -( int32 val, const Double &value );
    friend Double operator -( uint32 val, const Double &value );
    Double& operator -= ( const Double &right );
    Double& operator -= ( const float val );
    Double& operator -= ( const int32 val );
    Double& operator -= ( const uint32 val );
    Double& operator -- ();
    Double& operator -- ( int );

    operator byte* ();
    operator const byte* () const;
    Double operator * ( const Double &right ) const;
    Double operator * ( const float val ) const;
    Double operator * ( const int32 val ) const;
    Double operator * ( const uint32 val ) const;
    friend Double operator *( float val, const Double &value );
    friend Double operator *( int32 val, const Double &value );
    friend Double operator *( uint32 val, const Double &value );
    Double& operator *= ( const Double &right );
    Double& operator *= ( const float val );
    Double& operator *= ( const int32 val );
    Double& operator *= ( const uint32 val );

    Double operator / ( const Double &right ) const;
    Double operator / ( const float val ) const;
    Double operator / ( const int32 val ) const;
    Double operator / ( const uint32 val ) const;
    friend Double operator /( float val, const Double &value );
    friend Double operator /( int32 val, const Double &value );
    friend Double operator /( uint32 val, const Double &value );
    Double& operator /= ( const Double &right );
    Double& operator /= ( const float val );
    Double& operator /= ( const int32 val );
    Double& operator /= ( const uint32 val );

    Double operator % ( const Double &right ) const;
    Double operator % ( const float val ) const;
    Double operator % ( const int32 val ) const;
    Double operator % ( const uint32 val ) const;
    friend Double operator %( float val, const Double &value );
    friend Double operator %( int32 val, const Double &value );
    friend Double operator %( uint32 val, const Double &value );
    Double& operator %= ( const Double &right );
    Double& operator %= ( const float val );
    Double& operator %= ( const int32 val );
    Double& operator %= ( const uint32 val );


    Double& operator = ( const Double &right );
    Double& operator = ( const float right );
    Double& operator = ( const int32 right );
    Double& operator = ( const uint32 right );
    Double& operator = ( const char* right );
    Double& operator = ( const Int64_ right );

    bool operator == ( const Double &right ) const;
    bool operator == ( const float right ) const;
    bool operator == ( const int32 right ) const;
    bool operator == ( const uint32 right ) const;

    bool operator != ( const Double &right ) const;
    bool operator != ( const float right ) const;
    bool operator != ( const int32 right ) const;
    bool operator != ( const uint32 right ) const;

    bool operator < ( const Double &right ) const;
    bool operator < ( const float right ) const;
    bool operator < ( const int32 right ) const;
    bool operator < ( const uint32 right ) const;

    bool operator > ( const Double &right ) const;
    bool operator > ( const float right ) const;
    bool operator > ( const int32 right ) const;
    bool operator > ( const uint32 right ) const;

    bool operator <= ( const Double &right ) const;
    bool operator <= ( const float right ) const;
    bool operator <= ( const int32 right ) const;
    bool operator <= ( const uint32 right ) const;

    bool operator >= ( const Double &right ) const;
    bool operator >= ( const float right ) const;
    bool operator >= ( const int32 right ) const;
    bool operator >= ( const uint32 right ) const;


private:
    Double_ m_vData;
};

#endif
