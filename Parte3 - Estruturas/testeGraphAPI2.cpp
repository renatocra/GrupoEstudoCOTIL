#include <windows.h>

// Função de callback para processar mensagens da janela
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Define a cor da caneta para desenhar (neste caso, preta)
            HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);

            // Define o ponto inicial e desenha a linha até o ponto final
            MoveToEx(hdc, 400, 10, NULL);  // Ponto inicial (50, 50)
            LineTo(hdc, 400, 430);        // Ponto final (200, 200)
            MoveToEx(hdc, 10, 215, NULL);  
            LineTo(hdc, 800, 215);
            int X0 = 405, Y0 = 220; 
            MoveToEx(hdc, X0+0, Y0-3, NULL);  
            LineTo(hdc, X0+10, Y0-50);
            MoveToEx(hdc, X0+10, Y0-50, NULL);
            LineTo(hdc, X0+20, Y0-70);
            MoveToEx(hdc, X0+20, Y0-70, NULL);
            LineTo(hdc, X0+30, Y0-90);                    

            // Restaura a caneta antiga e limpa a caneta criada
            SelectObject(hdc, hOldPen);
            DeleteObject(hPen);

            EndPaint(hwnd, &ps);
        }
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Função principal do programa
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Classe da janela

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("JanelaExemplo");
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    // Registro da classe da janela
    RegisterClass(&wc);

    // Criação da janela
    HWND hwnd = CreateWindowEx(
        0,                          // Estilo da janela
        TEXT("JanelaExemplo"),      // Nome da classe da janela
        TEXT("Minha Primeira Janela"),    // Título da janela
        WS_OVERLAPPEDWINDOW,        // Estilo da janela
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,  // Posição e tamanho
        NULL,                       // Janela pai
        NULL,                       // Menu
        hInstance,                  // Instância
        NULL                        // Dados adicionais
    );

    if (hwnd == NULL) {
        return 0;
    }

    // Exibe a janela
    ShowWindow(hwnd, nCmdShow);

    // Loop de mensagens
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
