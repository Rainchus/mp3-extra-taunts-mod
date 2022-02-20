# mp3-extra-taunts-mod
MP3 more character taunts mod

You can set the following options with gameshark codes:<br>
800977D0 s16, if taunts are active globally bool<br>
800977D2 s16, if you can taunt when it's your turn on the board<br>
810977D0 00xx<br>
810977D2 00xx<br><br>

To apply mod to vanilla rom:<br>
Download flips (IPS patcher) and apply the .bps patch provided to a vanilla US mp3.z64 rom<br><br>

To build from source:<br>
First, setup armips compiling by following this tutorial: https://hack64.net/Thread-Importing-C-Code-Into-SM64-Using-n64chain-and-armips <br>
Create a folder in the root of the project named `rom`<br>
Put a mario party 3 US rom in the folder with the name `mp3.z64`<br>
Run `build.bat` to build the modded rom<br>
The modded rom will output as `mp3mod.z64`
