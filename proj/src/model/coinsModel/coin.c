#include "coin.h"

Coin coins[326];
Energizer energizers[5];

void (setCoinsPositions)() {
    int i;

    i = 195;
    for (int c = 0; c < 15; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 50;
        coins[c].pos.yMin = 75;
        i += 19;
    }

    i = 555;
    for (int c = 15; c < 30; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 50;
        coins[c].pos.yMin = 75;
        i += 19;
    }

    i = 195;
    for (int c = 30; c < 64; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 144;
        coins[c].pos.yMin = 169;
        i += 19;
    }

    i = 195;
    for (int c = 64; c < 71; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 220;
        coins[c].pos.yMin = 245;
        i += 19;
    }    

    i = 390;
    for (int c = 71; c < 76; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 220;
        coins[c].pos.yMin = 245;
        i += 19;
    }

    i = 550;
    for (int c = 76; c < 81; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 220;
        coins[c].pos.yMin = 245;
        i += 19;
    }

    i = 705;
    for (int c = 81; c < 88; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 220;
        coins[c].pos.yMin = 245;
        i += 19;
    }    

    i = 385;
    for (int c = 88; c < 102; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 290;
        coins[c].pos.yMin = 315;
        i += 19;
    } 

    i = 195;
    for (int c = 102; c < 113; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 358;
        coins[c].pos.yMin = 383;
        i += 19;
    }
    
    i = 630;
    for (int c = 113; c < 124; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 358;
        coins[c].pos.yMin = 383;
        i += 19;
    }

    i = 385;
    for (int c = 124; c < 138; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 430;
        coins[c].pos.yMin = 455;
        i += 19;
    }

    i = 195;
    for (int c = 138; c < 153; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 503;
        coins[c].pos.yMin = 528;
        i += 19;
    }
    
    i = 560;
    for (int c = 153; c < 168; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 503;
        coins[c].pos.yMin = 528;
        i += 19;
    }

    i = 195;
    for (int c = 168; c < 171; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 575;
        coins[c].pos.yMin = 600;
        i += 19;
    }

    i = 310;
    for (int c = 171; c < 177; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 575;
        coins[c].pos.yMin = 600;
        i += 19;
    }

    i = 612;
    for (int c = 177; c < 183; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 575;
        coins[c].pos.yMin = 600;
        i += 19;
    }

    i = 792;
    for (int c = 183; c < 186; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 575;
        coins[c].pos.yMin = 600;
        i += 19;
    }

    i = 205;
    for (int c = 186; c < 201; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 710;
        coins[c].pos.yMin = 735;
        i += 19;
    }

    i = 545;
    for (int c = 201; c < 216; c++) {
        coins[c].pos.xMin = i;
        coins[c].pos.xMax = i + 25;
        coins[c].pos.yMax = 710;
        coins[c].pos.yMin = 735;
        i += 19;
    }

    i = 65;
    for (int c = 216; c < 220; c++) {
        coins[c].pos.xMin = 195;
        coins[c].pos.xMax = 220;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 162;
    for (int c = 220; c < 223; c++) {
        coins[c].pos.xMin = 195;
        coins[c].pos.xMax = 220;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 535;
    for (int c = 223; c < 225; c++) {
        coins[c].pos.xMin = 195;
        coins[c].pos.xMax = 220;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 600;
    for (int c = 225; c < 228; c++) {
        coins[c].pos.xMin = 233;
        coins[c].pos.xMax = 358;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 90;
    for (int c = 228; c < 231; c++) {
        coins[c].pos.xMin = 310;
        coins[c].pos.xMax = 335;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }
    
    i = 175;
    for (int c = 231; c < 233; c++) {
        coins[c].pos.xMin = 310;
        coins[c].pos.xMax = 335;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 240;
    for (int c = 233; c < 239; c++) {
        coins[c].pos.xMin = 310;
        coins[c].pos.xMax = 335;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 380;
    for (int c = 239; c < 245; c++) {
        coins[c].pos.xMin = 310;
        coins[c].pos.xMax = 335;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 535;
    for (int c = 245; c < 247; c++) {
        coins[c].pos.xMin = 310;
        coins[c].pos.xMax = 335;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 600;
    for (int c = 247; c < 250; c++) {
        coins[c].pos.xMin = 310;
        coins[c].pos.xMax = 335;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 180;
    for (int c = 250; c < 252; c++) {
        coins[c].pos.xMin = 390;
        coins[c].pos.xMax = 415;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 310;
    for (int c = 252; c < 254; c++) {
        coins[c].pos.xMin = 385;
        coins[c].pos.xMax = 410;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 390;
    for (int c = 254; c < 256; c++) {
        coins[c].pos.xMin = 385;
        coins[c].pos.xMax = 410;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 430;
    for (int c = 256; c < 260; c++) {
        coins[c].pos.xMin = 385;
        coins[c].pos.xMax = 410;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 600;
    for (int c = 260; c < 263; c++) {
        coins[c].pos.xMin = 405;
        coins[c].pos.xMax = 430;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 180;
    for (int c = 263; c < 265; c++) {
        coins[c].pos.xMin = 627;
        coins[c].pos.xMax = 652;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 310;
    for (int c = 265; c < 267; c++) {
        coins[c].pos.xMin = 632;
        coins[c].pos.xMax = 657;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 390;
    for (int c = 267; c < 269; c++) {
        coins[c].pos.xMin = 632;
        coins[c].pos.xMax = 657;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 450;
    for (int c = 269; c < 272; c++) {
        coins[c].pos.xMin = 632;
        coins[c].pos.xMax = 657;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 600;
    for (int c = 272; c < 275; c++) {
        coins[c].pos.xMin = 615;
        coins[c].pos.xMax = 640;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 90;
    for (int c = 275; c < 278; c++) {
        coins[c].pos.xMin = 705;
        coins[c].pos.xMax = 730;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }
    
    i = 175;
    for (int c = 278; c < 280; c++) {
        coins[c].pos.xMin = 705;
        coins[c].pos.xMax = 730;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 240;
    for (int c = 280; c < 286; c++) {
        coins[c].pos.xMin = 705;
        coins[c].pos.xMax = 730;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 380;
    for (int c = 286; c < 292; c++) {
        coins[c].pos.xMin = 705;
        coins[c].pos.xMax = 730;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    coins[292].pos.xMin = 310;
    coins[292].pos.xMax = 335;
    coins[292].pos.yMax = 67;
    coins[292].pos.yMin = 92;

    i = 535;
    for (int c = 293; c < 295; c++) {
        coins[c].pos.xMin = 705;
        coins[c].pos.xMax = 730;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 600;
    for (int c = 295; c < 298; c++) {
        coins[c].pos.xMin = 705;
        coins[c].pos.xMax = 730;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 600;
    for (int c = 298; c < 301; c++) {
        coins[c].pos.xMin = 795;
        coins[c].pos.xMax = 820;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    coins[301].pos.xMin = 705;
    coins[301].pos.xMax = 730;
    coins[301].pos.yMax = 67;
    coins[301].pos.yMin = 92;

    coins[302].pos.xMin = 830;
    coins[302].pos.xMax = 855;
    coins[302].pos.yMax = 554;
    coins[302].pos.yMin = 579;

    i = 85;
    for (int c = 303; c < 306; c++) {
        coins[c].pos.xMin = 820;
        coins[c].pos.xMax = 845;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 162;
    for (int c = 306; c < 309; c++) {
        coins[c].pos.xMin = 820;
        coins[c].pos.xMax = 845;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 535;
    for (int c = 309; c < 311; c++) {
        coins[c].pos.xMin = 830;
        coins[c].pos.xMax = 855;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 90;
    for (int c = 311; c < 313; c++) {
        coins[c].pos.xMin = 460;
        coins[c].pos.xMax = 485;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    } 

    i = 235;
    for (int c = 313; c < 316; c++) {
        coins[c].pos.xMin = 460;
        coins[c].pos.xMax = 485;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 530;
    for (int c = 316; c < 318; c++) {
        coins[c].pos.xMin = 460;
        coins[c].pos.xMax = 485;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 235;
    for (int c = 318; c < 321; c++) {
        coins[c].pos.xMin = 550;
        coins[c].pos.xMax = 575;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 530;
    for (int c = 322; c < 324; c++) {
        coins[c].pos.xMin = 560;
        coins[c].pos.xMax = 585;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    }

    i = 90;
    for (int c = 324; c < 326; c++) {
        coins[c].pos.xMin = 555;
        coins[c].pos.xMax = 580;
        coins[c].pos.yMax = i;
        coins[c].pos.yMin = i + 25;
        i += 19;
    } 

    for (int c = 0; c < 326; c++){
        coins[c].isCaptured = false;
    }

}

void (setEnergizersPositions)() {
    energizers[0].pos.xMin = 175;
    energizers[0].pos.xMax = 200;
    energizers[0].pos.yMax = 355;
    energizers[0].pos.yMin = 380;

    energizers[1].pos.xMin = 835;
    energizers[1].pos.xMax = 860;
    energizers[1].pos.yMax = 355;
    energizers[1].pos.yMin = 380;
    
    energizers[2].pos.xMin = 195;
    energizers[2].pos.xMax = 220;
    energizers[2].pos.yMax = 65;
    energizers[2].pos.yMin = 90;

    energizers[3].pos.xMin = 820;
    energizers[3].pos.xMax = 855;
    energizers[3].pos.yMax = 65;
    energizers[3].pos.yMin = 90;

    energizers[4].pos.xMin = 506;
    energizers[4].pos.xMax = 531;
    energizers[4].pos.yMax = 710;
    energizers[4].pos.yMin = 735;

    for (int i = 0; i < 5; i++)
        energizers[i].isCaptured = false;
}

