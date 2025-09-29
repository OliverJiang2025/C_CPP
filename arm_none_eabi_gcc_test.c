void _exit(int status) {
    while (1) { }
}

int main(void) {
    // 假设 LED 接在 GPIOA 的第5引脚
    volatile unsigned int *GPIOA_MODER = (unsigned int *)0x40020000;
    volatile unsigned int *GPIOA_ODR  = (unsigned int *)0x40020014;

    // 配置 PA5 为输出
    *GPIOA_MODER |= (1 << 10);

    // 点亮 LED
    *GPIOA_ODR |= (1 << 5);

    while (1) { } // 死循环防止程序退出
}