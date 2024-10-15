#ifndef WELDING_PATH_H
#define WELDING_PATH_H

#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <geometry_msgs/PoseStamped.h>
#include <vector>
#include <geometry_msgs/Pose.h>

#include <moveit/robot_state/conversions.h>

class weldingPath
{
private:
    std::vector<geometry_msgs::Pose> poses_; // Vector to store poses
    geometry_msgs::Pose startPose_;          // Pose for starting weld
    geometry_msgs::Pose endPose_;            // Pose for ending weld

    moveit::planning_interface::MoveGroupInterface move_group_;
    moveit_msgs::RobotTrajectory planned_trajectory_;

    ros::Publisher display_publisher_; // Publisher for RViz visualization

public:
    weldingPath();

    weldingPath(const std::string &planning_group);

    // Method to add a pose to the vector
    void addPose(const geometry_msgs::Pose &pose);

    // Method to get all poses
    std::vector<geometry_msgs::Pose> getPoses() const;

    // Method to get start pose
    geometry_msgs::Pose getStart() const;

    // Method to get end pose
    geometry_msgs::Pose getEnd() const;

    // Optional: method to clear all poses
    void clearPoses();

    // Optional: method to return the number of poses stored
    size_t poseCount() const;

    // Function to set poses and compute trajectory
    bool computeTrajectory();

    // Execute the planned trajectory
    void executeTrajectory();

    void setDisplayPublisher(const ros::Publisher &publisher);
};

#endif // WELDING_PATH_H