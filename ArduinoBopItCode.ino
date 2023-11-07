 // setup buttons
  const int button1Pin = 7;
  const int button2Pin = 6;
  const int button3Pin = 5;
  const int button4Pin = 6;
  const int ledPin = 4;

// setting up score variable
int score = 0;

// game loop variable
bool gameLoop = false;

// int for setting the time interval that the program waits for the user to react to the command
// making on the long side at first to give user plenty of time in beginning
int timeInterval = 4000;

void setup() {
  // put your setup code here, to run once:

  // start the serial input for debugging purposes
  Serial.begin(9600);

  // Display welcome message
  Serial.println("Welcome to Bop-It!");


 
  
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  
  // setup the LED
  pinMode(ledPin, OUTPUT);
  

  


  // pick a random song


  



}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state of the pushbutton values
  
  // using the states as the three game inputs, as well as the start game button

  // reading state of start game
  int startState = 0;
  startState = digitalRead(button1Pin);

  if (startState == HIGH) {
    Serial.println("Game starting in 3...");
    delay(1000);

    Serial.println("2...");
    delay(1000);


    Serial.println("1..");
    delay(1000);


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
      if (randNumber == 1) {
        Serial.println("Push it!");
      }
      else if (randNumber == 2) {
        Serial.println("Slide it!");
      }
      else if (randNumber == 3) {
        Serial.println("Spin it!");
      }

      // decreasing the time interval of waiting
      timeInterval -= 50;

      // give the user time to react to the command
      // program waits for some time
      delay(timeInterval);

      // detection code


      // detect if each user input is pressed or not
      bool pushed = false;
      bool spun = false;
      bool slid = false;

      // reading state of the pushbutton values: the three game inputs
      int pushedButtonState = 0;
      int spunState = 0;
      int slidState = 0;
      pushedButtonState = digitalRead(button2Pin);
      spunState = digitalRead(button3Pin);
      slidState = digitalRead(button4Pin);

      

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



      // if the correct input (and only the correct input, no incorrect inputs) is inputted by the user, then the user's score will increase by 1
      if (randNumber == 1) {
        if (pushed == false || spun == true || slid == true) {
          Serial.println("Incorrect input!");
          Serial.println("Game over!");

          gameLoop = false;
          break;
        }
      }
      
      if (randNumber == 2) {
        if (pushed == true || spun == false || slid == true) {
          Serial.println("Incorrect input!");
          Serial.print("Game over!");

          gameLoop = false;
          break;
        }
      }

      if (randNumber == 3) {
        if (pushed == true || spun == true || slid == false) {
          Serial.println("Incorrect input!");
          Serial.println("Game over!");
          
          gameLoop = false;
          break;
        }
      }

      // add 1 to the score
      // if the score reaches 99, then the game stops

      if (score == 99) {
        Serial.println("Congratulations, you have a score of 99 points, and you have successfully reached the end of the game!");
        Serial.println("Game over!");

        // once the game is over, exit the game loop and return back to the before the game state
        gameLoop = false;

        break;
      }
    }
  }

}
