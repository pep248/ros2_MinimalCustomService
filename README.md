# ros2_MinimalCustomService

This repository can be used as an example on how to use a custom ros2 service.

It has been created from the [ROS 2 examples](https://github.com/ros2/examples/tree/humble) repo.
This package has been highly simplified with respect to its predecessor in order to have an even more basic example.
When an integer is provided it simply counts up to said integer, providing the array of all the previous values as feedback and returning a `true` if the tasks succeeds.


## Folders
* Inside the [custom_service](custom_service) folder, we can find the package with the custom service definition
* Inside the [minimal_service](minimal_service) folder, we can find the codes for both, the service server and the client server files as well as the python launch file to launch both.

## Commands

To download this repo and run the mentioned nodes, use the following commands:

### Download and install the package
Create a folder:
```
mkdir ros2_ws
cd ros2_ws
```

Download the repo
```
git clone https://github.com/pep248/ros2_MinimalCustomService.git
```

Compile the packages:
```
colcon build --packages-select custom_service minimal_service
```

Source the environment:
```
source install/setup.bash
```
### Run the server
Now you can either run the server node manually and make a request through the terminal, or use the launch file that runs the server node and a client node that makes a request with a "goal: 10".

#### Manual server and requests
To run the server and the client, you can simply run the launch file using the following command:
```
ros2 launch minimal_service minimal_service.launch.py 
```

#### Manual server and requests
If instead you prefer to run the server manually, you can type the following:

Run the server:
```
ros2 run minimal_service minimal_service_server 
```

Open another terminal and make a manual requests:
```
ros2 action send_goal /custom_service custom_service/srv/CustomService 'goal: 10'
```

## Author
* Josep Rueda Collell: rueda_999@hotmail.com


