#ifndef SERIALIZER_H
# define SERIALIZER_H

# include "Data.hpp"
# include <stdint.h>

class Serializer
{
    private:
        Serializer( void );
        Serializer( Serializer const & seria );
        ~Serializer( void );

        Serializer &    operator=( Serializer const & seria );

    public:
        static uintptr_t    serialize( Data *ptr );
        static Data *       deserialize( uintptr_t raw );
};

#endif