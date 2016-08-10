#ifndef rpi_node_h
#define rpi_node_h


#include "sensor.h"
#include "rpi_sensor_factory.h" 

//#include "include/websocket_endpoint.h"
#include "mqtt_endpoint.h"


#include <string>
#include <memory>

class rpi_node{

	public:
		rpi_node(std::string const& name);
		~rpi_node(); 	

		std::string get_name();
		bool add_sensor( std::string const& name, std::shared_ptr<sensor> sP);
		std::shared_ptr<sensor> get_sensor(std::string const& sensorName);
		void try_connect(std::string const& uri);
		void send_data(std::string const& name, std::string const& data);

	private:
		rpi_sensor_factory factory_;
		std::string name_;
//		mirazabal::sio::websocket_endpoint endpoint_;

		mirazabal::mqtt_end::mqtt_endpoint endpoint_;

};



#endif
