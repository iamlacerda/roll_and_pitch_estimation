#define _USE_MATH_DEFINES

#include <iostream> 
#include <cmath> 
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

#define INPUT_FILE "attitude_exam.log"
#define OUTPUT_FILE "Roll_and_Pitch_Estimation.txt"

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


	void read_input()
	{
		string line_content, column_content;
		ifstream log_file(INPUT_FILE);
		while (getline(log_file, line_content))
		{
			stringstream line_stream(line_content);
			column = 0;
			while (getline(line_stream, column_content, ';'))
			{
				matrice[line][column] = clean_column(column_content);
				column++;
			}
			line++;
		}
		log_file.close();
	}


	void estimate_angle()
	{
		int j;
		for (j = 0; j < line; j++)
		{
			roll[j] = estimate_roll(matrice[j][2], matrice[j][3]);
			pitch[j] = estimate_pitch(matrice[j][1], matrice[j][2], matrice[j][3]);
			cout << j << "- pitch:" << pitch[j] << " | roll:" << roll[j] << endl;
		}
	}


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
	}


	float estimate_pitch(float accel_x_axis, float accel_y_axis, float accel_z_axis)
	{
		return 180 * (atan(accel_x_axis / (sqrt((accel_y_axis * accel_y_axis) + (accel_z_axis * accel_z_axis))))) / M_PI;
	}


	float estimate_roll(float accel_y_axis, float accel_z_axis)
	{
		return 180 * (atan(accel_y_axis / accel_z_axis)) / M_PI;
	}


	float clean_column(string data_column)
	{
		float i;
		sscanf_s(data_column.c_str(), "%f", &i);
		return i;
	}
};

int main()
{
	Desafio task;
	task.resolve();
}
