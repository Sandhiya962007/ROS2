# ROS2


# ROS 2 Projects

## Overview
This repository contains ROS 2 projects demonstrating coordinate transformations using TF2, robot modeling with URDF, Python publisher-subscriber communication, and webcam integration.

## Project Structure

```text
project/
├── tf2/
│   ├── test1.cpp
│   ├── test2.cpp
│   ├── tf2_robot.urdf
│   └── README.md
├── number_publisher.py
├── number_subscriber.py
└── webcam.py
```

## 1. TF2 – Transformation System

**Files:**
- `test1.cpp` – C++ source file for a TF2-related ROS 2 node.
- `test2.cpp` – C++ source file for another TF2-related node.
- `tf2_robot.urdf` – URDF description of the robot model.
- `README.md` – Documentation for the TF2 project.

**Purpose:**
TF2 manages coordinate frames and transformations between different parts of a robot. The URDF file defines the robot's links and joints.

**Technologies:** ROS 2, C++, TF2, URDF.

## 2. Number Publisher

**File:** `number_publisher.py`

Publishes numerical data to a ROS 2 topic using a Python node.

**Purpose:**
- Generate and publish numbers.
- Demonstrate ROS 2 publisher functionality.
- Send messages to subscribed nodes.

## 3. Number Subscriber

**File:** `number_subscriber.py`

Subscribes to a ROS 2 topic and receives numerical messages from the publisher.

**Purpose:**
- Receive published numbers.
- Display incoming messages.
- Demonstrate ROS 2 subscriber functionality.

**Communication:** The number publisher and subscriber communicate through a ROS 2 topic.

## 4. Webcam Integration

**File:** `webcam.py`

A Python script for webcam integration.

**Purpose:**
- Access webcam video.
- Capture live video frames.
- Provide a foundation for computer vision applications.

**Technologies:** Python, OpenCV, webcam.

## Requirements

- Ubuntu Linux
- ROS 2
- C++ compiler
- Python 3
- OpenCV (`cv2`) for webcam processing
- Required ROS 2 packages for TF2 and robot modeling

## Learning Objectives

- Understand coordinate transformations using TF2.
- Describe robot structures using URDF.
- Implement ROS 2 publisher-subscriber communication.
- Access a webcam using Python and OpenCV.
- Build a foundation for robotics and computer vision applications.
