// Pin Definitions
const int pwmPin = 9;        // PWM output for audio signal
const int monitorPin = A0;   // Analog pin to monitor LM386 output (optional)

// Variables
int audioFrequency = 1000;   // Test audio frequency in Hz (default: 1 kHz)

void setup() {
  // Pin configurations
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  generateAudio();     // Generate a test PWM audio signal
  monitorOutput();     // Monitor the amplified signal (optional)
}

// Function: Generate Audio Signal
void generateAudio() {
  // Generate a 1 kHz sine wave using PWM
  for (int i = 0; i < 360; i++) {
    int value = 127 + 127 * sin(radians(i)); // Sine wave values
    analogWrite(pwmPin, value);
    delayMicroseconds(1000000 / (360 * audioFrequency)); // Adjust frequency
  }
}

// Function: Monitor Amplifier Output (Optional)
void monitorOutput() {
  int amplifiedSignal = analogRead(monitorPin); // Read amplified signal from LM386
  Serial.print("Amplified Signal: ");
  Serial.println(amplifiedSignal); // Display signal value on Serial Monitor
  delay(100); // Adjust sampling rate as needed
}
