// name the pins
int led1 = A4;
int led2 = A5;
int led3 = A6;

void setup()
{
   //Register our Spark function here
   Spark.function("led", ledControl);

   // Configure the pins to be outputs
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);

   // Initialize LEDs to be OFF
   analogWrite(led1, 255);
   analogWrite(led2, 255);
   analogWrite(led3, 255);
}

void loop() 
{
// nothing here?
}

int ledControl(String command)
{
   //find out the pin number and convert the ascii to integer
   int pinNumber = command.charAt(0) - '0';

   //Sanity check to see if the pin numbers are within limits
   if (pinNumber < 0 || pinNumber > 4) return -1;

    // convert the string to an int
    // the command to send to API would be
    // curl https://api.spark.io/v1/devices/0123456789abcdef01234567/led \
    // -d access_token=1234123412341234123412341234123412341234 \
    // -d params=1,100
    // params are (123),(0-255)
    String x = command.substring(2);
    int state = x.toInt();

    if (pinNumber == 1)
    {
    analogWrite(led1, state);
    }
    else if (pinNumber == 2)
    {
    analogWrite(led2, state);
    }
    else if (pinNumber == 3)
    {
    analogWrite(led3, state);
    }
    else 
    {
        return -1;
    }

   return 1;
}
