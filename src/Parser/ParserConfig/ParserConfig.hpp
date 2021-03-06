#ifndef PARSER_CONFIG
# define PARSER_CONFIG

# include "Config.hpp"
# include <iostream>
# include <fstream>
# include <map>
# include <list>
# include <cmath>
# include <climits>
# include "HostTypes.hpp"
# include "utils.hpp"

class Config;

typedef struct {
	std::string 				path;
	std::string 				extension;
	std::string 				root;
	std::string 				ip;
	std::string 				port;
} CgiParser;

/*
** Класс читает данные из конфигурационного файла и парсит их
*/

class ParserConfig {
	private:
		CgiParser	*_cgi;

	public:
		ParserConfig();
		~ParserConfig();
		Config*					parse(char* configFilePath);
		std::vector<HostData*>	devideConfigToComponents(std::list<std::string> config);
		void	readConfigFile(char *configFilePath, std::list<std::string> *config);
		bool	checkConfigString(std::string data);
		void	fillHostData(HostData *host, std::list<std::string>::iterator *it);
		void	checkHostData(HostData *host);
		void	enterDataToHostDataStruct(std::string const &key,
				std::string const &value, HostData *hostData, bool *isLocation);
		void	setDefaultHostValues(HostData *hostData);
		void	setLocationDefaultValue(Location *location);
		void	cleanUpHost(HostData *hostData);

		/*			SETTERS			*/

		void	setListenData(std::string data, HostData *hostData);
		void	setServerNameData(std::string data, HostData *hostData);
		void	setRootData(std::string data, HostData *hostData);
		void	setErrorPageData(std::string data, HostData *hostData);
		void	setClientMaxBodySizeData(std::string data, HostData *hostData);
		void	setClientMaxBodySizeData(std::string data, Location *location);
		void	setLocationWayData(std::string data, HostData *hostData);
		void	setLocationDetailsData(std::string data, HostData *hostData);
		void	setRedirectToLocation(std::string data, Location *location);
		void	setRootDataToLocation(std::string data, Location *location);
		void	setMethodsToLocation(std::string data, Location *location);
		void	setAutoindexToLocation(std::string data, Location *location);
		void	setIndexToLocation(std::string data, Location *location);
		void	setUploadEnableToLocation(std::string data, Location *location);
		void	setUploadPathToLocation(std::string data, Location *location);
		void	setCgiParserData(std::string data, std::string type,
				HostData *hostData, Location *location);

		class ParserConfigException : public std::exception {
			private:
				const char *msg;
			public:
				ParserConfigException(const std::string message) {
					msg = message.c_str();
				}
				
				virtual const char *what() const throw() {
					return msg;
				}
		};

};

#endif