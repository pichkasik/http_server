/* **************************************************************************** */
/*                                                                      .       */
/*   TestResponseError.cpp                                                        / V\     */
/*                                                                   / `  /     */
/*   By: tilda      <tilda@student.21-school.ru.fr>                 <<   |      */
/*                                                                  /    |      */
/*   Created: 8/31/21 by tilda                                    /      |      */
/*                                                              /        |      */
/*                                                            /    \  \ /       */
/*                                                           (      ) | |       */
/*                                                   ________|   _/_  | |       */
/*                                                 <__________\______)\__)      */
/* **************************************************************************** */


#include "../../../include/acutest.hpp"
#include "../../../src/ResponseAPI/Response/Response.hpp"
#include "../../../src/ResponseAPI/ResponseError/ResponseError.hpp"
#include "../../../src/Types/HostTypes.hpp"
#include "../../../test_utils/MockHostData.hpp"
#include <iostream>

void
testResponseErrorBadRequest400(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 400;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " Bad Request\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseErrorForbidden403(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 403;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " Forbidden\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseErrorNotFound404(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 404;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " Not Found\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseErrorMethodNotAllowed405(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 405;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " Method Not Allowed\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseErrorInternalServerError500(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 500;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " Internal Server Error\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseErrorNotImplemented501(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 501;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " Not Implemented\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseErrorBadGateway502(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 502;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " Bad Gateway\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseErrorHTTPVersionNotSupported505(void){
	std::string filename = "./test_files/error.html";
	size_t codeError = 505;
	std::string body = getDataFileAsString(filename);
	long sizeFile = getSizeFile(filename);
	std::string expectedResponseData = "HTTP/1.1 " + std::to_string(codeError) + " HTTP Version Not Supported\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;

	ErrorPage errorPage;
	errorPage.errorNbr = codeError;
	errorPage.errorPagePath = filename;
	HostData *hostData = MockHostData::createDefaultHostData();
	ResponseError *response = new ResponseError(errorPage, hostData);

	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}
TEST_LIST = {
		{ "ResponseError: Bad Request [404]", testResponseErrorBadRequest400 },
		{ "ResponseError: Forbidden [403]", testResponseErrorForbidden403 },
		{ "ResponseError: Not Found [404]", testResponseErrorNotFound404 },
		{ "ResponseError: Method Not Allowed [405]", testResponseErrorMethodNotAllowed405 },
		{ "ResponseError: Internal Server Error [500]", testResponseErrorInternalServerError500 },
		{ "ResponseError: Not Implemented [501]", testResponseErrorNotImplemented501 },
		{ "ResponseError: Bad Gateway [502]", testResponseErrorBadGateway502 },
		{ "ResponseError: HTTP Version Not Supported [505]", testResponseErrorHTTPVersionNotSupported505 },
		{ nullptr, nullptr }
};
