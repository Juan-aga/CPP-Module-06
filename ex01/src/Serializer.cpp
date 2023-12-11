#include "Serializer.hpp"

Serializer::Serializer( void )
{

}

Serializer::Serializer( Serializer const & seria )
{
    (void) seria;
}

Serializer::~Serializer( void )
{

}

Serializer &    Serializer::operator=( Serializer const & seria )
{
    if (this != &seria)
        *this = seria;
    return *this;
}

uintptr_t       Serializer::serialize( Data * ptr )
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *          Serializer::deserialize( uintptr_t raw )
{
    return reinterpret_cast<Data *>(raw);
}