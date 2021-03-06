/* **************************************************************************** */
/*                                                                      .       */
/*   TestResponseHead.cpp                                                        / V\     */
/*                                                                   / `  /     */
/*   By: tilda      <tilda@student.21-school.ru.fr>                 <<   |      */
/*                                                                  /    |      */
/*   Created: 9/5/21 by tilda                                    /      |      */
/*                                                              /        |      */
/*                                                            /    \  \ /       */
/*                                                           (      ) | |       */
/*                                                   ________|   _/_  | |       */
/*                                                 <__________\______)\__)      */
/* **************************************************************************** */


#include "../../../include/acutest.hpp"
#include "../../../src/ResponseAPI/Response/Response.hpp"
#include "../../../src/ResponseAPI/ResponseHead/ResponseHead.hpp"
#include "../../../test_utils/MockHostData.hpp"
#include <iostream>

void
testResponseHeadHTMLFileInRootLocation(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/index.html";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "text/html,*/*"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void testResponseHeadCSSFileInRootLocation(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/index.css";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "text/css,*/*"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: text/css\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadEmptyFileInRootLocation(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/index.js";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "*/*"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: */*\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadWithFile3MB(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/text_3MB.txt";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "text/html,*/*"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadWithRootLocation(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRoot();
	std::string uri = "/";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename + "root_file.html");
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "text/html,*/*"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}


void
testResponseHeadWithFileInNestedLocation_1(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataNestedDir();
	std::string uri = "/test_files/nestedDir";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "text/html,*/*"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadWithOneTypeFile(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/index.html";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "text/html"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadWithSeveralTypesFile(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/index.html";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8"));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadWithEmptyTypeFile(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/index.html";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	header.insert(std::pair<std::string, std::string>("accept", ""));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-type: \r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadWithoutTypeFile(void){
	requestHeaderStruct header;
	HostData *hostData = MockHostData::createDefaultHostDataRootTestFiles();
	std::string uri = "/index.html";
	std::string filename = "." + hostData->root + uri;
	std::string body = "";
	long sizeFile = getSizeFile(filename);
	header.insert(std::pair<std::string, std::string>("uri", uri));
	std::string expectedResponseData = "HTTP/1.1 200 OK\r\nContent-length: " + std::to_string(sizeFile) + "\r\n\r\n" + body;
	RequestData requestData = {.header = header, .body = ""};

	ResponseHead *response = new ResponseHead(requestData, hostData);
	TEST_CHECK(response->getDataToSend() == expectedResponseData);

	delete response;
	delete hostData;
}

void
testResponseHeadWithPicture(void){
	TEST_CHECK(false);
}

TEST_LIST = {
		{ "ResponseHead with HTML file", testResponseHeadHTMLFileInRootLocation },
		{ "ResponseHead with CSS file", testResponseHeadCSSFileInRootLocation },
		{ "ResponseHead with EMPTY file", testResponseHeadEmptyFileInRootLocation },

		{ "ResponseHead with 3 MB file", testResponseHeadWithFile3MB },
		{ "ResponseHead with ROOT LOCATION file", testResponseHeadWithRootLocation },
		{ "ResponseHead with NESTED LOCATION file", testResponseHeadWithFileInNestedLocation_1 },
		{ "ResponseHead with ONE TYPE FILE file", testResponseHeadWithOneTypeFile },
		{ "ResponseHead with SEVERAL TYPE FILE file", testResponseHeadWithSeveralTypesFile },
		{ "ResponseHead with EMPTY TYPE FILE file", testResponseHeadWithEmptyTypeFile },
		{ "ResponseHead with WITHOUT TYPE FILE file", testResponseHeadWithoutTypeFile },


		{ nullptr, nullptr }
};

