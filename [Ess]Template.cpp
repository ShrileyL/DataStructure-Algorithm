/**************************************************
 * Essential C++ -- Stanley Lippman
 * Addison-Wesley 
 * ISBN 0-201-48518-4
 * homepage: www.objectwrite.com
 * email: slippman@objectwrite.com
 *
 * 2016/11/7 Shirley define and demons
 *************************************************/

template <typename Type>
inline Type max( Type t1, Type t2 )
       { return t1 > t2 ? t1 : t2; }

template <typename elemType>
inline elemType max( const vector<elemType> &vec )
       { return *max_element( vec.begin(), vec.end() ); }

template <typename arrayType>
inline arrayType max( const arrayType *parray, int size )
       { return *max_element( parray, parray+size ); }