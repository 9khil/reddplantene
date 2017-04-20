This is an BONUS EXERCICE if you have spare time at the end of the course.

STEPS

1. Download Blynk App on your mobile phone
2. Using the Blynk app, register an account and create a new project. Select Device "Wemos D1 mini" and connection type "Wifi"
3. Retrieve app key sent to your email address used to register account.
4. Using Arduino Studio, go to Tools - Library Manager - Manage Libraries
5. Install Blynk library (newest version)
6. Using Android Studio:
	Create a NEW project (do not base this project on the previous code base you created in the course)

	Include libraries, enable serial logging and define your Auth token:
		#define BLYNK_PRINT Serial
		#include <ESP8266WiFi.h>
		#include <BlynkSimpleEsp8266.h>
		char auth[] = "INSERT-YOUR-AUTH-TOKEN";
		
	In the setup-function, configure Blynk
		Blynk.config(auth);
		Blynk.connect();
		
	In the loop function, execute blynk	
		Blynk.run();
7. TASK: Try to retrieve the in the blynk App on your mobile phone
8. TASK: Try to blink the LED on the IoT-thing using your mobile phone (tip, pin D4)








