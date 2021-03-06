#ifndef RESPONSE_DELETE
# define RESPONSE_DELETE

#include "Response.hpp"

class ResponseDelete : public Response {
public:
	ResponseDelete();
	ResponseDelete(const ResponseDelete& other);
	ResponseDelete& operator=(const ResponseDelete &assign);
	ResponseDelete(RequestData &requestData, HostData *hostData);
	~ResponseDelete();

private:
	virtual void createBody(const std::string &uri, HostData *hostData);
};

#endif