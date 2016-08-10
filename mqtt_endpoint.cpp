
#include "mqtt_endpoint.h"
#include <iostream>

namespace mirazabal
{
namespace mqtt_end
{

	mqtt_endpoint::mqtt_endpoint()
	{
	
	}

	mqtt_endpoint::~mqtt_endpoint()
	{
	
	}

	// returns the connection ID
	int mqtt_endpoint::connect(std::string const & uri)
	{
		client_ = std::move(std::unique_ptr<mqtt::async_client> (new mqtt::async_client( uri,  "client_id" )));
		mqtt::itoken_ptr conntok = client_->connect();
		std::cout << "Waiting for the connection..." << std::flush;
		conntok->wait_for_completion();
		std::cout << "OK" << std::endl;

		return 0;
	}
	void mqtt_endpoint::emit(std::string const& msg_name, std::string const& msg)
		{
		
		mqtt::message_ptr pubmsg = std::make_shared<mqtt::message>(msg);
		// First use a message pointer.
			std::cout << "Sending message..." << std::flush;
			const int QOS = 1;
			pubmsg->set_qos(QOS);
			const int TIMEOUT = 10000;
			client_->publish(msg_name, pubmsg)->wait_for_completion(TIMEOUT);
			std::cout << "OK" << std::endl;
		}
} // namespace mqtt
} // namespace mirazabal



