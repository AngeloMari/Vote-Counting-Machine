#include <LiquidCrystal.h>

LiquidCrystal lcd (13,12,11,10,9,8);
const int btnPins[5] = { 3,4,5,6,7};
int votes[] = {0,0,0,0};
int a = 0;
int b = 0;
int c = 0;
int d = 0;



void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
  pinMode(btnPins[i], INPUT_PULLUP);
  }

  lcd.begin(16,2);
  lcd.home();
  lcd.write("Electronic");
  lcd.setCursor(0,1);
  lcd.write("Voting Machine");
  delay(1000);
  displayCandidates();


}

void loop() {
  if (!digitalRead(btnPins[0])){addVote(0);}
  else if (!digitalRead(btnPins[1])) {addVote(1);}
  else if (!digitalRead(btnPins[2])) {addVote(2);}
  else if (!digitalRead(btnPins[3])) {addVote(3);}
  else if (!digitalRead(btnPins[4])) {Result();}
  delay(200);
}
void addVote(int btn){
  votes[btn] = votes[btn] + 1;
  switch (btn){
    case 0:
    lcd.setCursor(1,1);
    lcd.print(votes[btn]);
    break;
    case 1:
    lcd.setCursor(5,1);
    lcd.print(votes[btn]);
    break;
    case 2:
    lcd.setCursor(9,1);
    lcd.print(votes[btn]);
    break;
    case 3:
    lcd.setCursor(13,1);
    lcd.print(votes[btn]);
    break;
  }
}
void Result(){
  bool isTie = false;
  int winner;
  for (int i = 0; i < 4; i++){
    if (winner < votes[i]){
      winner = votes[i];
    }
  }
  int repeat = 0;
  for (int i = 0; i < 4; i++){
   if (winner == votes[i]){
      repeat++;
      if (repeat > 1){
        isTie = true;
      }
    }
  }
  lcd.clear();
  if (isTie){
    lcd.print("Tie Up Or");
    lcd.setCursor(0,1);
    lcd.print("No Result");
    while(true);
  }
  for (int i = 0; i < 4; i++){
    lcd.clear();
    lcd.home();
    if (winner == votes[0]){
      lcd.print("A is Winner");
    }
     if (winner == votes[1]){
      lcd.print("B is Winner");
    }
     if (winner == votes[2]){
      lcd.print("C is Winner");
    }
     if (winner == votes[3]){
      lcd.print("D is Winner");
    }
  }
  while(true){}
 
}
void displayCandidates(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.write("A");
  lcd.setCursor(1,1);
  lcd.print(a);

  lcd.setCursor(5,0);
  lcd.write("B");
  lcd.setCursor(5,1);
  lcd.print(b);

  lcd.setCursor(9,0);
  lcd.write("C");
  lcd.setCursor(9,1);
  lcd.print(c);

  lcd.setCursor(13,0);
  lcd.write("D");
  lcd.setCursor(13,1);
  lcd.print(d);
}