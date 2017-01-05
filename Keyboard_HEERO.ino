// Libraries
//******************************************************************************
#include <Adafruit_NeoPixel.h>

// Pins
//******************************************************************************
#define PIN1 6
#define PIN2 7
#define PIN3 8
#define PIN4 9
#define N_LEDS 5
#define speaker 10
#define button0 16
#define button1 15
#define button2 14
#define button3 13
int buttons[4] = {16, 15, 14, 13};

// Defining Strips
//******************************************************************************
Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(N_LEDS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(N_LEDS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(N_LEDS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(N_LEDS, PIN4, NEO_GRB + NEO_KHZ800);

// Segment Definitions for Display
//******************************************************************************
#define digit1 20
#define digit2 21
#define digit3 22
#define digit4 23
#define segA 19
#define segB 17
#define segC 4
#define segD 2
#define segE 1
#define segF 18
#define segG 5

// Note Definitions
//******************************************************************************
#define C0 16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define AA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define AA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define AA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define AA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define AA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define AA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define AA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define AA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03
#define R       0

// BPM
//******************************************************************************
int bpm = 120;

// Note Durations
//******************************************************************************
#define H 2*Q //half 2/4
#define Q 60000/bpm //quarter 1/4  // Here assumes 4/4 time signature!
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4
#define EE E*4/3 // slightly slow E or a quick Q

// Color Arrays
//******************************************************************************
int red[3] = {255, 0, 0};
int orange[3] = {255, 165, 0};
int yellow[3] = {255, 255, 0};
int blue[3] = {0, 0, 255};
int purple[3] = {255, 0, 200};
int * colors[5] = {red, orange, yellow, blue, purple};

// Pallet Town Song
//******************************************************************************
int song[100][2] = {
  {D5,Q},{C5,Q},{B4,Q},{AA4,Q},{G5,Q},{E5,Q},{Gb5,Q},{E5,Q},{D5,H + Q},{B4,Q},{G4,Q},{G4,Q},{AA4,Q},{B4,Q},{C5,H + Q},{Gb4,Q},{G4,Q},{AA4,Q},{B4,H + Q},{C5,E},{B4,E},{AA4,W},{D5,Q},{C5,Q},{B4,Q},{D5,Q},{G5,Q},{Gb5,Q},{Gb5,Q},{G5,Q},{E5,H+Q},{D5,Q},{D5,W},{C5,Q},{B4,Q},{AA4,Q},{G4,Q},{D5,Q},{C5,Q},{B4,Q},{AA4,Q},{G4,W+Q},{G4,Q},{AA4,Q},{B4,Q},{C5,H},{C5,H},{D5,H+Q},{C5,Q},{B4,W+Q},{G4,Q},{AA4,Q},{B4,Q},{C5,H},{C5,H},{D5,H+Q},{C5,E},{D5,E},{B4,W+Q},{B4,Q},{AA4,Q},{G4,Q},{AA4,W},{E4,H},{B4,H},{AA4,W},{G4,H},{E4,H},{Gb4,H},{Gb4,H},{G4,H},{B4,H},{B4,W},{AA4,W}
};

// Variable Definitions
//******************************************************************************
int num_notes = 76;
double counter = 0;
bool started = false;
double score = 9;
//IntervalTimer myTimer;
bool song_over = false;

// Struct for Notes
//******************************************************************************
struct note_package
{
  bool on;
  int note;
  int light;
  int duration;
  int * color;
  int strip_num;
};

// NeoPixel Array of Strip Addresses
//******************************************************************************
Adafruit_NeoPixel * neo[4] = {&strip0, &strip1, &strip2, &strip3};

// LED Strip Arrays to Hold Information
//******************************************************************************
note_package a0[5];
note_package a1[5];
note_package a2[5];
note_package a3[5];
note_package * arrays[4] = {a0, a1, a2, a3};

// Song Index Variable
//******************************************************************************
int song_i = 0;

// Setup
//******************************************************************************
void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(button0, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);  
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  strip0.begin();
  strip1.begin();
  strip2.begin();
  strip3.begin();
  
  // Initialize all notes in the array
  // To false
  for (int i = 0; i < 5; i++)
  {
    init_note_package(&(a0[i]), false, 0, 0);
    init_note_package(&(a1[i]), false, 0, 0);
    init_note_package(&(a2[i]), false, 0, 0);
    init_note_package(&(a3[i]), false, 0, 0);
  }

  // Put first note into the array
  push_new_note(song[song_i][0], song[song_i][1]);
  counter = (song[song_i][1] / (Q/2));
  song_i++;

  Serial.begin(9600);
}

// Loop
//******************************************************************************
void loop() {
  play_song();
  
  while(1){
    displayNumber(score);
  }
}
