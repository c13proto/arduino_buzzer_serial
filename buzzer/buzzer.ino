
const int buzzer = 13; //buzzer to arduino pin 9

void setup() {
	Serial.begin(9600);
	pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}


const int LEN = 5;//コマンドの文字数
char buff[LEN] = {};
int counter = 0;
String command="command";
void loop() {

	if (Serial.available() > 0) {

		char data = Serial.read();
		//Serial.print(counter);

		if (data != '\n') {

			buff[counter] = data;
			counter++;

		}
		else {
			if (counter == 5)command = String(buff);
			else command = "";
			
			Serial.print(command);
			if (command.startsWith("test!"))tone(buzzer, 1000, 100);
			counter = 0;
		}
	}

	
	

}
