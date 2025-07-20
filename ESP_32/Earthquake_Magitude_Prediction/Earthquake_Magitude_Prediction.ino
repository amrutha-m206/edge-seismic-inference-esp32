#include <EloquentTinyML.h>
#include "earthquake_model_esp32.h"

#define NUMBER_OF_INPUTS 3
#define NUMBER_OF_OUTPUTS 1 
#define TENSOR_ARENA_SIZE 5*1024 

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
    Serial.begin(115200);

    if (!ml.begin(earthquake_model_esp32)) {
        Serial.println("Model failed to initialize!");
        while (true); 
    }
    Serial.println("CDI, Depth, Distance, Predicted Magnitude");
}

float normalize(float value, float min, float max) {
    return (value - min) / (max - min);
}

void loop() {
   
    // Test Case 1: CDI = 3, Depth = 29.068, Distance = 113 ,magnitude=5.65
    float cdi1 = 3;
    float depth1 = 29.068;
    float distance1 = 113;

    float cdi1_normalized = normalize(cdi1, 1.0, 10.0);
    float depth1_normalized = normalize(depth1, 0, 50);
    float distance1_normalized = normalize(distance1, 30, 350);

    float input_data1[] = {cdi1_normalized, depth1_normalized, distance1_normalized};
    float predictedMagnitude1 = ml.predict(input_data1);

    Serial.print("Test Case 1 - CDI = ");
    Serial.print(cdi1);
    Serial.print(", Depth = ");
    Serial.print(depth1);
    Serial.print(", Distance = ");
    Serial.print(distance1);
    Serial.print(", Predicted Magnitude = ");
    Serial.println(predictedMagnitude1);

    // Test Case 2: CDI = 3, Depth = 10, Distance = 210, magnitude=5.15
    float cdi2 = 3;
    float depth2 = 10;
    float distance2 = 210;

    float cdi2_normalized = normalize(cdi2, 1.0, 10.0);
    float depth2_normalized = normalize(depth2, 0, 50);
    float distance2_normalized = normalize(distance2, 30, 350);

    float input_data2[] = {cdi2_normalized, depth2_normalized, distance2_normalized};
    float predictedMagnitude2 = ml.predict(input_data2);

    Serial.print("Test Case 2 - CDI = ");
    Serial.print(cdi2);
    Serial.print(", Depth = ");
    Serial.print(depth2);
    Serial.print(", Distance = ");
    Serial.print(distance2);
    Serial.print(", Predicted Magnitude = ");
    Serial.println(predictedMagnitude2);

   
    for (int i = 0; i < 10; i++) {
        float cdi = random(1, 11);
        float depth = random(10, 50);
        float distance = random(30, 300);

        float cdi_normalized = normalize(cdi, 1.0, 10.0);
        float depth_normalized = normalize(depth, 0, 50);
        float distance_normalized = normalize(distance, 30, 350);

        float input_data[] = {cdi_normalized, depth_normalized, distance_normalized};
        float predictedMagnitude = ml.predict(input_data);

        Serial.print("Random Case - CDI = ");
        Serial.print(cdi);
        Serial.print(", Depth = ");
        Serial.print(depth);
        Serial.print(", Distance = ");
        Serial.print(distance);
        Serial.print(", Predicted Magnitude = ");
        Serial.println(predictedMagnitude);

        delay(400); 
    }

    
    delay(5000);
}
