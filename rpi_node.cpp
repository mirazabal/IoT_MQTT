
#include "rpi_node.h"

rpi_node::rpi_node(std::string const& name){
	name_ = name;
}

rpi_node::~rpi_node(){

}

std::string rpi_node::get_name(){
	return name_;
}

void rpi_node::send_data(std::string const& name, std::string const& data){
	endpoint_.emit(name,data);
}

std::shared_ptr<sensor> rpi_node::get_sensor(std::string const& sensorName){
	return factory_.get_sensor(sensorName);
}

bool rpi_node::add_sensor( std::string const& name, std::shared_ptr<sensor> sP){
	return 	factory_.register_sensor(name, sP);	
}

void rpi_node::try_connect(std::string const& uri){
	endpoint_.connect(uri);
}

