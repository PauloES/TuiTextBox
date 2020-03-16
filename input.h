#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

class input_control
{

HANDLE hStdin; 
DWORD fdwSaveOldMode;

/*VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD); 
VOID MouseEventProc(MOUSE_EVENT_RECORD); 
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD); */
public:
std::string currentVal = "";
std::string lbl;
int pos = currentVal.length();
int start_input = 0;
int line = 0;
int finish = 0;

void fGotoxy(int x, int y)
{	
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}    

 
int input(std::string *val, std::string label, int lin) 
{ 	
	
	lbl=label;
	currentVal = *val;
	start_input = lbl.length()+1;
	pos = currentVal.length();
	line = lin;
	
    DWORD cNumRead, fdwMode, i; 
    INPUT_RECORD irInBuf[128]; 
    int counter=0;
 
    // Get the standard input handle. 
 
    hStdin = GetStdHandle(STD_INPUT_HANDLE); 
  
    
    if (hStdin == INVALID_HANDLE_VALUE) 
        ErrorExit("GetStdHandle"); 
 
    // Save the current input mode, to be restored on exit. 
 
    if (! GetConsoleMode(hStdin, &fdwSaveOldMode) ) 
        ErrorExit("GetConsoleMode"); 

    // Enable the window and mouse input events. 
 
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
    if (! SetConsoleMode(hStdin, fdwMode) ) 
        ErrorExit("SetConsoleMode"); 
 
    // Loop to read and handle the next 100 input events. 
    
    fGotoxy(0, line);
	std::cout << lbl;
	fGotoxy(start_input, line);
	std::cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ";
	fGotoxy(start_input,line);
	std::cout << currentVal;					
 
    while (counter++ <= 1000 and finish ==0)
    { 
        // Wait for the events. 
 
        if (! ReadConsoleInput( 
                hStdin,      // input buffer handle 
                irInBuf,     // buffer to read into 
                128,         // size of read buffer 
                &cNumRead) ) // number of records read 
            ErrorExit("ReadConsoleInput"); 
 
        // Dispatch the events to the appropriate handler. 
        
         
        for (i = 0; i < cNumRead; i++) 
        {
            if(irInBuf[i].EventType==KEY_EVENT) 
            {               
     
                KeyEventProc(irInBuf[i].Event.KeyEvent); 
     		} 
 		}
    } 

    // Restore input mode on exit.

    SetConsoleMode(hStdin, fdwSaveOldMode);
    
    *val = currentVal;

    return 0; 
}

			
			
VOID ErrorExit (LPSTR lpszMessage) 
{ 
    fprintf(stderr, "%s\n", lpszMessage); 

    // Restore input mode on exit.

    SetConsoleMode(hStdin, fdwSaveOldMode);

    ExitProcess(0); 
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	//printf("Key event: ");   

    //if!(ker.bKeyDown)
    //    printf("key pressed\n");
    //else printf("key released\n");	
	
	if (ker.bKeyDown)
	{	
		
	
		if(ker.wVirtualKeyCode == VK_BACK)
		{			
			currentVal = currentVal.substr(0, pos - 1)+  currentVal.substr(pos, currentVal.length());
			pos--;
			if(pos < 0)	
				pos = 0;		
		}
		else if(ker.wVirtualKeyCode == VK_LEFT)
		{
			pos--;
			if(pos < 0)	
				pos = 0;		
		}
		else if(ker.wVirtualKeyCode == VK_RIGHT)
		{
			
			if(pos < currentVal.length()-1)	
				pos++;
		}
		else if(ker.wVirtualKeyCode == VK_END)
		{			
			pos = currentVal.length();				
		}
		else if(ker.wVirtualKeyCode == VK_HOME)
		{			
			pos = 0;				
		}
		else if(ker.wVirtualKeyCode == VK_RETURN )
		{		
			
			finish = 1;				
			
		}
		
		
     	else if(ker.wVirtualKeyCode == VK_DELETE)
		{
			if(pos <  currentVal.length())
			{
			
				currentVal = currentVal.substr(0, pos)+  currentVal.substr(pos+1, currentVal.length()-1);			
				//if(pos == currentVal.length()-1)
				//	pos--;
			}
		}

		else if(ker.wVirtualKeyCode != VK_SHIFT )
		{
			std::ostringstream o;
			o << ker.uChar.AsciiChar;	
			//currentVal += o.str();
			currentVal = currentVal.substr(0, pos)+ o.str() + currentVal.substr(pos, currentVal.length()-1);						
			pos++;		
		
		}
		
	
		fGotoxy(start_input, line);
		std::cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ";
		fGotoxy(start_input,line);
		std::cout << currentVal;//  << "POS:" << pos;;
		fGotoxy(start_input+pos, line);
		//Sleep(200);
		FlushConsoleInputBuffer(hStdin);
	
		
	}	
		
}
};


