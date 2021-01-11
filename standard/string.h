/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: string.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_STRING_H__
#define __STANDARD_STRING_H__

#include <include/stdtype.h>
#include <standard/allocator.h>
#include <include/string.h>
#include <standard/math.h>


class string{
public:
    typedef size_t size_type;
    typedef char* iterator;
    typedef char value_type;
private:
    iterator uninitialized_copy( iterator first, iterator last, iterator result ){
        memcpy( result, first, (last - first) * sizeof( *first ) );
        return result + (last - first);
    }
    iterator uninitialized_copy_n( iterator first, size_t n, iterator result ){
        memcpy( result, first, n * sizeof( *first ) );
        return result + n;
    }

    //uninitialized_copy_n

    iterator uninitialized_fill_n( iterator first, size_t n, const char& value ){
        for( ; n > 0; --n, ++first )
            *first = value;
        return first;
    }

    char *start, *end_of_storage, *End;
    //std::allocator<char> data_allocator;
    void DeallocateAndDestory(){
        if( capacity() != 0 ){
            Allocator__deallocate( start, capacity() );
            //free( start_  );
        }

       // Allocator__deallocate( start_, capacity() );
       // data_allocator.deallocate( start, end_of_storage - start );
    }
    //重新构造元素 
    void reallocate( size_t new_size = 0 ){
        size_t old_size = size();
        if( new_size == 0 )
            new_size = size() ? 2 * size() : 1;
        char* new_start = (char*)Allocator__allocate( sizeof( char ), new_size ); //data_allocator.allocate( new_size );
       // std::copy( start, start + size(), new_start );
        uninitialized_copy( start, start + size(), new_start );

        DeallocateAndDestory();
        start = new_start;
        End = new_start + old_size;
        end_of_storage = new_start + new_size;
    }
    //移动构造元素
    /*void reallocate()
    {
    int old_size = size();
    int new_size = size() ? 2 * size() : 1;
    char* new_start = data_allocator.allocate(new_size);
    char* pos = new_start;
    char* old_pos = start;
    for (int i = 0; i < old_size; i++)
    data_allocator.construct(pos++, std::move(*old_pos)), old_pos++;
    data_allocator.deallocate(start, old_size);
    start = new_start;
    End = new_start + old_size;
    end_of_storage = new_start + new_size;
    }*/
public:
    //debug
    void print(){
        //for( auto it = start; it != End; it++ )
        //    std::cout << *it;
        //std::cout << std::endl;
    }
    //Construct
    string(){
        start = end_of_storage = End = nullptr;
    }
    string( const string& rhs ){
        start = end_of_storage = End = nullptr;
        append( rhs );
    }
    string( string&& rhs )noexcept :start( rhs.start ), end_of_storage( rhs.end_of_storage ), End( rhs.End ){
        rhs.start = rhs.end_of_storage = rhs.End = nullptr;
    }
    string( const char* s ){
        if( s == nullptr )
            string();
        else{
            int cnt = 0;
            for( ; s[cnt] != '\0'; cnt++ ){}
            start = (char*)Allocator__allocate( sizeof(char), cnt );// data_allocator.allocate( cnt );
            uninitialized_copy_n( (char*)s, cnt, start );
            end_of_storage = End = start + cnt;
        }
    }
    string( size_type n, char c ){
        start = (char*)Allocator__allocate( sizeof( char ), n );
        uninitialized_fill_n( start, n, c );
        end_of_storage = End = start + n;
    }
    string( const char* s, size_t n ){
        start = (char*)Allocator__allocate( sizeof( char ), n );
        uninitialized_copy_n( (char*)s, n, start );
        End = end_of_storage = start + n;
    }
    ~string(){
        DeallocateAndDestory();
    }
    //Iterator
    const iterator begin() const{
        return start;
    }

    const iterator end() const{
        return End;
    }

    iterator begin(){
        return start;
    }
    iterator end(){
        return End;
    }

    //Capacity
    void clear(){
        DeallocateAndDestory();
        End = start = end_of_storage = nullptr;
    }
    bool empty()const{
        return (start == End);
    }
    const size_type size() const{
        return End - start;
    }
    const size_type length() const{
        return size();
    }
    const size_type capacity() const{
        return end_of_storage - start;
    }
    void resize( size_type n ){
        resize( n, value_type() );
    }
    void resize( size_type n, const value_type &val ){
        if( n <= size() ){
            End = start + n;
        } else{
            append( string( n - size(), val ) );
        }
    }
    void reserve( size_type res_arg = 0 ){
        if( res_arg + size() < capacity() ) return;
        reallocate( res_arg + size() );
    }
    //Modifiers
    value_type& operator[]( size_type index ){
        if( index < 0 || index >= size() ){
            //std::cerr << "index out of range!" << std::endl;
            //std::exit( 1 );
            return *(start);
        } else{
            return *(start + index);
        }
    }
    value_type& front(){
        return *start;
    }
    value_type& back(){
        auto tmp = end();
        return *(--tmp);
    }
    void push_back( const value_type& val ){
        if( size() == capacity() )
            reallocate();
        *End = val;
        End++;
    }
    void pop_back(){
        if( empty() ){
            //std::cerr << "Error : pop_back() on empty String!" << std::endl;
            //exit( 1 );
        }
        End--;
    }
    void swap( string& rhs ){
        iterator _tempit;
        _tempit = start;
        start = rhs.start;
        rhs.start = _tempit;

        _tempit = end_of_storage;
        end_of_storage = rhs.end_of_storage;
        rhs.end_of_storage = _tempit;

        _tempit = End;
        End = rhs.End;
        rhs.End = _tempit;

       // std::swap( start, rhs.start );
       // std::swap( end_of_storage, rhs.end_of_storage );
       // std::swap( End, rhs.End );
    }
    void append( const string& rhs ){
        if( rhs.empty() ) return;
        if( capacity()<size() + rhs.size() ) reallocate( size() + rhs.size() );
        //std::copy( rhs.start, rhs.end_of_storage, End );
        uninitialized_copy( rhs.start, rhs.end_of_storage, End );
        End += rhs.size();
    }
    void append( const char* s ){
        if( s == nullptr ) return;
        size_t cnt = 0;
        for( ; s[cnt] != '\0'; cnt++ ){}
        if( capacity() < size() + cnt )	reallocate( size() + cnt );
        uninitialized_copy_n( (char*)s, cnt, End );
        End += cnt;
    }
    void append( const char* s, size_t l, size_t r ){
        if( r <= l ) return;
        if( s == nullptr ) return;
        if( capacity()<size() + r - l - 1 ) reallocate( size() + r - l );
        uninitialized_copy_n( (char*)(s + l), r - l, End );
        End += r - l;
    }
    string& operator+=( const char c ){
        (*this).push_back( c );
        return *this;
    }
    string& operator+=( const string& rhs ){
        (*this).append( rhs );
        return *this;
    }
    string operator+( const string& rhs ){
        string tmp( *this );
        return tmp += rhs;
    }
    string& operator=( const string& str ){
        return assign( str );
    }
    string& operator=( const char* s ){
        return assign( string( s ) );
    }
    string& operator=( char c ){
        return assign( string( (size_type)1, c ) );
    }
    string& assign( const string& str ){
        clear();
        append( str );
        return (*this);
    }
    string& assign( const char* s ){
        clear();
        if( s == nullptr ) return *this;
        size_t cnt = 0;
        while( s[cnt] != '\0' ) cnt++;
        //start = data_allocator.allocate( cnt );
        start = (char*)Allocator__allocate( sizeof( char ), cnt );
        End = uninitialized_copy_n( (char*)s, cnt, start );
        end_of_storage += cnt;
    }
    string& assign( size_type n, char c ){
        clear();
        if( n == 0 ) return *this;
        //start = data_allocator.allocate( n );
        start = (char*)Allocator__allocate( sizeof( char ), n );
        End = end_of_storage = uninitialized_fill_n( start, n, c );
    }
    string& insert( size_type pos, const string& rhs ){
        pos = Min( size(), pos );
        size_type new_size = size() + rhs.size();
        //iterator new_start = data_allocator.allocate( new_size );
        iterator new_start = (iterator)Allocator__allocate( sizeof( char ), new_size );

        uninitialized_copy( start, start + pos, new_start );
        uninitialized_copy( rhs.start, rhs.End, new_start + pos );
        uninitialized_copy( start + pos, End, new_start + pos + rhs.size() );
        start = new_start;
        end_of_storage = End = new_size + new_start;
        return *this;
    }
    string& insert( size_type pos, const char* s, size_type n ){
        return insert( pos, string( s, n ) );
    }
    string& insert( size_type pos, const char* s ){
        return insert( pos, string( s ) );
    }
    iterator insert( iterator pos, const value_type& val ){
        size_type index = pos - start;
        if( size() == capacity() )
            reallocate();
        pos = start + index;
        if( pos > end() ) pos = end();
        uninitialized_copy( pos, End, pos + 1 );
        (*pos) = val;
        End++;
        return pos;
    }
    string& insert( size_type pos, size_type num, const value_type& val ){
        return insert( pos, string( num, val ) );
    }
    string& insert( iterator pos, size_type num, const value_type& val ){
        return insert( pos - start, string( num, val ) );
    }
    string& erase( size_type pos, size_type n ){
        uninitialized_copy( pos + n + start, End, start + pos );
        End = End - n;
        return *this;
    }
    iterator erase( iterator pos ){
        uninitialized_copy( pos + 1, End, pos );
        End--;
        return pos;
    }
    iterator erase( iterator first, iterator last ){
        uninitialized_copy( last, End, first );
        End = End - (last - first);
        return first;
    }
    string& replace( size_t pos, size_t n, const string& str ){
        erase( pos, n );
        insert( pos, str );
        return *this;
    }
    string& replace( iterator i1, iterator i2, const string& str ){
        insert( erase( i1, i2 ) - start, str );
        return *this;
    }
    const char* c_str() const{
        if( empty() ){
            static char _NULLString = 0;
            return &_NULLString;
        }
        char* ret = start;// new char[End - start + 1];
        //uninitialized_copy( start, End, ret );
        ret[End - start] = '\0';
        return ret;
       // return start;
    }
    bool operator == ( const string& rhs ){
        if( size() != rhs.size() )
            return false;
        else{
            for( auto i = start, j = rhs.start; i != End; i++, j++ ){
                if( (*i) != (*j) )
                    return false;
            }
            return true;
        }
    }
    bool operator == ( const string& rhs ) const{
        if( size() != rhs.size() )
            return false;
        else{
            for( auto i = start, j = rhs.start; i != End; i++, j++ ){
                if( (*i) != (*j) )
                    return false;
            }
            return true;
        }
    }
    int compare( const string& rhs )const{
        iterator i = start, j = rhs.start;
        while( i != End && j != rhs.End ){
            if( (*i) > (*j) )
                return 1;
            else if( (*i) < (*j) )
                return -1;
            else
                i++, j++;
        }
        if( i == End&&j == rhs.End )
            return 0;
        else if( i == End )
            return -1;
        else
            return 1;
    }
    size_type copy( char* s, size_type n, size_type pos = 0 ){
        if( pos + n >= size() ){
            /*std::cerr << "out of range" << std::endl;
            std::exit( 1 );*/
            return 0;
        }

        uninitialized_copy_n( (start + pos), n, s );
        return n;
    }
    size_t find( const string& str, size_t pos = 0 ) const{
        if( size() - pos < str.size() )
            return (size_type)(-1);
        for( auto it = start + pos; it != End; it++ ){
            auto i = it, j = str.start;
            while( j<str.End && *i == *j )
                i++, j++;
            if( j == str.End )
                return it - start;
        }
        return (size_type)(-1);
    }
    size_t find( const char* s, size_t pos, size_t n ) const{
        return find( string( s, n ), pos );
    }
    size_t find( const char* s, size_t pos = 0 ) const{
        return find( string( s ), pos );
    }
    size_t find( char c, size_t pos = 0 ) const{
        if( empty() )
            return size_type( -1 );
        else{
            for( auto it = start; it != End; it++ )
                if( *it == c )
                    return it - start;
            return size_type( -1 );
        }
    }
    string substr( size_t pos = 0, size_t n = 0 ){
        return string( start + pos, n );
    }
    size_t rfind( string& rhs, size_t pos = 0 ){
        if( pos == 0 ) pos = size();
        for( auto it = Min( start + pos, End - 1 ); it != start - 1; it-- ){
            size_t i;
            for( i = 0; i < rhs.size();)
                if( rhs[i] == *(it + i) )
                    i++;
                else
                    break;
            if( i == rhs.size() )
                return it - start;
        }
        return size_t( -1 );
    }
    size_t rfind( const char& c, size_t pos = 0 ){
        if( pos == 0 ) pos = size();
        for( auto it = Min( End - 1, start + pos ); it != start; it-- ){
            if( *it == c )
                return it - start;
        }
        return size_t( -1 );
    }
    size_t rfind( const char* str ){
        return rfind( string( str ) );
    }
    size_t find_first_of( const string& rhs, size_t pos = 0 ){
        for( auto it = start + pos; it != End; it++ ){
            auto i = rhs.start;
            while( i != rhs.End ){
                if( *i == *it )
                    break;
                i++;
            }
            if( i != rhs.End )
                return it - start;
        }
        return (size_t)-1;
    }
    size_t find_first_of( const char& c, size_t pos = 0 ){
        for( auto it = start + pos; it != End; it++ ){
            if( *it == c )
                return it - start;
        }
        return (size_t)-1;
    }
    size_t find_last_of( const char &c, size_t pos = 0 ){
        if( pos == 0 ) pos = size();
        for( auto it = pos + start; it != start - 1; it-- )
            if( *it == c )
                return it - start;
        return (size_t)-1;
    }
    size_t find_last_of( const char* str, size_t pos, size_t len ){
        size_t l = 0;
        for( size_t i = 0; str[i] != '\0'; i++ )
            l++;
        for( auto it = start + pos; it != start + pos - len; it-- ){
            size_t i;
            for( i = 0; str[i] != '\0'; i++ )
                if( str[i] == *it )
                    break;
            if( str[i] != '\0' ) return it - start;
        }
        return size_t( -1 );
    }
    size_t find_last_of( const string& rhs, size_t pos ){
        for( auto it = start + pos; it != start - 1; it-- ){
            size_t i = 0;
            while( rhs.start + i != rhs.End )
                if( *it == *(start + i) )
                    break;
                else
                    i++;
            if( rhs.size() != i )	return it - start;
        }
        return size_t( -1 );
    }
    size_t find_first_not_of( const string& rhs ){
        for( auto it = start; it != End; it++ ){
            size_t i = 0;
            while( i < rhs.size() )
                if( *(rhs.start + i) == *it )
                    break;
                else
                    i++;
            if( i == rhs.size() ) return it - start;
        }
        return size_t( -1 );
    }
    size_t find_last_not_of( const string& rhs, size_t pos ){
        for( auto it = start + pos; it != start - 1; it-- ){
            size_t i = 0;
            while( i < rhs.size() )
                if( *(rhs.start + i) == *it )
                    break;
                else
                    i++;
            if( i == rhs.size() ) return it - start;
        }
        return size_t( -1 );
    }
    bool operator!=( const string& rhs ) const{
        return !(*this == rhs);
    }
    bool operator>( const string& rhs ) const{
        return compare( rhs ) > 0;
    }
    bool operator>=( const string& rhs ) const{
        return compare( rhs ) >= 0;
    }
    bool operator<( const string& rhs ) const{
        return compare( rhs ) < 0;
    }
    bool operator<=( const string& rhs ) const{
        return compare( rhs ) <= 0;
    }
};
//std::ostream& operator<<( std::ostream& os, const ministl::string& rhs ){
//    os << rhs.c_str();
//    return os;
//}

//size_t hash_value( const string& val ){
//    const size_t _FNV_offset_basis = 2166136261U;
//    const size_t _FNV_prime = 16777619U;
//    size_t ans = _FNV_offset_basis;
//    for( auto it = val.begin(); it != val.end(); it++ ){
//        ans ^= *it;
//        ans *= _FNV_prime;
//    }
//    return ans;
//}


#endif
