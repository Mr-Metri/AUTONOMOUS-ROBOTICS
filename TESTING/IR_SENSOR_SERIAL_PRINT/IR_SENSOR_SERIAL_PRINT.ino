void setup() 
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() 
{
  int IR = digitalRead(A0);

    if (IR == HIGH)
    {
      Serial.println("1");
    }

    else
    {
      Serial.println("0");   
    }

    delay(500);
}
