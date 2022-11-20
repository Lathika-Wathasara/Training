// File:          wall_following_cpp.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>

#include<webots/Motor.hpp>
#include<webots/DistanceSensor.hpp>

#define TIME_STEP 64
#define MAX_SPEED 6.28

#define proxy_range 65

// if this is 0, we can go forward, if there is no wall infront, or (if this is 1) it will have to go back until there is a path in right
int go_back_logic=0; 

// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();


  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);

  Motor *left_motor = robot-> getMotor("left wheel motor");
  Motor *right_motor = robot-> getMotor("right wheel motor");

  left_motor->setPosition(INFINITY);
  right_motor->setPosition(INFINITY);

  left_motor->setVelocity(0.0);
  right_motor->setVelocity(0.0);

  DistanceSensor*prox_sensors[8];
  for (int ind = 0; ind<8; ++ind)
  {
    std ::string ps_name = "ps" + std::to_string(ind);
    prox_sensors[ind] = robot->getDistanceSensor(ps_name);
    prox_sensors[ind]->enable(TIME_STEP);
  }

  double left_speed = MAX_SPEED;
  double right_speed = MAX_SPEED;

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(TIME_STEP) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();

    bool left_wall = prox_sensors[5]-> getValue() >proxy_range;
    bool front_wall = prox_sensors[7]-> getValue() > proxy_range +10;
    bool right_wall = prox_sensors[2]-> getValue() >proxy_range;
    // need a sensor for back

    // Process sensor data here.

    //if path in left, turn left
    if (left_wall == false)
    {
      left_speed = -MAX_SPEED;
      right_speed = MAX_SPEED;
    }
    //if path in front, drive forward
    else if (front_wall == false)
    {
      left_speed = MAX_SPEED ;
      right_speed = MAX_SPEED ;
    }
    
    //if path in right, drive right
    else if (right_wall == false)
    {
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED;
      go_back_logic =0 ;
    }
    //if no path, go back

    else if (front_wall == true)
    {
      left_speed = -MAX_SPEED;
      right_speed = -MAX_SPEED;
      go_back_logic = 1;
    }

    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);

    left_motor->setVelocity(left_speed);
    right_motor->setVelocity(right_speed);
  }

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
