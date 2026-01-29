#pragma once
#ifndef __COLORS__
#define __COLORS__

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define INFO YELLOW << "[INFO] "
#define ERROR RED << "[ERROR] "
#define OK GREEN << "[OK] "

const unsigned short int	HIGHEST_VALUE = 150;
const unsigned short int	LOWEST_VALUE = 1;

#endif // __COLORS__