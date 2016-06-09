/*!
 *  @file mempool_common.inl
 *  @brief Implementação do arquivo mempool_common.h
 */
 
#include "mempool_common.h"
#include "StoragePool.h"

using namespace std;
//Sobrecarga do operador New
void * operator new ( size_t bytes, StoragePool & p )
{
	Tag* const tag = reinterpret_cast<Tag *> ( p.Allocate(bytes + sizeof(Tag)) );
	tag->pool = &p;
	// skip sizeof tag to get the raw data-block.
	return ( reinterpret_cast<void *>( tag + 1U ) );
}
//Sobrecarga do operador New
void * operator new ( size_t bytes ) 
{ // Regular new
	Tag* const tag = reinterpret_cast<Tag *>( std::malloc(bytes + sizeof(Tag)) ); 
	tag->pool = nullptr;
// skip sizeof tag to get the raw data-block.
	return ( reinterpret_cast<void *>( tag + 1U ) );
}
//Sobrecarga do operador New[]
void * operator new[]( size_t bytes, StoragePool & p )
{
	Tag* const tag = reinterpret_cast<Tag *> ( p.Allocate(bytes + sizeof(Tag)) );
	tag->pool = &p;
	// skip sizeof tag to get the raw data-block.
	return ( reinterpret_cast<void *>( tag + 1U ) );
}
//Sobrecarga do operador New[]
void * operator new[]( size_t bytes ) 
{ // Regular new
	Tag* const tag = reinterpret_cast<Tag *>( std::malloc(bytes + sizeof(Tag)) ); 
	tag->pool = nullptr;
// skip sizeof tag to get the raw data-block.
	return ( reinterpret_cast<void *>( tag + 1U ) );
}
//Sobrecarga do operador delete
void operator delete ( void * arg ) noexcept 
{
// We need to subtract 1U (in fact, pointer arithmetics) because arg // points to the raw data (second block of information).
// The pool id (tag) is located ‘sizeof(Tag)’ bytes before.
	Tag * const tag = reinterpret_cast<Tag *>( arg ) - 1U;
	if ( nullptr != tag->pool ) // Memory block belongs to a particular GM.
 		tag->pool->Free (reinterpret_cast<void *>( tag ));
	else
		std::free(reinterpret_cast<void *>( tag ));
}
 