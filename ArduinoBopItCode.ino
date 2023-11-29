#include <SD.h> // need to include the SD library
#define SD_ChipSelectPin 4 //connect pin 4 of arduino to cs pin of sd card
#include <TMRpcm.h> //Arduino library for asynchronous playback of PCM/WAV files
#include <SPI.h> //  need to include the SPI library

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Adafruit_MMA8451 mma = Adafruit_MMA8451();

// define the thresholds for the acceleration and the slide switch for those inputs
int thresholdAcceleration = 1;
int thresholdSlideSwitch = 10;

// pick a random song

// there are three songs, randomly choose a song to play out of the three possible songs

// generate random number between 1 and 3
int randNumberforSongSelection = random(1, 4);

// setup buttons
  const int button1Pin = 7;
  const int button2Pin = 6;
  //const int button3Pin = 5;
  //const int button4Pin = 6;
  const int slideSwitchPin = A0;
  const int ledPin = 4;

// setting up score variable
int score = 0;

// game loop variable
bool gameLoop = false;

// int for setting the time interval that the program waits for the user to react to the command
// making on the long side at first to give user plenty of time in beginning
int timeInterval = 4000;

TMRpcm tmrpcm; // create an object for use in this sketch

void setup() {
  // define the speaker pin
  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  // put your setup code here, to run once:

  // start the serial input for debugging purposes
  Serial.begin(9600);

  // accelerometer setup code

  Serial.println("Adafruit MMA8451 test!");
  

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

  lcd.init();
  lcd.backlight();
  lcd.clear();
  

  // Display welcome message
  Serial.println("Welcome to Bop-It!");
  lcd.println("Welcome to Bop-It!");


 
  // setup the pins for the user inputs
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  //pinMode(button3Pin, INPUT);
  //pinMode(button4Pin, INPUT);

  
  pinMode(slideSwitchPin, INPUT);
  
  // setup the LED
  pinMode(ledPin, OUTPUT);


  // setup the LCD display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  

  


 // start playing the randomly selected song

  if (randNumberforSongSelection == 1) {

    // start playing the first song
    tmrpcm.setVolume(5); //
    tmrpcm.play("Song1.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
                          //try to provide the file name with extension
    
  }

  if (randNumberforSongSelection == 2) {

    // start playing the second song
    tmrpcm.setVolume(5); //
    tmrpcm.play("Song2.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
                          //try to provide the file name with extension

  }

  if (randNumberforSongSelection == 3) {

    // start playing the third song
    tmrpcm.setVolume(5); //
    tmrpcm.play("Song3.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
                          //try to provide the file name with extension

  }


  



}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state of the pushbutton values
  
  // using the states as the three game inputs, as well as the start game button

  // reading state of start game
  int startState = 0;
  startState = digitalRead(button1Pin);

  // wait a few seconds and countdown
  lcd.clear();
  lcd.println("5");
  delay(1000);
  lcd.clear();
  lcd.println("4");
  delay(1000);
  lcd.clear();
  lcd.println("3");
  delay(1000);
  lcd.clear();
  lcd.println("2");
  delay(1000);
  lcd.clear();
  lcd.println("1");
  delay(1000);
  startState = HIGH;

  if (startState == HIGH) {
    lcd.clear();
    
    Serial.println("Game starting in 3...");
    lcd.println("Game starting in 3...");
    delay(1000);

    lcd.clear();

    Serial.println("Game starting in 2...");
    lcd.println("Gane starting in 2...");
    delay(1000);


    lcd.clear();


    Serial.println("Game starting in 1...");
    lcd.println("Game starting in 1...");
    delay(1000);

    lcd.clear();


    // enter the game loop
    gameLoop = true;
  }


  // if the game loop variable is set to true, begin the game loop
  if (gameLoop == true) {
    while (true) {
      // start of the game loop

      // generate random number between 1 and 3
      int randNumber = random(1,4);

      // This random number, different for each iteration, will be the number of the correct input, which is considered the correct input, the other inputs are incorrect
      // This will change every iteration of the game loop/cycle
      // each game cycle will have one command

      // audio output of command that tells user to do input that is randomly selected

      // play the command audio

      // visual output of the command

      // display visual output on the LCD display/8 segment display/any other visual displays that we have

      // printing outputs to serial so we can observe the command in the Serial output for debugging purposes

      // printing command to user, telling user what input they must provide
      // also audio output of command is played out of the speakers
      if (randNumber == 1) {
        lcd.clear();
        Serial.println("Press it!");
        lcd.println("Press it!");
        tmrpcm.play("PressIt.wav");
      }
      else if (randNumber == 2) {
        lcd.clear();
        Serial.println("Slide it!");
        lcd.println("Slide it!");
        tmrpcm.play("SlideIt.wav");
      }
      else if (randNumber == 3) {
        lcd.clear();
        Serial.println("Spin it!");
        lcd.println("Spin it!");
        tmrpcm.play("SpinIt.wav");
      }

      // decreasing the time interval of waiting
      timeInterval -= 50;

      

      // detection code


      // detect if each user input is pressed or not
      bool pushed = false;
      bool spun = false;
      bool slid = false;

      // reading state of the pushbutton values: the three game inputs
      int pushedButtonState = 0;
      int spunState = 0;
      int slidState = 0;
      int currentSlidState = 0;
      int previousSlidState = 0;

      pushedButtonState = digitalRead(button2Pin);
      //spunState = digitalRead(button3Pin);

      // reading the slide switch
      currentSlidState = analogRead(slideSwitchPin);

      int x = abs(currentSlidState - previousSlidState); 

      if (x > thresholdSlideSwitch) {
        slidState = HIGH;
      }

      // update the previousSlidState
      previousSlidState = currentSlidState;
      

      // for the spinning, detect if the X, Y, or Z acceleration exceeds the threshold, if so, a spun has been detected
      mma.read();
      sensors_event_t event;
      mma.getEvent(&event);

      if (event.acceleration.x > thresholdAcceleration || event.acceleration.y > thresholdAcceleration || event.acceleration.z > thresholdAcceleration) {
        // a spin has been detected if the X, Y, or Z acceleration exceeds the threshold
        spunState = HIGH;
      }

      

      if (pushedButtonState == HIGH) {
        pushed = true;
      }
      if (spunState == HIGH) {
        spun = true;
      }
      if (slidState == HIGH) {
        slid = true;
      }

      // game logic

      // detect if any incorrect inputs are inputted by user and detect for correct inputs


      // if incorrect inputs, the game is over

      // give the user time to react to the command
      // program waits for some time
      delay(timeInterval);



      // if the correct input (and only the correct input, no incorrect inputs) is inputted by the user, then the user's score will increase by 1
      if (randNumber == 1) {
        if (pushed == false || spun == true || slid == true) {
          lcd.clear();
          Serial.println("Incorrect input!");
          Serial.println("Game over!");

          lcd.println("Incorrect input!");
          delay(5000);
          lcd.clear();
          lcd.println("Game over!");

          gameLoop = false;
          break;
        }
      }
      
      if (randNumber == 2) {
        if (pushed == true || spun == false || slid == true) {
          lcd.clear();
          Serial.println("Incorrect input!");
          Serial.print("Game over!");

          lcd.println("Incorrect input!");
          delay(5000);
          lcd.clear();
          lcd.print("Game over!");

          gameLoop = false;
          break;
        }
      }

      if (randNumber == 3) {
        if (pushed == true || spun == true || slid == false) {
          lcd.clear();
          Serial.println("Incorrect input!");
          delay(5000);
          lcd.clear();
          Serial.println("Game over!");

          lcd.println("Incorrect input!");
          delay(5000);
          lcd.clear();
          lcd.println("Game over!");
          
          gameLoop = false;
          break;
        }
      }

      // add 1 to the score
      // if the score reaches 99, then the game stops

      if (score == 99) {
        lcd.clear();
        Serial.println("Congratulations, you have a score of 99 points, and you have successfully reached the end of the game!");
        Serial.println("Game over!");

        lcd.println("Congratulations, you have a score of 99 points, and you have successfully reached the end of the game!");
        delay(5000);
        lcd.clear();

        lcd.println("Game over!");

        // once the game is over, exit the game loop and return back to the before the game state
        gameLoop = false;

        break;
      }


      // continue playing the randomly selected song if the game will be continuing

      if (randNumberforSongSelection == 1) {

        // start playing the first song
        tmrpcm.setVolume(5); //
        tmrpcm.play("Song1.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
                              //try to provide the file name with extension
        
      }

      if (randNumberforSongSelection == 2) {

        // start playing the second song
        tmrpcm.setVolume(5); //
        tmrpcm.play("Song2.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
                              //try to provide the file name with extension

      }

      if (randNumberforSongSelection == 3) {

        // start playing the third song
        tmrpcm.setVolume(5); //
        tmrpcm.play("Song3.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
                              //try to provide the file name with extension

      }

    }
  }

}
