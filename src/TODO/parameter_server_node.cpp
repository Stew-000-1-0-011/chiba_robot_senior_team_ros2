#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <common_settings.hpp>
using namespace common_settings::topic;
#include <server.h>

namespace parameter_server_node{
    //it is like dynamic reconfigure on nodelet
    //it can be used to change double parameter on runtime
    class ParameterServerNode : public nodelet::Nodelet
    {
        private:
            ros::NodeHandle nodehandle_;
            dynamic_reconfigure::Server server;
            
        public:
            void callback(chiba_robot_senior_team::ParameterConfig& config, uint32_t level)
            {
            ROS_INFO("Reconfigure Request: %d %f %s %s %d", config.int_param, config.double_param, config.str_param.c_str(),
                    config.bool_param ? "True" : "False", config.size);
            }

        public:
            void onInit()override{
                nodehandle_ = getMTNodeHandle();
                NODELET_INFO("1");
                server.onInit(nodehandle_);
                                NODELET_INFO("2");
                // dynamic_reconfigure::Server::CallbackType function;
                //                 NODELET_INFO("3");
                // function = boost::bind(&ParameterServerNode::callback,this, _1, _2);
                //                 NODELET_INFO("4");
                // server.setCallback( function);
                // NODELET_INFO("5");
            }

    };
}
PLUGINLIB_EXPORT_CLASS(parameter_server_node::ParameterServerNode, nodelet::Nodelet)