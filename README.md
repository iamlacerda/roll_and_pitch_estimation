# Roll and Pitch angles Estimation using Aerospace Rotation Sequence.
Author: M Lacerda (matheus016@gmail.com)

## Description.
The project estimates Roll and Pitch angles, using the solution known as the Aerospace Rotation Sequence.
It reads strings from a table of raw data, parse it as floats variables and allocates the elements into a matrix.
Having the elements as numeric values, it calculates the angles for Roll and Pitch, and write the acquired results in a output table.

## Pre-requirements.
- C++ compiler.
- Any IDE.
- Your preferred bash.

## How to Run it.
Clone the Project folder by doing (or download it from GitHub):
```
git clone https://github.com/iamlacerda/roll_and_pitch_estimation
```
Go to the Project folder 
```
cd roll_and_pitch_estimation
```
It is essential to have the input data table (provided within this project) in the same Folder as the .cpp application.

Compile the application using your instaled compiler.

Run the Application.

On console, it is shown the angles as calculation are made.

Once the application ends, a table naming Roll_and_Pitch_Estimations.txt is expected into the Project folder.

It will have the time stamps, alongside with the angles for Pitch and Roll estimated for all the marks.

## Known Bugs
It will not overwrite the table generated. For a new visualization
it is necessary to delete the Roll_and_Pitch_Estimations.txt archive in Project folder,
and run the application again.

## License

Matheus Lacerda, 2022.
