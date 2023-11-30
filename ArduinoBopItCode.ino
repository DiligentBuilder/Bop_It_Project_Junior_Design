#include <SD.h> // need to include the SD library
//#define SD_ChipSelectPin 4 //connect pin 4 of arduino to cs pin of sd card
//#include <TMRpcm.h> //Arduino library for asynchronous playback of PCM/WAV files
#include <SPI.h> //  need to include the SPI library

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Adafruit_MMA8451 mma = Adafruit_MMA8451();

// define the thresholds for the acceleration and the slide switch for those inputs
int thresholdAcceleration = 10;
int thresholdSlideSwitch = 10;

// pick a random song

// there are three songs, randomly choose a song to play out of the three possible songs

// generate random number between 1 and 3
int randNumberforSongSelection = random(1, 4);

// setup buttons
  //const int button1Pin = 7;
  const int buttonPin = 4;
  //const int button3Pin = 5;
  //const int button4Pin = 6;
  const int slideSwitchPin = A0;
  //const int ledPin = 4;

// setting up score variable to keep track of the player's score
int score = 0;

// game loop variable
bool gameLoop = false;

// int for setting the time interval that the program waits for the user to react to the command
// making on the long side at first to give user plenty of time in beginning
//int timeInterval = 4000;

//TMRpcm tmrpcm; // create an object for use in this sketch

void setup() {
  // define the speaker pin
  //tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  // put your setup code here, to run once:

  // start the serial input for debugging purposes
  // Serial.begin(9600);

  // accelerometer setup code

  // Serial.print("Adafruit MMA8451 test!");
  

  if (! mma.begin()) {
    // Serial.print("Couldnt start");
    while (1);
  }
  // Serial.print("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  //Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  //Serial.print("G");

  lcd.init();
  lcd.backlight();
  lcd.clear();
  

  // Display welcome message
  //Serial.print("Welcome to Bop-It!");
  lcd.print("Welcome to...");
  lcd.print("Bop-It!");

  delay(2);


 
  // setup the pins for the user inputs
  //pinMode(button1Pin, INPUT);
  pinMode(buttonPin, INPUT);
  //pinMode(button3Pin, INPUT);
  //pinMode(button4Pin, INPUT);

  
  pinMode(slideSwitchPin, INPUT);
  
  // setup the LED
  //pinMode(ledPin, OUTPUT);


  // setup the LCD display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  

  // start playing the begin soundtrack
  //tmrpcm.setVolume(5);
  //tmrpcm.play("BeginIt.wav");




 // start playing the randomly selected song

  // if (randNumberforSongSelection == 1) {

  //   // start playing the first song
  //   tmrpcm.setVolume(5); //
  //   tmrpcm.play("Song1.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
  //                         //try to provide the file name with extension
    
  // }

  // if (randNumberforSongSelection == 2) {

  //   // start playing the second song
  //   tmrpcm.setVolume(5); //
  //   tmrpcm.play("Song2.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
  //                         //try to provide the file name with extension

  // }

  // if (randNumberforSongSelection == 3) {

  //   // start playing the third song
  //   tmrpcm.setVolume(5); //
  //   tmrpcm.play("Song3.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
  //                         //try to provide the file name with extension

  // }




}

bool firstTime = 1;

int startState = 0;

void loop() {

  if (firstTime) {
    lcd.clear();

    lcd.print("Press it!");
    lcd.setCursor(0,1);
    lcd.print("to begin!");
    lcd.setCursor(0,0);

    startState = 0;
  }

  


  // put your main code here, to run repeatedly:

  // read the state of the pushbutton values
  
  // using the states as the three game inputs, as well as the start game button

  // reading state of start game
  
  startState = digitalRead(buttonPin);

  // wait a few seconds and countdown

  // before the game starts, the player starts with a score of 0
  score = 0;

  


  if (startState == HIGH) {

      

    lcd.clear();
    lcd.print("Game starting in...");
    delay(1000);
    lcd.clear();
    lcd.print("5");
    delay(1000);
    lcd.clear();
    lcd.print("4");
    delay(1000);
    lcd.clear();

  
    lcd.clear();
    
    //Serial.print("Game starting in 3...");
    lcd.print("Starting in 3...");
    delay(1000);

    lcd.clear();

    //Serial.print("Game starting in 2...");
    lcd.print("Starting in 2...");
    delay(1000);


    lcd.clear();


    //Serial.print("Game starting in 1...");
    lcd.print("Starting in 1...");
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
        // Serial.print("Press it!");
        lcd.print("Press it!");

        lcd.setCursor(0, 1);
        lcd.print("Your score is ");
        lcd.print(score);
        lcd.setCursor(0, 0);
        //tmrpcm.play("PressIt.wav");
      }
      else if (randNumber == 2) {
        lcd.clear();
        // Serial.print("Slide it!");
        lcd.print("Slide it!");

        lcd.setCursor(0, 1);
        lcd.print("Your score is ");
        lcd.print(score);
        lcd.setCursor(0, 0);
        //tmrpcm.play("SlideIt.wav");
      }
      else if (randNumber == 3) {
        lcd.clear();
        // Serial.print("Spin it!");
        lcd.print("Spin it!");

        lcd.setCursor(0, 1);
        lcd.print("Your score is ");
        lcd.print(score);
        lcd.setCursor(0, 0);
        //tmrpcm.play("SpinIt.wav");
      }

      

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

      previousSlidState = analogRead(slideSwitchPin);

      // constantly read the pins to check if there is an input during the time window

      // defining variables
      int count = 0;
      int timeInterval = 500;
      int smallInterval = 10;

      while (true) {
        pushedButtonState = digitalRead(buttonPin);
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
          lcd.clear();
          lcd.print("Push detected!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(1000);

          firstTime = 1;
          
          break;
        }
        if (spunState == HIGH) {
          spun = true;
          lcd.clear();
          lcd.print("Spin detected!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(1000);

          firstTime = 1;
          
          break;
        }
        if (slidState == HIGH) {
          slid = true;
          lcd.clear();
          lcd.print("Slid detected!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(1000);

          firstTime = 1;
          break;
        }


      // if the time has exceeded, we break out of the loop
      // give the user time to react to the command
      // program waits for some time
      delay(smallInterval);

      count++;

      if (count > timeInterval) {
        lcd.clear();
        lcd.print("Time's up!");

        lcd.setCursor(0, 1);
        lcd.print("Your score is ");
        lcd.print(score);
        lcd.setCursor(0, 0);

        delay(2000);

        firstTime = 1;
        break;
      }

      }

      
      

      

      // game logic

      // detect if any incorrect inputs are inputted by user and detect for correct inputs


      // if incorrect inputs, the game is over


      



      // if the correct input (and only the correct input, no incorrect inputs) is inputted by the user, then the user's score will increase by 1
      if (randNumber == 1) {
        if (pushed == false) {
         
          // Serial.print("Incorrect input!");
          // Serial.print("Game over!");
          
          lcd.clear();
          lcd.print("Incorrect input!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);
          
          delay(2000);

          lcd.clear();
          lcd.print("Game over!");
          
          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(2000);

         



          gameLoop = false;
          firstTime = 1;
          break;
        }

        else {
          lcd.clear();
          lcd.print("Correct input!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          score++;

          delay(2000);

   

          
        }
      }
      
      if (randNumber == 2) {
        if (slid == false) {
          
          // Serial.print("Incorrect input!");
          // Serial.print("Game over!");

          lcd.clear();

          lcd.print("Incorrect input!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);


          delay(2000);

          lcd.clear();
          lcd.print("Game over!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(2000);

   

          gameLoop = false;

          firstTime = 1;

          break;
        }

        else {
          lcd.clear();
          lcd.print("Correct input!");

          score++;

          
          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(2000);

          lcd.clear();
          
          //lcd.print("Job well done!");
          //delay(2000);



          
        }
      }

      if (randNumber == 3) {
        if (spun == false) {
          //lcd.clear();
          // Serial.print("Incorrect input!");
          //delay(2000);
         
          // Serial.print("Game over!");

          lcd.clear();

          lcd.print("Incorrect input!");

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(2000);

          lcd.clear();
          lcd.print("Game over!");
          
          delay(2000);

          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

        
          gameLoop = false;

          firstTime = 1;

          break;
        }

        else {
          lcd.clear();
          lcd.print("Correct input!");

          score++;

          
          lcd.setCursor(0, 1);
          lcd.print("Your score is ");
          lcd.print(score);
          lcd.setCursor(0, 0);

          delay(2000);

          lcd.clear();
          
          //lcd.print("Job well done!");
          //delay(2000);



           

          
        }
      }

      // add 1 to the score
      // if the score reaches 99, then the game stops

      if (score == 99) {
        lcd.clear();
        // Serial.print("Congratulations, you have a score of 99 points, and you have successfully reached the end of the game!");
        // Serial.print("Game over!");

        lcd.print("Congratulations, your");
        lcd.print("score is 99 points");

        delay(5000);

        lcd.clear();
        lcd.print("Game over!");

        lcd.setCursor(0, 1);
        lcd.print("Your score is ");
        lcd.print(score);
        lcd.setCursor(0, 0);

        delay(2000);

        
        
       

        // once the game is over, exit the game loop and return back to the before the game state
        gameLoop = false;

        firstTime = 1;

        break;
      }


      // continue playing the randomly selected song if the game will be continuing

      // if (randNumberforSongSelection == 1) {

      //   // start playing the first song
      //   tmrpcm.setVolume(5); //
      //   tmrpcm.play("Song1.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
      //                         //try to provide the file name with extension
        
      // }

      // if (randNumberforSongSelection == 2) {

      //   // start playing the second song
      //   tmrpcm.setVolume(5); //
      //   tmrpcm.play("Song2.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
      //                         //try to provide the file name with extension

      // }

      // if (randNumberforSongSelection == 3) {

      //   // start playing the third song
      //   tmrpcm.setVolume(5); //
      //   tmrpcm.play("Song3.wav"); //the sound file "song" will play each time the arduino powers up, or is reset
      //                         //try to provide the file name with extension

      // }

      // if the game is continuing to the next iteration of the loop, decrease the time interval
      // for the next instruction, so the time interval that the user has to react gets shorter and shorter
      // as the game progresses, the player inputted the correct inputs, and the player gets a higher and higher score
      timeInterval -= 10;

    }
  }

}
