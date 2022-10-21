/*
Developer Name: Joe Williams
Developer Contact: joe.williams@oit.edu
Class: CST116
Project Focus: User input/output; formatting text with member functions and manipulators.

Is this program needlessly complicated and concerningly overengineered? Yes, yes it is. But I don't believe in hard-coding things, and this is the price I pay for it.
*/


#include <iostream> //Standard input/output stuff. You know what it does.
#include <iomanip> //Member functions and manipulators.
#include <sstream> //Adds stringstreams. Literally saved my life when it came to rounding numbers.
#include <windows.h> //Used for printing fancy colored text.
#include <vector> //Vectors are lists of things...including other vectors.

using namespace std;

const HANDLE HCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE); //I'm like 80% sure that this is getting access to the output console so that the cout color can be changed later. Required for colorPrint either way.


//Uses black magic (OS commands) to print in full color with (optional) automatic line breaks. Requires the <windows.h> library. Returns nothing and takes up to 4 parameters:
//text (string): The text to be printed. Don't put a newline or endl at the end.
//color (int): The color code of the text. Optional, defaults to white.
//linebreak (bool): Whether to end the line after printing. Optional, defaults to true.
//console (HANDLE) the console the function is printing to, used for changing color. Defaults to HCONSOLE, so as long as you define the console as HCONSOLE somewhere, you can probably just ignore it.
void colorPrint(string text, int color = 15, bool linebreak = true, HANDLE console = HCONSOLE)
{
	SetConsoleTextAttribute(console, color); //Change the output color to whatever is chosen for the text (defaults to 15, which is white).
	cout << text;
	SetConsoleTextAttribute(console, 15); //Chang the color back to white so that we don't start randomly printing other colors.
	if (linebreak) //Add a line break to the end of the text unless told not to
	{
		cout << endl;
	}
}


//Prints a prompt in full color, then gets a string input from the user. Under the hood its really just a colorPrint along with a cin. Returns a string and takes up to 4 parameters:
//text (string): The text to be printed. Don't put a newline at the end.
//color (int): The color code of the text. Optional, defaults to white.
//newline (bool): Whether to end the line after printing but before input. Optional, defaults to false.
//console (HANDLE) the console the function is printing to, used for changing color. Defaults to HCONSOLE, so as long as you define the console as HCONSOLE somewhere, you can probably just ignore it.
string getStringInput(string text, int color = 15, bool linebreak = false, HANDLE console = HCONSOLE)
{
	string input;
	string afterWhitespace; //cin stops reading input when it reaches whitespace (typically a space) but any remaining input is still in the input buffer, which causes the next cin to read that instead of waiting for user input.
	colorPrint(text, color, false, console);
	cin >> input;
	getline(cin, afterWhitespace); //Reads the entire input buffer, inluding spaces, but doesn't wait for user input (except sometimes it does and I don't fully understand why), so using it on its own won't allow the user to input anything if there is whitespace left in the buffer (which there usually is). To avoid this, I use a normal cin that will always wait for user input, then follow it up with a getline to get anything left after the cin stops reading.
	input += afterWhitespace; //Add the additional input picked up by getline to the result of the cin. Works even if there wasn't anything left for getline to pick up, since getline will just return an empty string.
	if (linebreak)
	{
		cout << endl;
	}

	return input; //Send the input to whatever variable the function is passed to.
}


//Identical to getStringInput, but for numbers. Returns a float and takes up to 4 parameters:
//text (string): The text to be printed. Don't put a newline at the end.
//color (int): The color code of the text. Optional, defaults to white.
//newline (bool): Whether to end the line after printing but before input. Optional, defaults to false.
//console (HANDLE) the console the function is printing to, used for changing color. Defaults to HCONSOLE, so as long as you define the console as HCONSOLE somewhere, you can probably just ignore it.
float getFloatInput(string text, int color = 15, bool linebreak = false, HANDLE console = HCONSOLE)
{
	float input;
	cin.sync(); // Really weird things happen if this isn't here.
	while (true)
	{
		colorPrint(text, color, false, console);
		if (cin >> input) //Tests if the input is a valid number and ends the loop if it is.
		{
			if (linebreak) {
				cout << endl;
			}
			return input; //Immediately exit the function and return the input.
		}
		colorPrint("Error: Your input must be a number. Please try again.", 12);

		// Prevents some very strange infinite loops.
		cin.clear();
		cin.ignore(80, '\n');
	}
}


//Returns the length of the longest string in a vector (of strings). Requires the <vector> library. Takes 1 parameter, which is the vector to be calculated.
int maxLength(vector <string> data) {
	int longest = 0;

	for (string s : data) //Loop through the entire vector, and set s to the current item each time.
	{
		int currentLength = (int)s.length(); //Find the length of s and convert it to an int (because .length() doesn't return an int for some reason).

		if (currentLength > longest) //If the item is longer than the longest item so far...
		{
			longest = currentLength; //...update the longest length to the length of the item.
		}
	}

	return longest;
}


//Really, *really* fancy preformatted tables, requires the <vector> library. Returns nothing and takes up to 6 parameters:
//data (vector <vector <string> >): A vector filled with vectors that are filled with strings, containing the text in the table. Each vector inside it is one column in the table. Columns are printed from top to bottom, with the first item as the heading.
//headingColor (int): The color of the headings at the top of each column, using the same color codes as everything else. Optional, defaults to 15 (white).
//dataColor (int): The color of the data in the table, using the same color codes as everything else. Optional, defaults to 15 (white).
//separator (string): The text used to separate each column. Optional, defaults to "|".
//verticalColor (int): The color of the separators between columns, using the same color codes as everything else. Optional, defaults to 15 (white).
//console (HANDLE) the console the function is printing to, used for changing color. Defaults to HCONSOLE, so as long as you define the console as HCONSOLE somewhere, you can probably just ignore it.
void dynamicTable(vector <vector <string> > data, int headingColor = 15, int dataColor = 15, string separator = "|", int verticalColor = 15, HANDLE console = HCONSOLE)
{
	vector <int> columnWidths; //Holds the maximum length of each column.

	//Loop through the data table and determine how wide each column needs to be.
	for (vector <string> i : data)
	{
		columnWidths.push_back(maxLength(i)); //For each column in the table, find how wide it needs to be (using maxLength), and add it to the vector that holds the widths (using .push_back).
	}

	cout << left; //Align text to the left (if it wasn't there already).

	for (int r = 0; r < data[0].size(); r++) //Loop sideways through the data table, with each loop using a row, instead of a column. Works well, even if it does feel wrong on so many levels.
	{
		colorPrint(separator, verticalColor, false); //Print a separator at the left edge of the table.

		for (int c = 0; c < data.size(); c++) //The first loop selects a row made up of one item from each column (sort of like a slice from each vector in the table). This loop goes through that row and prints everything.
		{
			cout << setw(columnWidths[c]); //Set the cout width to the correct width for the current column.

			//If we're currently printing the first row, print the text with the heading color. Otherwise, print it with the data color.
			if (r == 0)
			{
				colorPrint(data[c][r], headingColor, false);

			}
			else {
				colorPrint(data[c][r], dataColor, false);
			}

			colorPrint(separator, verticalColor, false); //Print a separator between each item.
		}
		cout << endl; //Linebreak between rows.
	}
}

//Literally identical to the other table printer, but it uses member functions. I'm not documenting it, because I'm never going to use it again.
void dynamicTableMember(vector <vector <string> > data, int headingColor = 15, int dataColor = 15, string separator = "|", int verticalColor = 15, HANDLE console = HCONSOLE)
{
	vector <int> columnWidths;

	for (vector <string> i : data)
	{
		columnWidths.push_back(maxLength(i));
	}

	cout.setf(ios::left, ios::adjustfield);

	for (int r = 0; r < data[0].size(); r++)
	{
		colorPrint(separator, verticalColor, false);
		for (int c = 0; c < data.size(); c++)
		{
			cout.width(columnWidths[c]);
			if (r == 0)
			{
				colorPrint(data[c][r], headingColor, false);
				r--;
			}
			else {
				colorPrint(data[c][r], dataColor, false);
			}
			colorPrint(separator, verticalColor, false);
		}
		cout << endl;
	}
}


int main()
{
	//These vectors contain the strings that will go into the table. DynamicTable uses the first item in each column as the heading, so they're predefined with the correct string.
	vector <string> names = { "Name:" };
	vector <string> tableIncomes = { "Income:" };
	vector <string> tableAges = { "Age:" };
	vector <string> tableGPAs = { "GPA:" };

	//Everything except names are inputted as floats, so they're stored in these vectors and converted to strings later. 
	vector <float> incomes = {};
	vector <float> ages = {};
	vector <float> GPAs = {};

	//Get input from the user. Nothing special here.
	for (int i = 0; i < 4; i++) {
		names.push_back(getStringInput("Please enter your name: "));
		incomes.push_back(getFloatInput("Please enter your income: "));
		GPAs.push_back(getFloatInput("Please enter your GPA: "));
	}

	//Converts the floats in the income vector to strings for the table.
	for (float i : incomes)
	{
		stringstream stream; //Create a stringstream.
		stream << fixed << setprecision(2) << i; //stringstreams behave like couts and can use the same manipulators, but instead of printing things, they store the formatted text.
		tableIncomes.push_back("$" + stream.str()); //Pull the text out of the stream and put it in the table vector.
	}

	//Converts the floats in the GPA vector to strings for the table.
	for (float i : GPAs)
	{
		stringstream stream;
		stream << fixed << setprecision(2) << i;
		tableGPAs.push_back(stream.str());
	}

	vector <vector <string> > GPATable = { names, tableIncomes, tableGPAs }; //Construct the final data table using the vectors for names, incomes, and GPAs.
	dynamicTableMember(GPATable, 9); //Print the table.

	//Reset the vectors for names and incomes to their original values. GPA isn't reset because it won't be used again.
	names = { "Name:" };
	tableIncomes = { "Income:" };
	incomes = {};

	//Repeat the entire first half of main, but ask for age instead of GPA.
	for (int i = 0; i < 4; i++) {
		names.push_back(getStringInput("Please enter your name: "));
		incomes.push_back(getFloatInput("Please enter your income: "));
		ages.push_back(getFloatInput("Please enter your age: "));
	}

	for (float i : incomes)
	{
		stringstream stream;
		stream << fixed << setprecision(2) << i;
		tableIncomes.push_back("$" + stream.str());
	}

	for (float i : ages)
	{
		stringstream stream;
		stream << fixed << setprecision(2) << i;
		tableAges.push_back(stream.str());
	}

	vector <vector <string> > ageTable = { names, tableIncomes, tableAges };
	dynamicTableMember(ageTable, 9);

	return 0;
}