#include<SoftwareSerial.h>

#define Motor1IN1 9
#define Motor1IN2 10
#define Motor2IN3 11
#define Motor2IN4 12
#define pwm1 6 //variable out
#define pwm2 5 //variable out
char B;


void setup() {
Serial.begin(9600);

pinMode (Motor1IN1, OUTPUT );
pinMode (Motor1IN2, OUTPUT );
pinMode (Motor2IN3, OUTPUT );
pinMode (Motor2IN4, OUTPUT );
pinMode (pwm1, OUTPUT );
pinMode (pwm2, OUTPUT );
}

void loop() {
  digitalWrite(Motor1IN1, HIGH);
  digitalWrite(Motor1IN2, LOW);
  digitalWrite(Motor2IN4, HIGH);
  digitalWrite(Motor2IN3, LOW);
  analogWrite(pwm1, 200);
  analogWrite(pwm2, 200);
}
/*if (Serial.available() ) { 
  B = Serial.read();
  Serial.println(B);
  }
  if (B=='F')
  {
    forward();
  }
  else if (B=='B')
  {
     back();
  }
  else if (B=='R')
  {
     right();
  }
    else if (B=='L')
  {
    left();
  }
    else if (B=='I')
  {
    forwardRight();
  }
   else if (B=='G')
  {
     forwardLeft();
  }
    else if (B=='J')
  {
     BackRight();
  }
    else if (B=='H')
  {
   BackLeft();
  }
  else 
 {stop();}
}



void forward() {
  digitalWrite(Motor1IN1, HIGH);
  digitalWrite(Motor1IN2, LOW);
  digitalWrite(Motor2IN4, HIGH);
  digitalWrite(Motor2IN3, LOW);
  analogWrite(pwm1, 100);
  analogWrite(pwm2, 100);
}

void back() {
  digitalWrite(Motor1IN1, LOW);
  digitalWrite(Motor1IN2, HIGH);
  digitalWrite(Motor2IN4, LOW);
  digitalWrite(Motor2IN3, HIGH);
  analogWrite(pwm1, 100);
  analogWrite(pwm2, 100);
}

void left(){
  digitalWrite(Motor1IN1, LOW);
  digitalWrite(Motor1IN2, HIGH); //analogWrite(Motor1IN2, HIGH); to back
  digitalWrite(Motor2IN4, HIGH);
  digitalWrite(Motor2IN3, LOW);
  analogWrite(pwm1, 100);
  analogWrite(pwm2, 100);
}

void right (){
  digitalWrite(Motor1IN1, HIGH);
  digitalWrite(Motor1IN2, LOW);
  digitalWrite(Motor2IN4, LOW);
  digitalWrite(Motor2IN3, HIGH); //analogWrite(Motor2IN3, HIGH); to back
  analogWrite(pwm1, 100);
  analogWrite(pwm2, 100);
}

void forwardRight(){
  analogWrite(pwm1,0);
  analogWrite(pwm2, 100);
  digitalWrite(Motor1IN1, HIGH);
  digitalWrite(Motor1IN2, LOW);
  digitalWrite(Motor2IN4, HIGH);
  digitalWrite(Motor2IN3, LOW);
}

void forwardLeft(){
  analogWrite(pwm1, 100);
  analogWrite(pwm2, 0);
  digitalWrite(Motor1IN1, HIGH);
  digitalWrite(Motor1IN2, LOW);
  digitalWrite(Motor2IN4, HIGH);
  digitalWrite(Motor2IN3, LOW);
}
/*
void BackRight(){
  analogWrite(pwm1, 25);
  analogWrite(pwm2, 255);
  digitalWrite(Motor1IN1, LOW);
  digitalWrite(Motor1IN2, HIGH);
  digitalWrite(Motor2IN4, LOW);
  digitalWrite(Motor2IN3, HIGH);
}

void BackLeft(){
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 25);
  digitalWrite(Motor1IN1, LOW);
  digitalWrite(Motor1IN2, HIGH);
  digitalWrite(Motor2IN4, LOW);
  digitalWrite(Motor2IN3, HIGH);
}*/

/*void stop() {
  digitalWrite(Motor1IN1, LOW);
  digitalWrite(Motor1IN2, LOW);
  digitalWrite(Motor2IN4, LOW);
  digitalWrite(Motor2IN3, LOW);
}*/










/*#include <stdint.h>
#include "tm4c123gh6pm.h"  // TM4C123 specific header

// Define the LED pin and Timer configuration
#define LED_PIN 0x02           // PF1 on TM4C123
#define TIMER_INTERVAL 16000000 // 1-second interval with 16 MHz clock

void Timer0A_Init(void);
void GPIO_Init(void);

int main(void) {
    GPIO_Init();       // Initialize GPIO for LED
    Timer0A_Init();    // Initialize Timer0A for periodic interrupts

    while (1) {
        // Main loop remains empty as LED toggling is handled by Timer ISR
    }
}

// Initialize GPIO for the LED
void GPIO_Init(void) {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;        // Enable clock for Port F
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5) == 0) {}; // Wait until port is ready

    GPIO_PORTF_DIR_R |= LED_PIN;                   // Set LED_PIN as output
    GPIO_PORTF_DEN_R |= LED_PIN;                   // Enable digital function for LED_PIN
}

// Initialize Timer0A to generate an interrupt every 1 second
void Timer0A_Init(void) {
    SYSCTL_RCGCTIMER_R |= 1;                      // Enable clock for Timer0
    TIMER0_CTL_R = 0;                             // Disable Timer0A during setup
    TIMER0_CFG_R = 0x00000000;                    // Configure for 32-bit timer mode
    TIMER0_TAMR_R = 0x02;                         // Configure for periodic mode
    TIMER0_TAILR_R = TIMER_INTERVAL - 1;          // Load interval value
    TIMER0_IMR_R |= 0x01;                         // Enable TimerA timeout interrupt
    NVIC_EN0_R = 1 << 19;                         // Enable IRQ 19 in NVIC (Timer0A)
    TIMER0_CTL_R |= 0x01;                         // Enable Timer0A
}

// Timer0A interrupt handler
void Timer0A_Handler(void) {
    TIMER0_ICR_R = 0x01;                         // Clear Timer0A timeout flag
    GPIO_PORTF_DATA_R ^= LED_PIN;                // Toggle LED
}

//Mariam Tarek Abdelnaby


#include <stdint.h>
#include "tm4c1294ncpdt.h"  // TM4C129 specific header

// Define the LED pin and Timer configuration
#define LED_PIN 0x01           // PN0 on TM4C129
#define TIMER_INTERVAL 120000000 // 1-second interval with 120 MHz clock

void Timer0A_Init(void);
void GPIO_Init(void);

int main(void) {
    GPIO_Init();       // Initialize GPIO for LED
    Timer0A_Init();    // Initialize Timer0A for periodic interrupts

    while (1) {
        // Main loop remains empty as LED toggling is handled by Timer ISR
    }
}

// Initialize GPIO for the LED
void GPIO_Init(void) {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;       // Enable clock for Port N
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12) == 0) {}; // Wait until port is ready

    GPIO_PORTN_DIR_R |= LED_PIN;                    // Set LED_PIN as output
    GPIO_PORTN_DEN_R |= LED_PIN;                    // Enable digital function for LED_PIN
}

// Initialize Timer0A to generate an interrupt every 1 second
void Timer0A_Init(void) {
    SYSCTL_RCGCTIMER_R |= 1;                      // Enable clock for Timer0
    TIMER0_CTL_R = 0;                             // Disable Timer0A during setup
    TIMER0_CFG_R = 0x00000000;                    // Configure for 32-bit timer mode
    TIMER0_TAMR_R = 0x02;                         // Configure for periodic mode
    TIMER0_TAILR_R = TIMER_INTERVAL - 1;          // Load interval value
    TIMER0_IMR_R |= 0x01;                         // Enable TimerA timeout interrupt
    NVIC_EN0_R = 1 << 19;                         // Enable IRQ 19 in NVIC (Timer0A)
    TIMER0_CTL_R |= 0x01;                         // Enable Timer0A
}

// Timer0A interrupt handler
void Timer0A_Handler(void) {
    TIMER0_ICR_R = 0x01;                         // Clear Timer0A timeout flag
    GPIO_PORTN_DATA_R ^= LED_PIN;                // Toggle LED
}
//Mariam Tarek Abdelnaby*/