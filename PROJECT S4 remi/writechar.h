#ifndef WRITECHAR_H
#define WRITECHAR_H
#include "constants.h"

void writechar( int size, char c, struct marker (*vector)[size] );

void writeA( int size, struct marker (*vector)[size] );

void writeE( int size, struct marker (*vector)[size] );

void writeF( int size, struct marker (*vector)[size] );

void writeH( int size, struct marker (*vector)[size] );

void writeI( int size, struct marker (*vector)[size] );

void writeK( int size, struct marker (*vector)[size] );

void writeL( int size, struct marker (*vector)[size] );

void writeT( int size, struct marker (*vector)[size] );

#endif

