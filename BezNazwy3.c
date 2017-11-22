#include <windows.h>

LPSTR NazwaKlasy = "okienko";

HWND hButton,hTekst,hwnd,hwnd1,hwnd2,hwnd3,hStatic;
MSG Komunikat;
int pin = 1234;
int spr;
char bufor[128];






LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )

{

    WNDCLASSEX wc;										// wype³nianie struktury

    wc.cbSize = sizeof( WNDCLASSEX );				
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground;  (HBRUSH )( COLOR_WINDOW + 50 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );


    RegisterClassEx( & wc );						// rejestracja klasy okna
    
    
	hwnd = CreateWindowEx( WS_EX_WINDOWEDGE, NazwaKlasy, "Bankomat", WS_OVERLAPPEDWINDOW,      // tworzenie okien oraz przycisków
    CW_USEDEFAULT, CW_USEDEFAULT, 500, 450, NULL, NULL, hInstance, NULL );
    
    hwnd1 = CreateWindowEx(WS_EX_CLIENTEDGE, NazwaKlasy, "Bankomat - wprowadzanie PINu", WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, CW_USEDEFAULT, 500, 450, NULL, NULL, hInstance, NULL);
	
	hwnd2 = CreateWindowEx(WS_EX_CLIENTEDGE, NazwaKlasy, "Bankomat - mo¿liwe opcje", WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, CW_USEDEFAULT, 500, 450, NULL, NULL, hInstance, NULL);
	
	hwnd3 = CreateWindowEx(WS_EX_CLIENTEDGE, NazwaKlasy, "Bankomat - mo¿liwe nomina³y", WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, CW_USEDEFAULT, 500, 450, NULL, NULL, hInstance, NULL);
	

	HWND hStatic = CreateWindowEx (0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_CENTER, 170, 150, 150, 30, hwnd1,NULL, hInstance, NULL);
	SetWindowText( hStatic, "Proszê podaæ PIN" );
	
	MessageBox(NULL, "Witaj w banku ING !", "Powitanie", MB_ICONINFORMATION); 

	hButton = CreateWindowEx (WS_EX_CLIENTEDGE,"BUTTON","WprowadŸ PIN", WS_CHILD | WS_VISIBLE | WS_BORDER,170, 150, 150, 30, hwnd,(HMENU) 101, hInstance, NULL);
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE,"BUTTON","WyjdŸ", WS_CHILD | WS_VISIBLE | WS_BORDER,170, 220, 150, 30, hwnd,(HMENU) 110, hInstance, NULL);
	
	
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "ZatwierdŸ", WS_CHILD | WS_VISIBLE | WS_BORDER,170, 250, 150, 30, hwnd1, (HMENU) 102, hInstance, NULL);
	hTekst = CreateWindowEx (WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |ES_NUMBER, 170, 200, 150, 20, hwnd1,(HMENU) 202, hInstance, NULL);
	
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "Wp³ata", WS_CHILD | WS_VISIBLE | WS_BORDER,170, 120, 150, 30, hwnd2, (HMENU) 103, hInstance, NULL);
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "Wyp³ata", WS_CHILD | WS_VISIBLE | WS_BORDER,170, 190, 150, 30, hwnd2, (HMENU) 104, hInstance, NULL);
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "WyjdŸ", WS_CHILD | WS_VISIBLE | WS_BORDER,170, 260, 150, 30, hwnd2, (HMENU) 105, hInstance, NULL);
		
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "10z³", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,170, 90, 150, 30, hwnd3, (HMENU) 106, hInstance, NULL);
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "20z³", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,170, 160, 150, 30, hwnd3, (HMENU) 107, hInstance, NULL);
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "50z³", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,170, 230, 150, 30, hwnd3, (HMENU) 108, hInstance, NULL);
	hButton = CreateWindowEx (WS_EX_CLIENTEDGE, "BUTTON", "100z³", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,170, 300, 150, 30, hwnd3, (HMENU) 109, hInstance, NULL);
	
	
	ShowWindow( hwnd, nCmdShow); 						// pokazywanie okna
    UpdateWindow( hwnd );
   
   
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )						// pêtla komunikatów
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)				// obs³uga zdarzeñ
{

    switch(msg)
    {
    	case WM_COMMAND:
	    	switch(wParam)
			{
				case 101:
	    			ShowWindow(hwnd1, SW_SHOW);
	    		break;
	    		
	    		case 110:
	    			DestroyWindow(hwnd);
	    		break;
	    		
	    		case 102:
					spr = GetDlgItemInt(hwnd1,202,NULL,TRUE);
					sprintf(bufor,"%d",spr);
					if(pin == spr )
						ShowWindow(hwnd2, SW_SHOW);
					else
						MessageBox(hwnd1, "Niepoprawny PIN!", "Komunikat", MB_OK|MB_ICONSTOP);
                break;
                
                case 103:
                	ShowWindow(hwnd3, SW_SHOW);
                break;
                
                case 104:
                	ShowWindow(hwnd3, SW_SHOW);
                break;
                
                case 105:
                	DestroyWindow(hwnd2);
                break;
                
                case 106:
                	MessageBox(NULL, "Dziêkujemy za skorzystanie z naszych us³ug :)","Proszê poczekaæ na wydruk gotówki i potwierdzenia", MB_ICONINFORMATION); 
                	DestroyWindow (hwnd3);
				break;
                
                case 107:
                	MessageBox(NULL, "Dziêkujemy za skorzystanie z naszych us³ug :)","Proszê poczekaæ na wydruk gotówki i potwierdzenia", MB_ICONINFORMATION); 
                	DestroyWindow (hwnd3);
				break;
                
                case 108:
                	MessageBox(NULL, "Dziêkujemy za skorzystanie z naszych us³ug :)","Proszê poczekaæ na wydruk gotówki i potwierdzenia", MB_ICONINFORMATION); 
                	DestroyWindow (hwnd3);
				break;
                	
                case 109:
                	MessageBox(NULL, "Dziêkujemy za skorzystanie z naszych us³ug :)","Proszê poczekaæ na wydruk gotówki i potwierdzenia", MB_ICONINFORMATION); 
                	DestroyWindow (hwnd3);
				break;
	    	}
	    	
	    	break;
						

    	case WM_CLOSE:										//okno
    	DestroyWindow (hwnd);
    	break;
    	case WM_DESTROY:
    		PostQuitMessage(0);
    	break;
    	
    	default:
    		return DefWindowProc (hwnd, msg, wParam, lParam);
    		
    }
    	
	return 0;
}

