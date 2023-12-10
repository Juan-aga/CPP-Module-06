#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{

}

ScalarConverter::ScalarConverter( ScalarConverter const & scalar )
{
    if (this != &scalar)
        *this = scalar;
}

ScalarConverter::~ScalarConverter( void )
{

}

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & scalar )
{
    (void) scalar;
    return *this;
}

void            ScalarConverter::convert( std::string const & literal )
{
    bool    check = false;
    types  getTypes[TYPES] = {
        &_isLiteral,
        &_isFloat,
        &_isDouble,
        &_isInt,
        &_isChar,
        &_isUnknown
    };

    for (int i = 0; i < TYPES; i++)
    {
        check = getTypes[i](literal);
        if (check)
        {
            if (i > LITERAL && i < NONE)
            {
                if (!_setScalar(literal, i))
                    getTypes[NONE](literal); 
            }
            return;
        }
    }
}

bool            ScalarConverter::_setScalar( std::string const & literal, int type )
{
    long        _int;
    float       _float;
    double      _double;
    int         _char;

    if (type == CHAR)
    {
        _char = static_cast<int>(literal[0]);
        _int = static_cast<int>(_char);
        _float = static_cast<float>(_char);
        _double = static_cast<double>(_char);
    }
    else if (type == INT)
    {
        try
        {
            _int = std::stoi(literal);
        }
        catch (std::exception & e)
        {
            return false;
        }
        _char = static_cast<int>(_int);
        _float = static_cast<float>(_int);
        _double = static_cast<double>(_int);
    }
    else if (type == FLOAT)
    {
        try
        {
            _float = std::stof(literal.c_str());
        }
        catch ( std::exception &e )
        {
            return false;
        }
        _int = static_cast<long>(std::strtol(literal.c_str(), NULL, 10));
        //_int = static_cast<long>(_float);
        _char = static_cast<int>(_float);
        _double = static_cast<double>(_float);
    }
    else if (type == DOUBLE)
    {
        try
        {
            _double = std::stod(literal.c_str(), NULL);
        }
        catch (std::exception & e)
        {
            return false;
        }
        _int = static_cast<long>(_double);
        _char = _int;
        _float = static_cast<float>(_double);
    }
    else
        return false;

    _print(_int, _float, _double, _char);
    return true;
}

void            ScalarConverter::_print( long _int, float _float, double _double, int _char )
{
    std::cout << std::fixed;
    //std::cout.precision(2);
    std::cout << "char:     " ;
    if (_char > 31 && _char < 127)
        std::cout << "'" << static_cast<char>(_char) << "'" << std::endl;
    else
        std::cout << "Non displayable\n";

    std::cout << "int:      ";
    if (_int >= INT_MIN && _int <= INT_MAX)
        std::cout << _int << std::endl;
    else
        std::cout << "impossible\n";
    
    std::cout << "float:    " << _float;
    std::cout << "f" << std::endl;
    
    std::cout << "double:   " << _double << std::endl;
}



bool            ScalarConverter::_isInt( std::string const & literal )
{
    size_t  i = 0;

    if (literal[i] == '+'|| literal[i] == '-')
        i++;
    for (size_t j(i); i < literal.length(); j ++, i++)
    {
        if (!isdigit(literal[j]))
            return false;
    }
    if (i == 0 || literal[i] == '+'|| literal[i] == '-')
        return false;
    return true;
}

bool            ScalarConverter::_isDouble( std::string const & literal )
{
    size_t  i = 0;
    size_t  dot = 0;

    dot = literal.find('.');
    if (literal[i] == '+'|| literal[i] == '-')
        i++;
    if (dot == std::string::npos || dot == i || dot == literal.length() -1)
        return false;
    for (size_t j(i); j < literal.length(); j++, i++)
        if (literal[j] == '.' || !isdigit(literal[j]))
        {
            if(j != dot)
                return false;
        }
    return true;
}

bool            ScalarConverter::_isFloat( std::string const & literal )
{
    size_t  i = 0;
    size_t  dot = 0;

    dot = literal.find('.');
    if (literal[i] == '+'|| literal[i] == '-')
        i++;
    if (dot == std::string::npos || literal[literal.length() -1] != 'f' || dot == i || \
        dot == literal.length() - 2)
        return false;
    for (size_t j(i); j < literal.length() - 1; j++, i++)
        if (literal[j] == '.' || !isdigit(literal[j]))
        {
            if(j != dot)
                return false;
        }
    return true;
}

bool            ScalarConverter::_isChar( std::string const & literal )
{
    if (literal.length() == 1)
        return true;
    return false;
}

bool            ScalarConverter::_isLiteral( std::string const & literal )
{
    if (literal == "inf" || literal == "inff" || \
        literal == "+inf" || literal == "+inff")
    {
        std::cout << "char:     imposible\n";
        std::cout << "int:      imposible\n";
        std::cout << "float:    inff\n";
        std::cout << "double    inf\n";
        return true;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char:     imposible\n";
        std::cout << "int:      imposible\n";
        std::cout << "float:    -inff\n";
        std::cout << "double    -inf\n";
        return true;
    }
    else if (literal == "nan")
    {
        std::cout << "char:     imposible\n";
        std::cout << "int:      imposible\n";
        std::cout << "float:    nanf\n";
        std::cout << "double    nan\n";
        return true;
    }
    return false;
}

bool            ScalarConverter::_isUnknown( std::string const & literal )
{
    (void) literal;
    std::cout << "char:     imposible\n";
    std::cout << "int:      imposible\n";
    std::cout << "float:    imposible\n";
    std::cout << "double    imposible\n";
    return true;
}