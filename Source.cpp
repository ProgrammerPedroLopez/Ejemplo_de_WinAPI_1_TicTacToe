#include <windows.h>
#include "resource.h"

HWND hwndButton[9];
HWND hwndReiniciar;

HBITMAP bitmap_x = NULL;
HBITMAP bitmap_o = NULL;

int x = 10;
int y = 10;
int id_button = 10001;
int cuenta_de_clicks = 0;

bool imagen[9];
bool partida_continua = true;
bool jugador_1_casillas[3][3];
bool jugador_2_casillas[3][3];

#define id_button_01 10001
#define id_button_02 10002
#define id_button_03 10003
#define id_button_04 10004
#define id_button_05 10005
#define id_button_06 10006
#define id_button_07 10007
#define id_button_08 10008
#define id_button_09 10009
#define id_button_reiniciar 10010

void revisar_partida(bool arreglo[3][3], const char mensaje[]);

void reiniciar(HWND param);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    // Register the window class.
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "GATO",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        0,0,720,512,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        hwndReiniciar = CreateWindow("BUTTON", "Reiniciar", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            500, 10, 100, 30, hwnd, (HMENU)id_button_reiniciar, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);


        for (int i=0; i<9; i++) 
        {
            imagen[i] = false;
        }

        for (int i=0; i<9; i++) 
        {
            hwndButton[i] = CreateWindow("BUTTON", "", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                x, y, 100, 100, hwnd, (HMENU)id_button, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

            id_button++;
            x = x + 100;
            if (x>300) 
            {
                x = 10;
                y = y + 100;
            }
        }

        bitmap_o = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
        bitmap_x = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2));
        break;

    case WM_COMMAND:
      
        if (partida_continua)
        {
            switch (LOWORD(wParam))
            {
            case id_button_reiniciar:
                reiniciar(hwnd);
                break;

            case id_button_01:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[0][0] = true;
                }
                else
                {
                    jugador_2_casillas[0][0] = true;
                }

                imagen[0] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[0]);
                break;

            case id_button_02:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[0][1] = true;
                }
                else
                {
                    jugador_2_casillas[0][1] = true;
                }

                imagen[1] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[1]);
                break;

            case id_button_03:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[0][2] = true;
                }
                else
                {
                    jugador_2_casillas[0][2] = true;
                }

                imagen[2] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[2]);
                break;

            case id_button_04:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[1][0] = true;
                }
                else
                {
                    jugador_2_casillas[1][0] = true;
                }

                imagen[3] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[3]);
                break;

            case id_button_05:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[1][1] = true;
                }
                else
                {
                    jugador_2_casillas[1][1] = true;
                }

                imagen[4] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[4]);
                break;

            case id_button_06:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[1][2] = true;
                }
                else
                {
                    jugador_2_casillas[1][2] = true;
                }
                imagen[5] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[5]);
                break;

            case id_button_07:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[2][0] = true;
                }
                else
                {
                    jugador_2_casillas[2][0] = true;
                }

                imagen[6] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[6]);
                break;

            case id_button_08:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[2][1] = true;
                }
                else
                {
                    jugador_2_casillas[2][1] = true;
                }

                imagen[7] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[7]);
                break;

            case id_button_09:
                if (cuenta_de_clicks % 2 == 0)
                {
                    jugador_1_casillas[2][2] = true;
                }
                else
                {
                    jugador_2_casillas[2][2] = true;
                }

                imagen[8] = true;
                cuenta_de_clicks++;
                DestroyWindow(hwndButton[8]);
                break;
            }
        }
        else 
        {
            switch (LOWORD(wParam))
            {
            case id_button_reiniciar:
                reiniciar(hwnd);
                break;
            }
        }
        
        break;

    case WM_DESTROY:
        DeleteObject(bitmap_o);
        DeleteObject(bitmap_x);
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        int i = 0;
        x = 10;
        y = 10;
        while (i<9) 
        {

            if (imagen[i])
            {

                imagen[i] = false;

                BITMAP bm;
                /*PAINTSTRUCT ps;*/

                /*HDC hdc = BeginPaint(hwnd, &ps);*/

                HDC hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hbmOld;

                if (cuenta_de_clicks % 2 == 0)
                {
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_o);
                    GetObject(bitmap_o, sizeof(bm), &bm);
                }
                else
                {
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_x);
                    GetObject(bitmap_x, sizeof(bm), &bm);
                }
                
                BitBlt(hdc, x, y, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
                
                SelectObject(hdcMem, hbmOld);
                DeleteDC(hdcMem);

                /*EndPaint(hwnd, &ps);*/
            }

            x = x + 100;
            if (x > 300)
            {
                x = 10;
                y = y + 100;
            }

            i++;
        }

        revisar_partida(jugador_1_casillas, "Jugador X gana");
        revisar_partida(jugador_2_casillas, "Jugador O gana");

        EndPaint(hwnd, &ps);
        
    }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void revisar_partida(bool arreglo[3][3], const char mensaje[])
{

    //horizontal

    if (arreglo[0][0] && arreglo[0][1] && arreglo[0][2])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, horizontal 1",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }

    if (arreglo[1][0] && arreglo[1][1] && arreglo[1][2])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, horizontal 2",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }

    if (arreglo[2][0] && arreglo[2][1] && arreglo[2][2])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, horizontal 3",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }

    //vertical

    if (arreglo[0][0] && arreglo[1][0] && arreglo[2][0])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, vertical 1",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }

    if (arreglo[0][1] && arreglo[1][1] && arreglo[2][1])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, vertical 2",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }

    if (arreglo[0][2] && arreglo[1][2] && arreglo[2][2])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, vertical 3",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }

    //diagonal

    if (arreglo[0][0] && arreglo[1][1] && arreglo[2][2])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, diagonal 1",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }

    if (arreglo[2][0] && arreglo[1][1] && arreglo[0][2])
    {
        MessageBox(NULL, (LPCSTR)"Partida finalizo, diagonal 2",
            (LPCSTR)mensaje, MB_ICONINFORMATION | MB_OK);
        partida_continua = false;
    }
}

void reiniciar(HWND param)
{
    partida_continua = true;

    for (int i = 0; i < 9; i++)
    {
        DestroyWindow(hwndButton[i]);
        imagen[i] = false;
        jugador_1_casillas[0][i] = false;
        jugador_2_casillas[0][i] = false;
    }

    x = 10;
    y = 10;
    id_button = 10001;

    for (int i = 0; i < 9; i++)
    {
        hwndButton[i] = CreateWindow("BUTTON", "", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            x, y, 100, 100, param, (HMENU)id_button, (HINSTANCE)GetWindowLongPtr(param, GWLP_HINSTANCE), NULL);

        id_button++;
        x = x + 100;
        if (x > 300)
        {
            x = 10;
            y = y + 100;
        }
    }
};