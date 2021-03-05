/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: stdio.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_STDIO_H__
#define __GRAY_SDK_STDIO_H__

#include <include/stdtype.h>
#ifdef __ANDROID__
#include <include/stdarg.h>
#endif

#ifdef _NATIVE_
#include <stdio.h>
#else
typedef char* va_list;

#define clearerr ___clearerr___
#define fclose ___fclose___
#define feof ___feof___
#define ferror ___ferror___
#define fflush ___fflush___
#define fgetc ___fgetc___
#define fgetpos ___fgetpos___
#define fgets ___fgets___
#define fopen ___fopen___
#define fprintf ___fprintf___
#define fputc ___fputc___
#define fputs ___fputs___
#define fread ___fread___
#define freopen ___freopen___
#define fscanf ___fscanf___
#define fseek ___fseek___
#define fsetpos ___fsetpos___
#define ftell ___ftell___
#define fwrite ___fwrite___
#define getc ___getc___
#define getchar ___getchar___
#define gets ___gets___
#define perror ___perror___
#define printf ___printf___
#define putc ___putc___
#define putchar ___putchar___
#define puts ___puts___
#define remove ___remove___
#define rename ___rename___
#define rewind ___rewind___
#define scanf ___scanf___
//#define setbuf ___setbuf___
#define setvbuf ___setvbuf___
#define sprintf ___sprintf___
#define sscanf ___sscanf___
#define tmpfile ___tmpfile___
#define tmpnam ___tmpnam___
#define ungetc ___ungetc___
#define vprintf ___vprintf___
#define vfprintf ___vfprintf___
#define vsprintf ___vsprintf___

#define L_tmpnam   260 // _MAX_PATH
#define EOF    (-1)

#define _IOFBF 0x0000
#define _IOLBF 0x0040
#define _IONBF 0x0004

#endif

typedef unsigned int _FILE;

#define _SEEK_SET_ (0)
#define _SEEK_CUR_ (1)
#define _SEEK_END_ (2)

EXTERN void ___clearerr___( _FILE *stream );
EXTERN int ___fclose___( _FILE *stream );
EXTERN int ___feof___( _FILE *stream );
EXTERN int ___ferror___( _FILE *stream );
EXTERN int ___fflush___( _FILE *stream );
EXTERN int ___fgetc___( _FILE *stream );
EXTERN int ___fgetpos___( _FILE *stream, int *position );
EXTERN char *___fgets___( char *str, int num, _FILE *stream );
EXTERN _FILE *___fopen___( const char *fname, const char *mode );
EXTERN int ___fprintf___( _FILE *stream, const char *format, ... );
EXTERN int ___fputc___( int ch, _FILE *stream );
EXTERN int ___fputs___( const char *str, _FILE *stream );
EXTERN int ___fread___( void *buffer, int size, int num, _FILE *stream );
EXTERN _FILE *___freopen___( const char *fname, const char *mode, _FILE *stream );
EXTERN int ___fscanf___( _FILE *stream, const char *format, ... );
EXTERN int ___fseek___( _FILE *stream, long offset, int origin );
EXTERN int ___fsetpos___( _FILE *stream, const int *position );
EXTERN int ___ftell___( _FILE *stream );
EXTERN int ___fwrite___( const void *buffer, int size, int count, _FILE *stream );
EXTERN int ___getc___( _FILE *stream );
EXTERN int ___getchar___( void );
EXTERN char *___gets___( char *str );
EXTERN void ___perror___( const char *str );
EXTERN int ___printf___( const char *format, ... );
EXTERN int ___putc___( int ch, _FILE *stream );
EXTERN int ___putchar___( int ch );
EXTERN int ___puts___( char *str );
EXTERN int ___remove___( const char *fname );
EXTERN int ___rename___( const char *oldfname, const char *newfname );
EXTERN void ___rewind___( _FILE *stream );
EXTERN int ___scanf___( const char *format, ... );
EXTERN void ___setbuf___( _FILE *stream, char *buffer );
EXTERN int ___setvbuf___( _FILE *stream, char *buffer, int mode, int size );
EXTERN int ___sprintf___( char *buffer, const char *format, ... );
EXTERN int ___sscanf___( const char *buffer, const char *format, ... );
EXTERN _FILE *___tmpfile___( void );
EXTERN char *___tmpnam___( char *name );
EXTERN int ___ungetc___( int ch, _FILE *stream );
EXTERN int ___vprintf___( char *format, va_list arg_ptr );
EXTERN int ___vfprintf___( _FILE *stream, const char *format, va_list arg_ptr );
EXTERN int ___vsprintf___( char *buffer, const char *format, va_list arg_ptr );

#endif
