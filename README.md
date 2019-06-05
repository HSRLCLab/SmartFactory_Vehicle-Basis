# SmartFactory_Vehicle-Basis

The [SmartFactory_Vehicle-Basis](https://github.com/LMazzole/SmartFactory_Vehicle-Basis) is an modular part of the SmartFactory Project.  

[SmartFactory_Vehicle-Basis](https://github.com/LMazzole/SmartFactory_Vehicle-Basis) is a Vehicle which is equipped with a drive, sensors (line-detection, ~~sonar and a camera~~) and a hoist. It consists of three modules:

* Environment-Detection
* Drive-Control
* Hoist-Control

 Multiple nested  Finite State Machines (FSM) based on the pattern of the [ArdFSM](<https://github.com/LMazzole/ArdFSM>) are used to control the processes.

<!-- add Pagebreak: <div style="page-break-after: always;"></div> -->

## Table of Content

<!-- TOC Generated with https://magnetikonline.github.io/markdown-toc-generate/ -->

[TOC]

## The SmartFactroy Project

[SmartFactory_Vehicle-Basis](https://github.com/LMazzole/SmartFactory_Vehicle-Basis) is part of the SmartFactory-Project. It provides a library with basic vehicle functions.

Other SmartFactory-Components are:
* [SmartFactory_MQTTCommunication](https://github.com/LMazzole/SmartFactory_MQTTCommunication)

A possible implementation of the SmartFactory-Project can be seen in the  Sortic-Showcase:

<img src="./docs/images/RepoOverview.png" height="300"/>

The associated  Repositorys are:  
  [SmartFactory-Sortic](https://github.com/LMazzole/SmartFactory-Sortic)  
  [SmartFactory_Box-Sortic](https://github.com/LMazzole/SmartFactory_Box-Sortic)  
  [SmartFactory_Vehicle-Sortic](https://github.com/LMazzole/SmartFactory_Vehicle-Sortic)  
  [SmartFactory_Vehicle-Basis](https://github.com/LMazzole/SmartFactory_Vehicle-Basis)  
  [SmartFactory_MQTTCommunication](https://github.com/LMazzole/SmartFactory_MQTTCommunication)  

## Tools and Technologies

The source-code is written in C++.
To achieve this project, the following listed tools and technologies were used.

### Doxygen
Doxygen is used for the documentation of the source-code.  
An intorduction to *Doxygen* and how to install it can be found in the [ArdFSM-Repo](https://github.com/LMazzole/ArdFSM#documentation-with-doxygen).  

### VSCode PlatformIO
The used  IDE is [VSCode](https://code.visualstudio.com/) with the [PlatformIO](https://platformio.org/platformio-ide)-Extension.

### MQTT
For a description of the MQTT-Technologie take a look at the [MQTTCommunication-ReadMe](<https://github.com/LMazzole/SmartFactory_MQTTCommunication#mqtt>).   


# Documentation

## Hardware

<img src="./docs/images/HardwareSV.png" width="600"/>
<img src="./docs/images/HardwareSV2.png" width="600"/>
[Source: FTS, BA FS18, Huber,Paly]

To build a SmartVehicle the following hardware is needed:

* 1x [Adafruit Feather M0 WiFi - ATSAMD21 + ATWINC1500](https://www.adafruit.com/product/3010) from Adafruit.
* 1x [DC Motor + Stepper FeatherWing Add-on ](<https://www.adafruit.com/product/2927>)
* 3x Battery with an JST 2.0 Connection
* 1x [PixyCam](<https://pixycam.com/>)
* 1x Sonar - [HC-SR04](<https://www.play-zone.ch/de/ultraschall-distanzmesser-hc-sr04.html>)
* 5x IR Sensor - [IR-Sensor breakout-board](<https://www.play-zone.ch/de/reflektions-spur-sensor-breakout.html>)
* 1x Servo for Hoist - [Bluebird Midi-Servo BMS-390](<https://www.conrad.ch/de/p/bluebird-midi-servo-bms-390-dmh-digital-servo-getriebe-material-metall-stecksystem-jr-275487.html?insert=62>)
* 1x Servo for Cam and Sonar - [SG92R Adafruit 169](<https://www.conrad.ch/de/p/motor-micro-servo-sg92r-adafruit-169-1516595.html?insert=62>)
* 2x Drive Lego - [LEGO® Power Functions M-Motor](<https://shop.lego.com/de-CH/product/LEGO-Power-Functions-M-Motor-8883>)

For detailed building instructions please contact [Felix Nyffenegger](mailto:felix.nyffenegger@hsr.ch).
## Software

All functions and files are documented on the [GitHub-Page](<https://lmazzole.github.io/SmartFactory_Vehicle-Basis/>).  

It's important to mention that all functions are non blocking and as short as possible so no other process starves.

The Sonar and PixyCam functionalities are not implemented at the moment and are ~~crossed out~~.

The interface is documented in [DriveCtrl](<https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_drive_ctrl.html>), [EnvironmentDetection](<https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_environment_detection.html>) and [HoistCtrl](<https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_hoist_ctrl.html>).

### Dependency Graph

[<img src="./docs/_drive_ctrl_8h__incl.png" width="550"/>](https://lmazzole.github.io/SmartFactory_Vehicle-Basis/_drive_ctrl_8h.html)

[<img src="./docs/_hoist_ctrl_8h__incl.png" width="450"/>](https://lmazzole.github.io/SmartFactory_Vehicle-Basis/_hoist_ctrl_8h.html)

Extern Libraries:  

- [Adafruit Motor Shield V2 Library]()
- [Arduino PID](https://github.com/br3ttb/Arduino-PID-Library/)
- [Servo](<https://www.arduino.cc/en/Reference/Servo>)
- ~~[NewPing](<https://playground.arduino.cc/Code/NewPing/>)~~

### Collaboration Diagram
 [<img src="./docs/class_drive_ctrl__coll__graph.png" width="300" />](https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_drive_ctrl.html)       [<img src="./docs/class_hoist_ctrl__coll__graph.png" width="120" />](https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_hoist_ctrl.html)  



### Important Functions and Files

#### HardwareConfiguration.h

In HardwareConfiguration.h are all important settings for the Vehcile-Hardware defined:  

- Setup for Drive
	- Speed, Motor-Pins, PID-Values
- Setup for the Linedetector
	- Pin-Number
- Setup for Hoist
	- Pin-Number, Delay, minimal and maximal position 
- ~~Setup for Sonar~~
- ~~Setup for Vision~~




## FAQ's

#### I'd like to use this code in my project. What do I need to know?  
> All you need to do is at the GitHub-Link to this Repo under *lib_deps* in your platformio.ini File and your good to go. All dependencies are downloaded automatic. The interface is documented in [DriveCtrl](<https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_drive_ctrl.html>), [EnvironmentDetection](<https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_environment_detection.html>) and [HoistCtrl](<https://lmazzole.github.io/SmartFactory_Vehicle-Basis/class_hoist_ctrl.html>).

### ToDo's

#### Hardware

- [ ] The battery of the vehicle must be recharged by hand. Inductive charging while waiting would be desirable.
- [ ] Sensors for line recognition have an unfavourable distance to the turning point. They should be placed closer to the vehicle axis to increase the accuracy of alignment.

#### Software

The open ToDo's can be found in the Documentation on the [GitHub-Page](https://lmazzole.github.io/SmartFactory_Box-Sortic/todo.html)

- [ ] Implement Sonar
- [ ] Implement Vision
## Contributors

- [Luca Mazzoleni](https://github.com/LMazzole)
- Glenn Patrick Huber
- Robert Paly

## Changelog

V 1.0	-	Release BA FS19	-	[Luca Mazzoleni](https://github.com/LMazzole)

## License

[TODO]

