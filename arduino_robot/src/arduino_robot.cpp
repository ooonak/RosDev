#include <iostream>
#include <string>

#include "ros/ros.h"
#include "arduino_robot/ArmMotors.h"
#include "arduino_robot/MotorSpeed.h"

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "arduino_robot");
    ros::NodeHandle nh;

    ros::Publisher arm_pub = 
        nh.advertise<arduino_robot::ArmMotors>("/arduino_robot/arm_motors", 1000);
    ros::Publisher speed_pub = 
        nh.advertise<arduino_robot::MotorSpeed>("/arduino_robot/motor_speed", 1000);

    ros::Rate loop_rate(1);
    int count = 0;
    int speed = 100;

    while (ros::ok()) {
        if (count < 2) {
            arduino_robot::ArmMotors am;
            am.state = 1;
            arm_pub.publish(am);

            ROS_INFO("Arduino robot: publish arm_motors %d", am.state);
        }

        arduino_robot::MotorSpeed ms;
        ms.m1 = speed;
        ms.m2 = speed;
        speed_pub.publish(ms);
        ROS_INFO("%d Arduino robot: publish motor_speed %d, %d", 
                count, ms.m1, ms.m2);

        // Let's speed up
        if (count == 20)
            speed = 150;

        if (count == 40)
            speed = 200;

        if (count == 60)
            speed = 250;

        // Disarm
        if (count == 90) {
            arduino_robot::ArmMotors am;
            am.state = 0;
            arm_pub.publish(am);

            ROS_INFO("Arduino robot: publish arm_motors %d", am.state);
        }

        ros::spinOnce();
        loop_rate.sleep(); 
        ++count;

        // Stop
        if (count == 100)
            break;

    }

    return 0;
}

