char dataIn; // Durma fonksiyonu için karakter
const int sol_i = 4; // motor sürücü pinleri tanımlandı
const int sol_g = 5;
const int sag_i = 7;
const int sag_g = 6;
const int e1 = 10;
const int e2 = 11;
char determinant; //Program döngüsü için karakter
char det; //Program döngüsü için karakter

void setup()
{
  Serial.begin(9600); //HC-07 bluetooth modülü için btu 9600
  pinMode(sol_i, OUTPUT);
  pinMode(sol_g, OUTPUT);
  pinMode(sag_i, OUTPUT);
  pinMode(sag_g, OUTPUT);
}

void loop()
{
  det = check();
  while (det == 'F') //Telefondaki programda atanmış olan ileri sürüş butonunun harf eşdeğeri
  {
    digitalWrite(sol_i, HIGH);
    digitalWrite(sag_i, HIGH);
    det = check();
  }
  while (det == 'B') //Telefondaki programda atanmış olan geri sürüş butonunun harf eşdeğeri
  {
    digitalWrite(sol_g, HIGH);
    digitalWrite(sag_g, HIGH);
    det = check();
  }

  while (det == 'L') //Telefondaki programda atanmış olan sola dönüş butonunun harf eşdeğeri
  {
    digitalWrite(sol_g, HIGH);
    digitalWrite(sag_i, HIGH);
    det = check();
  }
  while (det == 'R') //Telefondaki programda atanmış olan sağa butonunun harf eşdeğeri
  {
    digitalWrite(sag_g, HIGH);
    digitalWrite(sol_i, HIGH);
    det = check();
  }
  
  while (det == 'S') //Telefondaki programda atanmış olan durma fonksiyonun harf eşdeğeri
  {
    digitalWrite(sag_i, LOW);
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, LOW);
    digitalWrite(sol_g, LOW);
    det = check();
  }

}
int check()
{
  if (Serial.available() > 0) //Serial portun kontrollü
  {
    dataIn = Serial.read(); //Telefondan gelen verilerin kontrollü
    if (dataIn == 'F')
    {
      determinant = 'F';
    }
    else if (dataIn == 'B')
    {
      determinant = 'B';
    }
    else if (dataIn == 'L')
    {
      determinant = 'L';
    }
    else if (dataIn == 'R')
    {
      determinant = 'R';
    }
    
    else if (dataIn == 'S')
    {
      determinant = 'S';
    }

  }
  return determinant;
}
