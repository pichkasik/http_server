#ifndef HOSTTYPES
# define HOSTTYPES

# include <iostream>
# include <vector>

class CGI;
/*
**	Структура-дополнение с HostData. Описывает location. Нет обязательных полей.
*/

typedef struct {
	std::string					way;
	size_t						clientMaxBodySize;
	std::string					root;
	size_t						redirectStatusCode;
	std::string					redirectPath;
	std::vector<std::string>	httpMethods;
	std::vector<std::string>	index;
	bool						autoindex;
	bool						uploadEnable;
	std::string					uploadPath;
	CGI*						cgi;
} Location;

/*
**	Структура-дополнение к HostData. Описывает ErrorPage.
*/

typedef struct {
	size_t						errorNbr;
	std::string					errorPagePath;
} ErrorPage;

/*
**	Структура со всеми возможными данными из конфигурационного файла. Обязательные поля:
**	- ip;
**	- port;
*/

typedef struct {
	std::string					ip;
	std::string					serverName;
	size_t						port;
	std::string					root;
	std::vector<ErrorPage*>		errorPage;
	size_t						clientMaxBodySize;
	std::vector<Location*>		location;
} HostData;

#endif