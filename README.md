# Leakage Detection and Broadcast
 
This project can be used in homes, offices and buildings to alert the residents on their WiFi-enabled devices about a possible gas leakage.
In this project an `ESP8266` Node is used at the center of the various `Arduino UNO` nodes are installed at possible gas leakage points. In this project a `MQ-5` gas sensor is used to detect the leakage of gas in-situ. The data output from the gas leakage sensor (which monitors the gas levels) is relayed to the ESP8266 node via `SPI`.
In an event of gas leakage, the spike in concentration of gaseous levels will trigger an emergency event which is relayed on to the ESP8266 server hosted on the local WiFi. 
I have also developed an Android application which constantly monitors the ESP866 server for any emergency warning and alerts the user by visual and aural warnings, which gives them an advantage of early evacuation and curtailing the emergency before it becomes a disaster.

However, this project is still open to some improvements. I have listed some modifications that can improve the capabilities in a real-life deployment of this system:
* In addition to MQ-5 sensor, multiple sensors can be added to the Arduino node to detect levels of different gases. In addition to that, fire detection sensors can also be interfaces with the Arduino
* The data is currently sent only to the localhost which requires the devices to be connected to same WiFi network. The infrastructure can be moved to globally available databases like Firebase.
* App needs to constantly monitor the server, and this reduces the stability and efficiency of the Android application. A better alternative would be implementing webhooks, which are faster and more reliable.
