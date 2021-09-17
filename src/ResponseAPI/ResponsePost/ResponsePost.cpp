#include "ResponsePost.hpp"
#include "ResponseError.hpp"

ResponsePost::ResponsePost() : Response() {}

ResponsePost::ResponsePost(const ResponsePost& other) : Response(other) {
	operator=(other);
}

ResponsePost &ResponsePost::operator=(const ResponsePost &assign) {
	if (this != &assign){
		_leftBytesToSend = assign.getLeftBytesToSend();
		_dataToSend = assign.getDataToSend();
		_state = assign.getState();
		_status = assign.getStatus();
	}
	return *this;
}

ResponsePost::ResponsePost(RequestData &requestData, HostData *hostData)
		: Response(requestData,
				   hostData)
{
	ResponsePost::createBody(requestData, hostData);
	_leftBytesToSend = _dataToSend.length();//TODO set in one place
}

ResponsePost::~ResponsePost() {}

std::pair<std::string, std::string> ResponsePost::parseBody(std::string body){
	size_t filenameOffset;
	std::pair<std::string, std::string> bodyStruct;
	std::string filenameSeporator = FILENAME_SEPORATOR;

	size_t file_end = body.find(filenameSeporator, 0);
	if (file_end != std::string::npos){
		filenameOffset = file_end + filenameSeporator.length();
		bodyStruct.first = body.substr(0, file_end);
		bodyStruct.second = body.substr(filenameOffset, body.length() - filenameOffset);
	}
	else{
		bodyStruct.first = "";
		bodyStruct.second = body;
	}
	return bodyStruct;
}

std::string getUploadFilePath(Location *location){//TODO move up to Response
	std::string uploadPath;
	if (location && location->uploadEnable){
		uploadPath = location->root + location->uploadPath;
	}
	if (uploadPath.empty()) {
		uploadPath = DEFAULT_UPLOAD_PATH;
	}
	uploadPath += "/";
	return uploadPath;
}


void ResponsePost::createBody(RequestData &requestData, HostData *hostData){
	std::pair<std::string, std::string> bodyStruct;
	std::string filePath;
	Location *location;

	//TODO create a behavior if file gets from uri
	bodyStruct = parseBody(requestData.body);//TODO may be needs a constuctor with size
	location = getLocationByUri(requestData.header["uri"], hostData->location);
	filePath = "." + getUploadFilePath(location) + bodyStruct.first;

//TODO test chunked method
	std::ofstream outfile (filePath);
	if (!isFileExist(filePath)){
		//TODO if throw exception could lose the pointer on the response
		throw NotFoundException();
	}

	outfile << bodyStruct.second << std::endl;
	outfile.close();
	std::string dataFromCGI = "The body of post!!!";
	changeContentLength(dataFromCGI.length());
	_dataToSend += "\r\n";
	_dataToSend += dataFromCGI;
}

void ResponsePost::createBody(const std::string &uri, HostData *hostData){
	Response::createBody(uri, hostData);
}
