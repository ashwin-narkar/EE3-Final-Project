// INCREASE SCORE FUNCTION
//******************************************************************************
void increaseScore(int stripNumber, int position) {
  Serial.println(score);
  
  /*if (digitalRead(button0) || digitalRead(button1) || digitalRead(button2) || digitalRead(button3)) {
    ++score;
    delay(300);
  }*/

  if((stripNumber == buttonNumber()) && (position == 0)){     // Not sure how we're reading the position on the LED strips
    ++score;
    Serial.println(score);
    return;
  }
  
  else
    Serial.println(score);
    return;  
}

// BUTTON NUMBER FUNCTION
//******************************************************************************
int buttonNumber() {
  delay(300);
  if (digitalRead(button0)){
    return 0;
  }
  else if (digitalRead(button1)) {
    return 1;
  }
  else if (digitalRead(button2)) {
    return 2;
  }
  else if (digitalRead(button3)) {
    return 3;
  }
  else 
    return 69;
}

// DISPLAY NUMBER FUNCTION
//******************************************************************************
void displayNumber(int toDisplay) {
  long beginTime = millis();
  
  if ((toDisplay >= 0) && (toDisplay < 10)) {
    digitalWrite(digit4, LOW);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit1, HIGH);
    lightNumber(toDisplay);
    //delay(1000);
    delayMicroseconds(500); //Display this digit for a fraction of a second (between 1us and 5000us, 500 is pretty good)

    //Turn off all segments
    //lightNumber(10); 

    //Turn off all digits
   // digitalWrite(digit1, LOW);
    //digitalWrite(digit2, LOW);
    //digitalWrite(digit3, LOW);
    //digitalWrite(digit4, LOW);
  }
  
  else if ((toDisplay >= 10) && (toDisplay < 100)) {
    digitalWrite(digit4, LOW);
    lightNumber(toDisplay % 10);
    
    delay(5);
    digitalWrite(digit4, HIGH);
    
    
    digitalWrite(digit3, LOW);
    lightNumber(toDisplay/10);
    
    delay(5);
    digitalWrite(digit3, HIGH);
    
    digitalWrite(digit2, HIGH);
    digitalWrite(digit1, HIGH);

    delayMicroseconds(500); //Display this digit for a fraction of a second (between 1us and 5000us, 500 is pretty good)

    //Turn off all segments
    lightNumber(10); 
  }
 
  while( (millis() - beginTime) < 10) ; //Wait for 20ms to pass before we paint the display again
}

// LIGHT NUMBER FUNCTION
//******************************************************************************
void lightNumber(int numberToDisplay) {
  switch (numberToDisplay){

  case 0:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, LOW);
    break;

  case 1:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;

  case 2:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, LOW);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;

  case 3:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;

  case 4:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 5:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 6:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 7:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;

  case 8:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 9:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 10:
    digitalWrite(segA, LOW);
    digitalWrite(segB, LOW);
    digitalWrite(segC, LOW);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
  }
}

// GET STRIP NUMBER FUNCTION
//******************************************************************************
int getStripNum(int note)
{
  //Serial.println(note);
  if(note < 444){
      return 0;
    }

    else if (note < 557){
      return 1;
    }

    else if (note < 671){
      return 2;
    }

    else{
      return 3;
    }
}

// PLAY SONG FUNCTION
//******************************************************************************
void play_song() {
 
  for (int i=0; i < num_notes; i++) 
  {
    while (counter > 0)
    {
      move_down();
      
      if(!started && (arrays[0][4].on || arrays[1][4].on || arrays[2][4].on || arrays[3][4].on))
      {
        started = true;
        i = 0;
        song_i = 1;
      }
      int startTime = millis();
      if(started)
      {
        tone(speaker, song[i][0],song[i][1]);
      }

      if (digitalRead(buttons[getStripNum(song[i][0])]))
        {
           score++;
          Serial.println(score);
          displayNumber(score);
        }
          
      delay((Q/2));
        
      counter--;
      //Serial.println(counter);
      
    }
    if (counter <= 0)
    {
        push_new_note(song[song_i][0], song[song_i][1]);
        counter = song[song_i][1] / (Q/2);
        song_i++;
        if(digitalRead(button0) || digitalRead(button1) || digitalRead(button2) || digitalRead(button3))
          score--;
    }
        
    
  }

}

// INITIALIZE NOTE PACKAGE FUNCTION
//******************************************************************************
void init_note_package(note_package * p, bool o, int n, int d)
{
  p->on = o;
  p->note = n;
  p->duration = d;
  p->light = 0;
  p->color = makeColor(d);
  p->strip_num = getStripNum(n);
}

// MAKE COLOR FUNCTION
//******************************************************************************
int * makeColor(int d)
{
  if (d <= E)
    return blue;
  if (d <= Q)
    return purple;
  if (d <= H)
    return red;
  if (d <= Q + E)
    return orange;
  return yellow;
}

// PUSH NEW NOTE FUNCTION
//******************************************************************************
void push_new_note(int n, int d)
{
  //Serial.println(n);
  int number = getStripNum(n);
  init_note_package(&arrays[number][0], true, n, d);
  int * color = makeColor(d);
  arrays[number][0].color = color;
  neo[number]->setPixelColor(0,neo[number]->Color(color[0], color[1], color[2]));
  neo[number]->show();
}

// MOVE DOWN FUNCTION
//******************************************************************************
void move_down()
{
  
  if(arrays[0][3].on || arrays[1][3].on || arrays[2][3].on || arrays[3][3].on)
  {
    init_note_package(&(a0[4]), a0[3].on, a0[3].note, a0[3].duration);
    init_note_package(&(a1[4]), a1[3].on, a1[3].note, a1[3].duration);
    init_note_package(&(a2[4]), a2[3].on, a2[3].note, a2[3].duration);
    init_note_package(&(a3[4]), a3[3].on, a3[3].note, a3[3].duration);
  }

 
  
  for (int i = 2; i >= 0; i--)
  {
    init_note_package(&(a0[i+1]), a0[i].on, a0[i].note, a0[i].duration);
    init_note_package(&(a1[i+1]), a1[i].on, a1[i].note, a1[i].duration);
    init_note_package(&(a2[i+1]), a2[i].on, a2[i].note, a2[i].duration);
    init_note_package(&(a3[i+1]), a3[i].on, a3[i].note, a3[i].duration);
  }

  init_note_package(&(a0[0]), false, 0, 0);
  init_note_package(&(a1[0]), false, 0, 0);
  init_note_package(&(a2[0]), false, 0, 0);
  init_note_package(&(a3[0]), false, 0, 0);
  

  for (int i = 0; i < 5; i++)
  {
    if (a0[i].on)
    {
      //Serial.println("a0 on");
       neo[0]->setPixelColor(i,neo[0]->Color(a0[i].color[0], a0[i].color[1], a0[i].color[2]));
       neo[0]->show();
    }
    else
    {
       neo[0]->setPixelColor(i, 0, 0, 0);
       neo[0]->show();
    }
    if (a1[i].on)
    {
       //Serial.println("a1 on");
        neo[1]->setPixelColor(i,neo[1]->Color(a1[i].color[0], a1[i].color[1], a1[i].color[2]));
        neo[1]->show();
    }
    else
    {
        neo[1]->setPixelColor(i, 0, 0, 0);
        neo[1]->show();
    }
    if (a2[i].on)
    {
       //Serial.println("a2 on");
        neo[2]->setPixelColor(i,neo[2]->Color(a2[i].color[0], a2[i].color[1], a2[i].color[2]));
        neo[2]->show();
    }
    else
    {
       neo[2]->setPixelColor(i, 0, 0, 0);
       neo[2]->show();
    }
    if (a3[i].on)
    {
       //Serial.println("a3 on");
        neo[3]->setPixelColor(i,neo[3]->Color(a3[i].color[0], a3[i].color[1], a3[i].color[2]));
        neo[3]->show();
    }
    else
    {
        neo[3]->setPixelColor(i, 0, 0, 0);
        neo[3]->show();
    }
    
  }
}

// CHASE FUNCTION (for testing LED strips)
//******************************************************************************
/*static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip1.numPixels()+4; i++) {
      strip1.setPixelColor(i  , c); // Draw new pixel
      strip1.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip1.show();
      delay(25);
  }
}*/

