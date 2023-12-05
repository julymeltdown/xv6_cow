#include "types.h"
#include "user.h"

int getNumFreePages(void);

int main(int argc, char *argv[]) {
    int freePages = getNumFreePages(); // 래퍼 함수 호출
    printf(1, "Number of free pages: %d\n", freePages); // 결과 출력
    exit();
}


