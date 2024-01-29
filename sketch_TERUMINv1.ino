#define trigPin 13
#define echoPin 12
#define speaker 10
#define led5 5
#define led6 6
#define led7 7
#define led8 8
#define led9 9

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 5000 - duration ;


   if (distance <=4900 && distance >= 4435){   // 8オクターブ
    tone(speaker,distance,50);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
   }

   if (distance < 4435 && distance >= 2093){  // 7オクターブ
    tone(speaker,distance,50);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, LOW );
   }

   if (distance <2093 && distance >= 1047){  // 6オクターブ
    tone(speaker,distance,50);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, LOW );
    digitalWrite(led9, LOW );
   }

   if (distance <1047 && distance >= 523){  //5オクターブ
    tone(speaker,distance,50);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, LOW );
    digitalWrite(led8, LOW );
    digitalWrite(led9, LOW );
   }

   if (distance <523 && distance >= 0){  //4オクターブ以下
    tone(speaker,distance,50);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, LOW );
    digitalWrite(led7, LOW );
    digitalWrite(led8, LOW );
    digitalWrite(led9, LOW );
   }

  if (distance > 4900 || distance < 0){  //0~4900の外なら音とLEDを消す
    Serial.println("Out of range");
    noTone(speaker);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
  }
  else {
    Serial.println(distance);
  }

}
