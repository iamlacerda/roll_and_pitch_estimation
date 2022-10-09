#define _USE_MATH_DEFINES // For using the most precise value of PI.
#define _CRT_SECURE_NO_WARNINGS // Necessary to run the time applications. Compiler indicates a error without using it and recommends the usage.

#include <iostream> 
#include <cmath> //Library for the mathematical calculations.
#include <fstream> //For operations with outsource files.
#include <string> //Operations with strings.
#include <sstream>
#include <cstdio>
#include <chrono> //Using with the ctime library to generate date and time.
#include <ctime> //Using with the chrono library to generate date and time.


using namespace std;

#define INPUT_FILE "attitude_exam.log" 
#define OUTPUT_FILE "Roll_and_Pitch_Estimation.txt"

/*
This class is responsible for read data, parse it, calculate and write it down.
*/
class Desafio 
{
public:

	int resolve()
	{
		read_input();
		estimate_angle();
		write_output();
		return 0;
	}

private:
	
	int line = 0, column = 0;
	float matrice[5500][4];
	float roll[5500];
	float pitch[5500];


	void read_input() //This function reads all the data and stores it into a matrix.
	{
		tic_tac("Starting to read the data input.");
		string line_content, column_content;
		ifstream log_file(INPUT_FILE);
		while (getline(log_file, line_content)) //Get each line.
		{
			stringstream line_stream(line_content);
			column = 0;
			while (getline(line_stream, column_content, ';')) //Get each column.
			{
				matrice[line][column] = clean_column(column_content);
				column++;
			}
			line++;
		}
		log_file.close();
		tic_tac("End to parse the data input, and starting to Calculate Pitch and Roll Estimated Angles.");

	}

	/*
	For each element of the matrix contening the variation of the axis,
	it performs a mathematical operation to set the roll and pitch angles.
	*/
	void estimate_angle() 
	{
		int j;
		for (j = 0; j < line; j++)
		{
			roll[j] = estimate_roll(matrice[j][2], matrice[j][3]);
			pitch[j] = estimate_pitch(matrice[j][1], matrice[j][2], matrice[j][3]);
		}
		cout << "Number of iterations: " << j << endl;
		tic_tac("Calculations on Pitch and Roll Estimated Angles Completed and starting to Elaborate the data Output..");
	}

	/*
	Write the elements into a output file.
	*/
	void write_output()
	{
		int k;
		fstream out_file;
		out_file.open(OUTPUT_FILE, ios_base::app);
		for (k = 0; k < line; k++)
		{
			string line_text = "Leitura nº " + to_string(k) + " | Pitch: " + to_string(pitch[k]) + " deg | Roll:" + to_string(roll[k]) + " deg" "\n";
			out_file.write(line_text.c_str(), line_text.length());
		}
		out_file.close();
		tic_tac("The data Output for the Pitch and Roll Estimated angles are now available in the file 'Roll_and_Pitch_Estimation.txt'.");
	}

	/*
	Calculation of the Pitch angle, given the axis variation.
	*/
	float estimate_pitch(float accel_x_axis, float accel_y_axis, float accel_z_axis)
	{
		return 180 * (atan(accel_x_axis / (sqrt((accel_y_axis * accel_y_axis) + (accel_z_axis * accel_z_axis))))) / M_PI;
	}

	/*
	Calculation of the Roll angle, given the axis variation.
	*/
	float estimate_roll(float accel_y_axis, float accel_z_axis)
	{
		return 180 * (atan(accel_y_axis / accel_z_axis)) / M_PI;
	}

	/*
	Trim function. Return data with no blank spaces or commas.
	*/
	float clean_column(string data_column)
	{
		float i;
		sscanf_s(data_column.c_str(), "%f", &i);
		return i;
	}

	/*
	Display a custom message with the currente time.
	*/
	void tic_tac(string message)
	{
		auto message_time = chrono::system_clock::now();
		time_t text_for_time = chrono::system_clock::to_time_t(message_time);
		cout << ctime(&text_for_time) << message << endl;
	}
};


int main()
{
	Desafio task; //Initialize the task object.
	task.resolve(); //Call the resolution method.
}
