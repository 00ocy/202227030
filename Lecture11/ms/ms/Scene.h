#pragma once
char screenBuf[35 * 12 + 1];

int drawBorder(char* screenBuf, int width, int height) {
    // ���μ� �׸���
    for (int i = 0; i < width; i++) {
        screenBuf[i] = '-';
        screenBuf[(height - 1) * width + i] = '-';
    }

    // ���μ� �׸���
    for (int i = 1; i < height - 1; i++) {
        screenBuf[i * width] = '|';
        screenBuf[(i * width) + (width - 1)] = '|';
        for (int j = 1; j < width - 1; j++) {
            screenBuf[i * width + j] = NULL;
        }
    }
} 