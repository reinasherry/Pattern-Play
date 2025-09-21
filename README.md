# Arduino Simon Game

A classic Simon memory game implemented using Arduino Uno.



## Features

- 3 LED lights with corresponding buttons
- Audio feedback with different tones for each button
- Progressive difficulty with increasing sequence length
- Visual and audio cues for correct/incorrect inputs

## Hardware Requirements

- Arduino Uno
- 3 LEDs (different colors recommended)
- 3 Push buttons
- Piezo buzzer
- 3x 220Ω resistors (for LEDs)
- Breadboard and jumper wires

## Wiring Diagram
<img width="729" height="693" alt="Screenshot 2025-09-21 181559" src="https://github.com/user-attachments/assets/83f45d7e-4114-4ec5-9fc5-2fec40330a0c" />


### Other Components:
- LEDs: Pins 2, 3, 4 (with 220Ω resistors)
- Buttons: Pins 5, 6, 7 
- Buzzer: Pin 9

## Installation

1. Connect all components as shown in the wiring diagram
2. Clone this repository or download the `.ino` file
3. Open the sketch in Arduino IDE
4. Select the correct board (Arduino Uno) and port
5. Upload the sketch to your Arduino

## How to Play

1. Press any button to start the game
2. Watch the sequence of lights and remember the pattern
3. Repeat the pattern by pressing the buttons in the same order
4. The sequence gets longer with each successful round
5. If you make a mistake, the game ends and shows your final level
6. Press any button to play again

## Customization

You can customize these aspects of the game:

- **Tones**: Modify the `tones` array to change the sounds
- **Timing**: Adjust the delay values to change game speed
- **Difficulty**: Change the maximum sequence length (currently 50)


## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
