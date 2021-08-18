#include "Request.hpp"

Request::Request() : _status(READING), _data() {
	// std::cout << "			REQUEST			" << std::endl;	
}

Request::Request(const Request& other) : _data(other._data) {
}

Request::~Request() {}

void	Request::addRequestChunk(std::string chunk) {
	// _data += chunk;
	_data.insert(_data.length(), chunk);
	// std::cout << "|" << _data << "|" << std::endl;
	// isDone();
}

bool	Request::isDone() {
	if (_data.find("\r\n\r\n") == std::string::npos)
		return false;

	// _status = DONE;
	return true;
}

void	Request::resetRequest() {
	_status = NO_REQUEST;
	_data = "";
}

Request *Request::clone() const{
	return (new Request(*this));
}

int		Request::getStatus() const {
	return _status;
}