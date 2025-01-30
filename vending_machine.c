Include libraries
#include <Servo.h>
#include <SoftwareSerial.h>
// Define constants
#define SERVO_PIN 9 // Servo motor pin (for dispensing product)
// Bluetooth communication (using SoftwareSerial)
SoftwareSerial BTserial (10, 11); // RX, TX (Bluetooth module pins)
// Create instance for Servo
Servo productServo;
// Variables
int productIndex = 0; // Keeps track of the selected product
void setup() {
// Initialize serial communication
Serial.begin(9600);
BTserial.begin(9600); // Start Bluetooth communication
// Initialize Servo
productServo.attach(SERVO_PIN);
productServo.write(0); // Initialize servo position to 0 (ready for dispensing)
}
void loop() {
// Check if Bluetooth data is available
if (BTserial.available()) {
char command = BTserial.read();
if (command == '1') { // Command to dispense product 1
productIndex = 1;
dispenseProduct();
} else if (command == '2') { // Command to dispense product 2
productIndex = 2;
dispenseProduct();
}
}
}
// Function to dispense the selected product
void dispenseProduct()
{ Serial.print("Dispensing Product ");
Serial.println(productIndex);
// Activate servo to dispense the product
productServo.write(90); // Rotate servo to 90 degrees to release product
delay(2000); // Wait for 2 seconds
productServo.write(0); // Reset the servo position
}