#ifndef RESPONSE_TYPES
# define RESPONSE_TYPES

# include <iostream>

class Response;
class Request;

/*
** Структура для автоматического определения наследника класса Response
*/
typedef struct {
	std::string method;
	Response*	(*createResponse)(RequestData&);
}	ResponseCreatorList;

/*
** Характеризует текущий статут считывание ответа
*/
typedef enum { NO_RESPONSE, SENDING, SENDED } responseState;

/*
** Структура для автоматического определения обработчика Header
*/
typedef struct {
	const char*		nameHeader;
	std::string			(*getProcessedHeader)(std::string valueHeader);
}		t_response_process;


#endif