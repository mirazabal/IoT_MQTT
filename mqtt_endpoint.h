#ifndef MQTT_ENDPOINT_
#define MQTT_ENDPOINT_


#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif 

#include "include/mqtt/async_client.h"

#include <string>
#include <memory>

namespace mirazabal
{
namespace mqtt_end
{

class mqtt_endpoint
{
	public:
		mqtt_endpoint();
		virtual ~mqtt_endpoint();

		// returns the connection ID
		int connect(std::string const & uri);
		void emit(std::string const& msg_name, std::string const& msg);

	private:
		std::unique_ptr<mqtt::async_client> client_;


};


} // namespace mqtt
} // namespace mirazabal


#endif
