/*!
 *  @file mempool_comoon.h
 *  @brief corpo das sobrecargas dos operadores new e delete
 *
 */
#ifndef _MEMPOOL_COMMON_H_
#define _MEMPOOL_COMMON_H_

#include <iostream>
#include "StoragePool.h"

using namespace std;

/*!
 *  @brief struct tag que possui um roteiro do tipo StoragePool
 *
 */
struct Tag { StoragePool * pool; };
/*!
 *  @brief Sobrecarga do operador new
 *  @param bytes do tipo size_t utilizado para calcular quanto é necessário alocar
 *  @param p do tipo StoragePool para ser utilizado como memória
 */
void * operator new ( size_t bytes, StoragePool & p );
/*!
 *  @brief Sobrecarga do operador new
 *  @param bytes do tipo size_t utilizado para calcular quanto é necessário alocar
 */	
void * operator new ( size_t bytes );
/*!
 *  @brief Sobrecarga do operador delete
 *  @param arg do tipo void utilizado para auxiliar destruir a memoria
 */
void operator delete ( void * arg ) noexcept;
/*!
 *  @brief Sobrecarga do operador new[]
 *  @param bytes do tipo size_t utilizado para calcular quanto é necessário alocar
 *  @param p do tipo StoragePool para ser utilizado como memória
 */
void * operator new[]( size_t bytes, StoragePool & p );
/*!
 *  @brief Sobrecarga do operador new[]
 *  @param bytes do tipo size_t utilizado para calcular quanto é necessário alocar
 */
void * operator new[]( size_t bytes );

#include "mempool_common.inl"
 
#endif