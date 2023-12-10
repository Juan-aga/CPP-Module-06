#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <limits.h>

# define TYPES 6

enum type{
    LITERAL,
    FLOAT,
    DOUBLE,
    INT,
    CHAR,
    NONE
};

class ScalarConverter
{
    private:
        ScalarConverter( void );
        ScalarConverter( ScalarConverter const & scalar );
        ~ScalarConverter( void );

        ScalarConverter &   operator=( ScalarConverter const & scalar );

        type                _getType( std::string const & literal );
        static bool         _isChar( std::string const & literal );
        static bool         _isInt( std::string const & literal );
        static bool         _isDouble( std::string const & literal );
        static bool         _isFloat( std::string const & literal );
        static bool         _isLiteral( std::string const & literal );
        static bool         _isUnknown( std::string const & literal );
        static bool         _setScalar( std::string const & literal, int type );
        static void         _print( long _int, float _float, double _double, int _char );

        typedef bool    (*types)( std::string const & );

    public:
        static void convert( std::string const & literal );
};


#endif