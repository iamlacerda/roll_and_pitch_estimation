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

## Detail Description
The program was made by following two methods.
The first one was in a procedural way, used as a proof of concepts. Realizing at first all the logical groundrules for the working of the aplication.
Hence, it was refactored within the guidelines of a Object Orientation Programming, by using the concept of Classes to achieve the expected main-goals.
Moreover, it will detailed some points of the main logic, as it follows.

- For acquire data of the log file:
	It was used the library `fstream` both for input data e output data.
	The function opens the file located in the same folder as the aplication itself.
	Once it was open, the program follows the logic to parse the data.

- For the parsing the raw data:
	This function aggregates both the acquire and data treatment.
	It collects the information, line by line, from the table data input, and stores it into a stream.
	Further, the information of the string formated is read column by column, and it is stored at a position of a matrix.
	The process is iterated, for all streamed values of the table data input as it becomes now a numeric variable, acessible for vectoring operations.

- For the calculations:
	By the method of Aerospace Rotation Sequence, the operation for determining the angles for the Pitch and Rolls is done iteratively.
	As long as the matrix has lines, the calculation holds.
	Once the values are calculated for every index, the associated value is placed in anothers vectors, for Pitch and Roll.

- For the data-write into the outsource file:
	Having utilized the library `fstream` again, the application creates a new file.
	For the process of writing, a loop is generated for the all Pitch and Roll values are written down, as long as the size of the vector.
	After writing, the application returns the message that a file is available in the Project folder.

- More informations about the basics of the functions are shown in the code itself.

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

It will have the time stamps, alongside with the estimated angles for Pitch and Roll for all marks.


## Known Bugs
It will not overwrite the table generated. For a new visualization it is necessary to delete the Roll_and_Pitch_Estimations.txt archive in Project folder, and run the application again.
It will show a error message if the 
```
#define _CRT_SECURE_NO_WARNINGS 
```
is not able. It is demanding for timing purposes.
## License

Matheus Lacerda, 2022.
