#include <lcom/lcf.h>
#include "graphic.c"
#include "vbe.c"

vbe_mode_info_t* mode_info;



int (set_graphic_mode)(uint16_t mode) {
    reg86_t reg86;
    memset(&reg86, 0, sizeof(reg86)); // inicialização da estrutura com o valor 0 em todos os parâmetros
    reg86.intno = 0x10;               // intno é sempre 0x10      
    reg86.ah = 0x4F;                  // parte mais significativa de AX
    reg86.al = 0x02;                  // parte menos significativa de AX. 0x02 no caso de modo gráfico
    // reg86.ax = 0x4F02;             // equivamente às duas últimas instruções
    reg86.bx = mode | BIT(14);        // determinação do submodo com memória linear
    if (sys_int86(&reg86) != 0)       // se houver algum erro, abortar a função
        return 1;
    return 0;
}