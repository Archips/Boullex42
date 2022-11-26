/* 
 * Code d'exemple pour un capteur à ultrasons HC-SR04.
 */
#include <math.h>

/* Constantes pour les broches */
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;
const byte ECHO_PIN_2 = 5;  
const byte TRIGGER_PIN_2 = 4;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

/** Fonction setup() */
void setup() {
   
  /* Initialise le port série */
  Serial.begin(115200);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(TRIGGER_PIN_2, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  digitalWrite(TRIGGER_PIN_2, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
  pinMode(ECHO_PIN_2, INPUT);
}
 
/** Fonction loop() */
void loop() {
  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);


  digitalWrite(TRIGGER_PIN, LOW);

  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);

  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;

  // int a = (int) Math.round (distance_mm);
  /* Affiche les résultats en mm, cm et m */
 Serial.print(distance_mm,0);
//Serial.print(distance_mm, 0 );
  Serial.print("/");


   digitalWrite(TRIGGER_PIN_2, HIGH);
     delayMicroseconds(10);
      digitalWrite(TRIGGER_PIN_2, LOW);
        long measure2 = pulseIn(ECHO_PIN_2, HIGH, MEASURE_TIMEOUT);
          float distance_mm_2 = measure2 / 2.0 * SOUND_SPEED;
      Serial.println(distance_mm_2 ,0);

  

   
  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(100);
}